/*
 * day08_01ReShadow.cpp
 *
 *  Created on: 2013/07/23
 *      Author: yumikoy
 */

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <direct.h>
#include <time.h>
#include <GL/glut.h>

using namespace std;

int WindowPositionX = 200;  //��������E�B���h�E�ʒu��X���W
int WindowPositionY = 200;  //��������E�B���h�E�ʒu��Y���W
int WindowWidth = 500;    //��������E�B���h�E�̕�
int WindowHeight = 500;    //��������E�B���h�E�̍���
char WindowTitle[] = "���E�̎n�܂�";  //�E�B���h�E�̃^�C�g��

//static GLfloat floor_planar[4];
static GLfloat floor_planar[4] = { 0, 0, 10000, 10000 };
static GLfloat pM[16];
static GLfloat lightpos[4] = { -30, -100, 50, 1 };

GLfloat floor_v[][3] = {
		{ 50, 50, -1 }, { -50,	50, -1 },{ -50, -50, -1 }, { 50, -50, -1}};

//----------------------------------------------------
// �֐��v���g�^�C�v�i��ɌĂяo���֐����ƈ����̐錾�j
//----------------------------------------------------
void Initialize(void);
void Display(void);

void shadowMatrix(GLfloat *m, GLfloat plane[4], GLfloat light[4]);
void DrawFloor(bool bTexture);
void DrawShadow(void);
void DrawStructure(bool);
//----------------------------------------------------
// ���C���֐�
//----------------------------------------------------
int main(int argc, char *argv[]) {
	glutInit(&argc, argv);  //���̏�����
	glutInitWindowPosition(WindowPositionX, WindowPositionY);  //�E�B���h�E�̈ʒu�̎w��
	glutInitWindowSize(WindowWidth, WindowHeight); //�E�B���h�E�T�C�Y�̎w��
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //�f�B�X�v���C���[�h�̎w��
	glutCreateWindow(WindowTitle);  //�E�B���h�E�̍쐬
	glutDisplayFunc(Display); //�`�掞�ɌĂяo�����֐����w�肷��i�֐����FDisplay�j
	Initialize(); //�����ݒ�̊֐����Ăяo��
	glutMainLoop();
	return 0;
}
//----------------------------------------------------
// �����ݒ�̊֐�
//----------------------------------------------------
void Initialize(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0); //�w�i�F
	glEnable(GL_DEPTH_TEST); //�f�v�X�o�b�t�@���g�p�FglutInitDisplayMode() �� GLUT_DEPTH ���w�肷��
//  glDepthFunc( GL_LEQUAL );  // TODO: ����̉e��`���Ƃ���DEPTH��؂��Ă邩��K�v�Ȃ��H�H
	glClearDepth(1.0);  // specify the GL_DEPTH_CLEAR_VALUE for the depth buffer

	//�����ϊ��s��̐ݒ�------------------------------
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  //�s��̏�����
	gluPerspective(30.0, (double) WindowWidth / (double) WindowHeight, 0.1,
			1000.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
//----------------------------------------------------
// �`��̊֐�
//----------------------------------------------------
void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	//���_�̐ݒ�------------------------------
	gluLookAt(0.0, -160.0, 40, // ���_�̈ʒux,y,z;
			0.0, 0.0, 0.0,   // ���E�̒��S�ʒu�̎Q�Ɠ_���Wx,y,z
			0.0, 0.0, 1.0);  //���E�̏�����̃x�N�g��x,y,z
	//----------------------------------------

	//���f���r���[�ϊ��s��̐ݒ�--------------------------
	glMatrixMode(GL_MODELVIEW); //�s�񃂁[�h�̐ݒ�iGL_PROJECTION : �����ϊ��s��̐ݒ�AGL_MODELVIEW�F���f���r���[�ϊ��s��j
	glLoadIdentity();  //�s��̏�����
	glViewport(0, 0, WindowWidth, WindowHeight);
	//----------------------------------------------

	//�X�e���V���o�b�t�@�N���A�l�̐ݒ�--------------------------
	glClearStencil(0);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	//----------------------------------------

	// ���ʎˉe�s��̎Z�o--------------------------
	shadowMatrix(pM, floor_planar, lightpos);
	//--------------------------

	// ����ON-----------------------------
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	//-----------------------------------

	glPushMatrix();
	DrawStructure(true);  // ����
//	glDisable(GL_LIGHTING);
	DrawShadow();
	glPopMatrix();

	glDisable(GL_AUTO_NORMAL);
	glDisable(GL_NORMALIZE);

	glutSwapBuffers();
}

