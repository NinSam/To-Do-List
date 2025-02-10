#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool Tab2::init(){

		if (!CCMenu::init())

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();

		auto screenSize = CCDirector::sharedDirector()->getWinSize();


		// Menus


		auto layout = CCMenu::create();
		layout->setID("layout");


		// ScrollLayer

		auto scroll = ScrollLayer::create({445,204.5f},true, true);
		
		scroll->m_contentLayer->addChild(layout);
		scroll->m_contentLayer->setLayout(

			ColumnLayout::create()
			->setAxisReverse(true)
            ->setAxisAlignment(AxisAlignment::End)
			->setAutoGrowAxis(500)

		);
		scroll->m_contentLayer->setPositionY(-208);
		scroll->m_contentLayer->setContentHeight(412.5f);
		scroll->setTouchEnabled(true);
		this->addChild(scroll);
		scroll->setPosition(screenSize/2 + CCPoint{-230.5f, -125});

		auto scrollbar = Scrollbar::create(scroll);
		scrollbar->setPosition(screenSize/2 + CCPoint{220, -28});
		this->addChild(scrollbar);
		

		 // Labels

		 auto first = CCLabelBMFont::create("1.", "bigFont.fnt");
		 first->setPosition(32, 206);
		 first->setScale(0.7f);
		 layout->addChild(first);
 
		 auto second = CCLabelBMFont::create("2.", "bigFont.fnt");
		 second->setPosition(32, 166);
		 second->setScale(0.7f);
		 layout->addChild(second);
 
		 auto third = CCLabelBMFont::create("3.", "bigFont.fnt");
		 third->setPosition(32, 126);
		 third->setScale(0.7f);
		 layout->addChild(third);
 
		 auto fourth = CCLabelBMFont::create("4.", "bigFont.fnt");
		 fourth->setPosition(32, 86);
		 fourth->setScale(0.7f);
		 layout->addChild(fourth);
 
		 auto fifth = CCLabelBMFont::create("5.", "bigFont.fnt");
		 fifth->setPosition(32, 46);
		 fifth->setScale(0.7f);
		 layout->addChild(fifth);
 
		 auto sixth = CCLabelBMFont::create("6.", "bigFont.fnt");
		 sixth->setPosition(32, 7);
		 sixth->setScale(0.7f);
		 layout->addChild(sixth);
 
		 auto seventh = CCLabelBMFont::create("7.", "bigFont.fnt");
		 seventh->setPosition(32, -33);
		 seventh->setScale(0.7f);
		 layout->addChild(seventh);
 
		 auto eighth = CCLabelBMFont::create("8.", "bigFont.fnt");
		 eighth->setPosition(32, -73);
		 eighth->setScale(0.7f);
		 layout->addChild(eighth);
 
		 auto ninth = CCLabelBMFont::create("9.", "bigFont.fnt");
		 ninth->setPosition(32, -113);
		 ninth->setScale(0.7f);
		 layout->addChild(ninth);
 
		 auto tenth = CCLabelBMFont::create("10.", "bigFont.fnt");
		 tenth->setPosition(32, -153);
		 tenth->setScale(0.7f);
		 layout->addChild(tenth);
	

		// TextInputs


		TextInput* input_1 = TextInput::create(200,"","bigFont.fnt");
		input_1->setPosition(153, 204);
		input_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-1-tab-2", "")));
		input_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-1-tab-2", str));
		
		});
		layout->addChild(input_1);

		TextInput* input_2 = TextInput::create(200,"","bigFont.fnt");
		input_2->setPosition({153,164.5f});
		input_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-2-tab-2", "")));
		input_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-2-tab-2", str));
		
		});
		layout->addChild(input_2);

		TextInput* input_3 = TextInput::create(200,"","bigFont.fnt");
		input_3->setPosition({153,124});
		input_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-3-tab-2", "")));
		input_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-3-tab-2", str));
		
		});
		layout->addChild(input_3);

		TextInput* input_4 = TextInput::create(200,"","bigFont.fnt");
		input_4->setPosition({153,84.5f});
		input_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-4-tab-2", "")));
		input_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-4-tab-2", str));
		
		});
		layout->addChild(input_4);

		TextInput* input_5 = TextInput::create(200,"","bigFont.fnt");
		input_5->setPosition({153,44});
		input_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-5-tab-2", "")));
		input_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-5-tab-2", str));
		
		});
		layout->addChild(input_5);

		TextInput* input_6 = TextInput::create(200,"","bigFont.fnt");
		input_6->setPosition({153,7});
		input_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-6-tab-2", "")));
		input_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-6-tab-2", str));
		
		});
		layout->addChild(input_6);

		TextInput* input_7 = TextInput::create(200,"","bigFont.fnt");
		input_7->setPosition({153,-33});
		input_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-7-tab-2", "")));
		input_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-7-tab-2", str));
		
		});
		layout->addChild(input_7);

		TextInput* input_8 = TextInput::create(200,"","bigFont.fnt");
		input_8->setPosition({153,-73});
		input_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-8-tab-2", "")));
		input_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-8-tab-2", str));
		
		});
		layout->addChild(input_8);

		TextInput* input_9 = TextInput::create(200,"","bigFont.fnt");
		input_9->setPosition({153,-113});
		input_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-9-tab-2", "")));
		input_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-9-tab-2", str));
		
		});
		layout->addChild(input_9);

		TextInput* input_10 = TextInput::create(200,"","bigFont.fnt");
		input_10->setPosition({153,-153});
		input_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-10-tab-2", "")));
		input_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-10-tab-2", str));
		
		});
		layout->addChild(input_10);


		// Priority

        TextInput* input_priority_1 = TextInput::create(50,"","bigFont.fnt");
		input_priority_1->setPosition({395,204});
		input_priority_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-one-tab-2", "")));
		input_priority_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-one-tab-2", str));
		
		});
		layout->addChild(input_priority_1);

        TextInput* input_priority_2 = TextInput::create(50,"","bigFont.fnt");
		input_priority_2->setPosition({395,164.5f});
		input_priority_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-two-tab-2", "")));
		input_priority_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-two-tab-2", str));
		
		});
		layout->addChild(input_priority_2);

        TextInput* input_priority_3 = TextInput::create(50,"","bigFont.fnt");
		input_priority_3->setPosition({395,124});
		input_priority_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-three-tab-2", "")));
		input_priority_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-three-tab-2", str));
		
		});
		layout->addChild(input_priority_3);

        TextInput* input_priority_4 = TextInput::create(50,"","bigFont.fnt");
		input_priority_4->setPosition({395,84.5f});
		input_priority_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-four-tab-2", "")));
		input_priority_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-four-tab-2", str));
		
		});
		layout->addChild(input_priority_4);

        TextInput* input_priority_5 = TextInput::create(50,"","bigFont.fnt");
		input_priority_5->setPosition({395,44});
		input_priority_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-five-tab-2", "")));
		input_priority_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-five-tab-2", str));
		
		});
		layout->addChild(input_priority_5);

		TextInput* input_priority_6 = TextInput::create(50,"","bigFont.fnt");
		input_priority_6->setPosition({395,7});
		input_priority_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-six-tab-2", "")));
		input_priority_6->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-six-tab-2", str));
		
		});
		layout->addChild(input_priority_6);

        TextInput* input_priority_7 = TextInput::create(50,"","bigFont.fnt");
		input_priority_7->setPosition({395,-33});
		input_priority_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-seven-tab-2", "")));
		input_priority_7->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-seven-tab-2", str));
		
		});
		layout->addChild(input_priority_7);

        TextInput* input_priority_8 = TextInput::create(50,"","bigFont.fnt");
		input_priority_8->setPosition({395,-73});
		input_priority_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-eight-tab-2", "")));
		input_priority_8->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-eight-tab-2", str));
		
		});
		layout->addChild(input_priority_8);

        TextInput* input_priority_9 = TextInput::create(50,"","bigFont.fnt");
		input_priority_9->setPosition({395,-113});
		input_priority_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-nine-tab-2", "")));
		input_priority_9->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-nine-tab-2", str));
		
		});
		layout->addChild(input_priority_9);

        TextInput* input_priority_10 = TextInput::create(50,"","bigFont.fnt");
		input_priority_10->setPosition({395,-153});
		input_priority_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-ten-tab-2", "")));
		input_priority_10->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-ten-tab-2", str));
		
		});
		layout->addChild(input_priority_10);

		

		// Checkboxes

		CCMenuItemToggler* toggle = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox),1);
		layout->addChild(toggle);
		toggle->setPosition({310, 205});
		toggle->toggle(Mod::get()->getSavedValue<bool>("checkbox-tab-2", false));

		CCMenuItemToggler* toggle_2 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox2),1);
		toggle_2->toggle(false);
		layout->addChild(toggle_2);
		toggle_2->setPosition({310, 164.5f});
		toggle_2->toggle(Mod::get()->getSavedValue<bool>("checkbox-2-tab-2", false));

		CCMenuItemToggler* toggle_3 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox3),1);
		toggle_3->toggle(false);
		layout->addChild(toggle_3);
		toggle_3->setPosition({310, 124});
		toggle_3->toggle(Mod::get()->getSavedValue<bool>("checkbox-3-tab-2", false));

		CCMenuItemToggler* toggle_4 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox4),1);
		toggle_4->toggle(false);
		layout->addChild(toggle_4);
		toggle_4->setPosition({310, 84.5f});
		toggle_4->toggle(Mod::get()->getSavedValue<bool>("checkbox-4-tab-2", false));

		CCMenuItemToggler* toggle_5 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox5),1);
		toggle_5->toggle(false);
		layout->addChild(toggle_5);
		toggle_5->setPosition({310, 45});
		toggle_5->toggle(Mod::get()->getSavedValue<bool>("checkbox-5-tab-2", false));

		CCMenuItemToggler* toggle_6 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox6),1);
		layout->addChild(toggle_6);
		toggle_6->setPosition({310, 7});
		toggle_6->toggle(Mod::get()->getSavedValue<bool>("checkbox-6-tab-2", false));

		CCMenuItemToggler* toggle_7 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox7),1);
		toggle_7->toggle(false);
		layout->addChild(toggle_7);
		toggle_7->setPosition({310, -33});
		toggle_7->toggle(Mod::get()->getSavedValue<bool>("checkbox-7-tab-2", false));

		CCMenuItemToggler* toggle_8 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox8),1);
		toggle_8->toggle(false);
		layout->addChild(toggle_8);
		toggle_8->setPosition({310, -73});
		toggle_8->toggle(Mod::get()->getSavedValue<bool>("checkbox-8-tab-2", false));

		CCMenuItemToggler* toggle_9 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox9),1);
		toggle_9->toggle(false);
		layout->addChild(toggle_9);
		toggle_9->setPosition({310, -113});
		toggle_9->toggle(Mod::get()->getSavedValue<bool>("checkbox-9-tab-2", false));

		CCMenuItemToggler* toggle_10 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox10),1);
		toggle_10->toggle(false);
		layout->addChild(toggle_10);
		toggle_10->setPosition({310, -153});
		toggle_10->toggle(Mod::get()->getSavedValue<bool>("checkbox-10-tab-2", false));

	
		// this
		
		this->setKeypadEnabled(true);
		this->setTouchEnabled(true);
		scroll->updateLayout();
		
		return true;

	}

	void Tab2::SaveCheckbox(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-tab-2", false));;
	}
	void Tab2::SaveCheckbox2(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-2-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-2-tab-2", false));
	}
	void Tab2::SaveCheckbox3(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-3-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-3-tab-2", false));
	}
	void Tab2::SaveCheckbox4(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-4-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-4-tab-2", false));
	}
	void Tab2::SaveCheckbox5(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-5-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-5-tab-2", false));
	}
	void Tab2::SaveCheckbox6(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-6-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-6-tab-2", false));
	}
	void Tab2::SaveCheckbox7(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-7-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-7-tab-2", false));
	}
	void Tab2::SaveCheckbox8(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-8-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-8-tab-2", false));
	}
	void Tab2::SaveCheckbox9(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-9-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-9-tab-2", false));
	}
	void Tab2::SaveCheckbox10(CCObject* sender){
		Mod::get()->setSavedValue<bool>("checkbox-10-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-10-tab-2", false));
	}

	Tab2* Tab2::create(){
		auto ret = new Tab2;
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}