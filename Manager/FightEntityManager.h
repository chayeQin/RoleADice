#ifndef __FIGHT_ENTITY_MANAGER_H__
#define __FIGHT_ENTITY_MANAGER_H__

#include "Entity.h"

class FightEntityManager
{
public:
	FightEntityManager* getInstance();

private:
	FightEntityManager();
	~FightEntityManager();
	FightEntityManager(const FightEntityManager&){};
	FightEntityManager& operator=(const FightEntityManager&){};
};

#endif // __FIGHT_ENTITY_MANAGER_H__
