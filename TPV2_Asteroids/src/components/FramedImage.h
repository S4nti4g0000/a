#pragma once
#include "../ecs/Component.hpp"


class Component;

class framedImage : public Component
{

public:

	framedImage(SDL_Texture* tex, SDL_Rect& srcRect, int numFrames, int animSpeed)
		:frTexture_(tex), srcRect_(srcRect), numFrames_(numFrames), animSpeed_(animSpeed), frameCount_(0), cFrame_(0), lastUpdate_(0)
	{}

	void initComponent();
	virtual void Render();

	int setFr(int f)
	{
		cFrame_ = f;
	}

private:

	SDL_Texture* frTexture_;
	TransformComponent* trn_;
	SDL_Rect srcRect_;

	int numFrames_;
	int animSpeed_;
	int cFrame_;
	int frameCount_;

	Uint32 lastUpdate_;

};
