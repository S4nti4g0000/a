#include "../ecs/Component.hpp"
#include "../components/Transform.h"

void TransformComponent::Update()
{
	auto& inH = *InputHandler::instance();

	float rad;

	if (inH.isKeyDown(SDL_SCANCODE_W))
	{
		rad = angle_ * (M_PI / 180.0);

		acceleration_.setX(sin(rad) * accelerationMagnitude_);
		acceleration_.setY(-cos(rad) * accelerationMagnitude_);

		currSpeed_ += acceleration_.getLength();

		if (currSpeed_ > maxSpeed_)
			currSpeed_ = maxSpeed_;

		velocity_ = velocity_ + acceleration_;

		position_ = position_ + velocity_;
	}
	if (inH.isKeyUp(SDL_SCANCODE_W))
	{
		float currentAccelerationMag = acceleration_.getLength();
		if (currSpeed_ > 0.0f)
		{
			float decel = decelerationMagnitude_ * inH.deltaTime();
			float decelerationMag = std::min(currSpeed_, decel);
			Vector2D deceleration = acceleration_.getNormalized() * decelerationMag;
			acceleration_ = acceleration_ - deceleration;
			velocity_ = velocity_ - acceleration_;
			position_ = position_ - velocity_;
		}
		currSpeed_ -= 0.5;
		if (currSpeed_ < 0.5)
		{
			currSpeed_ = 0;
		}

	}

	velocity_ = velocity_ + acceleration_;
	velocity_ = velocity_ * friction_;

	position_ = position_ + velocity_;


	if (inH.isKeyDown(SDL_SCANCODE_A))
	{
		angle_ -= 5;
	}


	if (inH.isKeyDown(SDL_SCANCODE_D))
	{
		angle_ += 5;
	}

	if (inH.getKeyUp())
	{


		velocity_.setX(velocity_.getX() * 0.95f);
		velocity_.setY(velocity_.getY() * 0.95f);


		position_ = position_ + velocity_;

	}

	setPosition(position_);

	//cout << "updating tr, component: " << manager_->getEntity("ship");

}

void TransformComponent::Render()
{

}


void TransformComponent::initComponent()
{

	position_.setX(x_);
	position_.setY(y_);
	velocity_.setX(vX_);
	velocity_.setY(vY_);
	width_ = 32;
	height_ = 32;
	angle_ = 0;

}