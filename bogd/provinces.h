#pragma once

#include "population.h"

#include <vector>

enum province_terrain_t
{
	ocean,
	urban,
	farmlands,
	mountains,
	hills
};

const unsigned int province_max_cap[5] = {
	0,
	250000,
	150000,
	100000,
	125000
};

class Province
{
public:
	Province()
	{
	}

	~Province()
	{
		for (auto *p : population_)
		{
			delete p;
		}
	}

	void AddPopulation(Population *);
	unsigned int GetTotalPopulation();
	void Update();

	std::vector<Population*> population_;

	province_terrain_t terrain_type_;
};

class ProvinceManager
{
public:
	ProvinceManager()
	{
	}

	~ProvinceManager()
	{
		for (auto *prov : provinces_)
		{
			delete prov;
		}
	}

	void AddProvince(Province*);
	void UpdateProvinces();

private:
	std::vector<Province*> provinces_;
};