const double px = 0, py = -10, pz = 6;
const double ax = 0.0, ay = 0.0, az = -4.0;
const double hanpatu = 0.9;
//----------------------------------------------------
// ���̂̕`��
//----------------------------------------------------
const double dt = 0.05;
GLfloat blue[] = { 0.2, 0.2, 0.8, 1};//�F

void DrawStructure(bool jittai) {
	if (jittai || pz > 0) {  // true��draw, false(�e)�����̂�������Ȃ�draw
		glPushMatrix();
		glTranslated(px, py, pz);  //���s�ړ��l�̐ݒ�
//      glutSolidSphere(4.0, 20, 20);//�����F(���a, Z���܂��̕�����, Z���ɉ�����������)
		if (!jittai)
			glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
		glutSolidCube(9);  //�����F(���a, Z���܂��̕�����, Z���ɉ�����������)
		glPopMatrix();
	}
}
//----------------------------------------------------
// �����ʂ̕������ƍs��̌v�Z
//----------------------------------------------------
void shadowMatrix(GLfloat *m, GLfloat plane[4], GLfloat light[4])
{ //         (out-�s��̃|�C���^, �ˉe����\�ʂ̕��ʕ������̌W��, �����̓������W�l)

	GLfloat dot;

	// Find dot product between light position vector and ground plane normal.
	dot = plane[0] * light[0] + plane[1] * light[1] + plane[2] * light[2]
			+ plane[3] * light[3];

	m[0] = dot - light[0] * plane[0];
	m[4] = 0.f - light[0] * plane[1];
	m[8] = 0.f - light[0] * plane[2];
	m[12] = 0.f - light[0] * plane[3];

	m[1] = 0.f - light[1] * plane[0];
	m[5] = dot - light[1] * plane[1];
	m[9] = 0.f - light[1] * plane[2];
	m[13] = 0.f - light[1] * plane[3];

	m[2] = 0.f - light[2] * plane[0];
	m[6] = 0.f - light[2] * plane[1];
	m[10] = dot - light[2] * plane[2];
	m[14] = 0.f - light[2] * plane[3];

	m[3] = 0.f - light[3] * plane[0];
	m[7] = 0.f - light[3] * plane[1];
	m[11] = 0.f - light[3] * plane[2];
	m[15] = dot - light[3] * plane[3];
}

//----------------------------------------------------
// ���̕`��Ɖe�̕`��
//----------------------------------------------------
void DrawFloor() {
	glDisable(GL_LIGHTING);  // ���͐F�w��ŕ`���̂Ō������[�h�͎g���Ȃ�
	glBegin(GL_QUADS);
	glVertex3fv(floor_v[0]);
	glVertex3fv(floor_v[1]);
	glVertex3fv(floor_v[2]);
	glVertex3fv(floor_v[3]);
	glEnd();
	glEnable(GL_LIGHTING);
}

