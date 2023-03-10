#include "../ecs/Component.hpp"
#include "../components/Gun.h"
#include "Transform.h"
#include "Image.h"

Bullet::Bullet(TransformComponent* trn, Manager* mng)
	:transform_(trn), manager_(mng)
{
	auto& ren_ = *rWindow::instance();
	bullets_.push_back(this);
	SDL_Surface* surf = IMG_Load("../TPV2_Asteroids/resources/images/fire.png");
	Texture* bTex = new Texture(ren_.renderer(), "../TPV2_Asteroids/resources/images/fire.png");
	SDL_FreeSurface(surf);
}

void Bullet::initComponent()
{

}

void Bullet::Update()
{
	auto& inH = *InputHandler::instance();
	
	if (inH.isKeyDown(SDL_SCANCODE_S))
	{
		if (time.getTime() - lastShot >= 0.2)
		{
			transform_->translate(velocity_ * inH.deltaTime());

			EntityFr* astIns = manager_->addEnts(_grp_Bullets);
			auto astComps = astIns->addComponent<TransformComponent>(_Transform, entity_, 0, 32, 32);
			astIns->addComponent<Image>(_frmImage, astIns, bTex);
			lastShot = time.getTime();
			cout << "Shot" << endl;

		}
	}

	if (transform_->getPosition().getX() < 0 || transform_->getPosition().getX() > 800 ||
		transform_->getPosition().getY() < 0 || transform_->getPosition().getY() > 600)
	{
		auto it = std::find(bullets_.begin(), bullets_.end(), this);
		if (it != bullets_.end())
		{
			bullets_.erase(it);
		}

		delete this;

	}


}

void Bullet::Render()
{

	//SDL_Rect rect = {transform_->getX_(), transform_->getY_(), 32,32};
	//SDL_RenderCopy(renderer_, bTex, nullptr, &rect);

}