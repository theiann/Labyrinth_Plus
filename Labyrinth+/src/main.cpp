

/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/binding/GJEffectManager.hpp>
#include <Geode/cocos/base_nodes/CCNode.h>
#include <Geode/binding/GJBaseGameLayer.hpp>

inline auto playlayer() { return GameManager::sharedState()->m_playLayer; }
/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;



#include <Geode/binding/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
class $modify(MyPlayerLayer, PlayLayer) {
	void setupHasCompleted(){
		PlayLayer::setupHasCompleted();
		PlayLayer* pl = playlayer();
		pl->m_effectManager->updateCountForItem(500, 1313);
		pl->updateCounters(500, 1313);
	}
};
