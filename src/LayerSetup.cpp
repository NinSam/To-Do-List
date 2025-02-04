#include <Geode/ui/GeodeUI.hpp>
#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool LayerSetup::init(){

		if (!CCMenu::init())

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
		auto screenSize = CCDirector::get()->getWinSize();

		// Menus

		auto menu = CCMenu::create();
		auto layout = CCMenu::create();
		auto smallbutton = CCMenu::create();

		this->addChild(smallbutton);
		smallbutton->setPosition({75,0 * relativescale});
		smallbutton->setScale(0.675f * relativescale);
		smallbutton->setID("small-buttons");
		smallbutton->setZOrder(2);
	
		this->addChild(menu);
		menu->setPosition({0,0 * relativescale});

		this->addChild(layout);
		layout->setPosition({0,35 * relativescale});
		layout->setScale(0.5f * relativescale);
		layout->setID("number-layout");
		layout->setZOrder(3);

		// bg

		CCScale9Sprite* bg = CCScale9Sprite::create("GJ_square01.png");
	    bg->setPosition(screenSize / 2);
		bg->setContentSize({213, 280 * relativescale});
		menu->addChild(bg);
		bg->setZOrder(-1);

        // Labels

		CCLabelBMFont* goldtext = CCLabelBMFont::create("To-Do List", "goldFont.fnt");
		goldtext->setPosition({289.5f, 278 * relativescale});
		menu->addChild(goldtext);
		goldtext->setScale(0.8f * relativescale);

		CCLabelBMFont* first = CCLabelBMFont::create("1.", "bigFont.fnt");
		first->setPosition({109, 207 * relativescale});
		first->setScale(0.7f * relativescale);
		layout->addChild(first);

		CCLabelBMFont* second = CCLabelBMFont::create("2.", "bigFont.fnt");
		second->setPosition({109, 167 * relativescale});
		second->setScale(0.7f * relativescale);
		layout->addChild(second);

		CCLabelBMFont* third = CCLabelBMFont::create("3.", "bigFont.fnt");
		third->setPosition({109, 127 * relativescale});
		third->setScale(0.7f * relativescale);
		layout->addChild(third);

		CCLabelBMFont* fourth = CCLabelBMFont::create("4.", "bigFont.fnt");
		fourth->setPosition({109, 87 * relativescale});
		fourth->setScale(0.7f * relativescale);
		layout->addChild(fourth);

		CCLabelBMFont* fifth = CCLabelBMFont::create("5.", "bigFont.fnt");
		fifth->setPosition({109, 47 * relativescale});
		fifth->setScale(0.7f * relativescale);
		layout->addChild(fifth);

		CCLabelBMFont* sixth = CCLabelBMFont::create("6.", "bigFont.fnt");
		sixth->setPosition({109, 7 * relativescale});
		sixth->setScale(0.7f * relativescale);
		layout->addChild(sixth);

		CCLabelBMFont* seventh = CCLabelBMFont::create("7.", "bigFont.fnt");
		seventh->setPosition({109, -33 * relativescale});
		seventh->setScale(0.7f * relativescale);
		layout->addChild(seventh);

		CCLabelBMFont* eighth = CCLabelBMFont::create("8.", "bigFont.fnt");
		eighth->setPosition({109, -73 * relativescale});
		eighth->setScale(0.7f * relativescale);
		layout->addChild(eighth);

		CCLabelBMFont* ninth = CCLabelBMFont::create("9.", "bigFont.fnt");
		ninth->setPosition({109, -113 * relativescale});
		ninth->setScale(0.7f * relativescale);
		layout->addChild(ninth);

		CCLabelBMFont* tenth = CCLabelBMFont::create("10.", "bigFont.fnt");
		tenth->setPosition({109, -153 * relativescale});
		tenth->setScale(0.7f * relativescale);
		layout->addChild(tenth);

		// Buttons

		CCMenuItemSpriteExtra* opensettings = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
			this,
			menu_selector(LayerSetup::OpenSettings)
		);
		smallbutton->addChild(opensettings);
		opensettings->setID("open-settings");
		opensettings->setPosition({297, 333 * relativescale});

		CCMenuItemSpriteExtra* info = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png"),
			this,
			menu_selector(LayerSetup::Info)
		);
		smallbutton->addChild(info);
		info->setID("info");
		info->setPosition({73, 332 * relativescale});


		// this
		
		this->setTouchEnabled(true);
		this->updateLayout();
		
		return true;

	}
	void LayerSetup::OpenSettings(CCObject*){
		geode::openSettingsPopup(Mod::get());
	}
	void LayerSetup::Info(CCObject*){
		FLAlertLayer::create("Info", "1. Level Name (Tabs). 2. Text Input. 3. Checkbox. 4. Priority (Low, Medium, High)", "OK")->show();
	}

	LayerSetup* LayerSetup::create(){
		auto ret = new LayerSetup;
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}