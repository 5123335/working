///*
// * p9_VertexArray.cpp
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
//void disp(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glEnableClientState(GL_VERTEX_ARRAY);  // 配列を有効にする
//	//	GL_VERTEX_ARRAY 頂点配列。glVertexPointer() を参照
//
//	glVertexPointer(2, GL_FLOAT, 0, vertex);  // 頂点配列の定義
//	//	void glVertexPointer(
//	//		GLint 2or3or4, GLenum データ型,
//	//		GLsizei 頂点間のオフセット(byte), const GLvoid* 配列へのポインタ
//	//	);
//
////	glBegin(GL_POLYGON);
////	int i;
////	for (i = 0; i < 3; i++)  // 2要素ずつ、3回
////		glArrayElement(i);  // 0,1,2
////	glEnd();
//
////	GLubyte indices[] = { 0, 1, 2 };
////	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, indices);
//////	glDrawElements(プリミティブの種類、レンダリングする頂点数、インデックスの型、インデックス配列)
//////	ちなみにindicesはindexの複数形
//
//	glDrawArrays(GL_POLYGON , 0 , 3);
////	glDrawArrays(プリミティブの種類、最初のデータまでのオフセット、レンダリングする頂点数)
//
//	glutSwapBuffers();
//}
//
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//	glutCreateWindow("vertex array");
//	glutDisplayFunc(disp);
//
//	glutMainLoop();
//	return 0;
//}
