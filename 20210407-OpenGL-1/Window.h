/*
 * Window.h
 *
 *  Created on: 12 апр. 2021 г.
 *      Author: erijkova
 */

#ifndef WINDOW_H_
#define WINDOW_H_


#include <memory>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>


class Window {

public:
	constexpr int DEFAULT_WIDTH = 1080;
	constexpr int DEFAULT_HEIGHT = 800;
	constexpr int DEFAULT_X = SDL_WINDOWPOS_CENTERED;
	constexpr int DEFAULT_Y = SDL_WINDOWPOS_CENTERED;

protected:
	std::shared_ptr<SDL_Window> _window;// окно
	std::shared_ptr<void> _gl_context;// Контекст OpenGL
	int _width, _height;
public:
	Window(int width = DEFAULT_WIDTH, int Height = DEFAULT_HEIGHT);
	virtual ~Window() = default;

	int getHeight() const {
		return _height;
	}

	int getWidth() const {
		return _width;
	}
};

#endif /* WINDOW_H_ */
