/*
 * p58textanimation01.cpp
 *
 *  Created on: 2013/07/17
 *      Author: yumikoy
 */

#define ID_MYTIMER 100   // ms/frame
#define ID0 10  // 1frameで動く幅

#include <windows.h>
#include <stdio.h>
#if defined(__MINGW32__)
#   undef  MAKEINTRESOURCE
#   define MAKEINTRESOURCE(i) ((LPSTR)((ULONG_PTR)(i)))
#endif  /* defined(__MINGW32__) */

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM InitApp(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
HFONT MyCreateFont(LPCTSTR, int);   // カスタムフォントの作成(フェイス名, サイズ)

LPCTSTR szClassName = TEXT("textanimation01");

int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE nl, LPSTR lpsCmdLine,
		int nCmdShow) {
	MSG msg;
	BOOL bRet;

	if (!InitApp(hCurInst))
		return FALSE;
	if (!InitInstance(hCurInst, nCmdShow))
		return FALSE;
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
		if (bRet == -1) {
			break;
		} else {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int) msg.wParam;
}

// ウィンドウクラスの登録
ATOM InitApp(HINSTANCE hInst) {
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = (HICON) LoadImage(NULL, MAKEINTRESOURCE(IDI_APPLICATION),
			IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	wc.hCursor = (HCURSOR) LoadImage(NULL, MAKEINTRESOURCE(IDC_ARROW),
			IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = (LPCSTR) szClassName;
	wc.hIconSm = (HICON) LoadImage(NULL, MAKEINTRESOURCE(IDI_APPLICATION),
			IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);

	return (RegisterClassEx(&wc));
}

// ウィンドウの生成
BOOL InitInstance(HINSTANCE hInst, int nCmdShow) {
	HWND hWnd;

	hWnd = CreateWindow(szClassName, TEXT("猫でもわかるアニメーション"), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, 288, 105, NULL, NULL, hInst, NULL);

	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

// ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	int id;
	static int x, clw, txtw; // 時間ごとの座標, クライアント領域の幅, 動かす文字列の幅
	HDC hdc;
	PAINTSTRUCT ps;
	static HFONT hFont;
	LPCTSTR lpszTxt = TEXT("ねこ");
	SIZE sz;   // SIZE構造体(GetTextExtentPoint32で使用)
	RECT rc;
	static int dir = 0;  // 0:右へ  1:左へ

	switch (msg) {
	case WM_CREATE:  // 初期化処理 (WM_CREATE : CreateWindowが呼び出されたときに送られる)
		hdc = GetDC(hWnd);
		hFont = MyCreateFont(TEXT("MS ゴシック"), 50);    // フェイス名"MS ゴシック", 高さ50のフォントを作成
		SelectObject(hdc, hFont);   // 文字列の幅を調べるためにフォントを一旦selectする必要がある
		GetTextExtentPoint32(hdc, lpszTxt, (int) lstrlen(lpszTxt), &sz);
		txtw = sz.cx;  // 文字列の幅(WndProcから抜けても保持されるようstaticなtxtwに格納)
		printf("%d,%d", txtw, (int)sz.cy);   // -> 102,50 (SelectObjectしないと32,18)
		SetTimer(hWnd, ID_MYTIMER, 30, NULL);  // タイマのセット
		ReleaseDC(hWnd, hdc);   // デバイスコンテキストハンドルを解放する
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SelectObject(hdc, hFont);   // hdcのデバイスコンテキストでhFontが選択される
		TextOut(hdc, x, 10, lpszTxt, (int) strlen(lpszTxt));   // xが動く
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		if (wp != ID_MYTIMER)   // TIMERのIDが自分の指定したものか確認する
			return DefWindowProc(hWnd, msg, wp, lp); // 違っていたらDefWindowProcに処理を任せる
		GetClientRect(hWnd, &rc);   // クライアント領域の矩形を取得
		clw = rc.right;
		// 表示する位置の変更
		if (dir == 0) {   // xを変えてる
			x += ID0;
			if (x > clw - txtw) {
				x = clw - txtw;
				dir = 1;
			}
		} else {
			x -= ID0;
			if (x < 0) {
				x = 0;
				dir = 0;
			}
		}
		// 無効領域を発生させWM_PAINTを発行させる
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_CLOSE:
		id = MessageBox(hWnd, TEXT("終了してもよろしいですか"), TEXT("終了確認"), MB_YESNO);
		if (id == IDYES)
			DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		// タイマやGDIオブジェクトの後始末
		KillTimer(hWnd, ID_MYTIMER);   // Timerを破棄
		DeleteObject(hFont);   // createしたGDIオブジェクト(今回はフォント)を破棄
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hWnd, msg, wp, lp));
	}
	return 0;
}

