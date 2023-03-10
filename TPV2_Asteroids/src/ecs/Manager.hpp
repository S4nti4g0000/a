#pragma once

#define MANAGER_HPP	

#include <vector>
#include <memory>	

#include "EntityFr.hpp"
#include "daRender.hpp"
#include "Texture.hpp"
#include "Vector2D.hpp"
#include "Singleton.hpp"
#include "Utils.hpp"
#include "ecs.hpp"

using namespace ecs;

class EntityFr;

class Manager
{

public:

	
	Manager();

	virtual ~Manager()
	{
		
		for (auto e: entities_)
		{
			delete e;
		}
	}

	static Manager& getInstance()
	{
		static Manager instance;
		return instance;
	}

	//----

	Manager(const Manager&) = delete;
	Manager& operator = (const Manager&) = delete;

	//----

	virtual EntityFr* addEnts(grpId_type gId);
	const auto& getEntities(grpId_type gId);

	virtual void Update();
	virtual void Refresh();
	virtual void Render();

	EntityFr* getEntity(const std::string& name);

private:

	EntityFr* ent;

	std::array<std::vector<EntityFr*>, ecs::maxGroupId> groups_;
	std::vector<EntityFr*> entities_;

};
