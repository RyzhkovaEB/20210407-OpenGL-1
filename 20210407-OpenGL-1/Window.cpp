/*
 * Window.cpp
 *
 *  Created on: 12 апр. 2021 г.
 *      Author: erijkova
 */
#include <string>
#include <stdexcept>
#include "Window.h"

Window::Window(int width, int height)
: _width(width), _height(height)
{
	using namespace std::literals;

	_window = std::shared_ptr<SDL_Window>(
		SDL_CreateWindow(
				"OpenGL Window",
				DEFAULT_X, DEFAULT_Y,
				width, height,
				SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL),
		SDL_DestroyWindow);
	if (_window == nullptr)
		throw std::runtime_error(
				"Не удалось создать окно: "s + SDL_GetError());

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	_gl_context = std::shared_ptr<void>(
			SDL_GL_CreateContext(_window.get()),
			SDL_GL_CreateContext);
	if (_gl_context == nullptr)
		throw std::runtime_error("Не удалось создать контекст OpenGL: "s + SDL_GetError());
	)
}
