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
//int pointSize = 1;  // ここを変えると点の大きさ(px)が変わる
//// コマンドライン引数でも渡せるヨ…
//
//void disp(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glPointSize(pointSize++);  // 描画のたびに大きくなる
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
