///*
// * p10_02_PrintMousePosition.cpp
// *
// *  Created on: 2013/07/19
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <stdio.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
////#include <windows.h>
////#include <GL/gl.h>
////#include <GL/glut.h>
//
//void disp(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//}
//
////�{�^����(�ǂꂩ��ł�)������Ă����Ԃ̈ړ��� GLUT�ł�motion�ƌĂ�
//void motion(int x, int y) {
//	printf("X = %d : Y = %d\n", x, y);
//}
//
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutCreateWindow("drag");
//	glutDisplayFunc(disp);
//
//	glutMotionFunc(motion);
//
//	glutMainLoop();
//	return 0;
//}