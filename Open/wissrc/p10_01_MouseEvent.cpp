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
//// �}�E�X�C�x���g�ɑ΂���R�[���o�b�N�֐����`
//	//	void (*func)(
//	//		int button,   // GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON �̂����ꂩ���w��
//	//		int state,    // GLUT_DOWN ���邢�� GLUT_UP
//	//		int x, int y  // �C�x���g�������̃J�[�\���̃E�B���h�E���W���i�[
//	//	);
//
//
//void mouse(int button, int state, int x, int y) {
//	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
//		return;
//	isLine = (isLine == GL_TRUE ? GL_FALSE : GL_TRUE);  // isLine��GL_TRUE<->GL_FALSE�Ő؂�ւ���
//	glutPostRedisplay();  // �ĕ`��C�x���g�𔭐�������(glutDisplayFunc�œo�^�����R�[���o�b�N�֐����Ăяo�����)
//}
//
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 50);
//	glutInitWindowSize(400, 300);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutCreateWindow("mouse event");
//	glutDisplayFunc(disp);  // �f�B�X�v���C�E�R�[���o�b�N�֐���o�^
//
//	glutMouseFunc(mouse);	// �}�E�X�E�R�[���o�b�N�֐���o�^
//
//	glutMainLoop();
//	return 0;
//}