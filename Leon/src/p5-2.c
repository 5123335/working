///*
// * p5-2.c
// *
// *  Created on: 2013/07/12
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <stdio.h>
//#include <tchar.h>
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine,
//		int nCmdShow) {
//
//	TCHAR chStr[128];
//
//	wsprintf(chStr, TEXT("インスタンスハンドル : %d"), hInstance);
//	MessageBox(NULL, chStr, TEXT("Kitty on your lap"), MB_OK);
//
//	//	int wsprintf(
//	//	  LPTSTR lpOut,    // 出力バッファ
//	//	  LPCTSTR lpFmt,   // 書式制御文字列
//	//	  ...              // オプションの引数
//	//	);
//	//	wsprintfは文字列を扱うWin32 APIなので，wsprintfAとwsprintfWがあります。
//	//	int WINAPI wsprintfA (char *, const char *, ...);
//	//	int WINAPI wsprintfW (wchar_t *, const wchar_t *, ...);
//	//	なので，wsprintfとして使う場合は，全てTCHAR系で統一する必要があります。
//	//  (charはマルチバイト文字、wchar_tはワイド文字)
//	//  (Unicode用のwsprintfW、ANSI用のwsprintfA)
//
//	const LPCTSTR str = TEXT("あああ");
//	printf(str);
//
//	return 0;
//}