void DrawShadow(void) {
	glEnable(GL_STENCIL_TEST);

	glStencilFunc(GL_ALWAYS, 1, ~0);  // ��l��1�A���ׂč��i
	//���ꂩ��`�悷�����(s,dp��pass��������)�̃X�e���V���l�����ׂ�1�ɂ���
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	glColor4f(0.7f, 0.4f, 0.0f, 1.0f);  // ���̐F
	DrawFloor();  //���̕`��

	//�ȉ��̓��e�̃s�N�Z���̐F�̒l�́A�������܂�Ȃ��B
	glDisable(GL_DEPTH_TEST);
	glColorMask(0, 0, 0, 0);  // �J���[�o�b�t�@��ی�
	glDepthMask(0);           // �f�v�X�o�b�t�@��ی�
	{
		//���ɃI�u�W�F�N�g�̉e�̃X�e���V����t����
//		glEnable(GL_STENCIL_TEST);
		glStencilFunc(GL_EQUAL, 1, ~0);

		//���ꂩ��`�悷����̂̃X�e���V���l�ɂ��ׂĂP�^�O������
		glStencilOp(GL_KEEP, GL_KEEP, GL_INCR);

		// �ˉe�s����|���ĕ��̂�draw(���ɒ���t�����`)
		glColor4f(1, 1, 0, 1.0);  // (�e�X�e���V���̐F)
		glPushMatrix();
		glMultMatrixf(pM);
		DrawStructure(false);  // ���̂�������Ȃ�e�X�e���V����draw
		glPopMatrix();
	}
	glColorMask(1, 1, 1, 1);
	glDepthMask(1);
	glEnable(GL_DEPTH_TEST);

	//�e������
	glStencilFunc(GL_EQUAL, 2, ~0);
//	glColor4f(0.1f, 0.1f, 0.1f, 0.5f);
	glColor4f(1, 0, 0, 0.2);  // �e�̐F,�e�̔Z��
	glDisable(GL_DEPTH_TEST);  // ���ɏ㏑�����邽��(�B��镔���̓X�e���V���o�b�t�@�ŏ����ς�)
	DrawFloor();  //���̕`��
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_STENCIL_TEST);
}


//	void glStencilFunc(
//		GLenum func,  // ��r���@���w��
//		GLint ref,    // ��l���w��(�X�e���V���e�X�g��ʉ߂�����l)
//		GLuint mask   // ~0(�S�r�b�g1)�ɂ��Ă����Ζ����ł���
//	);
//	GL_NEVER�F���ׂĕs���i
//	GL_LESS�F( ref & mask ) < ( stencil & mask ) �ō��i
//	GL_LEQUAL�F( ref & mask ) <= ( stencil & mask ) �ō��i
//	GL_GREATER�F( ref & mask ) > ( stencil & mask ) �ō��i
//	GL_GEQUAL�F( ref & mask ) >= ( stencil & mask ) �ō��i
//	GL_EQUAL�F( ref & mask ) = ( stencil & mask ) �ō��i
//	GL_NOTEQUAL�F( ref & mask ) != ( stencil & mask ) �ō��i
//	GL_ALWAYS�F���ׂč��i

//	void glStencilOp(
//		GLenum sfail,   // �X�e���V���e�X�g��ʉ߂ł��Ȃ��������̏���
//		GLenum dpfail,  // �X�e���V���e�X�g�͒ʉ߂ł������A�f�v�X�e�X�g��ʉ߂ł��Ȃ��������̏���
//		GLenum dppass   // �ǂ�����ʉ߂������̏���
//	);
//	GL_KEEP : ���݂̒l���L�[�v����B
//	GL_ZERO : �X�e���V���l���u0�v�ɐݒ�B
//	GL_REPLACE : glStencilFunc()�̑�2����ref �Œu��������B
//	GL_INCR : �X�e���V���l���u+1�v����B�������A�ő�l�ȏ�͑����Ȃ��B
//	GL_INCR_WRAP : �X�e���V���l���u+1�v����B�ő�l�܂ł�������u0�v�ɖ߂�B
//	GL_DECR : �X�e���V���l���u-1�v����B�u0�v�ȉ��ɂ͂Ȃ�Ȃ��B
//	GL_DECR_WRAP : �X�e���V���l���u-1�v����B�u0�v���u-1�v����ƃX�e���V���l�̂Ƃ肤��ő�l�ɂȂ�B
//	GL_INVERT : �X�e���V���l���r�b�g���]����B