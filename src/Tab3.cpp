#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "TabManager.hpp"

using namespace geode::prelude;

	bool Tab3::init(){

		if (!FLAlertLayer::init(150))

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();
		m_noElasticity = true;

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
		auto screenSize = CCDirector::get()->getWinSize();

		// Menus


		auto menu = CCMenu::create();
		auto layout = CCMenu::create();
		auto smallbutton = CCMenu::create();
		auto tabs = CCMenu::create();

		this->addChild(tabs);
		tabs->setPosition({54,21 * relativescale});
        tabs->setScale(0.8f * relativescale);
	    tabs->setZOrder(2);
		tabs->setID("tabs"_spr);
		
		this->addChild(smallbutton);
		smallbutton->setPosition({75,0 * relativescale});
		smallbutton->setScale(0.675f * relativescale);
		smallbutton->setID("small-buttons"_spr);
		smallbutton->setZOrder(2);
	
		this->addChild(menu);
		menu->setPosition({0,0 * relativescale});

		this->addChild(layout);
		layout->setPosition({0,35 * relativescale});
		layout->setScale(0.5f * relativescale);
		layout->setID("layout"_spr);
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
		goldtext->setZOrder(1);
		goldtext->setScale(0.8f * relativescale);

		CCLabelBMFont* first = CCLabelBMFont::create("1.", "bigFont.fnt");
		first->setPosition({109, 207 * relativescale});
		first->setScale(0.7f * relativescale);
		layout->addChild(first);
		first->setZOrder(1);

		CCLabelBMFont* second = CCLabelBMFont::create("2.", "bigFont.fnt");
		second->setPosition({109, 167 * relativescale});
		second->setScale(0.7f * relativescale);
		layout->addChild(second);
		second->setZOrder(1);

		CCLabelBMFont* third = CCLabelBMFont::create("3.", "bigFont.fnt");
		third->setPosition({109, 127 * relativescale});
		third->setScale(0.7f * relativescale);
		layout->addChild(third);
		third->setZOrder(1);

		CCLabelBMFont* fourth = CCLabelBMFont::create("4.", "bigFont.fnt");
		fourth->setPosition({109, 87 * relativescale});
		fourth->setScale(0.7f * relativescale);
		layout->addChild(fourth);
		fourth->setZOrder(1);

		CCLabelBMFont* fifth = CCLabelBMFont::create("5.", "bigFont.fnt");
		fifth->setPosition({109, 47 * relativescale});
		fifth->setScale(0.7f * relativescale);
		layout->addChild(fifth);
		fifth->setZOrder(1);

		CCLabelBMFont* sixth = CCLabelBMFont::create("6.", "bigFont.fnt");
		sixth->setPosition({109, 7 * relativescale});
		sixth->setScale(0.7f * relativescale);
		layout->addChild(sixth);
		sixth->setZOrder(1);

		CCLabelBMFont* seventh = CCLabelBMFont::create("7.", "bigFont.fnt");
		seventh->setPosition({109, -33 * relativescale});
		seventh->setScale(0.7f * relativescale);
		layout->addChild(seventh);
		seventh->setZOrder(1);

		CCLabelBMFont* eighth = CCLabelBMFont::create("8.", "bigFont.fnt");
		eighth->setPosition({109, -73 * relativescale});
		eighth->setScale(0.7f * relativescale);
		layout->addChild(eighth);
		eighth->setZOrder(1);

		CCLabelBMFont* ninth = CCLabelBMFont::create("9.", "bigFont.fnt");
		ninth->setPosition({109, -113 * relativescale});
		ninth->setScale(0.7f * relativescale);
		layout->addChild(ninth);
		ninth->setZOrder(1);

		CCLabelBMFont* tenth = CCLabelBMFont::create("10.", "bigFont.fnt");
		tenth->setPosition({109, -153 * relativescale});
		tenth->setScale(0.7f * relativescale);
		layout->addChild(tenth);
		tenth->setZOrder(1);

		// Buttons
		
		CCMenuItemSpriteExtra* closebutton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(Tab3::CloseTab)
		);
		menu->addChild(closebutton);
		closebutton->setID("close-button"_spr);
		closebutton->setZOrder(1);
		closebutton->setPosition({180, 295 * relativescale});

		CCMenuItemSpriteExtra* opensettings = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
			this,
			menu_selector(Tab3::OpenSettings)
		);
		smallbutton->addChild(opensettings);
		opensettings->setID("open-settings"_spr);
		opensettings->setZOrder(1);
		opensettings->setPosition({297, 333 * relativescale});

		CCMenuItemSpriteExtra* info = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png"),
			this,
			menu_selector(Tab3::Info)
		);
		smallbutton->addChild(info);
		info->setID("info"_spr);
		info->setZOrder(1);
		info->setPosition({73, 332 * relativescale});


		// Level Name (Tabs)

		TextInput* inputname_1 = TextInput::create(100,"3/5","bigFont.fnt");
		inputname_1->setPosition({217.5f, 243 * relativescale});
		inputname_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-1-tab-3", "")));
		inputname_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-1-tab-3", str));
		
		});
		tabs->addChild(inputname_1);


		// TextInputs

		TextInput* input_1 = TextInput::create(200,"","bigFont.fnt");
		input_1->setPosition({231,205 * relativescale});
		input_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-1-tab-3", "")));
		input_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-1-tab-3", str));
		
		});
		layout->addChild(input_1);

		TextInput* input_2 = TextInput::create(200,"","bigFont.fnt");
		input_2->setPosition({231,164.5f * relativescale});
		input_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-2-tab-3", "")));
		input_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-2-tab-3", str));
		
		});
		layout->addChild(input_2);

		TextInput* input_3 = TextInput::create(200,"","bigFont.fnt");
		input_3->setPosition({231,124 * relativescale});
		input_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-3-tab-3", "")));
		input_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-3-tab-3", str));
		
		});
		layout->addChild(input_3);

		TextInput* input_4 = TextInput::create(200,"","bigFont.fnt");
		input_4->setPosition({231,84.5f * relativescale});
		input_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-4-tab-3", "")));
		input_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-4-tab-3", str));
		
		});
		layout->addChild(input_4);

		TextInput* input_5 = TextInput::create(200,"","bigFont.fnt");
		input_5->setPosition({231,45 * relativescale});
		input_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-5-tab-3", "")));
		input_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-5-tab-3", str));
		
		});
		layout->addChild(input_5);

		TextInput* input_6 = TextInput::create(200,"","bigFont.fnt");
		input_6->setPosition({231,7 * relativescale});
		input_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-6-tab-3", "")));
		input_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-6-tab-3", str));
		
		});
		layout->addChild(input_6);

		TextInput* input_7 = TextInput::create(200,"","bigFont.fnt");
		input_7->setPosition({231,-33 * relativescale});
		input_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-7-tab-3", "")));
		input_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-7-tab-3", str));
		
		});
		layout->addChild(input_7);

		TextInput* input_8 = TextInput::create(200,"","bigFont.fnt");
		input_8->setPosition({231,-73 * relativescale});
		input_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-8-tab-3", "")));
		input_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-8-tab-3", str));
		
		});
		layout->addChild(input_8);

		TextInput* input_9 = TextInput::create(200,"","bigFont.fnt");
		input_9->setPosition({231,-113 * relativescale});
		input_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-9-tab-3", "")));
		input_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-9-tab-3", str));
		
		});
		layout->addChild(input_9);

		TextInput* input_10 = TextInput::create(200,"","bigFont.fnt");
		input_10->setPosition({231,-153 * relativescale});
		input_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-10-tab-3", "")));
		input_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-10-tab-3", str));
		
		});
		layout->addChild(input_10);


		// Priority

        TextInput* input_priority_1 = TextInput::create(50,"","bigFont.fnt");
		input_priority_1->setPosition({435,205 * relativescale});
		input_priority_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-one-tab-3", "")));
		input_priority_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-one-tab-3", str));
		
		});
		layout->addChild(input_priority_1);

        TextInput* input_priority_2 = TextInput::create(50,"","bigFont.fnt");
		input_priority_2->setPosition({435,164.5f * relativescale});
		input_priority_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-two-tab-3", "")));
		input_priority_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-two-tab-3", str));
		
		});
		layout->addChild(input_priority_2);

        TextInput* input_priority_3 = TextInput::create(50,"","bigFont.fnt");
		input_priority_3->setPosition({435,124 * relativescale});
		input_priority_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-three-tab-3", "")));
		input_priority_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-three-tab-3", str));
		
		});
		layout->addChild(input_priority_3);

        TextInput* input_priority_4 = TextInput::create(50,"","bigFont.fnt");
		input_priority_4->setPosition({435,84.5f * relativescale});
		input_priority_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-four-tab-3", "")));
		input_priority_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-four-tab-3", str));
		
		});
		layout->addChild(input_priority_4);

        TextInput* input_priority_5 = TextInput::create(50,"","bigFont.fnt");
		input_priority_5->setPosition({435,45 * relativescale});
		input_priority_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-five-tab-3", "")));
		input_priority_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-five-tab-3", str));
		
		});
		layout->addChild(input_priority_5);

		TextInput* input_priority_6 = TextInput::create(50,"","bigFont.fnt");
		input_priority_6->setPosition({435,7 * relativescale});
		input_priority_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-six-tab-3", "")));
		input_priority_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-sixv", str));
		
		});
		layout->addChild(input_priority_6);

        TextInput* input_priority_7 = TextInput::create(50,"","bigFont.fnt");
		input_priority_7->setPosition({435,-33 * relativescale});
		input_priority_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-seven-tab-3", "")));
		input_priority_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-seven-tab-3", str));
		
		});
		layout->addChild(input_priority_7);

        TextInput* input_priority_8 = TextInput::create(50,"","bigFont.fnt");
		input_priority_8->setPosition({435,-73 * relativescale});
		input_priority_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-eight-tab-3", "")));
		input_priority_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-eight-tab-3", str));
		
		});
		layout->addChild(input_priority_8);

        TextInput* input_priority_9 = TextInput::create(50,"","bigFont.fnt");
		input_priority_9->setPosition({435,-113 * relativescale});
		input_priority_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-nine-tab-3", "")));
		input_priority_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-nine-tab-3", str));
		
		});
		layout->addChild(input_priority_9);

        TextInput* input_priority_10 = TextInput::create(50,"","bigFont.fnt");
		input_priority_10->setPosition({435,-153 * relativescale});
		input_priority_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-ten-tab-3", "")));
		input_priority_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-ten-tab-3", str));
		
		});
		layout->addChild(input_priority_10);

		

		// Checkboxes

		CCMenuItemToggler* toggle = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox),1);
		layout->addChild(toggle);
		toggle->setZOrder(1);
		toggle->setPosition({371, 205 * relativescale});
		toggle->toggle(Mod::get()->getSavedValue<bool>("checkbox-tab-3", false));

		CCMenuItemToggler* toggle_2 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox2),1);
		toggle_2->toggle(false);
		layout->addChild(toggle_2);
		toggle_2->setZOrder(1);
		toggle_2->setPosition({371, 164.5f * relativescale});
		toggle_2->toggle(Mod::get()->getSavedValue<bool>("checkbox-2-tab-3", false));

		CCMenuItemToggler* toggle_3 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox3),1);
		toggle_3->toggle(false);
		layout->addChild(toggle_3);
		toggle_3->setZOrder(1);
		toggle_3->setPosition({371, 124 * relativescale});
		toggle_3->toggle(Mod::get()->getSavedValue<bool>("checkbox-3-tab-3", false));

		CCMenuItemToggler* toggle_4 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox4),1);
		toggle_4->toggle(false);
		layout->addChild(toggle_4);
		toggle_4->setZOrder(1);
		toggle_4->setPosition({371, 84.5f * relativescale});
		toggle_4->toggle(Mod::get()->getSavedValue<bool>("checkbox-4-tab-3", false));

		CCMenuItemToggler* toggle_5 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox5),1);
		toggle_5->toggle(false);
		layout->addChild(toggle_5);
		toggle_5->setZOrder(1);
		toggle_5->setPosition({371, 45 * relativescale});
		toggle_5->toggle(Mod::get()->getSavedValue<bool>("checkbox-5-tab-3", false));

		CCMenuItemToggler* toggle_6 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox6),1);
		layout->addChild(toggle_6);
		toggle_6->setZOrder(1);
		toggle_6->setPosition({371, 7 * relativescale});
		toggle_6->toggle(Mod::get()->getSavedValue<bool>("checkbox-6-tab-3", false));

		CCMenuItemToggler* toggle_7 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox7),1);
		toggle_7->toggle(false);
		layout->addChild(toggle_7);
		toggle_7->setZOrder(1);
		toggle_7->setPosition({371, -33 * relativescale});
		toggle_7->toggle(Mod::get()->getSavedValue<bool>("checkbox-7-tab-3", false));

		CCMenuItemToggler* toggle_8 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox8),1);
		toggle_8->toggle(false);
		layout->addChild(toggle_8);
		toggle_8->setZOrder(1);
		toggle_8->setPosition({371, -73 * relativescale});
		toggle_8->toggle(Mod::get()->getSavedValue<bool>("checkbox-8-tab-3", false));

		CCMenuItemToggler* toggle_9 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox9),1);
		toggle_9->toggle(false);
		layout->addChild(toggle_9);
		toggle_9->setZOrder(1);
		toggle_9->setPosition({371, -113 * relativescale});
		toggle_9->toggle(Mod::get()->getSavedValue<bool>("checkbox-9-tab-3", false));

		CCMenuItemToggler* toggle_10 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab3::SaveCheckbox10),1);
		toggle_10->toggle(false);
		layout->addChild(toggle_10);
		toggle_10->setZOrder(1);
		toggle_10->setPosition({371, -153 * relativescale});
		toggle_10->toggle(Mod::get()->getSavedValue<bool>("checkbox-10-tab-3", false));

		// Arrows

		CCMenuItemSpriteExtra* page_left = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(Tab3::PreviousTab)
		);
		tabs->addChild(page_left);
		page_left->setZOrder(1);
		page_left->setPosition({151, 242 * relativescale});

		CCMenuItemSpriteExtra* page_right = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_rightBtn_001.png"),
			this,
			menu_selector(Tab3::NextTab)
		);
		tabs->addChild(page_right);
		page_right->setZOrder(1);
		page_right->setPosition({284, 242 * relativescale});


		// this
		
		this->setKeypadEnabled(true);
		this->setTouchEnabled(true);
		this->updateLayout();
		
		return true;

	}
	void Tab3::CloseTab(CCObject*){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
 	}
	void Tab3::PreviousTab(CCObject*){
		
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
		Tab2::create()->show();
	}
    void Tab3::NextTab(CCObject*){
		
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
		Tab4::create()->show();
	}
	void Tab3::OpenSettings(CCObject*){
		geode::openSettingsPopup(Mod::get());
	}
	void Tab3::Info(CCObject*){
		FLAlertLayer::create("Info", "1. Level Name (Tabs). 2. Text Input. 3. Checkbox. 4. Priority (Low, Medium, High)", "OK")->show();
	}

	void Tab3::SaveCheckbox(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-tab-3", false));;
	}
	void Tab3::SaveCheckbox2(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-2-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-2-tab-3", false));
	}
	void Tab3::SaveCheckbox3(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-3-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-3-tab-3", false));
	}
	void Tab3::SaveCheckbox4(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-4-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-4-tab-3", false));
	}
	void Tab3::SaveCheckbox5(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-5-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-5-tab-3", false));
	}
	void Tab3::SaveCheckbox6(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-6-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-6-tab-3", false));
	}
	void Tab3::SaveCheckbox7(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-7-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-7-tab-3", false));
	}
	void Tab3::SaveCheckbox8(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-8-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-8-tab-3", false));
	}
	void Tab3::SaveCheckbox9(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-9-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-9-tab-3", false));
	}
	void Tab3::SaveCheckbox10(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-10-tab-3", !Mod::get()->getSavedValue<bool>("checkbox-10-tab-3", false));
	}

	Tab3* Tab3::create(){
		auto ret = new Tab3;
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}