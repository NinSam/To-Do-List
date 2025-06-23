#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool Tab1::init(){

		if (!CCMenu::init())

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();

		auto screenSize = CCDirector::sharedDirector()->getWinSize();


		// Menus


		auto layout = CCMenu::create();
		layout->setPosition(0,0);
		this->addChild(layout);
	

		// TextInputs

		std::string str;
		std::string str2;
		std::string str3;
		std::string str4;
		std::string str5;
		std::string str6;

		if (!Mod::get()->setSavedValue("one-time-example", true)){

			str = "Low";
			str2 = "Med";
			str3 = "High";

			str4 = "Add pulses at 82-90%";
			str5 = "Add glow in the BG";
			str6 = "Optimize 40-52%";

		}

		TextInput* input_1 = TextInput::create(200,str4,"bigFont.fnt");
		input_1->setPosition(153, 234);
		input_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-1-tab-1", "")));
		input_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-1-tab-1", str));
		
		});
		layout->addChild(input_1);

		TextInput* input_2 = TextInput::create(200,str5,"bigFont.fnt");
		input_2->setPosition(153,194);
		input_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-2-tab-1", "")));
		input_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-2-tab-1", str));
		
		});
		layout->addChild(input_2);

		TextInput* input_3 = TextInput::create(200,str6,"bigFont.fnt");
		input_3->setPosition(153,154);
		input_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-3-tab-1", "")));
		input_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-3-tab-1", str));
		
		});
		layout->addChild(input_3);

		TextInput* input_4 = TextInput::create(200,"","bigFont.fnt");
		input_4->setPosition(153,114);
		input_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-4-tab-1", "")));
		input_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-4-tab-1", str));
		
		});
		layout->addChild(input_4);

		TextInput* input_5 = TextInput::create(200,"","bigFont.fnt");
		input_5->setPosition(153,74);
		input_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-5-tab-1", "")));
		input_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-5-tab-1", str));
		
		});
		layout->addChild(input_5);

		TextInput* input_6 = TextInput::create(200,"","bigFont.fnt");
		input_6->setPosition(153,34);
		input_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-6-tab-1", "")));
		input_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-6-tab-1", str));
		
		});
		layout->addChild(input_6);

		TextInput* input_7 = TextInput::create(200,"","bigFont.fnt");
		input_7->setPosition(153,-6);
		input_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-7-tab-1", "")));
		input_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-7-tab-1", str));
		
		});
		layout->addChild(input_7);

		TextInput* input_8 = TextInput::create(200,"","bigFont.fnt");
		input_8->setPosition(153,-46);
		input_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-8-tab-1", "")));
		input_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-8-tab-1", str));
		
		});
		layout->addChild(input_8);

		TextInput* input_9 = TextInput::create(200,"","bigFont.fnt");
		input_9->setPosition(153,-86);
		input_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-9-tab-1", "")));
		input_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-9-tab-1", str));
		
		});
		layout->addChild(input_9);

		TextInput* input_10 = TextInput::create(200,"","bigFont.fnt");
		input_10->setPosition(153,-126);
		input_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-10-tab-1", "")));
		input_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-10-tab-1", str));
		
		});
		layout->addChild(input_10);


		// Priority

        TextInput* input_priority_1 = TextInput::create(50,str,"bigFont.fnt");
		input_priority_1->setPosition(395,234);
		input_priority_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-one-tab-1", "")));
		input_priority_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-one-tab-1", str));
		
		});
		layout->addChild(input_priority_1);

        TextInput* input_priority_2 = TextInput::create(50,str2,"bigFont.fnt");
		input_priority_2->setPosition(395,194);
		input_priority_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-two-tab-1", "")));
		input_priority_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-two-tab-1", str));
		
		});
		layout->addChild(input_priority_2);

        TextInput* input_priority_3 = TextInput::create(50,str3,"bigFont.fnt");
		input_priority_3->setPosition(395,154);
		input_priority_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-three-tab-1", "")));
		input_priority_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-three-tab-1", str));
		
		});
		layout->addChild(input_priority_3);

        TextInput* input_priority_4 = TextInput::create(50,"","bigFont.fnt");
		input_priority_4->setPosition(395,114);
		input_priority_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-four-tab-1", "")));
		input_priority_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-four-tab-1", str));
		
		});
		layout->addChild(input_priority_4);

        TextInput* input_priority_5 = TextInput::create(50,"","bigFont.fnt");
		input_priority_5->setPosition(395,74);
		input_priority_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-five-tab-1", "")));
		input_priority_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-five-tab-1", str));
		
		});
		layout->addChild(input_priority_5);

		TextInput* input_priority_6 = TextInput::create(50,"","bigFont.fnt");
		input_priority_6->setPosition(395,34);
		input_priority_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-six-tab-1", "")));
		input_priority_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-six-tab-1", str));
		
		});
		layout->addChild(input_priority_6);

        TextInput* input_priority_7 = TextInput::create(50,"","bigFont.fnt");
		input_priority_7->setPosition(395,-6);
		input_priority_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-seven-tab-1", "")));
		input_priority_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-seven-tab-1", str));
		
		});
		layout->addChild(input_priority_7);

        TextInput* input_priority_8 = TextInput::create(50,"","bigFont.fnt");
		input_priority_8->setPosition(395,-46);
		input_priority_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-eight-tab-1", "")));
		input_priority_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-eight-tab-1", str));
		
		});
		layout->addChild(input_priority_8);

        TextInput* input_priority_9 = TextInput::create(50,"","bigFont.fnt");
		input_priority_9->setPosition(395,-86);
		input_priority_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-nine-tab-1", "")));
		input_priority_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-nine-tab-1", str));
		
		});
		layout->addChild(input_priority_9);

        TextInput* input_priority_10 = TextInput::create(50,"","bigFont.fnt");
		input_priority_10->setPosition(395,-126);
		input_priority_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-ten-tab-1", "")));
		input_priority_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-ten-tab-1", str));
		
		});
		layout->addChild(input_priority_10);

		

		// Checkboxes

		CCMenuItemToggler* toggle = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox),1);
		layout->addChild(toggle);
		toggle->setPosition(312, 234);
		toggle->toggle(Mod::get()->getSavedValue<bool>("checkbox-tab-1", false));

		CCMenuItemToggler* toggle_2 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox2),1);
		toggle_2->toggle(false);
		layout->addChild(toggle_2);
		toggle_2->setPosition(312, 194);
		toggle_2->toggle(Mod::get()->getSavedValue<bool>("checkbox-2-tab-1", false));

		CCMenuItemToggler* toggle_3 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox3),1);
		toggle_3->toggle(false);
		layout->addChild(toggle_3);
		toggle_3->setPosition(312, 154);
		toggle_3->toggle(Mod::get()->getSavedValue<bool>("checkbox-3-tab-1", false));

		CCMenuItemToggler* toggle_4 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox4),1);
		toggle_4->toggle(false);
		layout->addChild(toggle_4);
		toggle_4->setPosition(312, 114);
		toggle_4->toggle(Mod::get()->getSavedValue<bool>("checkbox-4-tab-1", false));

		CCMenuItemToggler* toggle_5 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox5),1);
		toggle_5->toggle(false);
		layout->addChild(toggle_5);
		toggle_5->setPosition(312, 74);
		toggle_5->toggle(Mod::get()->getSavedValue<bool>("checkbox-5-tab-1", false));

		CCMenuItemToggler* toggle_6 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox6),1);
		layout->addChild(toggle_6);
		toggle_6->setPosition(312, 34);
		toggle_6->toggle(Mod::get()->getSavedValue<bool>("checkbox-6-tab-1", false));

		CCMenuItemToggler* toggle_7 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox7),1);
		toggle_7->toggle(false);
		layout->addChild(toggle_7);
		toggle_7->setPosition(312, -6);
		toggle_7->toggle(Mod::get()->getSavedValue<bool>("checkbox-7-tab-1", false));

		CCMenuItemToggler* toggle_8 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox8),1);
		toggle_8->toggle(false);
		layout->addChild(toggle_8);
		toggle_8->setPosition(312, -46);
		toggle_8->toggle(Mod::get()->getSavedValue<bool>("checkbox-8-tab-1", false));

		CCMenuItemToggler* toggle_9 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox9),1);
		toggle_9->toggle(false);
		layout->addChild(toggle_9);
		toggle_9->setPosition(312, -86);
		toggle_9->toggle(Mod::get()->getSavedValue<bool>("checkbox-9-tab-1", false));

		CCMenuItemToggler* toggle_10 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox10),1);
		toggle_10->toggle(false);
		layout->addChild(toggle_10);
		toggle_10->setPosition(312, -126);
		toggle_10->toggle(Mod::get()->getSavedValue<bool>("checkbox-10-tab-1", false));

		
		return true;

	}

	// not sure if was doing this right because it just turns all of them on/off if one of them is enabled/disabled

	void Tab1::SaveCheckbox(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-tab-1", !Mod::get()->getSavedValue<bool>("checkbox-tab-1", false));;
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
		if (ret->init()){

			ret->autorelease();
			return ret;
		}
		CC_SAFE_DELETE(ret);
		return nullptr;
	};