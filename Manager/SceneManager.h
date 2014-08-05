#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "cocos2d/cocos/base/CCMap.h"
#include "cocos2d/cocos/2d/CCScene.h"
#include <string>

class SceneManager
{
public:
	static SceneManager* getInstance();
	void destroySingleton();
	void addScene(cocos2d::Scene* scene, std::string name);
	void removeScene(std::string name);
	void getSceneByName(std::string name);

private:
	cocos2d::Map<std::string, cocos2d::Scene*> m_scene;
	static SceneManager* m_ist;
};
#endif // __SCENE_MANAGER_H__