///*
// * p12_03_glOrtho.cpp
// *
// *  Created on: 2013/07/22
// *      Author: yumikoy
// */
//
//
//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//const GLfloat vertex[] = {
//	-0.9 , 0.9 , -4 ,
//	0.9 , 0.9 , -2 ,
//	0 , -0.9 , -2 ,
//};
//
//void disp( void ) {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(3 , GL_FLOAT , 0 , vertex);
//
//	glDrawArrays(GL_POLYGON , 0 , 3);
//
//	glutSwapBuffers();
//}
//
//int main(int argc , char ** argv) {
//	glutInit(&argc , argv);
//	glutInitWindowPosition(100 , 50);
//	glutInitWindowSize(400 , 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//	glutCreateWindow("glOrtho");
//	glutDisplayFunc(disp);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
////	glFrustum(-1 , 1 , -1 , 1 , 2 , 4);
//	glOrtho(-1 , 1 , -1 , 1 , 2 , 4);
//
//	glutMainLoop();
//	return 0;
//}
//
//
//// orthographic projection : �����e
