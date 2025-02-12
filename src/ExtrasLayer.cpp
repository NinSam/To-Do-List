#include <Geode/ui/GeodeUI.hpp>
#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool ExtrasLayer::init(){

		if (!FLAlertLayer::init(50))

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();

		auto screenSize = CCDirector::sharedDirector()->getWinSize();

        // menu
	

		auto extramenu = CCMenu::create();
        auto extrasmallbtns = CCMenu::create();

		this->addChild(extramenu);
		extramenu->setPosition(0,0);
		extramenu->setID("extras");
		extramenu->setTouchPriority(-507);

		this->addChild(extrasmallbtns);
		extrasmallbtns->setPosition(0,0);
		extrasmallbtns->setScale(0.6f);
		extrasmallbtns->setID("settings");
		extrasmallbtns->setTouchPriority(-507);

		// bg

		auto extrabg = CCScale9Sprite::create("square01_001.png");
		extrabg->setPosition(screenSize/2 + CCPoint{179,59.5f});
		extrabg->setContentSize({108, 161});
		extramenu->addChild(extrabg);
	
		// buttons
		
        auto extrabutton = CCMenuItemSpriteExtra::create(
			ButtonSprite::create("Back"),
			this,
			menu_selector(ExtrasLayer::Close)
		);

		extrabutton->setPosition(screenSize/2 + CCPoint{180, 108});
		extramenu->addChild(extrabutton);


        auto extrasettings = CCMenuItemSpriteExtra::create(
			ButtonSprite::create("Settings"),
			this,
			menu_selector(ExtrasLayer::OpenSettings)
		);

		extrasettings->setPosition(screenSize/2 + CCPoint{299, 99});
		extrasmallbtns->addChild(extrasettings);

        auto extrainfo = CCMenuItemSpriteExtra::create(
			ButtonSprite::create("Info"),
			this,
			menu_selector(ExtrasLayer::Info)
		);

		extrainfo->setPosition(screenSize/2 + CCPoint{180, 10});
		extramenu->addChild(extrainfo);


		// this
		
		this->setTouchEnabled(true);
		this->updateLayout();
		
		return true;

	}
	void ExtrasLayer::Close(CCObject* sender){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
	}
	void ExtrasLayer::OpenSettings(CCObject*){
        geode::openSettingsPopup(Mod::get());
	}
	void ExtrasLayer::Info(CCObject*){
		FLAlertLayer::create("Info", "5 tabs (Level Name). 10 text inputs per tab, 10 checkboxes per tab, and 10 priorities per tab (Example: Low, Medium, High).", "OK")->show();
	}

	ExtrasLayer* ExtrasLayer::create(){
		auto ret = new ExtrasLayer;
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}