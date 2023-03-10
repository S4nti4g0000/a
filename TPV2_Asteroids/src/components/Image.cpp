#include "../ecs/Component.hpp"
#include "../components/Image.h"


Image::~Image()
{
	delete texture_;
}

void Image::initComponent()
{
	transform_ = entity_->getComponent<TransformComponent>(_Transform);
	assert(transform_ != nullptr);

}

void Image::Render()
{
	SDL_Rect dest = b_rect(transform_->getPosition(), transform_->getW(), transform_->getH());

	texture_->render(dest, transform_->getAngle());


}