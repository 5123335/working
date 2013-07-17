/*
 * p58textanimation01.cpp
 *
 *  Created on: 2013/07/17
 *      Author: yumikoy
 */

#define ID_MYTIMER 100   // ms/frame
#define ID0 10  // 1frame�œ�����

#include <windows.h>
#include <stdio.h>
#if defined(__MINGW32__)
#   undef  MAKEINTRESOURCE
#   define MAKEINTRESOURCE(i) ((LPSTR)((ULONG_PTR)(i)))
#endif  /* defined(__MINGW32__) */

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM InitApp(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
HFONT MyCreateFont(LPCTSTR, int);   // �J�X�^���t�H���g�̍쐬(�t�F�C�X��, �T�C�Y)

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

// �E�B���h�E�N���X�̓o�^
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

// �E�B���h�E�̐���
BOOL InitInstance(HINSTANCE hInst, int nCmdShow) {
	HWND hWnd;

	hWnd = CreateWindow(szClassName, TEXT("�L�ł��킩��A�j���[�V����"), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, 288, 105, NULL, NULL, hInst, NULL);

	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

// �E�B���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	int id;
	static int x, clw, txtw; // ���Ԃ��Ƃ̍��W, �N���C�A���g�̈�̕�, ������������̕�
	HDC hdc;
	PAINTSTRUCT ps;
	static HFONT hFont;
	LPCTSTR lpszTxt = TEXT("�˂�");
	SIZE sz;   // SIZE�\����(GetTextExtentPoint32�Ŏg�p)
	RECT rc;
	static int dir = 0;  // 0:�E��  1:����

	switch (msg) {
	case WM_CREATE:  // ���������� (WM_CREATE : CreateWindow���Ăяo���ꂽ�Ƃ��ɑ�����)
		hdc = GetDC(hWnd);
		hFont = MyCreateFont(TEXT("MS �S�V�b�N"), 50);    // �t�F�C�X��"MS �S�V�b�N", ����50�̃t�H���g���쐬
		SelectObject(hdc, hFont);   // ������̕��𒲂ׂ邽�߂Ƀt�H���g����Uselect����K�v������
		GetTextExtentPoint32(hdc, lpszTxt, (int) lstrlen(lpszTxt), &sz);
		txtw = sz.cx;  // ������̕�(WndProc���甲���Ă��ێ������悤static��txtw�Ɋi�[)
		printf("%d,%d", txtw, (int)sz.cy);   // -> 102,50 (SelectObject���Ȃ���32,18)
		SetTimer(hWnd, ID_MYTIMER, 30, NULL);  // �^�C�}�̃Z�b�g
		ReleaseDC(hWnd, hdc);   // �f�o�C�X�R���e�L�X�g�n���h�����������
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SelectObject(hdc, hFont);   // hdc�̃f�o�C�X�R���e�L�X�g��hFont���I�������
		TextOut(hdc, x, 10, lpszTxt, (int) strlen(lpszTxt));   // x������
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		if (wp != ID_MYTIMER)   // TIMER��ID�������̎w�肵�����̂��m�F����
			return DefWindowProc(hWnd, msg, wp, lp); // ����Ă�����DefWindowProc�ɏ�����C����
		GetClientRect(hWnd, &rc);   // �N���C�A���g�̈�̋�`���擾
		clw = rc.right;
		// �\������ʒu�̕ύX
		if (dir == 0) {   // x��ς��Ă�
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
		// �����̈�𔭐�����WM_PAINT�𔭍s������
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_CLOSE:
		id = MessageBox(hWnd, TEXT("�I�����Ă���낵���ł���"), TEXT("�I���m�F"), MB_YESNO);
		if (id == IDYES)
			DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		// �^�C�}��GDI�I�u�W�F�N�g�̌�n��
		KillTimer(hWnd, ID_MYTIMER);   // Timer��j��
		DeleteObject(hFont);   // create����GDI�I�u�W�F�N�g(����̓t�H���g)��j��
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hWnd, msg, wp, lp));
	}
	return 0;
}

