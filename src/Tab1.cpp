#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool Tab1::init(){

		if (!CCMenu::init())

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();


		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
		auto screenSize = CCDirector::sharedDirector()->getWinSize();


		// Menus


		auto layout = CCMenu::create();
		auto tabs = CCMenu::create();

		this->addChild(tabs);
		tabs->setPosition(ccp(0,0));
		tabs->setID("tabs");

		layout->setID("layout");


		// ScrollLayer

		auto scroll = ScrollLayer::create({460,211},true, true);
		
		
		scroll->m_contentLayer->addChild(layout);
		scroll->m_contentLayer->setLayout(

			ColumnLayout::create()
			->setAxisReverse(true)
            ->setAxisAlignment(AxisAlignment::End)
			->setAutoGrowAxis(500)

		);
		scroll->m_contentLayer->setPositionY(-200);
		scroll->m_contentLayer->setContentHeight(415);
		scroll->setTouchEnabled(true);

		this->addChild(scroll);
		scroll->setPosition(screenSize/2 + CCPoint{-230.5f, -131});

		 // Labels

		 auto first = CCLabelBMFont::create("1.", "bigFont.fnt");
		 first->setPosition(ccp(32, 203));
		 first->setScale(0.7f);
		 layout->addChild(first);
 
		 auto second = CCLabelBMFont::create("2.", "bigFont.fnt");
		 second->setPosition(ccp(32, 163));
		 second->setScale(0.7f);
		 layout->addChild(second);
 
		 auto third = CCLabelBMFont::create("3.", "bigFont.fnt");
		 third->setPosition(ccp(32, 123));
		 third->setScale(0.7f);
		 layout->addChild(third);
 
		 auto fourth = CCLabelBMFont::create("4.", "bigFont.fnt");
		 fourth->setPosition(ccp(32, 83));
		 fourth->setScale(0.7f);
		 layout->addChild(fourth);
 
		 auto fifth = CCLabelBMFont::create("5.", "bigFont.fnt");
		 fifth->setPosition(ccp(32, 43));
		 fifth->setScale(0.7f);
		 layout->addChild(fifth);
 
		 auto sixth = CCLabelBMFont::create("6.", "bigFont.fnt");
		 sixth->setPosition(ccp(32, 4));
		 sixth->setScale(0.7f);
		 layout->addChild(sixth);
 
		 auto seventh = CCLabelBMFont::create("7.", "bigFont.fnt");
		 seventh->setPosition(ccp(32, -36));
		 seventh->setScale(0.7f);
		 layout->addChild(seventh);
 
		 auto eighth = CCLabelBMFont::create("8.", "bigFont.fnt");
		 eighth->setPosition(ccp(32, -76));
		 eighth->setScale(0.7f);
		 layout->addChild(eighth);
 
		 auto ninth = CCLabelBMFont::create("9.", "bigFont.fnt");
		 ninth->setPosition(ccp(32, -116));
		 ninth->setScale(0.7f);
		 layout->addChild(ninth);
 
		 auto tenth = CCLabelBMFont::create("10.", "bigFont.fnt");
		 tenth->setPosition(ccp(32, -156));
		 tenth->setScale(0.7f);
		 layout->addChild(tenth);
	

		// Level Name (Tabs)


		TextInput* inputname_1 = TextInput::create(100,"1/5","bigFont.fnt");
		inputname_1->setPosition(ccp(284.5f, 268));
		inputname_1->setPosition(screenSize/2 + CCPoint{0, 108});
		inputname_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-1-tab-1", "")));
		inputname_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-1-tab-1", str));
		
		});
		tabs->addChild(inputname_1);

		// TextInputs


		TextInput* input_1 = TextInput::create(200,"","bigFont.fnt");
		input_1->setPosition(ccp(153, 201));
		input_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-1-tab-1", "")));
		input_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-1-tab-1", str)); // finally figured it out after "insert" attempts I have on Spectre
		
		});
		layout->addChild(input_1);

		TextInput* input_2 = TextInput::create(200,"","bigFont.fnt");
		input_2->setPosition({153,161.5f});
		input_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-2-tab-1", "")));
		input_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-2-tab-1", str));
		
		});
		layout->addChild(input_2);

		TextInput* input_3 = TextInput::create(200,"","bigFont.fnt");
		input_3->setPosition({153,121});
		input_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-3-tab-1", "")));
		input_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-3-tab-1", str));
		
		});
		layout->addChild(input_3);

		TextInput* input_4 = TextInput::create(200,"","bigFont.fnt");
		input_4->setPosition({153,81.5f});
		input_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-4-tab-1", "")));
		input_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-4-tab-1", str));
		
		});
		layout->addChild(input_4);

		TextInput* input_5 = TextInput::create(200,"","bigFont.fnt");
		input_5->setPosition({153,41});
		input_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-5-tab-1", "")));
		input_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-5-tab-1", str));
		
		});
		layout->addChild(input_5);

		TextInput* input_6 = TextInput::create(200,"","bigFont.fnt");
		input_6->setPosition({153,4});
		input_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-6-tab-1", "")));
		input_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-6-tab-1", str));
		
		});
		layout->addChild(input_6);

		TextInput* input_7 = TextInput::create(200,"","bigFont.fnt");
		input_7->setPosition({153,-36});
		input_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-7-tab-1", "")));
		input_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-7-tab-1", str));
		
		});
		layout->addChild(input_7);

		TextInput* input_8 = TextInput::create(200,"","bigFont.fnt");
		input_8->setPosition({153,-76});
		input_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-8-tab-1", "")));
		input_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-8-tab-1", str));
		
		});
		layout->addChild(input_8);

		TextInput* input_9 = TextInput::create(200,"","bigFont.fnt");
		input_9->setPosition({153,-116});
		input_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-9-tab-1", "")));
		input_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-9-tab-1", str));
		
		});
		layout->addChild(input_9);

		TextInput* input_10 = TextInput::create(200,"","bigFont.fnt");
		input_10->setPosition({153,-156});
		input_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-10-tab-1", "")));
		input_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-10-tab-1", str));
		
		});
		layout->addChild(input_10);


		// Priority

        TextInput* input_priority_1 = TextInput::create(50,"","bigFont.fnt");
		input_priority_1->setPosition({395,201});
		input_priority_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-one-tab-1", "")));
		input_priority_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-one-tab-1", str));
		
		});
		layout->addChild(input_priority_1);

        TextInput* input_priority_2 = TextInput::create(50,"","bigFont.fnt");
		input_priority_2->setPosition({395,161.5f});
		input_priority_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-two-tab-1", "")));
		input_priority_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-two-tab-1", str));
		
		});
		layout->addChild(input_priority_2);

        TextInput* input_priority_3 = TextInput::create(50,"","bigFont.fnt");
		input_priority_3->setPosition({395,121});
		input_priority_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-three-tab-1", "")));
		input_priority_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-three-tab-1", str));
		
		});
		layout->addChild(input_priority_3);

        TextInput* input_priority_4 = TextInput::create(50,"","bigFont.fnt");
		input_priority_4->setPosition({395,81.5f});
		input_priority_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-four-tab-1", "")));
		input_priority_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-four-tab-1", str));
		
		});
		layout->addChild(input_priority_4);

        TextInput* input_priority_5 = TextInput::create(50,"","bigFont.fnt");
		input_priority_5->setPosition({395,41});
		input_priority_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-five-tab-1", "")));
		input_priority_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-five-tab-1", str));
		
		});
		layout->addChild(input_priority_5);

		TextInput* input_priority_6 = TextInput::create(50,"","bigFont.fnt");
		input_priority_6->setPosition({395,4});
		input_priority_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-six-tab-1", "")));
		input_priority_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-six-tab-1", str));
		
		});
		layout->addChild(input_priority_6);

        TextInput* input_priority_7 = TextInput::create(50,"","bigFont.fnt");
		input_priority_7->setPosition({395,-36});
		input_priority_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-seven-tab-1", "")));
		input_priority_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-seven-tab-1", str));
		
		});
		layout->addChild(input_priority_7);

        TextInput* input_priority_8 = TextInput::create(50,"","bigFont.fnt");
		input_priority_8->setPosition({395,-76});
		input_priority_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-eight-tab-1", "")));
		input_priority_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-eight-tab-1", str));
		
		});
		layout->addChild(input_priority_8);

        TextInput* input_priority_9 = TextInput::create(50,"","bigFont.fnt");
		input_priority_9->setPosition({395,-116});
		input_priority_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-nine-tab-1", "")));
		input_priority_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-nine-tab-1", str));
		
		});
		layout->addChild(input_priority_9);

        TextInput* input_priority_10 = TextInput::create(50,"","bigFont.fnt");
		input_priority_10->setPosition({395,-156});
		input_priority_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-ten-tab-1", "")));
		input_priority_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-ten-tab-1", str));
		
		});
		layout->addChild(input_priority_10);

		

		// Checkboxes

		CCMenuItemToggler* toggle = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox),1);
		layout->addChild(toggle);
		toggle->setPosition({310, 202});
		toggle->toggle(Mod::get()->getSavedValue<bool>("checkbox-tab-1", false));

		CCMenuItemToggler* toggle_2 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox2),1);
		toggle_2->toggle(false);
		layout->addChild(toggle_2);
		toggle_2->setPosition({310, 161.5f});
		toggle_2->toggle(Mod::get()->getSavedValue<bool>("checkbox-2-tab-1", false));

		CCMenuItemToggler* toggle_3 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox3),1);
		toggle_3->toggle(false);
		layout->addChild(toggle_3);
		toggle_3->setPosition({310, 121});
		toggle_3->toggle(Mod::get()->getSavedValue<bool>("checkbox-3-tab-1", false));

		CCMenuItemToggler* toggle_4 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox4),1);
		toggle_4->toggle(false);
		layout->addChild(toggle_4);
		toggle_4->setPosition({310, 81.5f});
		toggle_4->toggle(Mod::get()->getSavedValue<bool>("checkbox-4-tab-1", false));

		CCMenuItemToggler* toggle_5 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox5),1);
		toggle_5->toggle(false);
		layout->addChild(toggle_5);
		toggle_5->setPosition({310, 42});
		toggle_5->toggle(Mod::get()->getSavedValue<bool>("checkbox-5-tab-1", false));

		CCMenuItemToggler* toggle_6 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox6),1);
		layout->addChild(toggle_6);
		toggle_6->setPosition({310, 4});
		toggle_6->toggle(Mod::get()->getSavedValue<bool>("checkbox-6-tab-1", false));

		CCMenuItemToggler* toggle_7 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox7),1);
		toggle_7->toggle(false);
		layout->addChild(toggle_7);
		toggle_7->setPosition({310, -36});
		toggle_7->toggle(Mod::get()->getSavedValue<bool>("checkbox-7-tab-1", false));

		CCMenuItemToggler* toggle_8 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox8),1);
		toggle_8->toggle(false);
		layout->addChild(toggle_8);
		toggle_8->setPosition({310, -76});
		toggle_8->toggle(Mod::get()->getSavedValue<bool>("checkbox-8-tab-1", false));

		CCMenuItemToggler* toggle_9 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox9),1);
		toggle_9->toggle(false);
		layout->addChild(toggle_9);
		toggle_9->setPosition({310, -116});
		toggle_9->toggle(Mod::get()->getSavedValue<bool>("checkbox-9-tab-1", false));

		CCMenuItemToggler* toggle_10 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab1::SaveCheckbox10),1);
		toggle_10->toggle(false);
		layout->addChild(toggle_10);
		toggle_10->setPosition({310, -156});
		toggle_10->toggle(Mod::get()->getSavedValue<bool>("checkbox-10-tab-1", false));

	


		// this
		
		this->setKeypadEnabled(true);
		this->setTouchEnabled(true);
		scroll->updateLayout();
		
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
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}