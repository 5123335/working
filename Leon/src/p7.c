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
//	// WS_EX_TOOLWINDOW : �^�X�N�o�[�ɕ\������Ȃ��A�^�C�g���o�[���������E�B���h�E
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
//	//	  DWORD dwExStyle,      // �g���E�B���h�E�X�^�C��
//	//	  LPCTSTR lpClassName,  // �o�^����Ă���N���X��
//	//	  LPCTSTR lpWindowName, // �E�B���h�E��
//	//	  DWORD dwStyle,        // �E�B���h�E�X�^�C��
//	//	  int x,                // �E�B���h�E�̉������̈ʒu
//	//	  int y,                // �E�B���h�E�̏c�����̈ʒu
//	//	  int nWidth,           // �E�B���h�E�̕�
//	//	  int nHeight,          // �E�B���h�E�̍���
//	//	  HWND hWndParent,      // �e�E�B���h�E�܂��̓I�[�i�[�E�B���h�E�̃n���h��
//	//	  HMENU hMenu,          // ���j���[�n���h���܂��͎q���ʎq
//	//	  HINSTANCE hInstance,  // �A�v���P�[�V�����C���X�^���X�̃n���h��
//	//	  LPVOID lpParam        // �E�B���h�E�쐬�f�[�^
//	//	);
//	//	�֐�����������ƁA�쐬���ꂽ�E�B���h�E�̃n���h�����Ԃ�܂��B
//	//	�֐������s����ƁANULL ���Ԃ�܂��B�g���G���[�����擾����ɂ́A �֐����g���܂��B
//
//
//	//	BOOL ShowWindow(
//	//	  HWND hWnd,     // �E�B���h�E�̃n���h��
//	//	  int nCmdShow   // �\�����
//	//	);
//	//	�E�B���h�E���ȑO����\������Ă����ꍇ�́A0 �ȊO�̒l���Ԃ�܂��B
//	//	�E�B���h�E���ȑO�͔�\���������ꍇ�́A0 ���Ԃ�܂��B
//
//
//
