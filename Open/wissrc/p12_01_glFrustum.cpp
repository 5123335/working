///*
// * p12_01_ProjectiveTransformation.cpp
// *
// *  Created on: 2013/07/22
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//const GLfloat vertex[] = {
//	3.1 , 1.9 , -3 , 4.5 , 0.1 , -3 , 6 , 1.9 , -3 ,
//	0.1 , 1.9 , -2 , 1.5 , 0.1 , -2 , 3 , 1.9 , -2
//};
//
//void disp(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(3 , GL_FLOAT , 0 , vertex);
//
//
//	// !!!描画順に上書きされる!!!
//	glBegin(GL_TRIANGLES);
//	{
//		int i;
//		glColor3f(0 , 0 , 1);
//		for(i = 0 ; i < 3 ; i++) glArrayElement(i);
//		glColor3f(1 , 0 , 0);
//		for(i = 3 ; i < 6 ; i++) glArrayElement(i);
//	}
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
//	glutCreateWindow("glFrustum");
//	glutDisplayFunc(disp);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	// 視点は(0,0,0), 視点方向のベクトルは(0,0,-1)(たぶん)
////	glFrustum(-10, 10, -10, 10, 2 , 10);
////	glFrustum(0, 4, 0, 4, 2 , 10);
////	glFrustum(0, 4, 0, 2, 2 , 10);
//	glFrustum(0, 4, 2, 0, 2 , 10);
//
//
//	glutMainLoop();
//	return 0;
//}
//
//
//
//
////	void glFrustum(
////		GLdouble left,	GLdouble right,
////		GLdouble bottom,  GLdouble top,
////		GLdouble zNear,  GLdouble zFar  // どちらも正の値とする
////	);
//
