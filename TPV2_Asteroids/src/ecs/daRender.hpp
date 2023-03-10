
#pragma once


#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#undef main


#include "EntityFr.hpp"
#include "Singleton.hpp"
#include "Texture.hpp"

using namespace std;

class EntityFr;


class rWindow: public Singleton<rWindow>
{
	friend Singleton<rWindow>;
public:

	//-----

	int getRefreshRate();

	SDL_Texture* loadTexture(const char* daPath);

	void cleanUp();
	void clearScreen();
	void daRender(EntityFr& texture);
	void display();

	inline SDL_Renderer* renderer()
	{
		return renderer_;
	}

	//-----

	inline int getWidth() const
	{
		return daWidth_;
	}
	inline int getHeight() const
	{
		return daWidth_;
	}

	//-----

	inline SDL_Window* getWindow() const
	{
		return window;
	}

	inline void setRender(SDL_Renderer* rend)
	{
		renderer_ = rend;
	}
	
private:

	rWindow() = default;

	const char* daWindowTitle_;
	int daWidth_ = 800;
	int daHeight_ = 600;

	EntityFr* entity;
	SDL_Window* window;
	SDL_Renderer* renderer_;

};


inline rWindow& ren()
{
	return *rWindow::instance();
}