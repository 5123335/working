///*
// * p7.c
// *
// *  Created on: 2013/07/16
// *      Author: yumikoy
// */
//
//#include <windows.h>
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine,
//		int nCmdShow) {
////	HWND hwnd = CreateWindow(TEXT("STATIC"), TEXT("Kitty on your lap"),
////			WS_CAPTION, 100, 100, 200, 200, NULL, NULL, hInstance, NULL);
//	HWND hwnd = CreateWindowEx(WS_EX_TOOLWINDOW, TEXT("STATIC"), TEXT("Kitty on your lap"),
//			WS_OVERLAPPEDWINDOW, 100, 100, 200, 200, NULL, NULL, hInstance, NULL);
//	// WS_EX_TOOLWINDOW : タスクバーに表示されない、タイトルバーが小さいウィンドウ
//
//	if (hwnd == NULL )
//		return 0;
//
//	ShowWindow(hwnd, SW_SHOW);
//	MessageBox(NULL, TEXT("Kit"), TEXT("Kitty"), MB_ICONINFORMATION);
//
//	return 0;
//}
//
//	//	HWND CreateWindowEx(
//	//	  DWORD dwExStyle,      // 拡張ウィンドウスタイル
//	//	  LPCTSTR lpClassName,  // 登録されているクラス名
//	//	  LPCTSTR lpWindowName, // ウィンドウ名
//	//	  DWORD dwStyle,        // ウィンドウスタイル
//	//	  int x,                // ウィンドウの横方向の位置
//	//	  int y,                // ウィンドウの縦方向の位置
//	//	  int nWidth,           // ウィンドウの幅
//	//	  int nHeight,          // ウィンドウの高さ
//	//	  HWND hWndParent,      // 親ウィンドウまたはオーナーウィンドウのハンドル
//	//	  HMENU hMenu,          // メニューハンドルまたは子識別子
//	//	  HINSTANCE hInstance,  // アプリケーションインスタンスのハンドル
//	//	  LPVOID lpParam        // ウィンドウ作成データ
//	//	);
//	//	関数が成功すると、作成されたウィンドウのハンドルが返ります。
//	//	関数が失敗すると、NULL が返ります。拡張エラー情報を取得するには、 関数を使います。
//
//
//	//	BOOL ShowWindow(
//	//	  HWND hWnd,     // ウィンドウのハンドル
//	//	  int nCmdShow   // 表示状態
//	//	);
//	//	ウィンドウが以前から表示されていた場合は、0 以外の値が返ります。
//	//	ウィンドウが以前は非表示だった場合は、0 が返ります。
//
//
//
