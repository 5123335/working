///*
// * p10_event.cpp
// *
// *  Created on: 2013/07/19
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//const GLfloat vertex[] = { -0.9, 0.9, 0.9, 0.9, 0, -0.9 };
////-0.9, 0.9,
////0.9, 0.9,
////0, -0.9
//
//GLboolean isLine = GL_FALSE;
//
//void disp(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(2, GL_FLOAT, 0, vertex);
//
//	glDrawArrays((isLine == GL_TRUE ? GL_LINE_LOOP : GL_POLYGON), 0, 3);
//
//	glutSwapBuffers();
//}
//
//// マウスイベントに対するコールバック関数を定義
//	//	void (*func)(
//	//		int button,   // GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON のいずれかを指定
//	//		int state,    // GLUT_DOWN あるいは GLUT_UP
//	//		int x, int y  // イベント発生時のカーソルのウィンドウ座標を格納
//	//	);
//
//
//void mouse(int button, int state, int x, int y) {
//	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
//		return;
//	isLine = (isLine == GL_TRUE ? GL_FALSE : GL_TRUE);  // isLineをGL_TRUE<->GL_FALSEで切り替える
//	glutPostRedisplay();  // 再描画イベントを発生させる(glutDisplayFuncで登録したコールバック関数が呼び出される)
//}
//
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutCreateWindow("mouse event");
//	glutDisplayFunc(disp);  // ディスプレイ・コールバック関数を登録
//
//	glutMouseFunc(mouse);	// マウス・コールバック関数を登録
//
//	glutMainLoop();
//	return 0;
//}
