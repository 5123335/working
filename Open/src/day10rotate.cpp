///*
// * day10rotate.cpp
// *
// *  Created on: 2013/07/17
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <math.h>
//#include <fstream>
//#include <sstream>
//#include <iostream>
//#include <direct.h>
//#include <time.h>
//#include <GL/glut.h>
//#include <GL/gl_screenshot.h>
//using namespace std;
//
//
//int WindowPositionX = 100;  //��������E�B���h�E�ʒu��X���W
//int WindowPositionY = 100;  //��������E�B���h�E�ʒu��Y���W
//int WindowWidth = 512;    //��������E�B���h�E�̕�
//int WindowHeight = 512;    //��������E�B���h�E�̍���
//char WindowTitle[] = "���E�̎n�܂�";  //�E�B���h�E�̃^�C�g��
//
//#define _BITMAP 1
//int tn = 0;
//double dt = 0.1;
//gl_screenshot gs; //bmp�t�@�C���̏o��
//
//
//#define SCALE (2.0 * 3.14159265358979323846)  // �}�E�X�̑��Έʒu����]�p�̊��Z�W��
//int cx, cy;                // �h���b�O�J�n�ʒu
//double sx, sy;              // �}�E�X�̐�Έʒu���E�B���h�E���ł̑��Έʒu�̊��Z�W��
//double cq[4] = { 1.0, 0.0, 0.0, 0.0 };  // ��]�̏����l (�N�H�[�^�j�I��)
//double tq[4];              // �h���b�O���̉�] (�N�H�[�^�j�I��)
//double rt[16];              // ��]�̕ϊ��s��
//
//unsigned int listNumber;
//float camera_z_pos =50.0;
//
////----------------------------------------------------
//// �����̂̒�`
////----------------------------------------------------
//GLdouble vertex[][3] = {
//  { 0.0, 0.0, 0.0 },
//  { 2.0, 0.0, 0.0 },
//  { 2.0, 2.0, 0.0 },
//  { 0.0, 2.0, 0.0 },
//  { 0.0, 0.0, 30.0 },
//  { 2.0, 0.0, 30.0 },
//  { 2.0, 2.0, 30.0 },
//  { 0.0, 2.0, 30.0 }
//};
//int face[][4] = {//�ʂ̒�`
//  { 0, 1, 2, 3 },
//  { 1, 5, 6, 2 },
//  { 5, 4, 7, 6 },
//  { 4, 0, 3, 7 },
//  { 4, 5, 1, 0 },
//  { 3, 2, 6, 7 }
//};
//GLdouble normal[][3] = {//�ʂ̖@���x�N�g��
//  { 0.0, 0.0,-1.0 },
//  { 1.0, 0.0, 0.0 },
//  { 0.0, 0.0, 1.0 },
//  {-1.0, 0.0, 0.0 },
//  { 0.0,-1.0, 0.0 },
//  { 0.0, 1.0, 0.0 }
//};
////----------------------------------------------------
//// ���������̒�`
////----------------------------------------------------
//struct MaterialStruct {
//  GLfloat ambient[4];
//  GLfloat diffuse[4];
//  GLfloat specular[4];
//  GLfloat shininess;
//};
////jade(�Ő�)
//MaterialStruct ms_jade = {
//  {0.135,     0.2225,   0.1575,   1.0},
//  {0.54,      0.89,     0.63,     1.0},
//  {0.316228,  0.316228, 0.316228, 1.0},
//  12.8};
////ruby(���r�[)
//MaterialStruct ms_ruby  = {
//  {0.1745,   0.01175,  0.01175,   1.0},
//  {0.61424,  0.04136,  0.04136,   1.0},
//  {0.727811, 0.626959, 0.626959,  1.0},
//  76.8};
////----------------------------------------------------
//// �F�̒�`�̒�`
////----------------------------------------------------
//GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 }; //�ԐF
//GLfloat green[] = { 0.2, 0.8, 0.2, 1.0 };//�ΐF
//GLfloat blue[] = { 0.2, 0.2, 0.8, 1.0 };//�F
//GLfloat yellow[] = { 0.8, 0.8, 0.2, 1.0 };//���F
//GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };//���F
//GLfloat shininess = 30.0;//����̋���
////-----------------------------------------
//
////----------------------------------------------------
//// �֐��v���g�^�C�v�i��ɌĂяo���֐����ƈ����̐錾�j
////----------------------------------------------------
//void Initialize(void);
//void Idle(void);
//void Display(void);
//void Ground(void);  //��n�̕`��
//
//static void qmul(double r[], const double p[], const double q[]);
//static void qrot(double r[], double q[]);
//void mouse_motion(int x, int y);
//void mouse_on(int button, int state, int x, int y);
//void mouse_wheel(float z);
////----------------------------------------------------
//// ���C���֐�
////----------------------------------------------------
//int main(int argc, char *argv[]){
//#if _BITMAP
//  _mkdir("bitmap"); //bmp�t�@�C���ۑ��p�̃t�H���_�̍쐬
//#endif
//
//  glutInit(&argc, argv);//���̏�����
//  glutInitWindowPosition(WindowPositionX, WindowPositionY);//�E�B���h�E�̈ʒu�̎w��
//  glutInitWindowSize(WindowWidth, WindowHeight); //�E�B���h�E�T�C�Y�̎w��
//  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);//�f�B�X�v���C���[�h�̎w��
//  glutCreateWindow(WindowTitle);  //�E�B���h�E�̍쐬
//  glutDisplayFunc(Display); //�`�掞�ɌĂяo�����֐����w�肷��i�֐����FDisplay�j
//  glutMouseFunc(mouse_on);      //�}�E�X�N���b�N���ɌĂяo�����֐� // TODO:
//  glutMotionFunc(mouse_motion);      //�}�E�X�h���b�O�������ɌĂяo�����֐� // TODO:
//
//  glutIdleFunc(Idle);       //�v���O�����A�C�h����Ԏ��ɌĂяo�����֐� // TODO:
//  Initialize(); //�����ݒ�̊֐����Ăяo��
//  glutMainLoop();
//  return 0;
//}
////----------------------------------------------------
//// �����ݒ�̊֐�
////----------------------------------------------------
//void Initialize(void){
//  glClearColor(1.0, 1.0, 1.0, 1.0); //�w�i�F
//  glEnable(GL_DEPTH_TEST);//�f�v�X�o�b�t�@���g�p�FglutInitDisplayMode() �� GLUT_DEPTH ���w�肷��
//
//  // �f�B�X�v���C���X�g���쐬
//  listNumber = glGenLists(1);
//  glNewList( listNumber, GL_COMPILE );
//
//
//
//  glEndList();
////--------------------------------------
//  // �}�E�X�|�C���^�ʒu�̃E�B���h�E���̑��ΓI�ʒu�ւ̊��Z�p
//  sx = 1.0 / (double)512;
//  sy = 1.0 / (double)512;
//
//  // ��]�s��̏�����
//  qrot(rt, cq);
////--------------------------------------
//
//  //�����ϊ��s��̐ݒ�------------------------------
//  glMatrixMode(GL_PROJECTION);//�s�񃂁[�h�̐ݒ�iGL_PROJECTION : �����ϊ��s��̐ݒ�AGL_MODELVIEW�F���f���r���[�ϊ��s��j
//  glLoadIdentity();//�s��̏�����
//  gluPerspective(30.0, (double)WindowWidth/(double)WindowHeight, 0.1, 1000.0); //�������e�@�̎��̐�gluPerspactive(th, w/h, near, far);
//}
////----------------------------------------------------
//// �A�C�h�����ɌĂяo�����֐�
////----------------------------------------------------
//void Idle(){
//  glutPostRedisplay(); //glutDisplayFunc()���P����s����
//}
//
////----------------------------------------------------
//// �`��̊֐�
////----------------------------------------------------
//void Display(void) {
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�o�b�t�@�̏���
//
//  //���f���r���[�ϊ��s��̐ݒ�--------------------------
//  glMatrixMode(GL_MODELVIEW);//�s�񃂁[�h�̐ݒ�iGL_PROJECTION : �����ϊ��s��̐ݒ�AGL_MODELVIEW�F���f���r���[�ϊ��s��j
//  glLoadIdentity();//�s��̏�����
//  glViewport(0, 0, WindowWidth, WindowHeight);
//  //----------------------------------------------
//
//  glPushMatrix();
//
//  //�����̐ݒ�--------------------------------------
//  GLfloat light_position0[] = { 0.0, 50.0, 50.0, 1.0 }; //����0�̍��W
//  glLightfv(GL_LIGHT0, GL_POSITION, light_position0); //����0��
//  //���_�̐ݒ�------------------------------
//  gluLookAt(
//       0.0, -100.0, 50.0, // ���_�̈ʒux,y,z;
//       0.0, 100.0, 0.0,   // ���E�̒��S�ʒu�̎Q�Ɠ_���Wx,y,z
//       0.0, 0.0, 1.0);  //���E�̏�����̃x�N�g��x,y,z
//  //----------------------------------------
//
//  //�A�eON-----------------------------
//  glEnable(GL_LIGHTING);
//  glEnable(GL_LIGHT0);//����0�𗘗p
//  //-----------------------------------
//
//////��]///////////////////////////////////////////////
//  glMultMatrixd(rt);
/////////////////////////////////////////////////////////
//
//  //��
//  glPushMatrix();
//  glMaterialfv(GL_FRONT, GL_AMBIENT, ms_ruby.ambient);
//  glMaterialfv(GL_FRONT, GL_DIFFUSE, ms_ruby.diffuse);
//  glMaterialfv(GL_FRONT, GL_SPECULAR, ms_ruby.specular);
//  glMaterialfv(GL_FRONT, GL_SHININESS, &ms_ruby.shininess);
//  glTranslated(0.0, 10.0, 20.0);//���s�ړ��l�̐ݒ�
//  glutSolidSphere(4.0, 20, 20);//�����F(���a, Z���܂��̕�����, Z���ɉ�����������)
//  glPopMatrix();
//
//  //������
//  glPushMatrix();
//  glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
//  glTranslated(-20.0, 0.0, 20.0);//���s�ړ��l�̐ݒ�
//  glutSolidCube(10.0);//�����F(��ӂ̒���)
//  glPopMatrix();
//
//  //�~��
//  glPushMatrix();
//  glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
//  glTranslated(20.0, 100.0, 0.0);//���s�ړ��l�̐ݒ�
//  glutSolidCone(5.0,10.0,20,20);//�����F(���a, ����, Z���܂��̕�����, Z���ɉ�����������)
//  glPopMatrix();
//
//  //������
//  glPushMatrix();
//  glMaterialfv(GL_FRONT, GL_AMBIENT, ms_jade.ambient);
//  glMaterialfv(GL_FRONT, GL_DIFFUSE, ms_jade.diffuse);
//  glMaterialfv(GL_FRONT, GL_SPECULAR, ms_jade.specular);
//  glMaterialfv(GL_FRONT, GL_SHININESS, &ms_jade.shininess);
//  glTranslated(30.0, 50.0, 0.0);//���s�ړ��l�̐ݒ�
//  glBegin(GL_QUADS);
//  for (int j = 0; j < 6; ++j) {
//    glNormal3dv(normal[j]); //�@���x�N�g���̎w��
//    for (int i = 0; i < 4; ++i) {
//      glVertex3dv(vertex[face[j][i]]);
//    }
//  }
//  glEnd();
//
//
//  glPopMatrix();
//
//  //�A�eOFF-----------------------------
//  glDisable(GL_LIGHTING);
//  //-----------------------------------
//
//  Ground();
//  glPopMatrix();
//
//#if _BITMAP
//  ostringstream fname;
//  int tt = tn +10000;
//  fname  << "bitmap/" << tt << ".bmp" ;//�o�̓t�@�C����
//  string name = fname.str();
//  gs.screenshot(name.c_str(), 24);
//#endif
//
//  glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)�Ń_�u���o�b�t�@�����O�𗘗p��
//  tn++;
//
//}
////----------------------------------------------------
//// �}�E�X�h���b�O��
////----------------------------------------------------
//void mouse_motion(int x, int y){
//  double dx, dy, a;
//
//  // �}�E�X�|�C���^�̈ʒu�̃h���b�O�J�n�ʒu����̕ψ�
//  dx = (x - cx) * sx;
//  dy = (y - cy) * sy;
//
//  // �}�E�X�|�C���^�̈ʒu�̃h���b�O�J�n�ʒu����̋���
//  a = sqrt(dx * dx + dy * dy);
//
//  if( a != 0.0 )
//  {
//    // �}�E�X�̃h���b�O�ɔ�����]�̃N�H�[�^�j�I�� dq �����߂�
//    double ar = a * SCALE * 0.5;
//    double as = sin(ar) / a;
//    double dq[4] = { cos(ar), dy * as, dx * as, 0.0 };
//
//    // ��]�̏����l cq �� dq ���|���ĉ�]������
//    qmul(tq, dq, cq);
//
//    // �N�H�[�^�j�I�������]�̕ϊ��s������߂�
//    qrot(rt, tq);
//  }
//}
////----------------------------------------------------
//// �}�E�X�N���b�N��
////----------------------------------------------------
//void mouse_on(int button, int state, int x, int y)
//{
//  switch (button) {
//  case 0:
//    switch (state) {
//    case 0:
//      // �h���b�O�J�n�_���L�^
//      cx = x;
//      cy = y;
//      break;
//    case 1:
//      // ��]�̕ۑ�
//      cq[0] = tq[0];
//      cq[1] = tq[1];
//      cq[2] = tq[2];
//      cq[3] = tq[3];
//      break;
//    default:
//      break;
//    }
//    break;
//  default:
//    break;
//  }
////  cout << x << " " << y<<endl;
//}
////----------------------------------------------------
//// ��n�̕`��
////----------------------------------------------------
//void Ground(void) {
//    double ground_max_x = 300.0;
//    double ground_max_y = 300.0;
//    glColor3d(0.8, 0.8, 0.8);  // ��n�̐F
//    glBegin(GL_LINES);
//    for(double ly = -ground_max_y ;ly <= ground_max_y; ly+=10.0){
//      glVertex3d(-ground_max_x, ly,0);
//      glVertex3d(ground_max_x, ly,0);
//    }
//    for(double lx = -ground_max_x ;lx <= ground_max_x; lx+=10.0){
//      glVertex3d(lx, ground_max_y,0);
//      glVertex3d(lx, -ground_max_y,0);
//    }
//    glEnd();
//}
//
////////////////////////////////////////////////////////////////////////////
//// �}�E�X�h���b�O�ɂ���]
////////////////////////////////////////////////////////////////////////////
//// �N�H�[�^�j�I���̐� r <- p x q
//static void qmul(double r[], const double p[], const double q[])
//{
//  r[0] = p[0] * q[0] - p[1] * q[1] - p[2] * q[2] - p[3] * q[3];
//  r[1] = p[0] * q[1] + p[1] * q[0] + p[2] * q[3] - p[3] * q[2];
//  r[2] = p[0] * q[2] - p[1] * q[3] + p[2] * q[0] + p[3] * q[1];
//  r[3] = p[0] * q[3] + p[1] * q[2] - p[2] * q[1] + p[3] * q[0];
//}
//
//// ��]�̕ϊ��s�� r <- �N�H�[�^�j�I�� q
//static void qrot(double r[], double q[]){
//  double x2 = q[1] * q[1] * 2.0;
//  double y2 = q[2] * q[2] * 2.0;
//  double z2 = q[3] * q[3] * 2.0;
//  double xy = q[1] * q[2] * 2.0;
//  double yz = q[2] * q[3] * 2.0;
//  double zx = q[3] * q[1] * 2.0;
//  double xw = q[1] * q[0] * 2.0;
//  double yw = q[2] * q[0] * 2.0;
//  double zw = q[3] * q[0] * 2.0;
//
//  r[ 0] = 1.0 - y2 - z2;
//  r[ 1] = xy + zw;
//  r[ 2] = zx - yw;
//  r[ 4] = xy - zw;
//  r[ 5] = 1.0 - z2 - x2;
//  r[ 6] = yz + xw;
//  r[ 8] = zx + yw;
//  r[ 9] = yz - xw;
//  r[10] = 1.0 - x2 - y2;
//  r[ 3] = r[ 7] = r[11] = r[12] = r[13] = r[14] = 0.0;
//  r[15] = 1.0;
//}
//
//void mouse_wheel(float z){
//  camera_z_pos += z;
//
//  if( camera_z_pos < 0.0f )
//  {
//    camera_z_pos = 0.0f;
//  }
//}
