#pragma once
#include "../ecs/Component.hpp"


class Component;

class WrapAroundComp : public Component
{

public:

	WrapAroundComp(int scWidth, int scHeight)
		:screenWidth_(scWidth), screenHeight_(scHeight)
	{}

	void initComponent();
	virtual void Update();

public:

	int screenWidth_;
	int screenHeight_;

};