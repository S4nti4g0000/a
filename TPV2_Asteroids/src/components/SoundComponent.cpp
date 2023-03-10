#pragma once

#include "SoundComponent.h"

void SoundComponent::initComponent()
{

	if (Mix_OpenAudio(4000, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{

		cout << "Something is wrong with the audio, go check. CODE: " << SDL_GetError() << endl;

	}

	Mix_VolumeChunk(movEff_, MIX_MAX_VOLUME / 2);

}

void SoundComponent::Update()
{

	auto& ih = *InputHandler::instance();

	if (ih.isKeyDown(SDL_SCANCODE_W))
	{
		cout << "should make a sound..." << endl;
		Mix_PlayChannel(-1, movEff_, 1);
	}

}