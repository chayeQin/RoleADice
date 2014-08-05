#include "SceneManager.h"

SceneManager* SceneManager::m_ist = nullptr;

SceneManager* SceneManager::getInstance()
{
	if (m_ist == nullptr)
	{
		m_ist = new SceneManager();		
	}
	return m_ist;
}

void SceneManager::destroySingleton()
{
	if (m_ist)
	{
		delete m_ist;
		m_ist = nullptr;
	}
}

void SceneManager::addScene(cocos2d::Scene* scene, std::string name)
{

}

void SceneManager::removeScene(std::string name)
{

}

void SceneManager::getSceneByName(std::string name)
{

}