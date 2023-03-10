

#include "../ecs/daRender.hpp"
#include "../ecs/EntityFr.hpp"



SDL_Texture* rWindow::loadTexture(const char* daPath)
{

	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer_, daPath);

	if (texture == NULL)
	{
		cout << "Nope, the texture did not load. CODE: " << SDL_GetError() << endl;
	}

	return texture;

}

int rWindow::getRefreshRate()
{

	int displayIndex = SDL_GetWindowDisplayIndex(window);

	SDL_DisplayMode mode;

	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;

}

void rWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void rWindow::clearScreen()
{
	SDL_RenderClear(renderer_);
}

void rWindow::daRender(EntityFr& texture)
{
	
	SDL_Rect src;

	src.x = texture.getwReckd()->x;
	src.y = texture.getwReckd()->y;
	src.w = texture.getwReckd()->w;
	src.y = texture.getwReckd()->h;

	SDL_Rect dst;

	dst.x = texture.getPos()->getX();
	dst.y = texture.getPos()->getY();
	dst.w = texture.getwReckd()->w;
	dst.h = texture.getwReckd()->h;

}

void rWindow::display()
{

	SDL_RenderPresent(renderer_);
}

