///*
// * p6-1.cpp
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
//int pointSize = 1;  // ������ς���Ɠ_�̑傫��(px)���ς��
//// �R�}���h���C�������ł��n���郈�c
//
//void disp(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glPointSize(pointSize++);  // �`��̂��тɑ傫���Ȃ�
//	glBegin(GL_POINTS);
//	glVertex2f(0, -0.9);
//	glVertex2f(-0.9, 0.9);
//	glVertex2f(0.9, 0.9);
//	glEnd();
//
//	glutSwapBuffers();
//}
//
//int main(int argc, char ** argv) {
//	if (argc >= 2)
//		sscanf(argv[1], "%d", &pointSize);
//
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//	glutCreateWindow("point size");
//	glutDisplayFunc(disp);
//
//	glutMainLoop();
//	return 0;
//}