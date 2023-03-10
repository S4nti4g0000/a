#pragma once

#include "EntityFr.hpp"
#include "daRender.hpp"
#include "Texture.hpp"
#include "Utils.hpp"

class EntityFr;
class Manager;

class Component 
{

public:
	Component(): entity_(), manager_()
	{}

	virtual ~Component() = default;

	inline void setContext(EntityFr* ent, Manager* mngr)
	{
		entity_ = ent;
		manager_ = mngr;
	}

	virtual void Update();
	virtual void Render();
	inline void initComponent();
	
protected:

	EntityFr* entity_;
	Manager* manager_;
	Vector2D position_;
	Vector2D velocity_;



};


