#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/modify/LevelTools.hpp>
#include <Geode/Enums.hpp>
#include "Geode/cocos/layers_scenes_transitions_nodes/CCTransition.h"
#include "World/ownWorldSelectLayer.h"
#include <iostream>
#include <filesystem>
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

static void openGDWorld(bool fromCreator = false) {
#ifdef GEODE_IS_WINDOWS
	g_returnToCreatorLayer = fromCreator;
	CCScene* scene = ownWorldSelectLayer::scene(0);
	if (fromCreator) {
		// replace the creator scene so that leaving World can put a fresh CreatorLayer back
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, scene));
	} else {
		CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));
	}
#endif

#ifdef GEODE_IS_ANDROID
	CCScene* scene = WorldSelectLayer::scene(0);
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));
#endif
}

void updateGroundColorM(CCSpriteBatchNode* batch, const cocos2d::ccColor3B& color)
{

	for (int i = 0; i < batch->getChildren()->count(); ++i) {
		auto sprite = (CCSprite*)batch->getChildren()->objectAtIndex(i);
		sprite->setColor(color);
		for (int o = 0; o < sprite->getChildren()->count(); ++o) {
			auto spriteChild = (CCSprite*)sprite->getChildren()->objectAtIndex(o);
			spriteChild->setColor(color);
		}
	}

}


class $modify(LoadingLayer)
{
	void loadAssets()
	{
		
		LoadingLayer::loadAssets();


		std::string zipFilePath;
			
		
		std::string unzipDir;
		

#ifdef GEODE_IS_WINDOWS


		zipFilePath = geode::Mod::get()->getResourcesDir().string() + "\\" + "SpinOffGames.zip";

		unzipDir = geode::Mod::get()->getResourcesDir().string() + "\\" + "SpinOffGames";

#endif
#ifdef GEODE_IS_ANDROID


		zipFilePath = geode::Mod::get()->getResourcesDir().string() + "/" + "SpinOffGames.zip";

		unzipDir = geode::Mod::get()->getResourcesDir().string() + "/" + "SpinOffGames";

#endif
		auto result = geode::utils::file::Unzip::intoDir(zipFilePath, unzipDir);
		
		CCFileUtils::get()->addTexturePack(CCTexturePack{
		  .m_id = this->getID(),
		  .m_paths = { unzipDir }
			});

		auto* textureCache = CCTextureCache::sharedTextureCache();
		auto* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();

		textureCache->addImage("WorldSheet.png", false);
		spriteFrameCache->addSpriteFramesWithFile("WorldSheet.plist");
		}

	
	
};

class $modify(LevelTools)
{
	static GJGameLevel* getLevel(int levelID, bool getString)
	{
		

		GJGameLevel* level = GJGameLevel::create();


		switch (levelID) {
		case 2001: //World
			level->m_levelName = getAudioTitle(27);
			level->m_audioTrack = 27;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 2;
			level->m_difficulty = GJDifficulty::Easy;
			break;
		case 2002:
			level->m_levelName = getAudioTitle(28);
			level->m_audioTrack = 28;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 2;
			level->m_difficulty = GJDifficulty::Easy;
			break;
		case 2003:
			level->m_levelName = getAudioTitle(29);
			level->m_audioTrack = 29;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2004:
			level->m_levelName = getAudioTitle(30);
			level->m_audioTrack = 30;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2005:
			level->m_levelName = getAudioTitle(31);
			level->m_audioTrack = 31;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2006:
			level->m_levelName = getAudioTitle(32);
			level->m_audioTrack = 32;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2007:
			level->m_levelName = getAudioTitle(33);
			level->m_audioTrack = 33;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2008:
			level->m_levelName = getAudioTitle(34);
			level->m_audioTrack = 34;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2009:
			level->m_levelName = getAudioTitle(35);
			level->m_audioTrack = 35;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2010:
			level->m_levelName = getAudioTitle(36);
			level->m_audioTrack = 36;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		default:
		
			return LevelTools::getLevel(levelID, getString);
		}

		level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);

		return level;
	}

	
};

class $modify(CreatorLayer) {
	bool init() {

		if (!CreatorLayer::init()) {
			return false;
		};

		auto menu = this->getChildByID("creator-buttons-menu");

		auto sprmap = CCSprite::createWithSpriteFrameName("GJ_mapBtn_001.png");

		std::map<std::string, CCSprite*> idsToBtns = {
			{ "map-button", sprmap },
		};
		
		for (auto pair = idsToBtns.begin(); pair != idsToBtns.end(); pair++) {
			auto id = pair->first.c_str();
			auto superExpertLoaded = ((strcmp("map-button", id) == 0) && (Loader::get()->isModLoaded("xanii.super_expert")));

			if (!menu->getChildByID(id)) continue;

			auto btn = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID(id));
			auto contentSize = btn->getContentSize();
			auto existingSprite = btn->getChildByType<CCSprite*>(0);

			if (!existingSprite) continue;

			auto scale = existingSprite->getScale();
			pair->second->setScale(scale);

			if (!superExpertLoaded) {
				btn->setNormalImage(pair->second);
			};

			btn->setContentSize(contentSize);

		};

