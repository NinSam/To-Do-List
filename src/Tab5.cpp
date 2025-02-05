#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool Tab5::init(){

		if (!CCMenu::init())

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
		auto screenSize = CCDirector::get()->getWinSize();

		// Menus

		auto menu = CCMenu::create();
		auto layout = CCMenu::create();
		auto tabs = CCMenu::create();

		this->addChild(tabs);
		tabs->setPosition({54,21});
        tabs->setScale(0.8f * relativescale);
	    tabs->setZOrder(2);
		tabs->setID("tabs");
	
		this->addChild(menu);
		menu->setPosition({0,0});

		this->addChild(layout);
		layout->setPosition({0,35});
		layout->setScale(0.5f * relativescale);
		layout->setID("layout");
		layout->setZOrder(3);


		// Level Name (Tabs)

		TextInput* inputname_1 = TextInput::create(100,"5/5","bigFont.fnt");
		inputname_1->setPosition({217.5f, 243});
		inputname_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-1-tab-5", "")));
		inputname_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-1-tab-5", str));
		
		});
		tabs->addChild(inputname_1);


		// TextInputs

		TextInput* input_1 = TextInput::create(200,"","bigFont.fnt");
		input_1->setPosition({231,205});
		input_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-1-tab-5", "")));
		input_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-1-tab-5", str));
		
		});
		layout->addChild(input_1);

		TextInput* input_2 = TextInput::create(200,"","bigFont.fnt");
		input_2->setPosition({231,164.5f});
		input_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-2-tab-5", "")));
		input_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-2-tab-5", str));
		
		});
		layout->addChild(input_2);

		TextInput* input_3 = TextInput::create(200,"","bigFont.fnt");
		input_3->setPosition({231,124});
		input_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-3-tab-5", "")));
		input_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-3-tab-5", str));
		
		});
		layout->addChild(input_3);

		TextInput* input_4 = TextInput::create(200,"","bigFont.fnt");
		input_4->setPosition({231,84.5f});
		input_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-4-tab-5", "")));
		input_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-4-tab-5", str));
		
		});
		layout->addChild(input_4);

		TextInput* input_5 = TextInput::create(200,"","bigFont.fnt");
		input_5->setPosition({231,45});
		input_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-5-tab-5", "")));
		input_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-5-tab-5", str));
		
		});
		layout->addChild(input_5);

		TextInput* input_6 = TextInput::create(200,"","bigFont.fnt");
		input_6->setPosition({231,7});
		input_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-6-tab-5", "")));
		input_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-6-tab-5", str));
		
		});
		layout->addChild(input_6);

		TextInput* input_7 = TextInput::create(200,"","bigFont.fnt");
		input_7->setPosition({231,-33});
		input_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-7-tab-5", "")));
		input_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-7-tab-5", str));
		
		});
		layout->addChild(input_7);

		TextInput* input_8 = TextInput::create(200,"","bigFont.fnt");
		input_8->setPosition({231,-73});
		input_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-8-tab-5", "")));
		input_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-8-tab-5", str));
		
		});
		layout->addChild(input_8);

		TextInput* input_9 = TextInput::create(200,"","bigFont.fnt");
		input_9->setPosition({231,-113});
		input_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-9-tab-5", "")));
		input_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-9-tab-5", str));
		
		});
		layout->addChild(input_9);

		TextInput* input_10 = TextInput::create(200,"","bigFont.fnt");
		input_10->setPosition({231,-153});
		input_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-10-tab-5", "")));
		input_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-10-tab-5", str));
		
		});
		layout->addChild(input_10);


		// Priority

        TextInput* input_priority_1 = TextInput::create(50,"","bigFont.fnt");
		input_priority_1->setPosition({435,205});
		input_priority_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-one-tab-5", "")));
		input_priority_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-one-tab-5", str));
		
		});
		layout->addChild(input_priority_1);

        TextInput* input_priority_2 = TextInput::create(50,"","bigFont.fnt");
		input_priority_2->setPosition({435,164.5f});
		input_priority_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-two-tab-5", "")));
		input_priority_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-two-tab-5", str));
		
		});
		layout->addChild(input_priority_2);

        TextInput* input_priority_3 = TextInput::create(50,"","bigFont.fnt");
		input_priority_3->setPosition({435,124});
		input_priority_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-three-tab-5", "")));
		input_priority_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-three-tab-5", str));
		
		});
		layout->addChild(input_priority_3);

        TextInput* input_priority_4 = TextInput::create(50,"","bigFont.fnt");
		input_priority_4->setPosition({435,84.5f});
		input_priority_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-four-tab-5", "")));
		input_priority_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-four-tab-5", str));
		
		});
		layout->addChild(input_priority_4);

        TextInput* input_priority_5 = TextInput::create(50,"","bigFont.fnt");
		input_priority_5->setPosition({435,45});
		input_priority_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-five-tab-5", "")));
		input_priority_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-five-tab-5", str));
		
		});
		layout->addChild(input_priority_5);

		TextInput* input_priority_6 = TextInput::create(50,"","bigFont.fnt");
		input_priority_6->setPosition({435,7});
		input_priority_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-six-tab-5", "")));
		input_priority_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-sixv", str));
		
		});
		layout->addChild(input_priority_6);

        TextInput* input_priority_7 = TextInput::create(50,"","bigFont.fnt");
		input_priority_7->setPosition({435,-33});
		input_priority_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-seven-tab-5", "")));
		input_priority_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-seven-tab-5", str));
		
		});
		layout->addChild(input_priority_7);

        TextInput* input_priority_8 = TextInput::create(50,"","bigFont.fnt");
		input_priority_8->setPosition({435,-73});
		input_priority_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-eight-tab-5", "")));
		input_priority_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-eight-tab-5", str));
		
		});
		layout->addChild(input_priority_8);

        TextInput* input_priority_9 = TextInput::create(50,"","bigFont.fnt");
		input_priority_9->setPosition({435,-113});
		input_priority_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-nine-tab-5", "")));
		input_priority_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-nine-tab-5", str));
		
		});
		layout->addChild(input_priority_9);

        TextInput* input_priority_10 = TextInput::create(50,"","bigFont.fnt");
		input_priority_10->setPosition({435,-153});
		input_priority_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-ten-tab-5", "")));
		input_priority_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-ten-tab-5", str));
		
		});
		layout->addChild(input_priority_10);

		

		// Checkboxes

		CCMenuItemToggler* toggle = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox),1);
		layout->addChild(toggle);
		toggle->setPosition({371, 205});
		toggle->toggle(Mod::get()->getSavedValue<bool>("checkbox-tab-5", false));

		CCMenuItemToggler* toggle_2 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox2),1);
		toggle_2->toggle(false);
		layout->addChild(toggle_2);
		toggle_2->setPosition({371, 164.5f});
		toggle_2->toggle(Mod::get()->getSavedValue<bool>("checkbox-2-tab-5", false));

		CCMenuItemToggler* toggle_3 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox3),1);
		toggle_3->toggle(false);
		layout->addChild(toggle_3);
		toggle_3->setPosition({371, 124});
		toggle_3->toggle(Mod::get()->getSavedValue<bool>("checkbox-3-tab-5", false));

		CCMenuItemToggler* toggle_4 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox4),1);
		toggle_4->toggle(false);
		layout->addChild(toggle_4);
		toggle_4->setPosition({371, 84.5f});
		toggle_4->toggle(Mod::get()->getSavedValue<bool>("checkbox-4-tab-5", false));

		CCMenuItemToggler* toggle_5 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox5),1);
		toggle_5->toggle(false);
		layout->addChild(toggle_5);
		toggle_5->setPosition({371, 45});
		toggle_5->toggle(Mod::get()->getSavedValue<bool>("checkbox-5-tab-5", false));

		CCMenuItemToggler* toggle_6 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox6),1);
		layout->addChild(toggle_6);
		toggle_6->setPosition({371, 7});
		toggle_6->toggle(Mod::get()->getSavedValue<bool>("checkbox-6-tab-5", false));

		CCMenuItemToggler* toggle_7 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox7),1);
		toggle_7->toggle(false);
		layout->addChild(toggle_7);
		toggle_7->setPosition({371, -33});
		toggle_7->toggle(Mod::get()->getSavedValue<bool>("checkbox-7-tab-5", false));

		CCMenuItemToggler* toggle_8 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox8),1);
		toggle_8->toggle(false);
		layout->addChild(toggle_8);
		toggle_8->setPosition({371, -73});
		toggle_8->toggle(Mod::get()->getSavedValue<bool>("checkbox-8-tab-5", false));

		CCMenuItemToggler* toggle_9 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox9),1);
		toggle_9->toggle(false);
		layout->addChild(toggle_9);
		toggle_9->setPosition({371, -113});
		toggle_9->toggle(Mod::get()->getSavedValue<bool>("checkbox-9-tab-5", false));

		CCMenuItemToggler* toggle_10 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab5::SaveCheckbox10),1);
		toggle_10->toggle(false);
		layout->addChild(toggle_10);
		toggle_10->setPosition({371, -153});
		toggle_10->toggle(Mod::get()->getSavedValue<bool>("checkbox-10-tab-5", false));


		// this
		
		this->setKeypadEnabled(true);
		this->setTouchEnabled(true);
		this->updateLayout();
		
		return true;

	}

	void Tab5::SaveCheckbox(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-tab-5", false));;
	}
	void Tab5::SaveCheckbox2(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-2-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-2-tab-5", false));
	}
	void Tab5::SaveCheckbox3(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-3-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-3-tab-5", false));
	}
	void Tab5::SaveCheckbox4(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-4-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-4-tab-5", false));
	}
	void Tab5::SaveCheckbox5(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-5-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-5-tab-5", false));
	}
	void Tab5::SaveCheckbox6(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-6-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-6-tab-5", false));
	}
	void Tab5::SaveCheckbox7(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-7-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-7-tab-5", false));
	}
	void Tab5::SaveCheckbox8(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-8-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-8-tab-5", false));
	}
	void Tab5::SaveCheckbox9(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-9-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-9-tab-5", false));
	}
	void Tab5::SaveCheckbox10(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-10-tab-5", !Mod::get()->getSavedValue<bool>("checkbox-10-tab-5", false));
	}

	Tab5* Tab5::create(){
		auto ret = new Tab5;
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}