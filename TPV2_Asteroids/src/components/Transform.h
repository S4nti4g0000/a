#pragma once
#include "../ecs/Component.hpp"

class Component;

class TransformComponent : public Component
{

public:

	TransformComponent(EntityFr* entity, float a, int w = 1, int h = 1)
		:entity_(entity), position_(Vector2D(x_, y_)), velocity_(Vector2D(vX_, vY_)), angle_(a), width_(w), height_(h)
	{}

	virtual void Update();
	virtual void Render() override;
	void initComponent();

	void translate(Vector2D vec)
	{
		position_ = position_ + vec;
	}

	//Getters
	Vector2D getVector2D()const
	{
		return Vector2D();
	}

	inline Vector2D getPosition() const
	{
		return position_;
	}
	inline SDL_Rect getSize() const
	{
		return size_;
	}
	inline float getAngle()
	{
		return angle_;
	}

	inline float getW() const
	{
		return width_;
	}

	inline float getH() const
	{
		return height_;
	}

	inline float getX_()
	{
		return x_;
	}

	inline float getY_()
	{
		return y_;
	}

	inline float getvX()
	{
		return vX_;
	}

	inline float getvY()
	{
		return vY_;
	}

	Vector2D getForward()
	{
		float rad = angle_ * (M_PI / 180.0f);
		return Vector2D(std::sin(rad), -std::cos(rad)).getNormalized();
	}


	//Setters

	inline void setPosition(const Vector2D& position)
	{
		position_ = position;
	}

	inline void setVelocity(const Vector2D& v)
	{
		velocity_ = v;
	}

	inline void setAngle(float angle)
	{
		angle_ = angle;
	}

	inline void setWidth(float width)
	{
		width_ = width;
	}

	inline void setHeight(float height)
	{
		height_ = height;
	}

	inline void setX(float x)
	{
		x_ = x;
	}

	inline void setY(float y)
	{
		y_ = y;
	}

	inline void setvX(float vx)
	{
		vX_ = vx;
	}

	inline void setvY(float vy)
	{

		vY_ = vy;
	}

	virtual ~TransformComponent() {}



private:

	EntityFr* entity_;
	Vector2D acceleration_;
	Vector2D position_;
	Vector2D velocity_;
	SDL_Rect size_;

	float angle_;
	float rotateSpeed_ = 0.5;

	float accelerationMagnitude_ = 0.05;
	float decelerationMagnitude_ = 1;
	float maxSpeed_ = 3;
	float currSpeed_ = 0;
	float friction_ = 0.95;

	int width_;
	int height_;

	float x_ = 362;
	float y_ = 268;

	float vX_;
	float vY_;

};
