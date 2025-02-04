#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool Tab1::init(){

		if (!FLAlertLayer::init(150))

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();
		m_noElasticity = true;


		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
		auto screenSize = CCDirector::get()->getWinSize();


		// Menus

		auto layersetup = LayerSetup::create();
		this->addChild(layersetup);
		layersetup->setPosition({0,0 * relativescale});
		layersetup->setID("setup");


		auto menu = CCMenu::create();
		auto layout = CCMenu::create();
		auto tabs = CCMenu::create();

		this->addChild(tabs);
		tabs->setPosition({54,21 * relativescale});
        tabs->setScale(0.8f * relativescale);
	    tabs->setZOrder(2);
		tabs->setID("tabs");
	
		this->addChild(menu);
		menu->setPosition({0,0 * relativescale});

		this->addChild(layout);
		layout->setPosition({0,35});
		layout->setScale(0.5f * relativescale);
		layout->setID("layout");
		layout->setZOrder(3);
	

		// Buttons
		
		CCMenuItemSpriteExtra* closebutton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(Tab1::CloseTab)
		);
		menu->addChild(closebutton);
		closebutton->setID("close-button");
		closebutton->setPosition({180, 295 * relativescale});


		// Level Name (Tabs)

		TextInput* inputname_1 = TextInput::create(100,"1/5","bigFont.fnt");
		inputname_1->setPosition({217.5f, 243 * relativescale});
		inputname_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-1-tab-1", "")));
		inputname_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-1-tab-1", str));
		
		});
		tabs->addChild(inputname_1);


		// TextInputs

		TextInput* input_1 = TextInput::create(200,"","bigFont.fnt");
		input_1->setPosition({screenSize - CCPoint {338, 115}});
		input_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-1-tab-1", "")));
		input_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-1-tab-1", str)); // finally figured it out after "insert" attempts I have on Spectre
		
		});
		layout->addChild(input_1);

		TextInput* input_2 = TextInput::create(200,"","bigFont.fnt");
		input_2->setPosition({231,164.5f * relativescale});
		input_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-2-tab-1", "")));
		input_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-2-tab-1", str));
		
		});
		layout->addChild(input_2);

		TextInput* input_3 = TextInput::create(200,"","bigFont.fnt");
		input_3->setPosition({231,124 * relativescale});
		input_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-3-tab-1", "")));
		input_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-3-tab-1", str));
		
		});
		layout->addChild(input_3);

		TextInput* input_4 = TextInput::create(200,"","bigFont.fnt");
		input_4->setPosition({231,84.5f * relativescale});
		input_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-4-tab-1", "")));
		input_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-4-tab-1", str));
		
		});
		layout->addChild(input_4);

		TextInput* input_5 = TextInput::create(200,"","bigFont.fnt");
		input_5->setPosition({231,45 * relativescale});
		input_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-5-tab-1", "")));
		input_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-5-tab-1", str));
		
		});
		layout->addChild(input_5);

		TextInput* input_6 = TextInput::create(200,"","bigFont.fnt");
		input_6->setPosition({231,7 * relativescale});
		input_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-6-tab-1", "")));
		input_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-6-tab-1", str));
		
		});
		layout->addChild(input_6);

		TextInput* input_7 = TextInput::create(200,"","bigFont.fnt");
		input_7->setPosition({231,-33 * relativescale});
		input_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-7-tab-1", "")));
		input_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-7-tab-1", str));
		
		});
		layout->addChild(input_7);

		TextInput* input_8 = TextInput::create(200,"","bigFont.fnt");
		input_8->setPosition({231,-73 * relativescale});
		input_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-8-tab-1", "")));
		input_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-8-tab-1", str));
		
		});
		layout->addChild(input_8);

		TextInput* input_9 = TextInput::create(200,"","bigFont.fnt");
		input_9->setPosition({231,-113 * relativescale});
		input_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-9-tab-1", "")));
		input_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-9-tab-1", str));
		
		});
		layout->addChild(input_9);

		TextInput* input_10 = TextInput::create(200,"","bigFont.fnt");
		input_10->setPosition({231,-153 * relativescale});
		input_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-10-tab-1", "")));
		input_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-10-tab-1", str));
		
		});
		layout->addChild(input_10);


		// Priority

        TextInput* input_priority_1 = TextInput::create(50,"","bigFont.fnt");
		input_priority_1->setPosition({435,205 * relativescale});
		input_priority_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-one-tab-1", "")));
		input_priority_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-one-tab-1", str));
		
		});
		layout->addChild(input_priority_1);

        TextInput* input_priority_2 = TextInput::create(50,"","bigFont.fnt");
		input_priority_2->setPosition({435,164.5f * relativescale});
		input_priority_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-two-tab-1", "")));
		input_priority_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-two-tab-1", str));
		
		});
		layout->addChild(input_priority_2);

        TextInput* input_priority_3 = TextInput::create(50,"","bigFont.fnt");
		input_priority_3->setPosition({435,124 * relativescale});
		input_priority_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-three-tab-1", "")));
		input_priority_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-three-tab-1", str));
		
		});
		layout->addChild(input_priority_3);

        TextInput* input_priority_4 = TextInput::create(50,"","bigFont.fnt");
		input_priority_4->setPosition({435,84.5f * relativescale});
		input_priority_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-four-tab-1", "")));
		input_priority_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-four-tab-1", str));
		
		});
		layout->addChild(input_priority_4);

        TextInput* input_priority_5 = TextInput::create(50,"","bigFont.fnt");
		input_priority_5->setPosition({435,45 * relativescale});
		input_priority_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-five-tab-1", "")));
		input_priority_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-five-tab-1", str));
		
		});
		layout->addChild(input_priority_5);

		TextInput* input_priority_6 = TextInput::create(50,"","bigFont.fnt");
		input_priority_6->setPosition({435,7 * relativescale});
		input_priority_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-six-tab-1", "")));
		input_priority_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-six-tab-1", str));
		
		});
		layout->addChild(input_priority_6);

        TextInput* input_priority_7 = TextInput::create(50,"","bigFont.fnt");
		input_priority_7->setPosition({435,-33 * relativescale});
		input_priority_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-seven-tab-1", "")));
		input_priority_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-seven-tab-1", str));
		
		});
		layout->addChild(input_priority_7);

        TextInput* input_priority_8 = TextInput::create(50,"","bigFont.fnt");
		input_priority_8->setPosition({435,-73 * relativescale});
		input_priority_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-eight-tab-1", "")));
		input_priority_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-eight-tab-1", str));
		
		});
		layout->addChild(input_priority_8);

        TextInput* input_priority_9 = TextInput::create(50,"","bigFont.fnt");
		input_priority_9->setPosition({435,-113 * relativescale});
		input_priority_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-nine-tab-1", "")));
		input_priority_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-nine-tab-1", str));
		
		});
		layout->addChild(input_priority_9);

        TextInput* input_priority_10 = TextInput::create(50,"","bigFont.fnt");
		input_priority_10->setPosition({435,-153 * relativescale});
		input_priority_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-ten-tab-1", "")));
		input_priority_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-ten-tab-1", str));
		
		});
		layout->addChild(input_priority_10);

		

		// Checkboxes

		CCMenuItemToggler* toggle = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox),1);
		layout->addChild(toggle);
		toggle->setPosition({371, 205 * relativescale});
		toggle->toggle(Mod::get()->getSavedValue<bool>("checkbox-tab-1", false));

		CCMenuItemToggler* toggle_2 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox2),1);
		toggle_2->toggle(false);
		layout->addChild(toggle_2);
		toggle_2->setPosition({371, 164.5f * relativescale});
		toggle_2->toggle(Mod::get()->getSavedValue<bool>("checkbox-2-tab-1", false));

		CCMenuItemToggler* toggle_3 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox3),1);
		toggle_3->toggle(false);
		layout->addChild(toggle_3);
		toggle_3->setPosition({371, 124 * relativescale});
		toggle_3->toggle(Mod::get()->getSavedValue<bool>("checkbox-3-tab-1", false));

		CCMenuItemToggler* toggle_4 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox4),1);
		toggle_4->toggle(false);
		layout->addChild(toggle_4);
		toggle_4->setPosition({371, 84.5f * relativescale});
		toggle_4->toggle(Mod::get()->getSavedValue<bool>("checkbox-4-tab-1", false));

		CCMenuItemToggler* toggle_5 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox5),1);
		toggle_5->toggle(false);
		layout->addChild(toggle_5);
		toggle_5->setPosition({371, 45 * relativescale});
		toggle_5->toggle(Mod::get()->getSavedValue<bool>("checkbox-5-tab-1", false));

		CCMenuItemToggler* toggle_6 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox6),1);
		layout->addChild(toggle_6);
		toggle_6->setPosition({371, 7 * relativescale});
		toggle_6->toggle(Mod::get()->getSavedValue<bool>("checkbox-6-tab-1", false));

		CCMenuItemToggler* toggle_7 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox7),1);
		toggle_7->toggle(false);
		layout->addChild(toggle_7);
		toggle_7->setPosition({371, -33 * relativescale});
		toggle_7->toggle(Mod::get()->getSavedValue<bool>("checkbox-7-tab-1", false));

		CCMenuItemToggler* toggle_8 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox8),1);
		toggle_8->toggle(false);
		layout->addChild(toggle_8);
		toggle_8->setPosition({371, -73 * relativescale});
		toggle_8->toggle(Mod::get()->getSavedValue<bool>("checkbox-8-tab-1", false));

		CCMenuItemToggler* toggle_9 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox9),1);
		toggle_9->toggle(false);
		layout->addChild(toggle_9);
		toggle_9->setPosition({371, -113 * relativescale});
		toggle_9->toggle(Mod::get()->getSavedValue<bool>("checkbox-9-tab-1", false));

		CCMenuItemToggler* toggle_10 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox10),1);
		toggle_10->toggle(false);
		layout->addChild(toggle_10);
		toggle_10->setPosition({371, -153 * relativescale});
		toggle_10->toggle(Mod::get()->getSavedValue<bool>("checkbox-10-tab-1", false));
	

		// Arrows

		CCMenuItemSpriteExtra* page_left = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(Tab1::PreviousTab)
		);
		tabs->addChild(page_left);
		page_left->setPosition({151, 242 * relativescale});

		CCMenuItemSpriteExtra* page_right = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_rightBtn_001.png"),
			this,
			menu_selector(Tab1::NextTab)
		);
		tabs->addChild(page_right);
		page_right->setPosition({284, 242 * relativescale});


		// this
		
		this->setKeypadEnabled(true);
		this->setTouchEnabled(true);
		this->updateLayout();
		
		return true;

	}
	void Tab1::CloseTab(CCObject*){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
 	}
	void Tab1::PreviousTab(CCObject*){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
		Tab5::create()->show();
	}
	void Tab1::NextTab(CCObject*){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
		Tab2::create()->show();
	}
		
	// not sure if was doing this right because it just turns all of them on/off if one of them is enabled/disabled

	void Tab1::SaveCheckbox(CCObject* sender){
		auto get = Mod::get()->setSavedValue<bool>("checkbox-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-tab-1", false));;
	}
	void Tab1::SaveCheckbox2(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-2-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-2-tab-1", false));
	}
	void Tab1::SaveCheckbox3(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-3-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-3-tab-1", false));
	}
	void Tab1::SaveCheckbox4(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-4-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-4-tab-1", false));
	}
	void Tab1::SaveCheckbox5(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-5-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-5-tab-1", false));
	}
	void Tab1::SaveCheckbox6(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-6-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-6-tab-1", false));
	}
	void Tab1::SaveCheckbox7(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-7-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-7-tab-1", false));
	}
	void Tab1::SaveCheckbox8(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-8-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-8-tab-1", false));
	}
	void Tab1::SaveCheckbox9(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-9-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-9-tab-1", false));
	}
	void Tab1::SaveCheckbox10(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-10-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-10-tab-1", false));
	}

	Tab1* Tab1::create(){
		auto ret = new Tab1;
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}