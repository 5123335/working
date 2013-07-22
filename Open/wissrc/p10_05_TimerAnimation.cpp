///*
// * p10_05_TimerAnimation.cpp
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
//GLfloat top = -0.9;
//void disp(void) {
////	printf("disp\n");
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
//	glutSwapBuffers();
//}
//
//void timer(int value) {
////	printf("timer\n");
//	static GLboolean isUp = GL_TRUE;
//
//	if (top > 0.9F)
//		isUp = GL_FALSE;
//	else if (top <= -0.9F)
//		isUp = GL_TRUE;
//	top += (isUp == GL_TRUE ? 0.01 : -0.01);
//
//	glutPostRedisplay();
//	glutTimerFunc(100, timer, 0);  // 100ms‘Ò‚Á‚Ä‚©‚çtimer‚ðŒÄ‚Ô
//}
//
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//	glutCreateWindow("have a nice time");
//	glutDisplayFunc(disp);
//
//	glutTimerFunc(100, timer, 0);
//
//	glutMainLoop();
//	return 0;
//}
