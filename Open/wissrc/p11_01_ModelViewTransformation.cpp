//#include <math.h>
//#include <windows.h>
//#include <stdio.h>
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//#define ANGLE 0.2  // ��]���x
//
//// 4*4�ł͂Ȃ�16�v�f�̔z��ň���
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
//	glMultMatrixf(translate);  // ���݂̍s��ɏ�Z����
//
//	// �ĕ`�恨50ms�҂��Ă��̊֐����Ăяo�����E�E
//	// TODO: �X�^�b�N�I�[�o�[�t���[�Ƃ��ɂȂ�Ȃ��̂�����
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
////	// x-z��]�s��
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
//	// y-z��]�s��
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
//	//glMatrixMode�֐� : ���̍s�񉉎Z�^�[�Q�b�g��I������
//	//	void glMatrixMode(
//	//		GLenum mode  // ���̍s�񉉎Z�̃^�[�Q�b�g�ƂȂ�s��̃X�^�b�N���w��
//	//	);
//	//GL_MODELVIEW : ���f���r���[�s��
//	//GL_PROJECTION : �ˉe�s��
//	//GL_TEXTURE : �e�N�X�`���s��
//	//(�f�t�H���g�ł� GL_MODELVIEW)
//	//
//	//glGet(GL_MATRIX_MODE, param)�Ō��݂̍s��𓾂�B
//	// TODO: �s��̃X�^�b�N �Ƃ