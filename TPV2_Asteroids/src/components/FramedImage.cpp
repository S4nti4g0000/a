#include "../ecs/Component.hpp"
#include "../components/FramedImage.h"
#include "Transform.h"


void framedImage::initComponent()
{
	TransformComponent* tran = entity_->getComponent<TransformComponent>(_Transform);

	tran->setX(srcRect_.x);
	tran->setX(srcRect_.y);
	tran->setWidth(srcRect_.w);
	tran->setHeight(srcRect_.h);


}

void framedImage::Render()
{
	auto& ren_ = *rWindow::instance();
	SDL_Rect dstRect = {

		static_cast<int>(trn_->getPosition().getX()),
		static_cast<int>(trn_->getPosition().getY()),
		srcRect_.w * trn_->getSize().x,
		srcRect_.h * trn_->getSize().y
	};

	if (SDL_GetTicks() - lastUpdate_ > animSpeed_)
	{
		cFrame_ = (cFrame_ + 1) % numFrames_;
		lastUpdate_ = SDL_GetTicks();
	}

	SDL_Rect cFrameRect = {
		srcRect_.x + cFrame_ * srcRect_.w,
		srcRect_.y,
		srcRect_.w,
		srcRect_.h

	};

	SDL_RenderCopy(ren_.renderer(), frTexture_, &cFrameRect, &dstRect);
}