HFONT MyCreateFont(LPCTSTR face, int h) {  // face:フォントフェイス名, h:フォントの高さ(論理単位)
	HFONT hFont;   // フォントハンドル(正体はHGDIOBJ)
	// 論理フォントの作成
	hFont = CreateFont(h, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, FIXED_PITCH | FF_MODERN, face);
	return hFont;
}

	// SetTimer関数 : 定期的にWM_TIMERメッセージを発行する
	//	UINT_PTR SetTimer(
	//		HWND hWnd,          // 関連付けるウィンドウのハンドル
	//		UINT_PTR nIDEvent,  // タイマのID(自分でdefine)
	//		UINT uElapse,       // タイムアウト値(WM_TIMERを送る間隔)(ミリ秒)
	//		TIMERPROC lpTimerFunc // タイマのプロシージャ(NULLを指定するとhWndのプロシージャにWM_TIMERが送られる)
	//	);

	// InvalidateRect関数 : 無効領域(矩形あるいはクライアント領域全体)を発生させる
	//	BOOL InvalidateRect(
	//		HWND hWnd,          // ウィンドウハンドル
	//		CONST RECT* lpRect, // RECT構造体へのポインタ(NULLを指定するとクライアント領域全体が対象)
	//		BOOL bErase         // 背景を消去するかどうか(FALSEにすると残像が出る)
	//	);

	// GetTextExtentPoint32関数 : 文字列の幅と高さを計算する。
	//	BOOL GetTextExtentPoint32(
	//		HDC hdc,          // デバイスコンテキストハンドル
	//		LPCTSTR lpString, // 調べる文字列
	//		int cbString,     // 文字数
	//		LPSIZE lpSize     // 結果を受け取るSIZE構造体へのポインタ
	//	);
	//　GetTextExtentPoint32(hdc, lpszTxt, (int)strlen(lpszTxt), &sz);

	// SIZE構造体 : 矩形の幅と高さを定義する
	//	typedef struct tagSIZE {
	//		LONG cx;    // 幅
	//		LONG cy;    // 高さ
	//	} SIZE,SIZEL,*PSIZE,*LPSIZE,*PSIZEL,*LPSIZEL;

	// GetClientRect関数 : クライアント領域の矩形を取得
	//	BOOL GetClientRect(
	//		HWND hWnd,     // 調べたいウィンドウのハンドルを指定
	//		LPRECT lpRect  // クライアント領域の座標が代入される
	//	);

	// CreateFont関数 : 論理フォントの作成
	//	HFONT CreateFont(
	//		int nHeight,         // フォントの論理単位の高さ
	//		int nWidth,          // 平均の幅(論理単位)
	//		int nEscapement,     // 文字送りの方向とX軸の角度
	//		int nOrientation,    // 各文字とX軸の角度
	//		int fnWeight,        // フォントの太さ(0〜900)
	//		DWORD fdwItalic,     // TRUEだとイタリック体
	//		DWORD fdwUnderline,  // TRUEだと下線付き
	//		DWORD fdwStrikeOut,  // TRUEだと打ち消し線付き
	//		DWORD fdwCharSet,    // フォント文字セット
	//		DWORD fdwOutputPrecision,  // 出力精度
	//		DWORD fdwClipPrecision,    // クリッピング精度
	//		DWORD fdwQuality,    // 出力品質
	//		DWORD fdwPitchAndFamily,   // ピッチとファミリ
	//		LPCTSTR lpszFace     // フォントフェイス名
	//	);
	//　hFont = CreateFont(h, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
	//		SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
	//		PROOF_QUALITY, FIXED_PITCH | FF_MODERN, face);


