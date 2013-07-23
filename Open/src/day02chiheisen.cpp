///*
// * day2chiheisen.cpp
// *
// *  Created on: 2013/07/17
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <stdio.h>
//#include <math.h>
//#include <tchar.h>
//#include <GL/glut.h>
//
//int WindowPositionX = 100;
//int WindowPositionY = 100;
//int WindowWidth = 512;
//int WindowHeight = 512;
//TCHAR WindowTitle[] = _T("こいつ・・・動くぞ！");
//
//double rad = M_PI / 2;  // ズレそう
//double eyeX = 0;
//double eyeY = -100;
//double eyeZ = 50;
//
////----------------------------------------------------
//// 関数プロトタイプ（後に呼び出す関数名と引数の宣言）
////----------------------------------------------------
//void Initialize(void);
//void Display(void);
//void key(unsigned char, int, int);
//void spkey(int, int, int);
//void Ground(void);  //大地の描画←増えた
////----------------------------------------------------
//// メイン関数
////----------------------------------------------------
//int main(int argc, char *argv[]) {
//	glutInit(&argc, argv);  //環境の初期化
//	glutInitWindowPosition(WindowPositionX, WindowPositionY);  //ウィンドウの位置の指定
//	glutInitWindowSize(WindowWidth, WindowHeight); //ウィンドウサイズの指定
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //ディスプレイモードの指定
//	glutCreateWindow(WindowTitle);  //ウィンドウの作成
//	glutDisplayFunc(Display); //描画時に呼び出される関数を指定する（関数名：Display）
//	glutKeyboardFunc(key);
//	glutSpecialFunc(spkey);
//	Initialize(); //初期設定の関数を呼び出す
//	glutMainLoop();
//	return 0;
//}
////----------------------------------------------------
//// 初期設定の関数
////----------------------------------------------------
//void Initialize(void) {
//	glClearColor(1.0, 1.0, 1.0, 1.0); //背景色
//	glEnable(GL_DEPTH_TEST); //デプスバッファを使用：glutInitDisplayMode() で GLUT_DEPTH を指定する
//}
////----------------------------------------------------
//// 描画の関数
////----------------------------------------------------
//void Display(void) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //バッファの消去
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluPerspective(30.0, (double) WindowWidth / (double) WindowHeight, 0.1,
//			1000.0); //透視投影法の視体積gluPerspactive(th, w/h, near, far);
//
//	printf("%f -> %f\n", rad, fmod(rad, 2*M_PI));
//	rad = fmod(rad, 2*M_PI);
//	gluLookAt(eyeX, eyeY, eyeZ, // 視点の位置x,y,z;
//			eyeX + cos(rad) * 200, eyeY + sin(rad) * 200, 0.0,   // 視界の中心位置の参照点座標x,y,z
//			0.0, 0.0, 1.0);  //視界の上方向のベクトルx,y,z
//
//	Ground();
//
//	glutSwapBuffers();
//}
//
//void key(unsigned char key, int x, int y) {
////	printf("Ke=%d\n", key);
//	double radDir;
//	switch(key){
//	case 97:
//		radDir = rad + M_PI/2;
//		break;
//	case 100:
//		radDir = rad - M_PI/2;
//		break;
//	case 119:
//		radDir = rad;
//		break;
//	case 115:
//		radDir = rad + M_PI;
//		break;
//	default:
//		return;
//	}
//	eyeX += cos(radDir) * 7;
//	eyeY += sin(radDir) * 7;
//	glutPostRedisplay();
//}
//
//void spkey(int key, int x, int y) {
//	switch (key) {
//	case GLUT_KEY_LEFT:
//		rad += M_PI / 32;
//		break;
//	case GLUT_KEY_RIGHT:
//		rad -= M_PI / 32;
//		break;
//	}
//	glutPostRedisplay();
//}
////----------------------------------------------------
//// 大地の描画
////----------------------------------------------------
//void Ground(void) {
//	double ground_max_x = 300.0;
//	double ground_max_y = 300.0;
//	glColor3d(0.8, 0.8, 0.8);  // 大地の色
//	glBegin(GL_LINES);
//	for (double ly = -ground_max_y; ly <= ground_max_y; ly += 10.0) {
//		glVertex3d(-ground_max_x, ly, 0);
//		glVertex3d(ground_max_x, ly, 0);
//	}
//	for (double lx = -ground_max_x; lx <= ground_max_x; lx += 10.0) {
//		glVertex3d(lx, ground_max_y, 0);
//		glVertex3d(lx, -ground_max_y, 0);
//	}
//	glEnd();
//}
//
