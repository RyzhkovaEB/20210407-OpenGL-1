/*
 * DemoWindow.cpp
 *
 *  Created on: 13 ���. 2021 �.
 *      Author: erijkova
 */

#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width, height)
{
	set_title("OpenGL Demo Window");
}

void DemoWindow::setup_gl()
{
	glEnable(GL_DEPTH_TEST);// ����������� ��������� ������ � ����������� ����� �������
	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0, // ���� ������ �� ���������
			double(width()) / double(height()), // ����������� ������
			0.1, // ���������� �� ������� ��
			20.0); // ���������� �� ������� ��
	glMatrixMode(GL_MODELVIEW);
}

void DemoWindow::renderCube(double shiftX = 0.0, double shiftY = 0.0, double shiftZ = 0.0)
{
	glNormal3d(  1.,  0.,  0.);
	glColor3d(1.0, 0.0, 0.0); // ������� �����, �������� �����
	glVertex3d(  1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY, -1. + shiftZ);
	glVertex3d(  1. + shiftX, -1. + shiftY, -1. + shiftZ);

	glNormal3d( -1.,  0.,  0.);
	glColor3d(1.0, 0.0, 1.0); // ���������� �����, ������ ������
	glVertex3d( -1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY, -1. + shiftZ);
	glVertex3d( -1. + shiftX,  1. + shiftY, -1. + shiftZ);

	glNormal3d(  0.,  1.,  0.);
	glColor3d(1.0, 1.0, 0.0); // ������ �����, �������� ������
	glVertex3d( -1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY, -1. + shiftZ);
	glVertex3d( -1. + shiftX,  1. + shiftY, -1. + shiftZ);

	glNormal3d(  0., -1.,  0.);
	glColor3d(1.0, 1.0, 1.0); // ����� �����, ������ �����
	glVertex3d(  1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY, -1. + shiftZ);
	glVertex3d(  1. + shiftX, -1. + shiftY, -1. + shiftZ);

	glNormal3d(  0.,  0.,  1.);
	glColor3d(0.0, 1.0, 1.0); // ��������� �����, �������
	glVertex3d( -1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY,  1. + shiftZ);

	glNormal3d(  0.,  0., -1.);
	glColor3d(0.0, 0.0, 0.0); // ������ �����, ������
	glVertex3d(  1. + shiftX,  1. + shiftY, -1. + shiftZ);
	glVertex3d( -1. + shiftX,  1. + shiftY, -1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY, -1. + shiftZ);
	glVertex3d(  1. + shiftX, -1. + shiftY, -1. + shiftZ);
}

void DemoWindow::renderPyramid()
{
	// ������ ���
	renderCube(-2.5, -2.5, 0.0);
	renderCube(-2.5, 0.0, 0.0);
	renderCube(-2.5, 2.5, 0.0);
	renderCube(0.0, -2.5, 0.0);
	renderCube(0.0, 0.0, 0.0);
	renderCube(0.0, 2.5, 0.0);
	renderCube(2.5, -2.5, 0.0);
	renderCube(2.5, 0.0, 0.0);
	renderCube(2.5, 2.5, 0.0);

	// ������� ���
	renderCube(-1.25, -1.25, 2.0);
	renderCube(-1.25, 1.25, 2.0);
	renderCube(1.25, -1.25, 2.0);
	renderCube(1.25, 1.25, 2.0);

	// ������� ���
	renderCube(0.0, 0.0, 4.0);
}

void DemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �������

	glLoadIdentity(); // MV = ��������� �������

	gluLookAt(	9.0, 12.0, 6.0, // ���������� ������
				0.0, 0.0, 0.0, // ���������� ������
				0.0, 0.0, 1.0); // ����������� �����,	MV = C

	glRotated(_cube_angle, 0.0, 0.0, 1.0);

	glBegin(GL_QUADS);

	renderPyramid();

//	glPushMatrix();          // Clones matrix 1 to create matrix 2 and pushes it on the top.
//	glTranslated(2.,2.,2.);


	/* TODO: ������� ��� ��������������� ������
		 * - �������� ���������� ����� ����
		 * - ��������, ������ ��� � ������� ���� ������������ �����������
		 * - ��������� ���������, ����� ��� ����� ��������� ������������
		 * - ����������� � ��������� ����������������:
		 * 		~ ������������ �������;
		 * 		~ �������;
		 * 		~ ���������������.
		 * - ����������� � ��������� glPushMatrix() � glPopMatrix()
		 * - ��������� �� ������� ���������:
		 *          +-+
		 *          |X|
		 *        +-+ +-+
		 *        |X| |X|
		 *      +-+ +-+ +-+
		 *      |X| |X| |X|
		 *      +-+ +-+ +-+
		 */

	glEnd();
}

void DemoWindow::update()
{
	_cube_angle += 1/10.;
	if (_cube_angle >= 360.0)
		_cube_angle -= 360.0;
}
