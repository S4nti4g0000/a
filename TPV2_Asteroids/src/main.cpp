#include "SDL_image.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#undef main


#include "../src/ecs/daRender.hpp"
#include "../src/ecs/EntityFr.hpp"
#include "../src/ecs/Utils.hpp"
#include "../src/ecs/ecs.hpp"
#include "../src/ecs/Component.hpp"
#include "../src/ecs/Texture.hpp"
#include "../src/ecs/Manager.hpp"
#include "../src/ecs/AsteroidManager.hpp"
#include "../src/components/AsteroidComp.h"
#include "../src/components/Transform.h"
#include "../src/components/Image.h"
#include "../src/components/Health.h"
#include "../src/components/Gun.h"
#include "../src/components/FramedImage.h"
#include "../src/components/SoundComponent.h"



namespace utils
{

	inline float time()
	{
		float t = SDL_GetTicks();
		t *= 0.001f;

		return t;

	}
	const int NUM_KEYS = 323;
	extern bool keys[NUM_KEYS] = { false };
}

//#include <SDL_ttf.h>

using namespace std;

int main(int argc, const char** argv[])
{

	bool itsAlive = true;

	int* moveC = 0;

	double angle = 45.0;
	IMG_Init(IMG_INIT_PNG);
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << "Bro, your video failed somewhere! CODE: " << SDL_GetError() << endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "Dude there's an error with the image! CODE: " << SDL_GetError() << endl;
	if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) < 0)
		cout << "No audio. CODE: " << SDL_GetError() << endl;

	auto& ren = *rWindow::instance();

	SDL_Window* window = SDL_CreateWindow("Epic Space Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, SDL_WINDOW_SHOWN);

	ren.setRender(SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC));
	SDL_Renderer* renderer = ren.renderer();



	int winWidth = 800;
	int winHeight = 600;

	auto x1 = 0;
	auto y1 = 0;
	auto vX = 1;
	auto vY = 1;

	//-----

	auto& ih = *InputHandler::instance();
	auto& tm = *TextureManager::instance();

	Bullet* b;

	//Textures

	Texture* shipTx = new Texture(ren.renderer(), "../TPV2_Asteroids/resources/images/fighter.png");
	Mix_Chunk* shSound = nullptr;// = Mix_LoadWAV("../resources/sound/thrust.wav");
	SoundComponent sComp(shSound);
	
	sComp.loadEffect("..resources/sound/thrust.wav");

	//Manager

	auto man_ = new Manager();
	EntityFr* ship = man_->addEnts(_grp_General);
	auto bullet = man_->addEnts(_grp_Bullets);
	auto ast = man_->addEnts(_grp_Asteroids);
	AsteroidManager* astMngr = new AsteroidManager(man_);

	//Ship components

	auto shipComp = ship->addComponent<TransformComponent>(_Transform, ship, 0, 32, 32);
	ship->addComponent<Image>(_frmImage, ship, shipTx);
	ship->addComponent<WrapAroundComp>(_reappear, winWidth - 64, winHeight - 64);
	ship->addComponent<health>(_health, renderer, 10, 10, 26, 26);
	//ship->addComponent<SoundComponent>(_sound, shSound);

	ship->getComponent<TransformComponent>(_Transform)->setContext(ship, man_);
	ship->getComponent<Image>(_frmImage)->setContext(ship, man_);

	ship->setName("ship");
	ship->setAlive(true);
	shipComp->setAngle(0);
	shipComp->setWidth(64);
	shipComp->setHeight(64);
	shipComp->setPosition(Vector2D(winWidth / 2, winHeight / 2));
	shipComp->setContext(ship, man_);

	//bullet debug

	bullet->addComponent<Bullet>(_bullet, ship->getComponent<TransformComponent>(_Transform), man_);

	SDL_Event running;

	//Timestepping

	const float tS = 0.01f;
	float acc = 0.0f;
	float cTime = utils::time();


	//GameLoop

	while (itsAlive)
	{

		auto dt = ih.deltaTime();

		//----

		int Ticks = SDL_GetTicks();

		float newTime = utils::time();
		float fT = newTime - cTime;

		cTime = newTime;

		acc += fT;

		//----

		ih.refresh();

		if (ih.isKeyDown(SDL_SCANCODE_ESCAPE))
		{
			ih.closeWindowEvent();
			itsAlive = false;
		}

		//----

		while (acc >= tS)
		{
			while (SDL_PollEvent(&running))
			{
				if (running.type == SDL_QUIT)
				{
					itsAlive = false;
				}
			}

			acc -= tS;

		}

		ren.clearScreen();
		man_->Update();
		man_->Render();
		ship->updateC();
		ship->renderC();
		//ast->renderC();
		//bullet->updateC();
		//bullet->renderC();
		
		

		ren.display();

		/**/

		int frTicks = SDL_GetTicks() - Ticks;

		if (frTicks < 1000 / ren.getRefreshRate())
		{

			SDL_Delay(1000 / ren.getRefreshRate() - frTicks);

		}
		man_->Refresh();

	}

	SDL_DestroyWindow(window);
	ren.cleanUp();
	SDL_Quit();
	Mix_Quit();
	IMG_Quit();

	return 0;
}

