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
//// �E�B���h�E�N���X�̓o�^
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
//// �E�B���h�E�̐���
//BOOL InitInstance(HINSTANCE hInst, int nCmdShow) {
//	HWND hWnd;
//		hWnd = CreateWindow(szClassName, TEXT("�L�ł��킩��e�L�X�g�\��"), WS_OVERLAPPEDWINDOW,
//				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//				NULL, NULL, hInst, NULL);
//
//	if(!hWnd)
//		return FALSE;
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);  // �Ȃ��Ă�����
//	return TRUE;
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
//{
//	int id, y = 0, i;
//	PAINTSTRUCT ps;  // PAINTSTRUCT�\���� : �`�����ێ�����B
//	HDC hdc;
//	TCHAR lpszStr[] = TEXT("�L�ł��킩��Q�[���v���O���~���O");
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
//		id = MessageBox(hWnd, TEXT("�I�����Ă���낵���ł���"), TEXT("�I���m�F"), MB_YESNO);
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
//	//  PAINTSTRUCT�\���� : �`�����ێ�����B���g��(���́H)�g��Ȃ�
//	//	typedef struct tagPAINTSTRUCT {
//	//		HDC	hdc;           // �f�o�C�X�R���e�L�X�g�n���h��
//	//		BOOL fErase;       // �����̈�̓h��Ԃ����s��ꂽ���ǂ���
//	//		RECT rcPaint;      // �����̈�
//	//		BOOL fRestore;     // �\��ς�
//	//		BOOL fIncUpdate;   // �\��ς�
//	//		BYTE rgbReserved[32];   // �\��ς�
//	//	} PAINTSTRUCT,*LPPAINTSTRUCT;
//
//	//	�f�o�C�X�R���e�L�X�g : �f�B�X�v���C��v�����^�Ȃǂ̏o�̓f�o�C�X�̏����܂ލ\���̂ŁA�V�X�e�����ۗL���Ă���B
//	//  �f�o�C�X�R���e�L�X�g�n���h�����擾����֐� :
//	//  HDC GetDC(HWND hWnd);
//	//  HDC BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint); // WM_PAINT���b�Z�[�W�̏����ł����g�p�ł��Ȃ��B
//
//	//  BeginPaint�ŊJ�n�����`�悪����������K��EndPaint�֐����Ăяo���K�v������B
//	//  EndPaint�֐� : �w�肳�ꂽ�E�B���h�E���̕`����I������B
//	//  BOOL EndPaint(HWND hWnd, CONST PAINTSTRUCT *lpPaint);
//
//	//  TextOut�֐� : �������`�悷��B
//	//	BOOL TextOut(
//	//		HDC hdc,            // �f�o�C�X�R���e�L�X�g�n���h��
//	//		int nXStart,        // x���W
//	//		int nYStart,        // y���W
//	//		LPCTSTR lpString,   // ������
//	//		int cbString        // ������
//	//	);
//
//
//