HFONT MyCreateFont(LPCTSTR face, int h) {  // face:�t�H���g�t�F�C�X��, h:�t�H���g�̍���(�_���P��)
	HFONT hFont;   // �t�H���g�n���h��(���̂�HGDIOBJ)
	// �_���t�H���g�̍쐬
	hFont = CreateFont(h, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, FIXED_PITCH | FF_MODERN, face);
	return hFont;
}

	// SetTimer�֐� : ����I��WM_TIMER���b�Z�[�W�𔭍s����
	//	UINT_PTR SetTimer(
	//		HWND hWnd,          // �֘A�t����E�B���h�E�̃n���h��
	//		UINT_PTR nIDEvent,  // �^�C�}��ID(������define)
	//		UINT uElapse,       // �^�C���A�E�g�l(WM_TIMER�𑗂�Ԋu)(�~���b)
	//		TIMERPROC lpTimerFunc // �^�C�}�̃v���V�[�W��(NULL���w�肷���hWnd�̃v���V�[�W����WM_TIMER��������)
	//	);

	// InvalidateRect�֐� : �����̈�(��`���邢�̓N���C�A���g�̈�S��)�𔭐�������
	//	BOOL InvalidateRect(
	//		HWND hWnd,          // �E�B���h�E�n���h��
	//		CONST RECT* lpRect, // RECT�\���̂ւ̃|�C���^(NULL���w�肷��ƃN���C�A���g�̈�S�̂��Ώ�)
	//		BOOL bErase         // �w�i���������邩�ǂ���(FALSE�ɂ���Ǝc�����o��)
	//	);

	// GetTextExtentPoint32�֐� : ������̕��ƍ������v�Z����B
	//	BOOL GetTextExtentPoint32(
	//		HDC hdc,          // �f�o�C�X�R���e�L�X�g�n���h��
	//		LPCTSTR lpString, // ���ׂ镶����
	//		int cbString,     // ������
	//		LPSIZE lpSize     // ���ʂ��󂯎��SIZE�\���̂ւ̃|�C���^
	//	);
	//�@GetTextExtentPoint32(hdc, lpszTxt, (int)strlen(lpszTxt), &sz);

	// SIZE�\���� : ��`�̕��ƍ������`����
	//	typedef struct tagSIZE {
	//		LONG cx;    // ��
	//		LONG cy;    // ����
	//	} SIZE,SIZEL,*PSIZE,*LPSIZE,*PSIZEL,*LPSIZEL;

	// GetClientRect�֐� : �N���C�A���g�̈�̋�`���擾
	//	BOOL GetClientRect(
	//		HWND hWnd,     // ���ׂ����E�B���h�E�̃n���h�����w��
	//		LPRECT lpRect  // �N���C�A���g�̈�̍��W����������
	//	);

	// CreateFont�֐� : �_���t�H���g�̍쐬
	//	HFONT CreateFont(
	//		int nHeight,         // �t�H���g�̘_���P�ʂ̍���
	//		int nWidth,          // ���ς̕�(�_���P��)
	//		int nEscapement,     // ��������̕�����X���̊p�x
	//		int nOrientation,    // �e������X���̊p�x
	//		int fnWeight,        // �t�H���g�̑���(0�`900)
	//		DWORD fdwItalic,     // TRUE���ƃC�^���b�N��
	//		DWORD fdwUnderline,  // TRUE���Ɖ����t��
	//		DWORD fdwStrikeOut,  // TRUE���Ƒł��������t��
	//		DWORD fdwCharSet,    // �t�H���g�����Z�b�g
	//		DWORD fdwOutputPrecision,  // �o�͐��x
	//		DWORD fdwClipPrecision,    // �N���b�s���O���x
	//		DWORD fdwQuality,    // �o�͕i��
	//		DWORD fdwPitchAndFamily,   // �s�b�`�ƃt�@�~��
	//		LPCTSTR lpszFace     // �t�H���g�t�F�C�X��
	//	);
	//�@hFont = CreateFont(h, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
	//		SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
	//		PROOF_QUALITY, FIXED_PITCH | FF_MODERN, face);

