#include "../ecs/Component.hpp"
#include "../ecs/AsteroidManager.hpp"

void AsteroidManager::CreateAst(int n)
{
	for (int i = 0; i < n; i++)
	{
		
		//EntityFr* ast = mngr_->addEnts(_grp_Asteroids);
		//ast->addComponent<TransformComponent>(_Transform, ast, 0, src_.w, src_.h);
		//ast->addComponent<Image>(_frmImage, )

		cout << "Created asteroid" << endl;
	}
}

void AsteroidManager::addAsteroid()
{

}

void AsteroidManager::destroyAllAsteroid()
{

}

void AsteroidManager::onCollision(EntityFr* col)
{

}
