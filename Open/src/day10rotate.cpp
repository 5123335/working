///*
// * day10rotate.cpp
// *
// *  Created on: 2013/07/17
// *      Author: yumikoy
// */
//
//#include <windows.h>
//#include <math.h>
//#include <fstream>
//#include <sstream>
//#include <iostream>
//#include <direct.h>
//#include <time.h>
//#include <GL/glut.h>
//#include <GL/gl_screenshot.h>
//using namespace std;
//
//
//int WindowPositionX = 100;  //生成するウィンドウ位置のX座標
//int WindowPositionY = 100;  //生成するウィンドウ位置のY座標
//int WindowWidth = 512;    //生成するウィンドウの幅
//int WindowHeight = 512;    //生成するウィンドウの高さ
//char WindowTitle[] = "世界の始まり";  //ウィンドウのタイトル
//
//#define _BITMAP 1
//int tn = 0;
//double dt = 0.1;
//gl_screenshot gs; //bmpファイルの出力
//
//
//#define SCALE (2.0 * 3.14159265358979323846)  // マウスの相対位置→回転角の換算係数
//int cx, cy;                // ドラッグ開始位置
//double sx, sy;              // マウスの絶対位置→ウィンドウ内での相対位置の換算係数
//double cq[4] = { 1.0, 0.0, 0.0, 0.0 };  // 回転の初期値 (クォータニオン)
//double tq[4];              // ドラッグ中の回転 (クォータニオン)
//double rt[16];              // 回転の変換行列
//
//unsigned int listNumber;
//float camera_z_pos =50.0;
//
////----------------------------------------------------
//// 直方体の定義
////----------------------------------------------------
//GLdouble vertex[][3] = {
//  { 0.0, 0.0, 0.0 },
//  { 2.0, 0.0, 0.0 },
//  { 2.0, 2.0, 0.0 },
//  { 0.0, 2.0, 0.0 },
//  { 0.0, 0.0, 30.0 },
//  { 2.0, 0.0, 30.0 },
//  { 2.0, 2.0, 30.0 },
//  { 0.0, 2.0, 30.0 }
//};
//int face[][4] = {//面の定義
//  { 0, 1, 2, 3 },
//  { 1, 5, 6, 2 },
//  { 5, 4, 7, 6 },
//  { 4, 0, 3, 7 },
//  { 4, 5, 1, 0 },
//  { 3, 2, 6, 7 }
//};
//GLdouble normal[][3] = {//面の法線ベクトル
//  { 0.0, 0.0,-1.0 },
//  { 1.0, 0.0, 0.0 },
//  { 0.0, 0.0, 1.0 },
//  {-1.0, 0.0, 0.0 },
//  { 0.0,-1.0, 0.0 },
//  { 0.0, 1.0, 0.0 }
//};
////----------------------------------------------------
//// 物質質感の定義
////----------------------------------------------------
//struct MaterialStruct {
//  GLfloat ambient[4];
//  GLfloat diffuse[4];
//  GLfloat specular[4];
//  GLfloat shininess;
//};
////jade(翡翠)
//MaterialStruct ms_jade = {
//  {0.135,     0.2225,   0.1575,   1.0},
//  {0.54,      0.89,     0.63,     1.0},
//  {0.316228,  0.316228, 0.316228, 1.0},
//  12.8};
////ruby(ルビー)
//MaterialStruct ms_ruby  = {
//  {0.1745,   0.01175,  0.01175,   1.0},
//  {0.61424,  0.04136,  0.04136,   1.0},
//  {0.727811, 0.626959, 0.626959,  1.0},
//  76.8};
////----------------------------------------------------
//// 色の定義の定義
////----------------------------------------------------
//GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 }; //赤色
//GLfloat green[] = { 0.2, 0.8, 0.2, 1.0 };//緑色
//GLfloat blue[] = { 0.2, 0.2, 0.8, 1.0 };//青色
//GLfloat yellow[] = { 0.8, 0.8, 0.2, 1.0 };//黄色
//GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };//白色
//GLfloat shininess = 30.0;//光沢の強さ
////-----------------------------------------
//
////----------------------------------------------------
//// 関数プロトタイプ（後に呼び出す関数名と引数の宣言）
////----------------------------------------------------
//void Initialize(void);
//void Idle(void);
//void Display(void);
//void Ground(void);  //大地の描画
//
//static void qmul(double r[], const double p[], const double q[]);
//static void qrot(double r[], double q[]);
//void mouse_motion(int x, int y);
//void mouse_on(int button, int state, int x, int y);
//void mouse_wheel(float z);
////----------------------------------------------------
//// メイン関数
////----------------------------------------------------
//int main(int argc, char *argv[]){
//#if _BITMAP
//  _mkdir("bitmap"); //bmpファイル保存用のフォルダの作成
//#endif
//
//  glutInit(&argc, argv);//環境の初期化
//  glutInitWindowPosition(WindowPositionX, WindowPositionY);//ウィンドウの位置の指定
//  glutInitWindowSize(WindowWidth, WindowHeight); //ウィンドウサイズの指定
//  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);//ディスプレイモードの指定
//  glutCreateWindow(WindowTitle);  //ウィンドウの作成
//  glutDisplayFunc(Display); //描画時に呼び出される関数を指定する（関数名：Display）
//  glutMouseFunc(mouse_on);      //マウスクリック時に呼び出される関数 // TODO:
//  glutMotionFunc(mouse_motion);      //マウスドラッグ解除時に呼び出される関数 // TODO:
//
//  glutIdleFunc(Idle);       //プログラムアイドル状態時に呼び出される関数 // TODO:
//  Initialize(); //初期設定の関数を呼び出す
//  glutMainLoop();
//  return 0;
//}
////----------------------------------------------------
//// 初期設定の関数
////----------------------------------------------------
//void Initialize(void){
//  glClearColor(1.0, 1.0, 1.0, 1.0); //背景色
//  glEnable(GL_DEPTH_TEST);//デプスバッファを使用：glutInitDisplayMode() で GLUT_DEPTH を指定する
//
//  // ディスプレイリストを作成
//  listNumber = glGenLists(1);
//  glNewList( listNumber, GL_COMPILE );
//
//
//
//  glEndList();
////--------------------------------------
//  // マウスポインタ位置のウィンドウ内の相対的位置への換算用
//  sx = 1.0 / (double)512;
//  sy = 1.0 / (double)512;
//
//  // 回転行列の初期化
//  qrot(rt, cq);
////--------------------------------------
//
//  //透視変換行列の設定------------------------------
//  glMatrixMode(GL_PROJECTION);//行列モードの設定（GL_PROJECTION : 透視変換行列の設定、GL_MODELVIEW：モデルビュー変換行列）
//  glLoadIdentity();//行列の初期化
//  gluPerspective(30.0, (double)WindowWidth/(double)WindowHeight, 0.1, 1000.0); //透視投影法の視体積gluPerspactive(th, w/h, near, far);
//}
////----------------------------------------------------
//// アイドル時に呼び出される関数
////----------------------------------------------------
//void Idle(){
//  glutPostRedisplay(); //glutDisplayFunc()を１回実行する
//}
//
////----------------------------------------------------
//// 描画の関数
////----------------------------------------------------
//void Display(void) {
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //バッファの消去
//
//  //モデルビュー変換行列の設定--------------------------
//  glMatrixMode(GL_MODELVIEW);//行列モードの設定（GL_PROJECTION : 透視変換行列の設定、GL_MODELVIEW：モデルビュー変換行列）
//  glLoadIdentity();//行列の初期化
//  glViewport(0, 0, WindowWidth, WindowHeight);
//  //----------------------------------------------
//
//  glPushMatrix();
//
//  //光源の設定--------------------------------------
//  GLfloat light_position0[] = { 0.0, 50.0, 50.0, 1.0 }; //光源0の座標
//  glLightfv(GL_LIGHT0, GL_POSITION, light_position0); //光源0を
//  //視点の設定------------------------------
//  gluLookAt(
//       0.0, -100.0, 50.0, // 視点の位置x,y,z;
//       0.0, 100.0, 0.0,   // 視界の中心位置の参照点座標x,y,z
//       0.0, 0.0, 1.0);  //視界の上方向のベクトルx,y,z
//  //----------------------------------------
//
//  //陰影ON-----------------------------
//  glEnable(GL_LIGHTING);
//  glEnable(GL_LIGHT0);//光源0を利用
//  //-----------------------------------
//
//////回転///////////////////////////////////////////////
//  glMultMatrixd(rt);
/////////////////////////////////////////////////////////
//
//  //球
//  glPushMatrix();
//  glMaterialfv(GL_FRONT, GL_AMBIENT, ms_ruby.ambient);
//  glMaterialfv(GL_FRONT, GL_DIFFUSE, ms_ruby.diffuse);
//  glMaterialfv(GL_FRONT, GL_SPECULAR, ms_ruby.specular);
//  glMaterialfv(GL_FRONT, GL_SHININESS, &ms_ruby.shininess);
//  glTranslated(0.0, 10.0, 20.0);//平行移動値の設定
//  glutSolidSphere(4.0, 20, 20);//引数：(半径, Z軸まわりの分割数, Z軸に沿った分割数)
//  glPopMatrix();
//
//  //立方体
//  glPushMatrix();
//  glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
//  glTranslated(-20.0, 0.0, 20.0);//平行移動値の設定
//  glutSolidCube(10.0);//引数：(一辺の長さ)
//  glPopMatrix();
//
//  //円錐
//  glPushMatrix();
//  glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
//  glTranslated(20.0, 100.0, 0.0);//平行移動値の設定
//  glutSolidCone(5.0,10.0,20,20);//引数：(半径, 高さ, Z軸まわりの分割数, Z軸に沿った分割数)
//  glPopMatrix();
//
//  //直方体
//  glPushMatrix();
//  glMaterialfv(GL_FRONT, GL_AMBIENT, ms_jade.ambient);
//  glMaterialfv(GL_FRONT, GL_DIFFUSE, ms_jade.diffuse);
//  glMaterialfv(GL_FRONT, GL_SPECULAR, ms_jade.specular);
//  glMaterialfv(GL_FRONT, GL_SHININESS, &ms_jade.shininess);
//  glTranslated(30.0, 50.0, 0.0);//平行移動値の設定
//  glBegin(GL_QUADS);
//  for (int j = 0; j < 6; ++j) {
//    glNormal3dv(normal[j]); //法線ベクトルの指定
//    for (int i = 0; i < 4; ++i) {
//      glVertex3dv(vertex[face[j][i]]);
//    }
//  }
//  glEnd();
//
//
//  glPopMatrix();
//
//  //陰影OFF-----------------------------
//  glDisable(GL_LIGHTING);
//  //-----------------------------------
//
//  Ground();
//  glPopMatrix();
//
//#if _BITMAP
//  ostringstream fname;
//  int tt = tn +10000;
//  fname  << "bitmap/" << tt << ".bmp" ;//出力ファイル名
//  string name = fname.str();
//  gs.screenshot(name.c_str(), 24);
//#endif
//
//  glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)でダブルバッファリングを利用可
//  tn++;
//
//}
////----------------------------------------------------
//// マウスドラッグ時
////----------------------------------------------------
//void mouse_motion(int x, int y){
//  double dx, dy, a;
//
//  // マウスポインタの位置のドラッグ開始位置からの変位
//  dx = (x - cx) * sx;
//  dy = (y - cy) * sy;
//
//  // マウスポインタの位置のドラッグ開始位置からの距離
//  a = sqrt(dx * dx + dy * dy);
//
//  if( a != 0.0 )
//  {
//    // マウスのドラッグに伴う回転のクォータニオン dq を求める
//    double ar = a * SCALE * 0.5;
//    double as = sin(ar) / a;
//    double dq[4] = { cos(ar), dy * as, dx * as, 0.0 };
//
//    // 回転の初期値 cq に dq を掛けて回転を合成
//    qmul(tq, dq, cq);
//
//    // クォータニオンから回転の変換行列を求める
//    qrot(rt, tq);
//  }
//}
////----------------------------------------------------
//// マウスクリック時
////----------------------------------------------------
//void mouse_on(int button, int state, int x, int y)
//{
//  switch (button) {
//  case 0:
//    switch (state) {
//    case 0:
//      // ドラッグ開始点を記録
//      cx = x;
//      cy = y;
//      break;
//    case 1:
//      // 回転の保存
//      cq[0] = tq[0];
//      cq[1] = tq[1];
//      cq[2] = tq[2];
//      cq[3] = tq[3];
//      break;
//    default:
//      break;
//    }
//    break;
//  default:
//    break;
//  }
////  cout << x << " " << y<<endl;
//}
////----------------------------------------------------
//// 大地の描画
////----------------------------------------------------
//void Ground(void) {
//    double ground_max_x = 300.0;
//    double ground_max_y = 300.0;
//    glColor3d(0.8, 0.8, 0.8);  // 大地の色
//    glBegin(GL_LINES);
//    for(double ly = -ground_max_y ;ly <= ground_max_y; ly+=10.0){
//      glVertex3d(-ground_max_x, ly,0);
//      glVertex3d(ground_max_x, ly,0);
//    }
//    for(double lx = -ground_max_x ;lx <= ground_max_x; lx+=10.0){
//      glVertex3d(lx, ground_max_y,0);
//      glVertex3d(lx, -ground_max_y,0);
//    }
//    glEnd();
//}
//
////////////////////////////////////////////////////////////////////////////
//// マウスドラッグによる回転
////////////////////////////////////////////////////////////////////////////
//// クォータニオンの積 r <- p x q
//static void qmul(double r[], const double p[], const double q[])
//{
//  r[0] = p[0] * q[0] - p[1] * q[1] - p[2] * q[2] - p[3] * q[3];
//  r[1] = p[0] * q[1] + p[1] * q[0] + p[2] * q[3] - p[3] * q[2];
//  r[2] = p[0] * q[2] - p[1] * q[3] + p[2] * q[0] + p[3] * q[1];
//  r[3] = p[0] * q[3] + p[1] * q[2] - p[2] * q[1] + p[3] * q[0];
//}
//
//// 回転の変換行列 r <- クォータニオン q
//static void qrot(double r[], double q[]){
//  double x2 = q[1] * q[1] * 2.0;
//  double y2 = q[2] * q[2] * 2.0;
//  double z2 = q[3] * q[3] * 2.0;
//  double xy = q[1] * q[2] * 2.0;
//  double yz = q[2] * q[3] * 2.0;
//  double zx = q[3] * q[1] * 2.0;
//  double xw = q[1] * q[0] * 2.0;
//  double yw = q[2] * q[0] * 2.0;
//  double zw = q[3] * q[0] * 2.0;
//
//  r[ 0] = 1.0 - y2 - z2;
//  r[ 1] = xy + zw;
//  r[ 2] = zx - yw;
//  r[ 4] = xy - zw;
//  r[ 5] = 1.0 - z2 - x2;
//  r[ 6] = yz + xw;
//  r[ 8] = zx + yw;
//  r[ 9] = yz - xw;
//  r[10] = 1.0 - x2 - y2;
//  r[ 3] = r[ 7] = r[11] = r[12] = r[13] = r[14] = 0.0;
//  r[15] = 1.0;
//}
//
//void mouse_wheel(float z){
//  camera_z_pos += z;
//
//  if( camera_z_pos < 0.0f )
//  {
//    camera_z_pos = 0.0f;
//  }
//}
