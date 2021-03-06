///*
// * p31text01.cpp
// *
// *  Created on: 2013/07/17
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <stdio.h>
//
//#if defined(__MINGW32__)
//#   undef  MAKEINTRESOURCE
//#   define MAKEINTRESOURCE(i) ((LPSTR)((ULONG_PTR)(i)))
//#endif  /* defined(__MINGW32__) */
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//ATOM InitApp(HINSTANCE);
//BOOL InitInstance(HINSTANCE, int);
//
//TCHAR szClassName[] = TEXT("text01");
//
//int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE nl, LPSTR lpsCmdLine,
//		int nCmdShow) {
//	MSG msg;
//	BOOL bRet;
//
//	if (!InitApp(hCurInst))
//		return FALSE;
//	if (!InitInstance(hCurInst, nCmdShow))
//		return FALSE;
//	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
//		if (bRet == -1) {
//			break;
//		} else {
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	}
//	return (int) msg.wParam;
//}
//
//// ウィンドウクラスの登録
//ATOM InitApp(HINSTANCE hInst) {
//	WNDCLASSEX wc;
//	wc.cbSize = sizeof(WNDCLASSEX);
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.lpfnWndProc = WndProc;
//	wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.hInstance = hInst;
//	wc.hIcon = (HICON) LoadImage(NULL, MAKEINTRESOURCE(IDI_APPLICATION),
//			IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
//	wc.hCursor = (HCURSOR) LoadImage(NULL, MAKEINTRESOURCE(IDC_ARROW),
//			IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
//	wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = (LPCSTR)szClassName;
//	wc.hIconSm = (HICON) LoadImage(NULL, MAKEINTRESOURCE(IDI_APPLICATION),
//			IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
//
//	return (RegisterClassEx(&wc));
//}
//
//// ウィンドウの生成
//BOOL InitInstance(HINSTANCE hInst, int nCmdShow) {
//	HWND hWnd;
//		hWnd = CreateWindow(szClassName, TEXT("猫でもわかるテキスト表示"), WS_OVERLAPPEDWINDOW,
//				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//				NULL, NULL, hInst, NULL);
//
//	if(!hWnd)
//		return FALSE;
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);  // なくても動く
//	return TRUE;
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
//{
//	int id, y = 0, i;
//	PAINTSTRUCT ps;  // PAINTSTRUCT構造体 : 描画情報を保持する。
//	HDC hdc;
//	TCHAR lpszStr[] = TEXT("猫でもわかるゲームプログラミング");
//
//	switch(msg){
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
////		printf("b%d\n", (int)ps.rcPaint.bottom);
////		printf("l%d\n", (int)ps.rcPaint.left);
////		printf("r%d\n", (int)ps.rcPaint.right);
////		printf("t%d\n", (int)ps.rcPaint.top);
//		for(i=0; i<20; i++){
//			TextOut(hdc, 0, y+30*i, lpszStr, (int)lstrlen(lpszStr));
//		}
////		printf("%d\n", (int)ps.rcPaint.bottom);
//		EndPaint(hWnd, &ps);
////		printf("%d\n", (int)ps.rcPaint.bottom);
//		break;
//	case WM_CLOSE:
//		id = MessageBox(hWnd, TEXT("終了してもよろしいですか"), TEXT("終了確認"), MB_YESNO);
//		if(id==IDYES)
//			DestroyWindow(hWnd);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return (DefWindowProc(hWnd, msg, wp, lp));
//	}
//	return 0;
//}
//
//	//  PAINTSTRUCT構造体 : 描画情報を保持する。中身は(今は？)使わない
//	//	typedef struct tagPAINTSTRUCT {
//	//		HDC	hdc;           // デバイスコンテキストハンドル
//	//		BOOL fErase;       // 無効領域の塗りつぶしが行われたかどうか
//	//		RECT rcPaint;      // 無効領域
//	//		BOOL fRestore;     // 予約済み
//	//		BOOL fIncUpdate;   // 予約済み
//	//		BYTE rgbReserved[32];   // 予約済み
//	//	} PAINTSTRUCT,*LPPAINTSTRUCT;
//
//	//	デバイスコンテキスト : ディスプレイやプリンタなどの出力デバイスの情報を含む構造体で、システムが保有している。
//	//  デバイスコンテキストハンドルを取得する関数 :
//	//  HDC GetDC(HWND hWnd);
//	//  HDC BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint); // WM_PAINTメッセージの処理でしか使用できない。
//
//	//  BeginPaintで開始した描画が完了したら必ずEndPaint関数を呼び出す必要がある。
//	//  EndPaint関数 : 指定されたウィンドウ内の描画を終了する。
//	//  BOOL EndPaint(HWND hWnd, CONST PAINTSTRUCT *lpPaint);
//
//	//  TextOut関数 : 文字列を描画する。
//	//	BOOL TextOut(
//	//		HDC hdc,            // デバイスコンテキストハンドル
//	//		int nXStart,        // x座標
//	//		int nYStart,        // y座標
//	//		LPCTSTR lpString,   // 文字列
//	//		int cbString        // 文字数
//	//	);
//
//
//
