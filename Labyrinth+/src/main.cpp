

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
			pl->m_effectManager->updateCountForItem(233, 1);
			pl->updateCounters(233, 1);

			//Souls
			pl->m_effectManager->updateCountForItem(64, Mod::get()->getSavedValue("souls", 0));
			pl->updateCounters(64, Mod::get()->getSavedValue("souls", 0));

			//Has gotten a soul before
			pl->m_effectManager->updateCountForItem(65, Mod::get()->getSavedValue("has_gotten_soul", 0));
			pl->updateCounters(65, Mod::get()->getSavedValue("has_gotten_soul", 0));

			//Language
			pl->m_effectManager->updateCountForItem(58, Mod::get()->getSavedValue("language", 0));
			pl->updateCounters(58, Mod::get()->getSavedValue("language", 0));

			//Idle Lookdown
			pl->m_effectManager->updateCountForItem(99, Mod::get()->getSavedValue("idle_lookdown", 0));
			pl->updateCounters(99, Mod::get()->getSavedValue("idle_lookdown", 0));

			//Bounce Staff Upgrades
			pl->m_effectManager->updateCountForItem(113, Mod::get()->getSavedValue("upgrade1", 0));
			pl->updateCounters(113, Mod::get()->getSavedValue("upgrade1", 0));

			//Teleporter Upgrades
			pl->m_effectManager->updateCountForItem(114, Mod::get()->getSavedValue("upgrade2", 0));
			pl->updateCounters(114, Mod::get()->getSavedValue("upgrade2", 0));

			//Jetpack Upgrades
			pl->m_effectManager->updateCountForItem(115, Mod::get()->getSavedValue("upgrade3", 0));
			pl->updateCounters(115, Mod::get()->getSavedValue("upgrade3", 0));

			//Ice Boots Upgrades
			pl->m_effectManager->updateCountForItem(116, Mod::get()->getSavedValue("upgrade4", 0));
			pl->updateCounters(116, Mod::get()->getSavedValue("upgrade4", 0));
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

			//Language
			Mod::get()->setSavedValue<int>("language", pl->m_effectManager->countForItem(58));

			//Idle Lookdown
			Mod::get()->setSavedValue<int>("idle_lookdown", pl->m_effectManager->countForItem(99));

			//Bounce Staff Upgrades
			Mod::get()->setSavedValue<int>("upgrade1", pl->m_effectManager->countForItem(113));

			//Teleporter Upgrades
			Mod::get()->setSavedValue<int>("upgrade2", pl->m_effectManager->countForItem(114));

			//Jetpack Upgrades
			Mod::get()->setSavedValue<int>("upgrade3", pl->m_effectManager->countForItem(115));

			//Ice Boots Upgrades
			Mod::get()->setSavedValue<int>("upgrade4", pl->m_effectManager->countForItem(116));
		}
	}
};
