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
//	glEnableClientState(GL_VERTEX_ARRAY);  // �z���L���ɂ���
//	//	GL_VERTEX_ARRAY ���_�z��BglVertexPointer() ���Q��
//
//	glVertexPointer(2, GL_FLOAT, 0, vertex);  // ���_�z��̒�`
//	//	void glVertexPointer(
//	//		GLint 2or3or4, GLenum �f�[�^�^,
//	//		GLsizei ���_�Ԃ̃I�t�Z�b�g(byte), const GLvoid* �z��ւ̃|�C���^
//	//	);
//
////	glBegin(GL_POLYGON);
////	int i;
////	for (i = 0; i < 3; i++)  // 2�v�f���A3��
////		glArrayElement(i);  // 0,1,2
////	glEnd();
//
////	GLubyte indices[] = { 0, 1, 2 };
////	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, indices);
//////	glDrawElements(�v���~�e�B�u�̎�ށA�����_�����O���钸�_���A�C���f�b�N�X�̌^�A�C���f�b�N�X�z��)
//////	���Ȃ݂�indices��index�̕����`
//
//	glDrawArrays(GL_POLYGON , 0 , 3);
////	glDrawArrays(�v���~�e�B�u�̎�ށA�ŏ��̃f�[�^�܂ł̃I�t�Z�b�g�A�����_�����O���钸�_��)
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