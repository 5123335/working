///*
// * p3.cpp
// *
// *  Created on: 2013/07/18
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <stdio.h>
//#include <GL/glut.h>
//#include <GL/gl.h>
//
//void disp(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_TRIANGLES);
//
////	GL_POINTS 各頂点を単独の点として扱う
////	頂点 n は、点 n を意味し n この点が描画される
////	GL_LINES 2つの頂点をペアとし、それぞれのペアを独立した線分として扱う
////	GL_LINE_STRIP 最初の頂点から最後の頂点まで、線分を連結して描画する
////	GL_LINE_LOOP すべての頂点を線分で連結する
////	GL_TRIANGLES 3つの頂点をペアとし、それぞれ独立した三角形として扱う
////	GL_TRIANGLE_STRIP 連結した三角形のグループを描画する
////	GL_TRIANGLE_FAN 最初の頂点を軸に、連結した三角形のグループを描画する
////	GL_QUADS 4つの頂点をペアとし、それぞれ独立した四角形として扱う
////	GL_QUAD_STRIP 連結した四角形のグループを描画する
////	GL_POLYGON 単独の凸ポリゴンを描画する
//// 連結多角形系よくわかんないね…
//// GL_POLYGON GL_TRIANGLES 違い
//
//	// 三角形A(上側)
//	glVertex2f(0, 0);
//	glVertex2f(-1, 0.9);
//	glVertex2f(0, 0.9);
//
//	// 三角形B(下側)
//	glVertex2f(0, 0);
//	glVertex2f(-1, -0.9);
//	glVertex2f(1, -0.9);
//
//	glEnd();
//	glutSwapBuffers();
//}
//
//// 何も色を指定しないと黒地に白で描画される(っぽい)
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(800, 50);
//	glutInitWindowSize(500, 500);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutCreateWindow("triangles");
//	glutDisplayFunc(disp);
//	glutMainLoop();
//	return 0;
//}
