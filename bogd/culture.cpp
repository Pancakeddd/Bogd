#include "culture.h"

void CultureManager::AddCulture(culture_t *cul)
{
	cultures_.push_back(cul);
}

culture_t *CultureManager::GetCulture(culturetype_t cultype)
{
	for (culture_t *cul : cultures_)
	{
		if (cul->type == cultype)
		{
			return cul;
		}
	}
	return nullptr;
}