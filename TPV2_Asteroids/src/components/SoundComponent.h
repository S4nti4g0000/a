#pragma once

#include "../ecs/daRender.hpp"
#include "SDL_mixer.h"

#include <iostream>

class SoundComponent : public Component
{

public:

	SoundComponent(Mix_Chunk* mix)
		:movEff_(mix)
	{}

	virtual ~SoundComponent() {}

	void initComponent();
	virtual void Update();

	virtual void loadEffect(const char* Path);


private:

	Mix_Chunk* movEff_;

};