		return true;
	};

	void onAdventureMap(CCObject*) {
		openGDWorld(true);
	};
};

class $modify(GJGarageLayer) {
	bool init() {
		auto back = Mod::get()->getSavedValue<int>("onsubzero");
		back = 10;
		Mod::get()->setSavedValue("onsubzero", back);
		return GJGarageLayer::init();
	}

	void onBack(cocos2d::CCObject* sender)
	{
		auto pages = Mod::get()->getSavedValue<int>("onworldpages");

		auto World = ownWorldSelectLayer::create(0);
		auto scene = CCScene::create();

		scene->addChild(World);
		
		if (pages != 0 && pages != 10)
		{
			auto transitionScene = CCScene::create(); 

			
			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
			CCActionInterval* moveUp = CCMoveBy::create(0.23f, ccp(0, winSize.height));
			this->runAction(moveUp);

			if (pages == 1) {
				World->m_scrollLayer->instantMoveToPage(0);
				World->m_background->setColor(GameManager::sharedState()->colorForIdx(4));
			}
			else if (pages == 2) {
				World->m_scrollLayer->instantMoveToPage(1);
				World->m_background->setColor(GameManager::sharedState()->colorForIdx(6));
			}
			else if (pages == 3) {
			 //page 3 is bug bc BoomScrollLayer is sucks
			}

			auto transition = CCTransitionMoveInB::create(0.31f, scene);

		
			CCActionInterval* moveDown = CCMoveBy::create(0.5f, ccp(0, -winSize.height));
			transitionScene->runAction(moveDown);

			scene->setZOrder(1);
			this->setZOrder(2);
			transition->setZOrder(1);
			transitionScene->setZOrder(2);
			CCDirector::sharedDirector()->pushScene(transitionScene);
			CCDirector::sharedDirector()->pushScene(transition);
		}
		
		else
		{
			GJGarageLayer::onBack(sender);
		}
		
		
	}
	
};

class $modify(PauseLayer) {
	void onQuit(CCObject* sender) {

		auto GM = GameManager::sharedState();

		
		if (GM->m_playLayer->m_level->m_levelID > 2000 && GM->m_playLayer->m_level->m_levelID < 2011)
		{
		
			auto levelID = GM->m_playLayer->m_level->m_levelID;
		
			auto specificWorldScene = ownWorldSelectLayer::create(0);
			auto scene = CCScene::create();
#ifdef GEODE_IS_WINDOWS

			int colorID = 0;

			
			if (levelID > 2000 && levelID < 2006) {
				specificWorldScene->m_scrollLayer->instantMoveToPage(0);
				colorID = 4;
			}
			else if (levelID > 2005 && levelID < 2011) {
				specificWorldScene->m_scrollLayer->instantMoveToPage(1);
				colorID = 6;
			}

			specificWorldScene->m_background->setColor(GameManager::sharedState()->colorForIdx(colorID));
			scene->addChild(specificWorldScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
#endif

#ifdef GEODE_IS_ANDROID

			int colorID = 0;
			auto worldScene = WorldSelectLayer::create(0);
			
			if (levelID > 2000 && levelID < 2006) {
				worldScene = WorldSelectLayer::create(0);
				colorID = 4;
			}
			else if (levelID > 2005 && levelID < 2011) {
				worldScene = WorldSelectLayer::create(1);
				colorID = 6;
			}
			else {
				worldScene = WorldSelectLayer::create(0); // Valor por defecto
			}

			scene->addChild(worldScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
#endif

			PauseLayer::onQuit(sender);
			
		}

		PauseLayer::onQuit(sender);
	}

	

};

class $modify(EndLevelLayer) {
	void onMenu(CCObject * sender) {
	
		auto GM = GameManager::sharedState();


		if (GM->m_playLayer->m_level->m_levelID > 2000 && GM->m_playLayer->m_level->m_levelID < 2011)
		{
			
			auto levelID = GM->m_playLayer->m_level->m_levelID;
			auto specificWorldScene = ownWorldSelectLayer::create(0);
			auto scene = CCScene::create();
#ifdef GEODE_IS_WINDOWS

			int colorID = 0;

			if (levelID > 2000 && levelID < 2006) {
				specificWorldScene->m_scrollLayer->instantMoveToPage(0);
				colorID = 4;
			}
			else if (levelID > 2005 && levelID < 2011) {
				specificWorldScene->m_scrollLayer->instantMoveToPage(1);
				colorID = 6;
			}

			specificWorldScene->m_background->setColor(GameManager::sharedState()->colorForIdx(colorID));
			scene->addChild(specificWorldScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
#endif

#ifdef GEODE_IS_ANDROID

			int colorID = 0;
			auto worldScene = WorldSelectLayer::create(0);
			if (levelID > 2000 && levelID < 2006) {
				worldScene = WorldSelectLayer::create(0);
				colorID = 4;
			}
			else if (levelID > 2005 && levelID < 2011) {
				worldScene = WorldSelectLayer::create(1);
				colorID = 6;
			}
			else {
				worldScene = WorldSelectLayer::create(0);
			}

			scene->addChild(worldScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
#endif

			EndLevelLayer::onMenu(sender);	
		}
		
		EndLevelLayer::onMenu(sender);
	}
};
