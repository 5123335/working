///*
// * p9.c
// *
// *  Created on: 2013/07/16
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <stdio.h>
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine,
//		int nCmdShow) {
//	HWND hwnd;
//	MSG msg;
//
//	hwnd = CreateWindow(TEXT("BUTTON"), TEXT("Kitty on your lap"),
//			WS_CAPTION | WS_VISIBLE,
//			100, 100, 200, 200, NULL, NULL,
//			hInstance, NULL);
//
//	if (hwnd == NULL )
//		return 0;
//
//	while (TRUE) {
//		GetMessage(&msg, NULL, 0, 0);  // msgにメッセージを格納
//		if (msg.message == WM_LBUTTONUP)
//			break;
//		DispatchMessage(&msg);
//	}
//
//	return 0;
//}
//
