

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


const std::string LEVEL_CREATOR = "tricipital";
const std::string LEVEL_NAME = "Labyrinth";


#include <Geode/binding/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
class $modify(MyPlayerLayer, PlayLayer) {
	void setupHasCompleted(){
		PlayLayer::setupHasCompleted();
		PlayLayer* pl = playlayer();
		if (((pl->m_level->m_levelName).compare(0, 9, LEVEL_NAME, 0, 9) == 0) && (pl->m_level->m_creatorName == LEVEL_CREATOR) && (Mod::get()->hasSavedValue("souls") == true)) {
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
			pl->m_effectManager->updateCountForItem(99, Mod::get()->getSavedValue("idle_lookdown", 2));
			pl->updateCounters(99, Mod::get()->getSavedValue("idle_lookdown", 2));

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

			//Blacksmith Freed
			pl->m_effectManager->updateCountForItem(126, Mod::get()->getSavedValue("blacksmith", 0));
			pl->updateCounters(126, Mod::get()->getSavedValue("blacksmith", 0));

			//Furthest Reached
			pl->m_effectManager->updateCountForItem(122, Mod::get()->getSavedValue("furthest", 0));
			pl->updateCounters(122, Mod::get()->getSavedValue("furthest", 0));

			//New NPC
			//pl->m_effectManager->updateCountForItem(127, Mod::get()->getSavedValue("visitor", 0));
			//pl->updateCounters(127, Mod::get()->getSavedValue("visitor", 0));

			//Times Stolen
			pl->m_effectManager->updateCountForItem(123, Mod::get()->getSavedValue("times_stolen", 0));
			pl->updateCounters(123, Mod::get()->getSavedValue("times_stolen", 0));

			//Entered Stage 1?
			pl->m_effectManager->updateCountForItem(128, Mod::get()->getSavedValue("entered1", 0));
			pl->updateCounters(128, Mod::get()->getSavedValue("entered1", 0));

			//Loot Goblin
			pl->m_effectManager->updateCountForItem(177, Mod::get()->getSavedValue("loot_goblin", 0));
			pl->updateCounters(177, Mod::get()->getSavedValue("loot_goblin", 0));

			//Shortcut progress
			pl->m_effectManager->updateCountForItem(180, Mod::get()->getSavedValue("shortcut", 0));
			pl->updateCounters(180, Mod::get()->getSavedValue("shortcut", 0));

			//Trail selected
			pl->m_effectManager->updateCountForItem(119, Mod::get()->getSavedValue("trail", 0));
			pl->updateCounters(119, Mod::get()->getSavedValue("trail", 0));
		}
	}

	virtual void onExit() {
		PlayLayer::onExit();
		PlayLayer* pl = playlayer();
		if (((pl->m_level->m_levelName).compare(0, 9, LEVEL_NAME, 0, 9) == 0) && (pl->m_level->m_creatorName == LEVEL_CREATOR)) {
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

			//Blacksmith Freed
			Mod::get()->setSavedValue<int>("blacksmith", pl->m_effectManager->countForItem(126));

			//Furthest Reached
			Mod::get()->setSavedValue<int>("furthest", pl->m_effectManager->countForItem(122));

			//New NPC
			//Mod::get()->setSavedValue<int>("visitor", pl->m_effectManager->countForItem(127));

			//Times Stolen
			Mod::get()->setSavedValue<int>("times_stolen", pl->m_effectManager->countForItem(123));
			
			//Entered Stage 1?
			Mod::get()->setSavedValue<int>("entered1", pl->m_effectManager->countForItem(128));

			//Loot Goblin
			Mod::get()->setSavedValue<int>("loot_goblin", pl->m_effectManager->countForItem(177));

			//Shortcut progress
			Mod::get()->setSavedValue<int>("shortcut", pl->m_effectManager->countForItem(180));

			//Trail Selected
			Mod::get()->setSavedValue<int>("trail", pl->m_effectManager->countForItem(119));
		}
	}
};
