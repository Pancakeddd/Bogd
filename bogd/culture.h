#pragma once

#include <vector>

enum culturetype_t
{
	hittite
};

struct culture_t
{
	culturetype_t type;
	int gfx_type;
};

class CultureManager
{
public:
	CultureManager()
	{
	}

	~CultureManager()
	{
		for (culture_t *cul : cultures_)
		{
			delete cul;
		}
	}

	void AddCulture(culture_t*);
	culture_t *GetCulture(culturetype_t);


private:
	std::vector<culture_t*> cultures_;
};
