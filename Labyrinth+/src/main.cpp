

/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/binding/GJEffectManager.hpp>
#include <Geode/cocos/base_nodes/CCNode.h>
#include <Geode/binding/GJBaseGameLayer.hpp>
#include <Geode/loader/Mod.hpp>

inline auto playlayer() { return GameManager::sharedState()->m_playLayer; }
/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;



bool hasSavedData;



#include <Geode/binding/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
class $modify(MyPlayerLayer, PlayLayer) {
	void setupHasCompleted(){
		PlayLayer::setupHasCompleted();
		PlayLayer* pl = playlayer();
		if ((pl->m_level->m_levelID == 116840162) && Mod::get()->hasSavedValue("souls") == true) {
			pl->m_effectManager->updateCountForItem(64, Mod::get()->getSavedValue("souls", 0));
			pl->updateCounters(64, Mod::get()->getSavedValue("souls", 0));
		}
	}

	virtual void onExit() {
		PlayLayer::onExit();
		PlayLayer* pl = playlayer();
		if (pl->m_level->m_levelID == 116840162) {
			Mod::get()->setSavedValue<int>("souls", pl->m_effectManager->countForItem(64));
		}
	}
};
