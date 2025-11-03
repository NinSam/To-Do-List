#include "NotepadManager.hpp"

using namespace geode::prelude;

bool Tab2::init(){

	if (!CCMenu::init())
	return false;

	// Menus


	auto layout = CCMenu::create();
	layout->setPosition(0, 0);
	this->addChild(layout);


	// TextInputs


	auto input_1 = TextInput::create(200, "", "bigFont.fnt");
	input_1->setPosition(153, 234);
	input_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-1-tab-2", "")));
	input_1->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-1-tab-2", str));

	});
	layout->addChild(input_1);

	auto input_2 = TextInput::create(200, "", "bigFont.fnt");
	input_2->setPosition(153, 194);
	input_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-2-tab-2", "")));
	input_2->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-2-tab-2", str));

	});
	layout->addChild(input_2);

	auto input_3 = TextInput::create(200, "", "bigFont.fnt");
	input_3->setPosition(153, 154);
	input_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-3-tab-2", "")));
	input_3->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-3-tab-2", str));

	});
	layout->addChild(input_3);

	auto input_4 = TextInput::create(200, "", "bigFont.fnt");
	input_4->setPosition(153, 114);
	input_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-4-tab-2", "")));
	input_4->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-4-tab-2", str));

	});
	layout->addChild(input_4);

	auto input_5 = TextInput::create(200, "", "bigFont.fnt");
	input_5->setPosition(153, 74);
	input_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-5-tab-2", "")));
	input_5->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-5-tab-2", str));

	});
	layout->addChild(input_5);

	auto input_6 = TextInput::create(200, "", "bigFont.fnt");
	input_6->setPosition(153, 34);
	input_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-6-tab-2", "")));
	input_6->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-6-tab-2", str));

	});
	layout->addChild(input_6);

	auto input_7 = TextInput::create(200, "", "bigFont.fnt");
	input_7->setPosition(153, -6);
	input_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-7-tab-2", "")));
	input_7->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-7-tab-2", str));

	});
	layout->addChild(input_7);

	auto input_8 = TextInput::create(200, "", "bigFont.fnt");
	input_8->setPosition(153, -46);
	input_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-8-tab-2", "")));
	input_8->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-8-tab-2", str));

	});
	layout->addChild(input_8);

	auto input_9 = TextInput::create(200, "", "bigFont.fnt");
	input_9->setPosition(153, -86);
	input_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-9-tab-2", "")));
	input_9->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-9-tab-2", str));

	});
	layout->addChild(input_9);

	auto input_10 = TextInput::create(200, "", "bigFont.fnt");
	input_10->setPosition(153, -126);
	input_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-10-tab-2", "")));
	input_10->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-10-tab-2", str));

	});
	layout->addChild(input_10);


	// Priority

    auto input_priority_1 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_1->setPosition(395, 234);
	input_priority_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-one-tab-2", "")));
	input_priority_1->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-one-tab-2", str));

	});
	layout->addChild(input_priority_1);

    auto input_priority_2 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_2->setPosition(395, 194);
	input_priority_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-two-tab-2", "")));
	input_priority_2->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-two-tab-2", str));

	});
	layout->addChild(input_priority_2);

    auto input_priority_3 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_3->setPosition(395, 154);
	input_priority_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-three-tab-2", "")));
	input_priority_3->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-three-tab-2", str));

	});
	layout->addChild(input_priority_3);

    auto input_priority_4 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_4->setPosition(395, 114);
	input_priority_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-four-tab-2", "")));
	input_priority_4->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-four-tab-2", str));

	});
	layout->addChild(input_priority_4);

    auto input_priority_5 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_5->setPosition(395, 74);
	input_priority_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-five-tab-2", "")));
	input_priority_5->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-five-tab-2", str));

	});
	layout->addChild(input_priority_5);

	auto input_priority_6 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_6->setPosition(395, 34);
	input_priority_6->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-six-tab-2", "")));
	input_priority_6->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-six-tab-2", str));

	});
	layout->addChild(input_priority_6);

    auto input_priority_7 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_7->setPosition(395, -6);
	input_priority_7->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-seven-tab-2", "")));
	input_priority_7->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-seven-tab-2", str));

	});
	layout->addChild(input_priority_7);

    auto input_priority_8 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_8->setPosition(395, -46);
	input_priority_8->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-eight-tab-2", "")));
	input_priority_8->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-eight-tab-2", str));

	});
	layout->addChild(input_priority_8);

    auto input_priority_9 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_9->setPosition(395, -86);
	input_priority_9->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-nine-tab-2", "")));
	input_priority_9->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-nine-tab-2", str));

	});
	layout->addChild(input_priority_9);

    auto input_priority_10 = TextInput::create(50, "", "bigFont.fnt");
	input_priority_10->setPosition(395, -126);
	input_priority_10->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-ten-tab-2", "")));
	input_priority_10->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>("input-priority-ten-tab-2", str));

	});
	layout->addChild(input_priority_10);


	// Checkboxes

	auto toggle = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox), 1);
	layout->addChild(toggle);
	toggle->setPosition(312, 234);
	toggle->toggle(Mod::get()->getSavedValue<bool>("checkbox-tab-2", false));

	auto toggle_2 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox2), 1);
	toggle_2->toggle(false);
	layout->addChild(toggle_2);
	toggle_2->setPosition(312, 194);
	toggle_2->toggle(Mod::get()->getSavedValue<bool>("checkbox-2-tab-2", false));

	auto toggle_3 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox3), 1);
	toggle_3->toggle(false);
	layout->addChild(toggle_3);
	toggle_3->setPosition(312, 154);
	toggle_3->toggle(Mod::get()->getSavedValue<bool>("checkbox-3-tab-2", false));

	auto toggle_4 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox4), 1);
	toggle_4->toggle(false);
	layout->addChild(toggle_4);
	toggle_4->setPosition(312, 114);
	toggle_4->toggle(Mod::get()->getSavedValue<bool>("checkbox-4-tab-2", false));

	auto toggle_5 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox5), 1);
	toggle_5->toggle(false);
	layout->addChild(toggle_5);
	toggle_5->setPosition(312, 74);
	toggle_5->toggle(Mod::get()->getSavedValue<bool>("checkbox-5-tab-2", false));

	auto toggle_6 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox6), 1);
	layout->addChild(toggle_6);
	toggle_6->setPosition(312, 34);
	toggle_6->toggle(Mod::get()->getSavedValue<bool>("checkbox-6-tab-2", false));

	auto toggle_7 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox7), 1);
	toggle_7->toggle(false);
	layout->addChild(toggle_7);
	toggle_7->setPosition(312, -6);
	toggle_7->toggle(Mod::get()->getSavedValue<bool>("checkbox-7-tab-2", false));

	auto toggle_8 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox8), 1);
	toggle_8->toggle(false);
	layout->addChild(toggle_8);
	toggle_8->setPosition(312, -46);
	toggle_8->toggle(Mod::get()->getSavedValue<bool>("checkbox-8-tab-2", false));

	auto toggle_9 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox9), 1);
	toggle_9->toggle(false);
	layout->addChild(toggle_9);
	toggle_9->setPosition(312, -86);
	toggle_9->toggle(Mod::get()->getSavedValue<bool>("checkbox-9-tab-2", false));

	auto toggle_10 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(Tab2::SaveCheckbox10), 1);
	toggle_10->toggle(false);
	layout->addChild(toggle_10);
	toggle_10->setPosition(312, -126);
	toggle_10->toggle(Mod::get()->getSavedValue<bool>("checkbox-10-tab-2", false));

		
	return true;
}

void Tab2::SaveCheckbox(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-tab-2", false));;
}

void Tab2::SaveCheckbox2(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-2-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-2-tab-2", false));
}

void Tab2::SaveCheckbox3(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-3-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-3-tab-2", false));
}

void Tab2::SaveCheckbox4(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-4-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-4-tab-2", false));
}

void Tab2::SaveCheckbox5(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-5-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-5-tab-2", false));
}

void Tab2::SaveCheckbox6(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-6-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-6-tab-2", false));
}

void Tab2::SaveCheckbox7(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-7-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-7-tab-2", false));
}

void Tab2::SaveCheckbox8(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-8-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-8-tab-2", false));
}

void Tab2::SaveCheckbox9(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-9-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-9-tab-2", false));
}

void Tab2::SaveCheckbox10(CCObject*){
	Mod::get()->setSavedValue<bool>("checkbox-10-tab-2", !Mod::get()->getSavedValue<bool>("checkbox-10-tab-2", false));
}

Tab2* Tab2::create(){
	auto ret = new Tab2();
	if (ret && ret->init()){

		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}