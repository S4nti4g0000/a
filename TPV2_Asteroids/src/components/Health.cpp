#include "../ecs/Component.hpp"
#include "../components/Health.h"

health::health(SDL_Renderer* rend, int x, int y, int w, int h)
	:renderer_(rend), x_(x), y_(y), w_(w), h_(h), health_(3)
{
	for (int i = 0; i < health_; i++) {
		textures_.push_back(tex_);
	}
}

void health::Render()
{

	for (int i = 0; i < health_; i++)
	{
		SDL_Rect dstRect = { x_ + i * (w_ + 10), y_, w_,h_ };
		textures_[i]->render(SDL_Rect{ 0, 0, 824, 824 }, dstRect);
	}
}

void health::decLife()
{
	if (health_ > 0)
	{
		delete textures_.back();
		textures_.pop_back();
		health_--;
	}
}

void health::initComponent()
{

}