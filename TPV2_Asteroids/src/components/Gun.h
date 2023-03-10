#pragma once
#include "../ecs/Component.hpp"


class Component;

class Bullet : public Component
{
	
public:

	std::vector<Bullet*> bullets_;

	Bullet(TransformComponent* trn, Manager* mngr);

	void initComponent();
	virtual void Update();
	virtual void Render();

private:

	Time time;

	TransformComponent* transform_;
	Vector2D velocity_;

	Manager* manager_;
	EntityFr* entity_;
	Vector2D bPos_;
	SDL_Renderer* renderer_;
	Texture* bTex;

	float speedB_ = 10.0f;
	int wWidth_ = 800;
	int hHeight_ = 600;

	float lastShot = 0;

	std::vector<Texture*> texturesB_;
};
