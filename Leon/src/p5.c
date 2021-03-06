///*
// * p5.c
// *
// *  Created on: 2013/07/11
// *      Author: yumikoy
// */
//#include <windows.h>
//
//int WINAPI WinMain(HINSTANCE hInstance,     // インスタンスハンドル
//		HINSTANCE hPrevInstance, // Win32では常にNULL(→使うことはない)
//		LPSTR lpCmdLine,         // コマンドラインから受け取る引数
//		int nCmdShow)            // アプリケーションの初期表示方法
//{
//	// ↑の引数たちはアプリケーションプログラム中で指定することはない。この関数の中で使うためのもの
//
//	// WINAPI : __stdcallのマクロ名
//	// #define [マクロ名] [パターン]
//
//	// HINSTANCE : インスタンスハンドル。アプリケーション自体をあらわす
//	// 	アプリケーションによってインスタンスハンドルの値は一意。
//	// 	インスタンスとは、アプリケーションのメモリ内での実体のこと。
//	// 	データとしては32bit整数値
//
//	// LPSTR :　ANSI(またはマルチバイト)文字列へのポインタ
//	// typedef CHAR *PCHAR,*LPCH,*PCH,*NPSTR,*LPSTR,*PSTR;
//
////	MessageBox(NULL, TEXT("Kitty on your lap"), TEXT("メッセージ愛ボックス"), MB_OK);
////	MessageBox(NULL, TEXT("Kitty on your lap"), TEXT("メッセージ愛ボックス"),
////			MB_OK | MB_ICONINFORMATION);
//	int modoriti;
//	modoriti = MessageBox(NULL, TEXT("Do you like Nekomimi?"), TEXT("質問しています"),
//			MB_YESNO | MB_ICONQUESTION);
//
//	//	int MessageBox(
//	//	  HWND hWnd,          // オーナーウィンドウのハンドル
//	//	  LPCTSTR lpText,     // メッセージボックス内のテキスト
//	//	  LPCTSTR lpCaption,  // メッセージボックスのタイトル
//	//	  UINT uType          // メッセージボックスのスタイル(形態を表す定数)
//	//	);
//	// -> どのボタンが押されたかを表す整数
//
//	// hWnd : 作成したいメッセージボックスのオーナーウィンドウのハンドルを指定。
//	// 	NULL を指定すると、オーナーウィンドウを持たないメッセージボックスが作成される。
//
//	// 違いは、パラメータとして受け取る文字列の型です。
//	// MessageBoxA() 関数の LPCSTR は const char * 型、
//	// MessageBoxW() 関数の LPCWSTR は const wchar_t * 型に相当します。
//	// MessageBox() 関数は、設定に応じてこれらのいずれかの関数にマッピングされます。
//	// このマッピングは、プロジェクトのプロパティから文字セットの設定を変更することで切り替えられます。
//
//	// LPCTSTR : Long Pointer Const T STRing
//	// 	Tはビルド環境によって変わるってこと
//	//		#ifdef UNICODE
//	//			typedef WCHAR    TCHAR;
//	//		#else
//	//			typedef char     TCHAR;
//	//		#endif
//	// 	何の略かは誰も知らないらしい(Typed,Text等の説を確認)
//
//	// TEXT()のことはあとでちゃんとわかろう
//	// マルチバイト文字、ワイド文字
//
//	// MB_OK : メッセージボックスに［OK］プッシュボタンだけを表示
//	// UINT : Win32 では 32ビット符合なし整数
//	//	Win16(Windows Versions 3.0 と 3.1) では16ビット符号なし整数だった
//
//	if(modoriti == IDYES){
//		MessageBox(NULL, TEXT("You are nice!"), TEXT("メッセージボックス"), MB_OK);
//	} else {
//		MessageBox(NULL, TEXT("Be Killed!!!!"), TEXT("メッセージボックス"), MB_OK);
//	}
//
//	return 0;
//}
