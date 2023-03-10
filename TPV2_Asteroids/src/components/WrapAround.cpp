#include "../ecs/Component.hpp"
#include "WrapAround.h"
#include "Transform.h"


void WrapAroundComp::Update()
{
	Vector2D pos_ = entity_->getComponent<TransformComponent>(_Transform)->getPosition();
	if (pos_.getX() < -64)
	{
		pos_.setX(screenWidth_ + 64);
	}
	else if (pos_.getX() > screenWidth_ + 64)
	{
		pos_.setX(-64);
	}
	if (pos_.getY() < -64)
	{
		pos_.setY(screenHeight_ + 64);
	}
	else if (pos_.getY() > screenHeight_ + 64)
	{
		pos_.setY(-64);
	}

	entity_->getComponent<TransformComponent>(_Transform)->setPosition(pos_);

}

void WrapAroundComp::initComponent()
{


}
