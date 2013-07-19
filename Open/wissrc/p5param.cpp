///*
// * p5param.cpp
// *
// *  Created on: 2013/07/19
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <tchar.h>
//#include <stdio.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//void printColor(const TCHAR* pstr, GLenum pname) {
//	GLfloat params[4];
//	glGetFloatv(pname, params);
//	printf("%s: (%f,%f,%f,%f)\n", pstr, params[0], params[1], params[2], params[3]);
//}
//
//void disp(void) {
//	glClearColor(1, 1, 1, 1);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	GLfloat c[4] = { 0, 0, 0, 0 };
//	glColor3fv(c);  // GL_CURRENT_COLORにcの中身がセットされる
//	//    glColor3f(float r, float g, float b)
//	//    glColor4f(float r, float g, float b, float a)
//	//    glColor3fv(float *rgb)
//	//    glColor4fv(float *rgba)
//
//	glBegin(GL_TRIANGLES);
//	{
//		glVertex2f(0, -0.9);
//		glVertex2f(-0.9, 0.9);
//		glVertex2f(0.9, 0.9);
//	}
//	glEnd();
//
//	printColor(_T("CURRENT"), GL_CURRENT_COLOR);
//	printColor(_T("COLOR_CLEAR"), GL_COLOR_CLEAR_VALUE);
////	(1.000000,1.000000,1.000000,1.000000) <- GL_CURRENT_COLOR(1)
////	(0.000000,0.000000,0.000000,0.000000) <- GL_COLOR_CLEAR_VALUE(1)
////	(0.000000,0.000000,0.000000,1.000000) <- GL_CURRENT_COLOR(2)
////	(1.000000,1.000000,1.000000,1.000000) <- GL_COLOR_CLEAR_VALUE(2)
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
//	glutCreateWindow("Kitty on your lap");
//	glutDisplayFunc(disp);
//
//	printColor(_T("CURRENT"), GL_CURRENT_COLOR);
//	printColor(_T("COLOR_CLEAR"), GL_COLOR_CLEAR_VALUE);
//
//	glutMainLoop();
//	return 0;
//}
