///*
// * p8.c
// *
// *  Created on: 2013/07/16
// *      Author: yumikoy
// */
//
//#include <windows.h>
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine,
//		int nCmdShow) {
//	HWND hwnd;
//	WNDCLASS winc;
//
//	winc.style = CS_HREDRAW | CS_VREDRAW;
//	winc.lpfnWndProc = DefWindowProc;
//	winc.cbClsExtra = winc.cbWndExtra = 0;
//	winc.hInstance = hInstance;
//	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	winc.hbrBackground = (HBRUSH)GetStockObject(0);
//	winc.lpszMenuName = NULL;
//	winc.lpszClassName = TEXT("KITTY");
//
//	if (!RegisterClass(&winc))
//		return 0;
//
//	hwnd =
//			CreateWindow(TEXT("KITTY"), TEXT("Kitty on your lap"),
//					WS_OVERLAPPEDWINDOW, 100, 100, 200, 200, NULL, NULL, hInstance, NULL);
//
//	if (hwnd == NULL )
//		return 0;
//
//	ShowWindow(hwnd, SW_SHOW);
//	MessageBox(NULL, TEXT("Kitty on your lap"), TEXT("Kitty"),
//			MB_ICONINFORMATION);
//
//	return 0;
//
//}
//
//	//	typedef struct _WNDCLASS {
//	//		UINT    style;  // ウィンドウクラスの基本スタイルを表す定数
//	//		WNDPROC lpfnWndProc;  // ウィンドウプロシージャを設定
//	//		int     cbClsExtra;  // クラス構造体の追加領域を予約
//	//		int     cbWndExtra;  // ウィンドウ構造体の追加領域を予約
//	//		HANDLE  hInstance;  // インスタンスハンドルを渡す
//	//		HICON   hIcon;  // タスクバーやタイトルバーに表示されるアイコンのbmpを指定
//	//		HCURSOR hCursor;  // ウィンドウのクライアントエリア上のマウスカーソルを指定
//	//		HBRUSH  hbrBackground;  // クライアントエリアの背景色を指定
//	//		LPCTSTR lpszMenuName;  // クラスメニューを指定
//	//		LPCTSTR lpszClassName;  // ウィンドウクラスの名前
//	//	} WNDCLASS;
//
//	// WNDPROC : ウィンドウプロシージャ関数へのポインタ型
//	// ウィンドウプロシージャ : ウィンドウで発生したイベントを処理する関数
//	//  DefWindowProc()がデフォルト。ウィンドウの移動などの基本的な動作をサポート
//	//  ↓ウィンドウズが呼び出す。
//	//		LRESULT DefWindowProc(
//	//		  HWND hWnd,
//	//		  UINT Msg,
//	//		  WPARAM wParam,
//	//		  LPARAM lParam
//	//		);
//
//	// HICON : アイコンのハンドル
//	//		HICON LoadIcon(
//	//		  HINSTANCE hInstance ,  // アイコンのリソースが入っているモジュールのインスタンスを指定
//	//		  LPCTSTR lpIconName  // アイコンの名前
//	//		);
//	// システム定義のアイコンの場合はhInstanceをNULLとする。
//	// その場合、lpIconNameは用意されているアイコンの定数を渡す。
//	// IDI_APPLICATION : アプリケーションアイコン
//
//	// HICON : アイコンのハンドル
//	//		HICON LoadCursor(
//	//		  HINSTANCE hInstance ,  // カーソルのリソースが入っているモジュールのインスタンスを指定
//	//		  LPCTSTR lpCursorName  // カーソルの名前
//	//		);
//	// システム定義のアイコンの場合はhInstanceをNULLとする。
//	// その場合、lpIconNameは用意されているアイコンの定数を渡す。
//
//	// HBRUSH : ブラシのハンドル型
//	// HGDIOBJ GetStockObject( int fnObject );
//	// 定義済みのブラシやフォントのハンドルを取得
//	// fnObjectに、取得したいハンドルの定数を指定する
//	// HGDIOBJ : グラフィック関連のハンドル(HBRUSHにキャストできる)
//
//	// ATOM RegisterClass(CONST WNDCLASS *lpwcx);
//	// ウィンドウクラスを登録する。失敗すると0が返る
//
//
//
