#include "provinces.h"

void Province::AddPopulation(Population *p)
{
	population_.push_back(p);
}

unsigned int Province::GetTotalPopulation()
{
	unsigned int i = 0;
	for (Population *pop : population_)
	{
		i += pop->pop_;
	}
	return i;
}

void Province::Update()
{
	if (terrain_type_ == province_terrain_t::urban && GetTotalPopulation() >= province_max_cap[province_terrain_t::urban])
	{
		terrain_type_ = province_terrain_t::urban;
	}
}

// Province Manager

void ProvinceManager::AddProvince(Province *p)
{
	provinces_.push_back(p);
}

void ProvinceManager::UpdateProvinces()
{
	for (Province *prov : provinces_)
	{
		prov->Update();
	}
}