#pragma once
#include "../ecs/Component.hpp"

class Component;

class health : public Component
{

public:

	health(SDL_Renderer* rend, int x, int y, int w, int h);

	~health()
	{
		for (auto texture : textures_)
		{
			delete texture;
		}
	}

	virtual void Render();
	inline void decLife();

	void initComponent();

private:

	SDL_Point point = { 0,0 };
	SDL_Renderer* renderer_;
	Texture* tex_ = new Texture(renderer_, "resources/images/heart.png");

	int x_;
	int y_;
	int health_;

	int w_;
	int h_;

	std::vector<Texture*> textures_;

};