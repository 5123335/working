///*
// * p16_01_Light.cpp
// *
// *  Created on: 2013/07/22
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//const GLfloat lightPos[] = { 0.4 , -0.1 , -2 , 1 };
////const GLfloat lightPos[] = { 0 , 0 , -5 , 1};
//const GLfloat lightCol[] = { 1 , 0 , 0 , 1};
//
//void disp( void ) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glBegin(GL_POLYGON);
//	{
//		// �����瓖�����Ă�����Ȃ�
////		glNormal3f(0 , 0 , 1);
////		glVertex3f(0 , -0.9 , -2);
////		glVertex3f(3 , -0.9 , -7);
////		glVertex3f(0 , 0.9 , -2);
////		glNormal3f(-3 , 0 , -2);
////		glVertex3f(0 , -0.9 , -2);
////		glVertex3f(-3 , -0.9 , -7);
////		glVertex3f(0 , 0.9 , -2);
//	}
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	{
//		glNormal3f(0 , -1 , 0);
//		glVertex3f(-1 , 1 , -3);
//		glVertex3f(1 , 1 , -3);
//		glVertex3f(0 , 1, -9);
//	}
//	glEnd();
//	glBegin(GL_POLYGON);
//	{
//		glNormal3f(0 , 1 , 0);
//		glVertex3f(-1 , -1 , -3);
//		glVertex3f(1 , -1 , -3);
//		glVertex3f(0 , -1, -9);
//	}
//	glEnd();
//	glBegin(GL_POLYGON);
//	{
//		glNormal3f(1 , 0 , 0);
//		glVertex3f(-1 , 1 , -3);
//		glVertex3f(-1 , -1 , -3);
//		glVertex3f(-1 , 0, -9);
//	}
//	glEnd();
//	glBegin(GL_POLYGON);
//	{
//		glNormal3f(-1 , 0 , 0);
//		glVertex3f(1 , 1 , -3);
//		glVertex3f(1 , -1 , -3);
//		glVertex3f(1 , 0, -9);
//	}
//	glEnd();
//
//	glutSwapBuffers();
//}
//
//int main(int argc , char ** argv) {
//	glutInit(&argc , argv);
//	glutInitWindowPosition(100 , 50);
//	glutInitWindowSize(400 , 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//	glutCreateWindow("light");
//	glutDisplayFunc(disp);
//
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
//	glFrustum(-1 , 1 , -1 , 1 , 2 , 10);  // -10 <= z <= -2
//
//	glLightfv(GL_LIGHT0 , GL_POSITION , lightPos);  // �Ɩ��̈ʒu���w��
//	glLightfv(GL_LIGHT0 , GL_DIFFUSE , lightCol);  // �g�U�����w��
//
//	glEnable(GL_LIGHTING);  // �������f����L���ɂ���
//	glEnable(GL_LIGHT0);    // ����0��L���ɂ���
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_NORMALIZE);
//
//	glutMainLoop();
//	return 0;
//}
//
//
////void glLightfv(
////	GLenum light ,  // �ݒ肷��Ώۂ̏Ɩ�(GL_LIGHT0, GL_LIGHT1, ..)
////	GLenum pname , const GLfloat *params
////);
////// �����̍ő吔��GL_MAX_LIGHTS�Ŏ擾(8�ȏ��ۏ�)