

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
std::string achievements[] = {"beginnings","big spender","quick death","cursed","thievery", "upgrade", "min max", "ispy","boom","invigorated","flying","spicy",
							  "freezing", "zap", "shutdown", "mystery", "prepared", "shortcut","sneaky deals", "secret box", "game time", "casino blitz","collector",
							  "speedrunner1","speedrunner2","speedrunner3","speedrunner4","it lives","it rests","sneaky sneaky","droppy","good ending","escapee",
							  "adventurer1","adventurer2","adventurer3","adventurer4","how to adventure","speed of light","blank","blank","blank"};

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

			//Perk equiped
			pl->m_effectManager->updateCountForItem(8998, Mod::get()->getSavedValue("equipedpos", 0));
			pl->updateCounters(8998, Mod::get()->getSavedValue("equipedpos", 0));

			//Charisma Perk
			pl->m_effectManager->updateCountForItem(8996, Mod::get()->getSavedValue("charismaperk", 0));
			pl->updateCounters(8996, Mod::get()->getSavedValue("charismaperk", 0));

			//Eye Spy Perk
			pl->m_effectManager->updateCountForItem(8995, Mod::get()->getSavedValue("ispyperk", 0));
			pl->updateCounters(8995, Mod::get()->getSavedValue("ispyperk", 0));

			//Blast Process Perk
			pl->m_effectManager->updateCountForItem(8994, Mod::get()->getSavedValue("blastperk", 0));
			pl->updateCounters(8994, Mod::get()->getSavedValue("blastperk", 0));

			//Gambler Perk
			pl->m_effectManager->updateCountForItem(8993, Mod::get()->getSavedValue("gamblerperk", 0));
			pl->updateCounters(8993, Mod::get()->getSavedValue("gamblerperk", 0));

			//Shopping Addict Perk
			pl->m_effectManager->updateCountForItem(8992, Mod::get()->getSavedValue("shopcompassperk", 0));
			pl->updateCounters(8992, Mod::get()->getSavedValue("shopcompassperk", 0));

			//Obsidian Skin Perk
			pl->m_effectManager->updateCountForItem(8991, Mod::get()->getSavedValue("lavaperk", 0));
			pl->updateCounters(8991, Mod::get()->getSavedValue("lavaperk", 0));

			//Shoplifter Perk
			pl->m_effectManager->updateCountForItem(8990, Mod::get()->getSavedValue("stealperk", 0));
			pl->updateCounters(8990, Mod::get()->getSavedValue("lavaperk", 0));

			//Speedballing Perk
			pl->m_effectManager->updateCountForItem(8989, Mod::get()->getSavedValue("speedperk", 0));
			pl->updateCounters(8989, Mod::get()->getSavedValue("speedperk", 0));

			//Big Man Perk
			pl->m_effectManager->updateCountForItem(8988, Mod::get()->getSavedValue("bigmanperk", 0));
			pl->updateCounters(8988, Mod::get()->getSavedValue("bigmanperk", 0));

			//Navigator Perk
			pl->m_effectManager->updateCountForItem(8987, Mod::get()->getSavedValue("compassperk", 0));
			pl->updateCounters(8987, Mod::get()->getSavedValue("compassperk", 0));

			//Curse of Greed Perk
			pl->m_effectManager->updateCountForItem(8986, Mod::get()->getSavedValue("greedperk", 0));
			pl->updateCounters(8986, Mod::get()->getSavedValue("greedperk", 0));\

			//Rooted Step Perk
			pl->m_effectManager->updateCountForItem(8985, Mod::get()->getSavedValue("rootedstepperk", 0));
			pl->updateCounters(8985, Mod::get()->getSavedValue("rootedstepperk", 0));
			
			//Interest Perk
			pl->m_effectManager->updateCountForItem(8984, Mod::get()->getSavedValue("interestperk", 0));
			pl->updateCounters(8984, Mod::get()->getSavedValue("interestperk", 0));

			//Rich Perk
			pl->m_effectManager->updateCountForItem(8983, Mod::get()->getSavedValue("richperk", 0));
			pl->updateCounters(8983, Mod::get()->getSavedValue("richperk", 0));

			//Clearance Perk
			pl->m_effectManager->updateCountForItem(8982, Mod::get()->getSavedValue("clearanceperk", 0));
			pl->updateCounters(8982, Mod::get()->getSavedValue("clearanceperk", 0));

			//Surplus Perk
			pl->m_effectManager->updateCountForItem(8981, Mod::get()->getSavedValue("surplusperk", 0));
			pl->updateCounters(8981, Mod::get()->getSavedValue("surplusperk", 0));

			//Demolitions Expert Perk
			pl->m_effectManager->updateCountForItem(8980, Mod::get()->getSavedValue("bombperk", 0));
			pl->updateCounters(8980, Mod::get()->getSavedValue("bombperk", 0));

			//Soulful Perk
			pl->m_effectManager->updateCountForItem(8979, Mod::get()->getSavedValue("soulfulperk", 0));
			pl->updateCounters(8979, Mod::get()->getSavedValue("soulfulperk", 0));

			//Perk key 1
			pl->m_effectManager->updateCountForItem(8974, Mod::get()->getSavedValue("key1", 0));
			pl->updateCounters(8974, Mod::get()->getSavedValue("key1", 0));

			//Perk key 2
			pl->m_effectManager->updateCountForItem(8973, Mod::get()->getSavedValue("key2", 0));
			pl->updateCounters(8973, Mod::get()->getSavedValue("key2", 0));

			//Perk key 3
			pl->m_effectManager->updateCountForItem(8972, Mod::get()->getSavedValue("key3", 0));
			pl->updateCounters(8972, Mod::get()->getSavedValue("key3", 0));

			//Perk key 1 total
			pl->m_effectManager->updateCountForItem(8975, Mod::get()->getSavedValue("key1total", 0));
			pl->updateCounters(8975, Mod::get()->getSavedValue("key1total", 0));

			//Perk key 2 total
			pl->m_effectManager->updateCountForItem(8976, Mod::get()->getSavedValue("key2total", 0));
			pl->updateCounters(8976, Mod::get()->getSavedValue("key2total", 0));

			//Perk key 3 total
			pl->m_effectManager->updateCountForItem(8977, Mod::get()->getSavedValue("key3total", 0));
			pl->updateCounters(8977, Mod::get()->getSavedValue("key3total", 0));
			
			
			for (int i = 0; i < 40; i++) {
				pl->m_effectManager->updateCountForItem(i+1000, Mod::get()->getSavedValue(achievements[i], 0));
				pl->updateCounters(i+1000, Mod::get()->getSavedValue(achievements[i], 0));
			}
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

			//Perk Selected
			Mod::get()->setSavedValue<int>("equipedpos", pl->m_effectManager->countForItem(8998));

			//Charisma Perk
			Mod::get()->setSavedValue<int>("charismaperk", pl->m_effectManager->countForItem(8996));

			//Eye Spy perk
			Mod::get()->setSavedValue<int>("ispyperk", pl->m_effectManager->countForItem(8995));

			//Blast Process
			Mod::get()->setSavedValue<int>("blastperk", pl->m_effectManager->countForItem(8994));

			//Gambler perk
			Mod::get()->setSavedValue<int>("gamblerperk", pl->m_effectManager->countForItem(8993));

			//Shopping Addict perk
			Mod::get()->setSavedValue<int>("shopcompassperk", pl->m_effectManager->countForItem(8992));

			//Obsidian Skin perk
			Mod::get()->setSavedValue<int>("lavaperk", pl->m_effectManager->countForItem(8991));

			//Shoplifter perk
			Mod::get()->setSavedValue<int>("stealperk", pl->m_effectManager->countForItem(8990));

			//Speedballing perk
			Mod::get()->setSavedValue<int>("speedperk", pl->m_effectManager->countForItem(8989));
			
			//Big Man perk
			Mod::get()->setSavedValue<int>("bigmanperk", pl->m_effectManager->countForItem(8988));

			//Navigator perk
			Mod::get()->setSavedValue<int>("compassperk", pl->m_effectManager->countForItem(8987));

			//Curse of Greed perk
			Mod::get()->setSavedValue<int>("greedperk", pl->m_effectManager->countForItem(8986));

			//Rooted Step perk
			Mod::get()->setSavedValue<int>("rootedstepperk", pl->m_effectManager->countForItem(8985));

			//Interest perk
			Mod::get()->setSavedValue<int>("interestperk", pl->m_effectManager->countForItem(8984));

			//Rich perk
			Mod::get()->setSavedValue<int>("richperk", pl->m_effectManager->countForItem(8983));

			//Clearance perk
			Mod::get()->setSavedValue<int>("clearanceperk", pl->m_effectManager->countForItem(8982));

			//Surplus perk
			Mod::get()->setSavedValue<int>("surplusperk", pl->m_effectManager->countForItem(8981));

			//Demolitions Expert perk
			Mod::get()->setSavedValue<int>("bombperk", pl->m_effectManager->countForItem(8980));

			//Soulful perk
			Mod::get()->setSavedValue<int>("soulfulperk", pl->m_effectManager->countForItem(8979));

			//Perk key 1
			Mod::get()->setSavedValue<int>("key1", pl->m_effectManager->countForItem(8974));

			//Perk key 2
			Mod::get()->setSavedValue<int>("key2", pl->m_effectManager->countForItem(8973));

			//Perk key 3
			Mod::get()->setSavedValue<int>("key3", pl->m_effectManager->countForItem(8972));

			//Perk key 1 total
			Mod::get()->setSavedValue<int>("key1total", pl->m_effectManager->countForItem(8975));

			//Perk key 2 total
			Mod::get()->setSavedValue<int>("key2total", pl->m_effectManager->countForItem(8976));

			//Perk key 3 total
			Mod::get()->setSavedValue<int>("key3total", pl->m_effectManager->countForItem(8977));

			for (int i = 0; i < 40; i++) {
				Mod::get()->setSavedValue<int>(achievements[i], pl->m_effectManager->countForItem(i+1000));
			}
		}
	}
};
