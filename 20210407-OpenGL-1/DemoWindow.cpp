/*
 * DemoWindow.cpp
 *
 *  Created on: 13 апр. 2021 г.
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
	glEnable(GL_DEPTH_TEST);// выполняется сравнение глубин и обновляется буфер глубины
	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0, // Угол обзора по вертикали
			double(width()) / double(height()), // Соотношение сторон
			0.1, // Расстояние до ближней ПО
			20.0); // Расстояние до дальней ПО
	glMatrixMode(GL_MODELVIEW);
}

void DemoWindow::renderCube(double shiftX = 0.0, double shiftY = 0.0, double shiftZ = 0.0)
{
	glNormal3d(  1.,  0.,  0.);
	glColor3d(1.0, 0.0, 0.0); // Красная грань, передняя левая
	glVertex3d(  1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY, -1. + shiftZ);
	glVertex3d(  1. + shiftX, -1. + shiftY, -1. + shiftZ);

	glNormal3d( -1.,  0.,  0.);
	glColor3d(1.0, 0.0, 1.0); // Фиолетовая грань, задняя правая
	glVertex3d( -1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY, -1. + shiftZ);
	glVertex3d( -1. + shiftX,  1. + shiftY, -1. + shiftZ);

	glNormal3d(  0.,  1.,  0.);
	glColor3d(1.0, 1.0, 0.0); // Желтая грань, передняя правая
	glVertex3d( -1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY, -1. + shiftZ);
	glVertex3d( -1. + shiftX,  1. + shiftY, -1. + shiftZ);

	glNormal3d(  0., -1.,  0.);
	glColor3d(1.0, 1.0, 1.0); // Белая грань, задняя левая
	glVertex3d(  1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY, -1. + shiftZ);
	glVertex3d(  1. + shiftX, -1. + shiftY, -1. + shiftZ);

	glNormal3d(  0.,  0.,  1.);
	glColor3d(0.0, 1.0, 1.0); // Бирюзовая грань, верхняя
	glVertex3d( -1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX,  1. + shiftY,  1. + shiftZ);
	glVertex3d(  1. + shiftX, -1. + shiftY,  1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY,  1. + shiftZ);

	glNormal3d(  0.,  0., -1.);
	glColor3d(0.0, 0.0, 0.0); // Черная грань, нижняя
	glVertex3d(  1. + shiftX,  1. + shiftY, -1. + shiftZ);
	glVertex3d( -1. + shiftX,  1. + shiftY, -1. + shiftZ);
	glVertex3d( -1. + shiftX, -1. + shiftY, -1. + shiftZ);
	glVertex3d(  1. + shiftX, -1. + shiftY, -1. + shiftZ);
}

void DemoWindow::renderPyramid()
{
	// нижний ряд
	renderCube(-2.5, -2.5, 0.0);
	renderCube(-2.5, 0.0, 0.0);
	renderCube(-2.5, 2.5, 0.0);
	renderCube(0.0, -2.5, 0.0);
	renderCube(0.0, 0.0, 0.0);
	renderCube(0.0, 2.5, 0.0);
	renderCube(2.5, -2.5, 0.0);
	renderCube(2.5, 0.0, 0.0);
	renderCube(2.5, 2.5, 0.0);

	// средний ряд
	renderCube(-1.25, -1.25, 2.0);
	renderCube(-1.25, 1.25, 2.0);
	renderCube(1.25, -1.25, 2.0);
	renderCube(1.25, 1.25, 2.0);

	// верхний ряд
	renderCube(0.0, 0.0, 4.0);
}

void DemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очистка

	glLoadIdentity(); // MV = единичная матрица

	gluLookAt(	9.0, 12.0, 6.0, // Координаты камеры
				0.0, 0.0, 0.0, // Координаты центра
				0.0, 0.0, 1.0); // Направление вверх,	MV = C

	glRotated(_cube_angle, 0.0, 0.0, 1.0);

	glBegin(GL_QUADS);

	renderPyramid();

//	glPushMatrix();          // Clones matrix 1 to create matrix 2 and pushes it on the top.
//	glTranslated(2.,2.,2.);


	/* TODO: задание для самостоятельной работы
		 * - Добавить оставшиеся грани куба
		 * - Выяснить, почему куб в текущем виде отображается неправильно
		 * - Исправить программу, чтобы куб начал правильно отображаться
		 * - Разобраться с основными преобразованиями:
		 * 		~ параллельный перенос;
		 * 		~ поворот;
		 * 		~ масштабирование.
		 * - Разобраться с функциями glPushMatrix() и glPopMatrix()
		 * - Построить из кубиков пирамидку:
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
