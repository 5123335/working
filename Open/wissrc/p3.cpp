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
////	GL_POINTS �e���_��P�Ƃ̓_�Ƃ��Ĉ���
////	���_ n �́A�_ n ���Ӗ��� n ���̓_���`�悳���
////	GL_LINES 2�̒��_���y�A�Ƃ��A���ꂼ��̃y�A��Ɨ����������Ƃ��Ĉ���
////	GL_LINE_STRIP �ŏ��̒��_����Ō�̒��_�܂ŁA������A�����ĕ`�悷��
////	GL_LINE_LOOP ���ׂĂ̒��_������ŘA������
////	GL_TRIANGLES 3�̒��_���y�A�Ƃ��A���ꂼ��Ɨ������O�p�`�Ƃ��Ĉ���
////	GL_TRIANGLE_STRIP �A�������O�p�`�̃O���[�v��`�悷��
////	GL_TRIANGLE_FAN �ŏ��̒��_�����ɁA�A�������O�p�`�̃O���[�v��`�悷��
////	GL_QUADS 4�̒��_���y�A�Ƃ��A���ꂼ��Ɨ������l�p�`�Ƃ��Ĉ���
////	GL_QUAD_STRIP �A�������l�p�`�̃O���[�v��`�悷��
////	GL_POLYGON �P�Ƃ̓ʃ|���S����`�悷��
//// �A�����p�`�n�悭�킩��Ȃ��ˁc
//// GL_POLYGON GL_TRIANGLES �Ⴂ
//
//	// �O�p�`A(�㑤)
//	glVertex2f(0, 0);
//	glVertex2f(-1, 0.9);
//	glVertex2f(0, 0.9);
//
//	// �O�p�`B(����)
//	glVertex2f(0, 0);
//	glVertex2f(-1, -0.9);
//	glVertex2f(1, -0.9);
//
//	glEnd();
//	glutSwapBuffers();
//}
//
//// �����F���w�肵�Ȃ��ƍ��n�ɔ��ŕ`�悳���(���ۂ�)
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