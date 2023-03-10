#pragma once
#include "../ecs/Component.hpp"
#include "../components/FramedImage.h"
#include "../components/Gun.h"
#include "../components/Health.h"
#include "../components/Transform.h"
#include "../components/WrapAround.h"

class Component;

class Image : public Component
{

public:

	Image(EntityFr* ent, Texture* tex) : entity_(ent), transform_(nullptr), texture_(tex)
	{
	}

	Image() : transform_(nullptr), texture_(nullptr)
	{
	}

	virtual ~Image();

	void initComponent();
	virtual void Render() override;

	static SDL_Rect b_rect(const Vector2D& position, int width, int height)
	{
		SDL_Rect rect;
		rect.x = position.getX();
		rect.y = position.getY();
		rect.w = width;
		rect.h = height;
		return rect;
	}


private:

	TransformComponent* transform_;
	Texture* texture_;
	EntityFr* entity_;

};

class AsteroidComp : public Component
{

public:

	enum type { a, b };

	AsteroidComp(type t = a)
		:t_(a) {}

	virtual void Update();
	virtual void Render();

private:

	type t_;


};