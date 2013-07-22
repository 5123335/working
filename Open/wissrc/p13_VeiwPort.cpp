///*
// * p13_VeiwPort.cpp
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
//	-0.9 , 0.9 ,
//	0.9 , 0.9 ,
//	0 , -0.9 ,
//
//	-0.9 , -0.9 ,
//	0.9 , -0.9 ,
//	0.9 , 0.9,
//	-0.9 , 0.9
//};
//
//int width , height;
//
//void disp( void ) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	// 上
//	glViewport(0 , height / 2 , width , height / 2);
//	glColor3f(1, 0, 0);
//	glDrawArrays(GL_QUADS , 3 , 4);
//
//	// 下
//	glViewport(0 , 0 , width , height / 2);
//	glColor3f(1, 1, 1);
//	glDrawArrays(GL_TRIANGLES , 0 , 3);
//
//	glutSwapBuffers();
//}
//
//void reshape(int w , int h) {  // reshape後のwidthとheightが入る
//	width = w; height = h;
//	disp();
//}
//
//int main(int argc , char ** argv) {
//	glutInit(&argc , argv);
//	glutInitWindowPosition(100 , 50);
//	glutInitWindowSize(400 , 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
////	width = 400; height = 300;
//
//	glutCreateWindow("view port");
//	glutDisplayFunc(disp);
//	glutReshapeFunc(reshape);
//
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(2 , GL_FLOAT , 0 , vertex);
//
//	glutMainLoop();
//	return 0;
//}
//
//
//void glViewport(
//	GLint x , GLint y ,             // ビューポート方形の左下隅の座標
//	GLsizei width , GLsizei height  // ウィンドウの幅と高さ
//);
