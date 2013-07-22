///*
// * p15_DepthBuffer.cpp
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
//const GLfloat vertex[] = {
//	-0.9 , -0.9 , -2 ,
//	0.9 , -0.9 , -2,
//	0 , 0.9 , -2
//};
//
////void Draw(void);
//
//void printTopModelViewMatrix(){
//	GLfloat fp[16];
//	glGetFloatv(GL_MODELVIEW_MATRIX, fp);
////	glGetFloatv(GL_PROJECTION_MATRIX, fp);
//	for(int i = 0; i < 4; i++){
//		printf("%2.2f, %2.2f, %2.2f, %2.2f\n", fp[i+0], fp[i+1], fp[i+2], fp[i+3]);
////		printf("%f, %f, %f, %f\n", fp[i+0], fp[i+1], fp[i+2], fp[i+3]);
//	}
//}
//
//void printMatrixMode(){
//	int param;
//	glGetIntegerv(GL_MATRIX_MODE, &param);
//	if(param!=GL_MODELVIEW)
//		return;
//	printf("MODELVIEW(");
//	glGetIntegerv(GL_MODELVIEW_STACK_DEPTH, &param);
//	printf("%d)\n", param);
//	printTopModelViewMatrix();
//}
//
//
//void Draw() {
//	printf("draw\n");
//	glBegin(GL_POLYGON);
//	{
//		glVertex3f(-0.9 , -0.9 , -2);
//		glVertex3f(0.9 , -0.9 , -2);
//		glVertex3f(0 , 0.9 , -2);
//	}
//	glEnd();
//
////	glViewport(0 , 0 , width , height);
//}
//
//void disp( void ) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//
//	glColor3f(1 , 0 ,0);         // red
//	glPushMatrix();
//	printf("push\n");
//	printMatrixMode();
//	glTranslatef(-0.5 , 0 , 0);  // dx = -0.5, z = -2
//	printf("trans\n");
//	printMatrixMode();
//	Draw();
//	glPopMatrix();
//	printf("pop\n");
//	printMatrixMode();
//
//	glColor3f(0 , 0 , 1);        // blue
//	glPushMatrix();
//	printf("push\n");
//	printMatrixMode();
//	printf("trans\n");
//	glTranslatef(0.5 , 0 , -1);  // dx = 0.5, z = -3
//	printMatrixMode();
//	Draw();
//	glPopMatrix();
//	printf("pop\n");
//	printMatrixMode();
//
//	glutSwapBuffers();
//}
//
////void reshape(int w , int h) {
////	width = w; height = h;
////	disp();
////}
//
//int main(int argc , char ** argv) {
//	glutInit(&argc , argv);
//	glutInitWindowPosition(100 , 50);
//	glutInitWindowSize(400 , 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//
//	glutCreateWindow("depth buffer");
//	glutDisplayFunc(disp);
////	glutReshapeFunc(reshape);
//
////	glMatrixMode(GL_PROJECTION);
//	printMatrixMode();
////	glLoadIdentity();
//	glFrustum(-1 , 1 , -1 , 1 , 2 , 10);  // -10 < z < -2
//
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(3 , GL_FLOAT , 0 , vertex);
//
////	printf("test!!\n");
////	 glMatrixMode( GL_MODELVIEW );
////     glLoadIdentity();
////     glTranslatef( 1, 2, 3 );
////     GLfloat m[16]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
////     glMultMatrixf(m);
//
//     printMatrixMode();
//
//	glutMainLoop();
//	return 0;
//}
//
//// glTranslatefは本当にMODELVIEW_MATRIXを書き換えてるのか？？？？？
