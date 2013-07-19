///*
// * p7texture.cpp
// *
// *  Created on: 2013/07/19
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//GLubyte mask[128];  // 4byte*32(=32bit*32)
//// F0,F0,F0,,,,の配列になる
//
//void disp(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glEnable(GL_POLYGON_STIPPLE);
//	glPolygonStipple(mask);
//
//	glBegin(GL_POLYGON);
//	glVertex2f(0, -0.9);
//	glVertex2f(-0.9, 0.9);
//	glVertex2f(0.9, 0.9);
//	glEnd();
//
//	glutSwapBuffers();
//}
//
//int main(int argc, char ** argv) {
//	int iCount;
//	for (iCount = 0; iCount < 128; iCount++)
//		mask[iCount] = 0xF0;
//
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//	glutCreateWindow("texture");
//	glutDisplayFunc(disp);
//
//	glutMainLoop();
//	return 0;
//}
