#include <Geode/ui/GeodeUI.hpp>
#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool ExtrasLayer::init(){

		if (!FLAlertLayer::init(0))

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
		auto screenSize = CCDirector::sharedDirector()->getWinSize();

        // menu
	

		auto extramenu = CCMenu::create();
        auto extrasmallbtns = CCMenu::create();

		this->addChild(extramenu);
		extramenu->setPosition(ccp(0,0));
		extramenu->setID("extras");


		this->addChild(extrasmallbtns);
		extrasmallbtns->setPosition(ccp(0,0));
		extrasmallbtns->setScale(0.7f * relativescale);

		auto extrabg = CCScale9Sprite::create("GJ_square01.png");
		extrabg->setPosition(screenSize/2 + CCPoint{179,59.5f});
		extrabg->setContentSize({108, 161});
		extramenu->addChild(extrabg);

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

		extrasettings->setPosition(screenSize/2 + CCPoint{256, 84});
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
	void ExtrasLayer::Close(CCObject*){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
	}
	void ExtrasLayer::OpenSettings(CCObject*){
        geode::openSettingsPopup(Mod::get());
	}
	void ExtrasLayer::Info(CCObject*){
		FLAlertLayer::create("Info", "1. Level Name (Tabs). 2. Text Input. 3. Checkbox. 4. Priority (Low, Medium, High).", "OK")->show();
	}

	//geode::openSettingsPopup(Mod::get());

	ExtrasLayer* ExtrasLayer::create(){
		auto ret = new ExtrasLayer;
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}