/*
 * day0101daichisouzou.cpp
 *
 *  Created on: 2013/07/18
 *      Author: yumikoy
 */

#include <windows.h>
#include <tchar.h>
#include <GL/glut.h>
#include <GL/gl.h>

//----------------------------------------------------
// �ϐ��̐錾
//----------------------------------------------------
int WindowPositionX = 200;  //��������E�B���h�E�ʒu��X���W
int WindowPositionY = 200;  //��������E�B���h�E�ʒu��Y���W
int WindowWidth = 512;      //��������E�B���h�E�̕�
int WindowHeight = 512;     //��������E�B���h�E�̍���
const TCHAR* WindowTitle = _T("���E�̎n�܂�");  //�E�B���h�E�̃^�C�g��

//----------------------------------------------------
// �֐��v���g�^�C�v�i��ɌĂяo���֐����ƈ����̐錾�j
//----------------------------------------------------
void Initialize(void);   //�����ݒ莞�ɌĂяo���֐�
void Idle(void);         //�A�C�h�����ɌĂяo���֐� ��������
void Display(void);      //��ʕ`�掞�ɌĂяo���֐�
void Ground(void);       //��n�̕`��p�̊֐�
//----------------------------------------------------
// ���C���֐�
//----------------------------------------------------
int main(int argc, char *argv[]){
  glutInit(&argc, argv);                                     //���̏�����
  glutInitWindowPosition(WindowPositionX, WindowPositionY);  //�E�B���h�E�̈ʒu�̎w��
  glutInitWindowSize(WindowWidth, WindowHeight);             //�E�B���h�E�T�C�Y�̎w��
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //�f�B�X�v���C���[�h�̎w��
  glutCreateWindow(WindowTitle);                             //�E�B���h�E�̍쐬
  glutIdleFunc(Idle);                                        //�v���O�����A�C�h����Ԏ��ɌĂяo�����֐� ��������
  //glutIdleFunc �֐��́A�v���O�����S�̂��u�Ђ܁v�ɂȂ������ɁA�w�肵���֐��i��ł́uIdle�v�֐��j���Ăяo���֐��ł��B�A�j���[�V���������s���邽�߂ɕK�{�̊֐��ł��B��q����uIdle�v�֐� �̐������ɏڂ����G��܂��B
  glutDisplayFunc(Display);                                  //�`�掞�ɌĂяo�����֐����w�肷��i�֐����FDisplay�j
  Initialize();                                              //�����ݒ�̊֐����Ăяo��
  glutMainLoop();
  return 0;
}
//----------------------------------------------------
// �����ݒ�̊֐�
//----------------------------------------------------
void Initialize(void){
  glClearColor(1.0, 1.0, 1.0, 0.9); //�w�i�F

  glEnable(GL_DEPTH_TEST);//�f�v�X�o�b�t�@���g�p�FglutInitDisplayMode() �� GLUT_DEPTH ���w�肷��

  //�����ϊ��s��̐ݒ�------------------------------
  glMatrixMode(GL_PROJECTION);//�s�񃂁[�h�̐ݒ�iGL_PROJECTION : �����ϊ��s��̐ݒ�AGL_MODELVIEW�F���f���r���[�ϊ��s��j
  glLoadIdentity();//�s��̏�����
  gluPerspective(30.0, (double)WindowWidth/(double)WindowHeight, 0.1, 1000.0); //�������e�@�̎��̐�gluPerspactive(th, w/h, near, far);
  //------------------------------------------------
  gluLookAt(
       0.0, -200.0, 50.0, // ���_�̈ʒux,y,z;
       0.0, 0.0, 20.0,   // ���E�̒��S�ʒu�̎Q�Ɠ_���Wx,y,z
       0.0, 0.0, 1.0);  //���E�̏�����̃x�N�g��x,y,z
}
//----------------------------------------------------
// �A�C�h�����ɌĂяo�����֐�
//----------------------------------------------------
void Idle(){
  glutPostRedisplay(); //glutDisplayFunc()���P����s����
}
//----------------------------------------------------
// �`��̊֐�
//----------------------------------------------------
void Display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�o�b�t�@�̏���
  //���f���r���[�ϊ��s��̐ݒ�--------------------------
  glMatrixMode(GL_MODELVIEW);//�s�񃂁[�h�̐ݒ�iGL_PROJECTION : �����ϊ��s��̐ݒ�AGL_MODELVIEW�F���f���r���[�ϊ��s��j
  glLoadIdentity();//�s��̏�����
  glViewport(0, 0, WindowWidth, WindowHeight);
  //----------------------------------------------

  Ground();

  glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)�Ń_�u���o�b�t�@�����O�𗘗p��
}
//----------------------------------------------------
// ��n�̕`��
//----------------------------------------------------
void Ground(void) {
    double ground_max_x = 300.0;
    double ground_max_y = 300.0;
    glColor3d(0.8, 0.8, 0.8);  // ��n�̐F
    glBegin(GL_LINES);

    for(double ly = -ground_max_y ;ly <= ground_max_y; ly+=20.0){
      glVertex3d(-ground_max_x, ly,0);
      glVertex3d(ground_max_x, ly,0);
    }
    for(double lx = -ground_max_x ;lx <= ground_max_x; lx+=20.0){
      glVertex3d(lx, ground_max_y,0);
      glVertex3d(lx, -ground_max_y,0);
    }
    glEnd();
}