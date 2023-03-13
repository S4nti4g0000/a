#pragma once

#include "SoundComponent.h"

void SoundComponent::initComponent()
{
	if (Mix_OpenAudio(4000, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "Something is wrong with the audio, go check. CODE: " << SDL_GetError() << ", SOUND ERROR: "<< Mix_GetError() << endl;
	}

	movEff_ = Mix_LoadWAV("resources/sound/thrust.wav");

	if (movEff_ != NULL)
	{
		cout << "Initializing audio..." << endl;

		Mix_VolumeChunk(movEff_, MIX_MAX_VOLUME / 2);
	}
}

void SoundComponent::loadEffect(const char* Path)
{
		movEff_ = Mix_LoadWAV(Path);
		if (movEff_ == NULL)
		{
			cout << "Failed to load effect. Code: " << Mix_GetError() << endl;
		}
}

void SoundComponent::Update()
{

	auto& ih = *InputHandler::instance();

	if (ih.isKeyDown(SDL_SCANCODE_W))
	{
		Mix_PlayChannel(-1, movEff_, 0);
	}

}