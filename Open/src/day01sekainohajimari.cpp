///*
// * sekainohajimari.cpp
// *
// *  Created on: 2013/07/16
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <tchar.h>
//#include <stdio.h>
//#include <GL/glut.h>
//#include <GL/gl.h>
//
//int WindowPositionX = 100;  //��������E�B���h�E�ʒu��X���W
//int WindowPositionY = 100;  //��������E�B���h�E�ʒu��Y���W
//int WindowWidth = 512;    //��������E�B���h�E�̕�
//int WindowHeight = 512;    //��������E�B���h�E�̍���
//TCHAR WindowTitle[] = _T("���E�̎n�܂�");  //�E�B���h�E�̃^�C�g��
//
////----------------------------------------------------
//// �֐��v���g�^�C�v�i��ɌĂяo���֐����ƈ����̐錾�j
////----------------------------------------------------
//void Initialize(void);
//void Display(void);
////----------------------------------------------------
//// ���C���֐�
////----------------------------------------------------
//int main(int argc, char *argv[]){
//  glutInit(&argc, argv);          // ���̏�����
//  glutInitWindowPosition(WindowPositionX, WindowPositionY);   // �E�B���h�E�̈ʒu�̎w��
//  glutInitWindowSize(WindowWidth, WindowHeight);              // �E�B���h�E�T�C�Y�̎w��
//  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);  // �f�B�X�v���C���[�h�̎w��
//  glutCreateWindow(WindowTitle);  // �E�B���h�E�̍쐬
//  glutDisplayFunc(Display);       // �`�掞�ɌĂяo�����֐����w�肷��i�֐����FDisplay�j
//  Initialize();                   // �����ݒ�̊֐����Ăяo��
//  glutMainLoop();                 // glut�̃C�x���g�������[�v�ɓ���B
//  return 0;
//}
////----------------------------------------------------
//// �����ݒ�̊֐�
////----------------------------------------------------
//void Initialize(void){
//  glClearColor(1.0, 1.0, 0.0, 1.0);  // �w�i�F(�����ƍ��ɂȂ�)(�o�b�t�@������������J���[���)
//  // glClearColor(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha);  // alpha : �����x
//  glEnable(GL_DEPTH_TEST);  // �f�v�X�o�b�t�@���g�p�FglutInitDisplayMode() �� GLUT_DEPTH ���w�肷��
//}
////----------------------------------------------------
//// �`��̊֐�
////----------------------------------------------------
////static
//void Display(void) {
////	printf("aaa");
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�o�b�t�@�̏���
//  // �������Ɛ^�����ɂȂ�(�E�B���h�E�T�C�Y��ς���Ɨ̈�O����)
//  glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)�Ń_�u���o�b�t�@�����O�𗘗p��
//  // �������Ɛ^�����ɂȂ�(�E�B���h�E�T�C�Y��ς���Ɨ̈�O����)
//}
//
//
//// TODO: �f�v�X�o�b�t�@ �Ƃ�
////�o�b�t�@ :
////OpenGL �ł́A���ׂẴs�N�Z���̏���ۑ�����̈���o�b�t�@�ƌĂ�
////�s�N�Z���Ɋւ���1�r�b�g�̏���ۑ�����o�b�t�@���r�b�g�v���[���ƌĂт܂�(?)
////�r�b�g�v���[���ɂ́ARGBA�@���A�J���[�Q�ƃe�[�u�����Q�Ƃ���l���ۑ�����܂�
////�����̏ꍇ�́A���@���F�ɃA���t�@�l�������� RGBA ���p�����܂�
//// TODO: �_�u���o�b�t�@�����O �Ƃ