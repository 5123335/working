///*
// * p14_MatrixStack.cpp
// *
// *  Created on: 2013/07/22
// *      Author: yumikoy
// */
//
//
//#include <windows.h>
//#include <stdio.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//int width , height;
//
//void Draw( void ) {
////	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // GL_LINEかGL_POINTでないとedgeFlagは意味ない
//
////	glBegin(GL_POLYGON);
//	glBegin(GL_LINE_LOOP);
//	{
//		glEdgeFlag(GL_TRUE); glVertex2f(-0.9 , -0.5);
//		glEdgeFlag(GL_TRUE); glVertex2f(-0.85 , 0.9);
//		glEdgeFlag(GL_FALSE);glVertex2f(0 , 0.3);
//
////		glEdgeFlag(GL_TRUE); glVertex2f(-0.9 , -0.5);
////		glEdgeFlag(GL_FALSE);glVertex2f(0.9 , -0.5);
////		glEdgeFlag(GL_TRUE); glVertex2f(0 , 0.3);
////
////		glEdgeFlag(GL_TRUE); glVertex2f(0.85 , 0.9);
////		glEdgeFlag(GL_FALSE);glVertex2f(0.9 , -0.5);
////		glEdgeFlag(GL_FALSE);glVertex2f(0 , 0.3);
//	}
//	glEnd();
//
//	//	glViewport(0 , 0 , width , height);
////	printf("drew\n");
//}
//
//void disp( void ) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	for(int i = 0; i < 10; i++){
//		glPushMatrix();
//		{
//			glTranslatef(0.1*i , 0 , 0);
//			glColor3f(1 - 0.1*i, 0.1*i, 0);
//			Draw();
////			printf("aaa\n");
//		}
//		glPopMatrix();
//	}
//
////	glPushMatrix();
////		glTranslatef(-1 , 0 , 0);
////		Draw();
////	glPopMatrix();
////	glPushMatrix();
////		glTranslatef(1 , 0 , 0);
////		Draw();
////	glPopMatrix();
//
//	glutSwapBuffers();
//}
//
////void reshape(int w , int h) {
////	width = w; height = h;
////	glViewport(0 , 0 , width , height);
////	disp();
////}
//
//int main(int argc , char ** argv) {
//	glutInit(&argc , argv);
//	glutInitWindowPosition(100 , 50);
//	glutInitWindowSize(400 , 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//	glutCreateWindow("matrix stack");
//	glutDisplayFunc(disp);
////	glutReshapeFunc(reshape);  // reshape(,viewport)を設定したほうがなめらかにはなる
//
//	glutMainLoop();
//	return 0;
//}
