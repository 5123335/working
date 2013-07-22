//#include <math.h>
//#include <windows.h>
//#include <stdio.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//#define ANGLE 0.2  // 回転速度
//
//// 4*4ではなく16要素の配列で扱う
//GLfloat translate[] = {
//	1 , 0 , 0 , 0 ,
//	0 , 1 , 0 , 0 ,
//	0 , 0 , 1 , 0 ,
//	0 , 0 , 0 , 1
//};
//
//void disp( void ) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glBegin(GL_POLYGON);
//	{
//		glColor3f(1 , 0 , 0); glVertex2f(-0.9 , -0.9);
//		glColor3f(0 , 1 , 0); glVertex2f(0.9, 0);
//		glColor3f(0 , 0 , 1); glVertex2f(-0.9 , 0.9);
//	}
//	glEnd();
//
////	int param;
////	glGetIntegerv(GL_MATRIX_MODE, &param);
////	printf("%X\n", param); -> 1700(=GL_MODELVIEW)
//	glutSwapBuffers();
//}
//
//void timer(int value) {
//	glMultMatrixf(translate);  // 現在の行列に乗算する
//
//	// 再描画→50ms待ってこの関数を呼び出す→・・
//	// TODO: スタックオーバーフローとかにならないのかしら
//	glutPostRedisplay();
//	glutTimerFunc(50 , timer , 0);
//}
//
//int main(int argc , char ** argv) {
//	glutInit(&argc , argv);
//	glutInitWindowPosition(100 , 50);
//	glutInitWindowSize(400 , 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutCreateWindow("rolling");
//
//	glutDisplayFunc(disp);
//	glutTimerFunc(100 , timer , 0);
//
////	// x-z回転行列
////	translate[0] = cos(ANGLE);
////	translate[2] = -sin(ANGLE);
////	translate[8] = sin(ANGLE);
////	translate[10] = cos(ANGLE);
////	// translate = {
////	//   c, 0,-s, 0,
////	//   0, 1, 0, 0,
////	//   s, 0, c, 0,
////	//   0, 0, 0, 1   };
//
//	// y-z回転行列
//	translate[5] = cos(ANGLE);
//	translate[6] = -sin(ANGLE);
//	translate[9] = sin(ANGLE);
//	translate[10] = cos(ANGLE);
//	// translate = {
//	//   1, 0, 0, 0,
//	//   0, c,-s, 0,
//	//   0, s, c, 0,
//	//   0, 0, 0, 1   };
//
//
//	glutMainLoop();
//	return 0;
//}
//
//	//glMatrixMode関数 : 次の行列演算ターゲットを選択する
//	//	void glMatrixMode(
//	//		GLenum mode  // 次の行列演算のターゲットとなる行列のスタックを指定
//	//	);
//	//GL_MODELVIEW : モデルビュー行列
//	//GL_PROJECTION : 射影行列
//	//GL_TEXTURE : テクスチャ行列
//	//(デフォルトでは GL_MODELVIEW)
//	//
//	//glGet(GL_MATRIX_MODE, param)で現在の行列を得る。
//	// TODO: 行列のスタック とは
