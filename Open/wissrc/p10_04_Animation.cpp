///*
// * p10_04_Animation.cpp
// *
// *  Created on: 2013/07/19
// *      Author: yumikoy
// */
//
///*
// *  !!!目に悪い!!!
// */
//
//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//void disp(void) {
//	static GLboolean isUp = GL_TRUE;
//	static GLfloat top = -0.9;
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glBegin(GL_POLYGON);
//	{
//		glVertex2f(-0.9, -0.9);
//		glVertex2f(0, top);
//		glVertex2f(0.9, -0.9);
//	}
//	glEnd();
//
//	if (top > 0.9F)
//		isUp = GL_FALSE;
//	else if (top <= -0.9F)
//		isUp = GL_TRUE;
//	top += (isUp == GL_TRUE ? 0.01 : -0.01);
//
//	glutSwapBuffers();
//}
//
//// ひまなときにすること
//void Idle() {
//	glutPostRedisplay();
//}
//
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//	glutCreateWindow("moving");
//	glutDisplayFunc(disp);
//
//	glutIdleFunc(Idle);
//
//	glutMainLoop();
//	return 0;
//}
