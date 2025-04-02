

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
const int LEVEL_ID = 116808890;


#include <Geode/binding/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
class $modify(MyPlayerLayer, PlayLayer) {
	void setupHasCompleted(){
		PlayLayer::setupHasCompleted();
		PlayLayer* pl = playlayer();
		if ((pl->m_level->m_levelID == LEVEL_ID) && Mod::get()->hasSavedValue("souls") == true) {
			//Souls
			pl->m_effectManager->updateCountForItem(64, Mod::get()->getSavedValue("souls", 0));
			pl->updateCounters(64, Mod::get()->getSavedValue("souls", 0));

			//Has gotten a soul before
			pl->m_effectManager->updateCountForItem(65, Mod::get()->getSavedValue("has_gotten_soul", 0));
			pl->updateCounters(65, Mod::get()->getSavedValue("has_gotten_soul", 0));
		}
	}

	virtual void onExit() {
		PlayLayer::onExit();
		PlayLayer* pl = playlayer();
		if (pl->m_level->m_levelID == LEVEL_ID) {
			//Souls
			Mod::get()->setSavedValue<int>("souls", pl->m_effectManager->countForItem(64));

			//Has gotten a soul before
			Mod::get()->setSavedValue<int>("has_gotten_soul", pl->m_effectManager->countForItem(65));
		}
	}
};
