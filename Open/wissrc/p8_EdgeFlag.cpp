///*
// * p8_EdgeFlag.cpp
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
//// glEdgeFlag\(GL_(TRUE|FALSE)\);\r?\n\s+glVertex2f\((.*),(.*)\)
//// -> vertexWithEdgeFlag(GL_$1, $2, $3)
//void vertexWithEdgeFlag(GLboolean flag, GLfloat x, GLfloat y) {
//	glEdgeFlag(flag);
//	glVertex2f(x, y);
//}
//
//void disp(void) {
//	GLint shadeModel;
//	glGetIntegerv(GL_SHADE_MODEL, &shadeModel);
//	printf("0x%X", shadeModel);  // デフォルトはSMOOTH
////#define GL_FLAT                                 0x1D00
////#define GL_SMOOTH                               0x1D01
////	glShadeModel(GL_FLAT);  // FLATにすると全部同じ色になる
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // GL_LINEかGL_POINTでないとedgeFlagは意味ない
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_POLYGON);
//
//	glColor4f(0, 1, 0, 1);
//	vertexWithEdgeFlag(GL_TRUE, -0.9, -0.5);  // 左下
//	glColor4f(0, 0, 1, 1);
//	vertexWithEdgeFlag(GL_TRUE, -0.85, 0.9);  // 左上
//	glColor4f(1, 0, 1, 1);
//	vertexWithEdgeFlag(GL_FALSE, 0, 0.3); //f  // 中央
//
//	glColor4f(0, 1, 0, 1);
//	vertexWithEdgeFlag(GL_TRUE, -0.9, -0.5);  // 左下
//	glColor4f(1, 0, 0, 1);
//	vertexWithEdgeFlag(GL_FALSE, 0.9, -0.5);  // f  // 右下
//	glColor4f(1, 0, 1, 1);
//	vertexWithEdgeFlag(GL_TRUE, 0, 0.3);  // 中央
//
//	glColor4f(0, 1, 1, 1);
//	vertexWithEdgeFlag(GL_TRUE, 0.85, 0.9);  // 右上
//	glColor4f(1, 0, 0, 1);
//	vertexWithEdgeFlag(GL_FALSE, 0.9, -0.5);  // f  // 右下
//	glColor4f(1, 0, 1, 1);
//	vertexWithEdgeFlag(GL_FALSE, 0, 0.3);  // f  // 中央
//
//	glEnd();
//	glutSwapBuffers();
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutCreateWindow("edge flag");
//	glutDisplayFunc(disp);
//	glutMainLoop();
//	return 0;
//}
//
////OpenGL では凸状のねじれのないポリゴンのみ正確な塗りつぶしができる
////凹状のポリゴン、穴の空いたポリゴンはGLU ライブラリで三角形分解してから塗りつぶす
