///*
// * p11_02_MVTUsingRotate.cpp
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
//void disp( void ) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	// (-1,-1,-1)から(1,1,1)の立方体に入ってない部分は描画されない
//	glBegin(GL_POLYGON);
//	{
//		glColor3f(1 , 0 , 0);
//		glVertex2f(-0.9 , -1.2);
//		glColor3f(0 , 1 , 0);
//		glVertex2f(0 , 0.9);
//		glColor3f(0 , 0 , 1);
//		glVertex2f(0.9 , -0.9);
//	}
//	glEnd();
//
//	glutSwapBuffers();
//}
//
//void timer(int value) {
////	glRotatef(2 , 0.5 , 1 , 0.25);
//	glRotatef(2 , 1 , 0 , 0);
//	glutPostRedisplay();
//	glutTimerFunc(50 , timer , 0);
//}
//
//int main(int argc , char ** argv) {
//	glutInit(&argc , argv);
//	glutInitWindowPosition(100 , 50);
//	glutInitWindowSize(400 , 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//	glutCreateWindow("rolling!!");
//	glutDisplayFunc(disp);
//	glutTimerFunc(100 , timer , 0);
//
//	glutMainLoop();
//	return 0;
//}
//
////	void glRotatef(
////		GLfloat angle ,  // 回転度数
////		GLfloat x , GLfloat y , GLfloat z  // 回転軸のベクトル
////	);
////  原点から(x,y,z)を通過する線を軸に、左回りでオブジェクトが回転する
//
