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

	inline void loadEffect(const char* Path)
	{
		movEff_ = Mix_LoadWAV(Path);
		if (movEff_ == NULL)
		{
			cout << "Failed to load effect. Code:" << Mix_GetError() << endl;
		}
	}


private:

	Mix_Chunk* movEff_;

};