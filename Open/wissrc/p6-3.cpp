///*
// * p6-3.cpp
// *
// *  Created on: 2013/07/19
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//void disp(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glEnable(GL_LINE_STIPPLE);
//	glLineStipple(10, 0xF0F0);  // 40pxごとに白黒切り替え
//	glLineWidth(10);  // 線の太さは切り替えに影響しない
//
//	// 点の順番によってバンドの位置は変わる
//	glBegin(GL_LINE_LOOP);
//	glVertex2f(0, -0.9);
//	glVertex2f(-0.9, 0.9);
//	glVertex2f(0.9, 0.9);
//	glEnd();
//
//	glutSwapBuffers();
//}
//
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//	glutCreateWindow("broken line");
//	glutDisplayFunc(disp);
//
//	glutMainLoop();
//	return 0;
//}
