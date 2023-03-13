#include "../ecs/EntityFr.hpp"

void EntityFr::initC()
{
	auto n = cComps_.size();
	for (auto i = 0u; i < n; i++)
	{
		cComps_[i]->initComponent();
	}
}

void EntityFr::updateC()
{
	auto n = cComps_.size();
	for (auto i = 0u; i < n; i++)
	{
		cComps_[i]->Update();
	}
}

void EntityFr::renderC()
{
	auto n = cComps_.size();
	for (auto i = 0u; i < n; i++)
	{
		cComps_[i]->Render();
	}
}