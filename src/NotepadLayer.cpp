#include "NotepadLayer.hpp"
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

bool NotepadLayer::init(){

	if (!Popup::init(440.0f, 280.0f)) 
	return false;

	m_bgSprite->removeFromParentAndCleanup(true);

	geode::cocos::handleTouchPriority(this);

	this->m_noElasticity = true;

	auto screenSize = CCDirector::sharedDirector()->getWinSize();

	auto themePresets = Mod::get()->getSettingValue<std::string>("theme-presets");
	auto customColorTheme = Mod::get()->getSettingValue<ccColor3B>("custom-theme");
	
	// Menus

	auto levelName = CCMenu::create();
	auto touchFixes = CCMenu::create();
	auto numLabels = CCLayer::create();
	auto layout = CCMenu::create();

	numLabels->setID("numbers");
	layout->setID("to-do-list");

	m_mainLayer->addChild(touchFixes, 1);
	touchFixes->setPosition(-64, -19.0f);
	touchFixes->setID("touch-fixes");

	m_mainLayer->addChild(levelName, 1);
	levelName->setPosition(-64.5f, -22.9f);
	levelName->setID("level-name");

	m_buttonMenu->setTouchPriority(-507);
	touchFixes->setTouchPriority(-506);
	levelName->setTouchPriority(-507);

	// bg

	auto png = "";

	if (themePresets == "Default"){
		png = "GJ_square01.png";
	}
	else if (themePresets == "Blue"){
		png = "GJ_square02.png";
	}
	else if (themePresets == "Green"){
		png = "GJ_square03.png";
	}
	else if (themePresets == "Purple"){
		png = "GJ_square04.png";
	}
	else if (themePresets == "Gray"){
		png = "GJ_square05.png";
	}
	else if (themePresets == "Geode Theme Color 1"){
		// @geode-ignore(unknown-resource)
		png = "geode.loader/GE_square01.png";
	}
	else if (themePresets == "Geode Theme Color 2"){
		// @geode-ignore(unknown-resource)
		png = "geode.loader/GE_square02.png";
	}
	else if (themePresets == "Geode Theme Color 3"){
		// @geode-ignore(unknown-resource)
		png = "geode.loader/GE_square03.png";
	}

	auto spritebg = CCScale9Sprite::create(png);
	spritebg->setPosition(m_bgSprite->getPosition());
	spritebg->setContentSize({440.0f, 280.0f});
	m_mainLayer->addChild(spritebg);


    if (Mod::get()->getSettingValue<bool>("custom-theme-enable")){

       	auto bgoutline = NineSlice::create("GJ_square07.png");
	    bgoutline->setContentSize({440.0f, 280.0f});

		spritebg->initWithFile("GJ_square06.png");
		spritebg->setColor(customColorTheme);
        spritebg->setContentSize({440.0f, 280.0f});
        spritebg->addChildAtPosition(bgoutline, Anchor::Center);

	}


	// ScrollLayer bg

	auto bg = NineSlice::create("square02_001.png");
	bg->setPosition(211.2f, 118.1f);
	bg->setOpacity(75);
	bg->setContentSize({399, 194.1f});
	m_mainLayer->addChild(bg);

	// touch fix

	auto touchfix = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("block008_topcolor_15_001.png"), this, nullptr);
	touchfix->setPosition(284.5f, 325);
	#ifdef GEODE_IS_WINDOWS
	touchfix->setContentSize({385, 181});
	#endif
	#ifdef GEODE_IS_ANDROID
	touchfix->setContentSize({385, 152});
	#endif
	#ifdef GEODE_IS_MACOS
	touchfix->setContentSize({385, 181});
	#endif
	#ifdef GEODE_IS_IOS
	touchfix->setContentSize({385, 152});
	#endif
	touchFixes->addChild(touchfix);
	touchfix->setOpacity(0);

	auto touchfix2 = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("block008_topcolor_15_001.png"), this, nullptr);
	touchfix2->setPosition(284.5f, -50);
	#ifdef GEODE_IS_WINDOWS
	touchfix2->setContentSize({385, 181});
	#endif
	#ifdef GEODE_IS_ANDROID
	touchfix2->setContentSize({385, 152});
	#endif
	#ifdef GEODE_IS_MACOS
	touchfix2->setContentSize({385, 181});
	#endif
	#ifdef GEODE_IS_IOS
	touchfix2->setContentSize({385, 152});
	#endif
	touchFixes->addChild(touchfix2);
	touchfix2->setOpacity(0);


	// Labels

	auto first = CCLabelBMFont::create("1.", "bigFont.fnt");
	first->setPosition(32, 236);
	first->setScale(0.6f);
	numLabels->addChild(first);
 
	auto second = CCLabelBMFont::create("2.", "bigFont.fnt");
	second->setPosition(32, 196);
	second->setScale(0.6f);
	numLabels->addChild(second);
 
	auto third = CCLabelBMFont::create("3.", "bigFont.fnt");
	third->setPosition(32, 156);
	third->setScale(0.6f);
	numLabels->addChild(third);
 
	auto fourth = CCLabelBMFont::create("4.", "bigFont.fnt");
	fourth->setPosition(32, 116);
	fourth->setScale(0.6f);
	numLabels->addChild(fourth);
 
	auto fifth = CCLabelBMFont::create("5.", "bigFont.fnt");
	fifth->setPosition(32, 76);
	fifth->setScale(0.6f);
	numLabels->addChild(fifth);
 
	auto sixth = CCLabelBMFont::create("6.", "bigFont.fnt");
	sixth->setPosition(32, 36);
	sixth->setScale(0.6f);
	numLabels->addChild(sixth);
 
	auto seventh = CCLabelBMFont::create("7.", "bigFont.fnt");
	seventh->setPosition(32, -4);
	seventh->setScale(0.6f);
	numLabels->addChild(seventh);
 
	auto eighth = CCLabelBMFont::create("8.", "bigFont.fnt");
	eighth->setPosition(32, -44);
	eighth->setScale(0.6f);
	numLabels->addChild(eighth);
 
	auto ninth = CCLabelBMFont::create("9.", "bigFont.fnt");
	ninth->setPosition(32, -84);
	ninth->setScale(0.6f);
	numLabels->addChild(ninth);
 
	auto tenth = CCLabelBMFont::create("10.", "bigFont.fnt");
	tenth->setPosition(32, -124);
	tenth->setScale(0.6f);
	numLabels->addChild(tenth);

	// TextInputs
		
	m_input1 = TextInput::create(200, "", "bigFont.fnt");
	m_input1->setPosition(153, 234);
	m_input1->setString(Mod::get()->getSavedValue<std::string>(m_inputTab1));
	m_input1->setCommonFilter(CommonFilter::Any);
	m_input1->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab1, str));

	});
	layout->addChild(m_input1);

	m_input2 = TextInput::create(200, "", "bigFont.fnt");
	m_input2->setPosition(153, 194);
	m_input2->setString(Mod::get()->getSavedValue<std::string>(m_inputTab2));
	m_input2->setCommonFilter(CommonFilter::Any);
	m_input2->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab2, str));

	});
	layout->addChild(m_input2);

	m_input3 = TextInput::create(200, "", "bigFont.fnt");
	m_input3->setPosition(153, 154);
	m_input3->setString(Mod::get()->getSavedValue<std::string>(m_inputTab3));
	m_input3->setCommonFilter(CommonFilter::Any);
	m_input3->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab3, str));

	});
	layout->addChild(m_input3);

	m_input4 = TextInput::create(200, "", "bigFont.fnt");
	m_input4->setPosition(153, 114);
	m_input4->setString(Mod::get()->getSavedValue<std::string>(m_inputTab4));
	m_input4->setCommonFilter(CommonFilter::Any);
	m_input4->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab4, str));

	});
	layout->addChild(m_input4);

	m_input5 = TextInput::create(200, "", "bigFont.fnt");
	m_input5->setPosition(153, 74);
	m_input5->setString(Mod::get()->getSavedValue<std::string>(m_inputTab5));
	m_input5->setCommonFilter(CommonFilter::Any);
	m_input5->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab5, str));

	});
	layout->addChild(m_input5);

	m_input6 = TextInput::create(200, "", "bigFont.fnt");
	m_input6->setPosition(153, 34);
	m_input6->setString(Mod::get()->getSavedValue<std::string>(m_inputTab6));
	m_input6->setCommonFilter(CommonFilter::Any);
	m_input6->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab6, str));

	});
	layout->addChild(m_input6);

	m_input7 = TextInput::create(200, "", "bigFont.fnt");
	m_input7->setPosition(153, -6);
	m_input7->setString(Mod::get()->getSavedValue<std::string>(m_inputTab7));
	m_input7->setCommonFilter(CommonFilter::Any);
	m_input7->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab7, str));

	});
	layout->addChild(m_input7);

	m_input8 = TextInput::create(200, "", "bigFont.fnt");
	m_input8->setPosition(153, -46);
	m_input8->setString(Mod::get()->getSavedValue<std::string>(m_inputTab8));
	m_input8->setCommonFilter(CommonFilter::Any);
	m_input8->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab8, str));

	});
	layout->addChild(m_input8);

	m_input9 = TextInput::create(200, "", "bigFont.fnt");
	m_input9->setPosition(153, -86);
	m_input9->setString(Mod::get()->getSavedValue<std::string>(m_inputTab9));
	m_input9->setCommonFilter(CommonFilter::Any);
	m_input9->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab9, str));

	});
	layout->addChild(m_input9);

	m_input10 = TextInput::create(200, "", "bigFont.fnt");
	m_input10->setPosition(153, -126);
	m_input10->setString(Mod::get()->getSavedValue<std::string>(m_inputTab10));
	m_input10->setCommonFilter(CommonFilter::Any);
	m_input10->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputTab10, str));

	});
	layout->addChild(m_input10);


	// Priority

    m_inputPriority1 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority1->setPosition(348, 234);
	m_inputPriority1->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString1));
	m_inputPriority1->setCommonFilter(CommonFilter::Any);
	m_inputPriority1->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString1, str));

	});
	layout->addChild(m_inputPriority1);

   	m_inputPriority2 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority2->setPosition(348, 194);
	m_inputPriority2->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString2));
	m_inputPriority2->setCommonFilter(CommonFilter::Any);
	m_inputPriority2->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString2, str));

	});
	layout->addChild(m_inputPriority2);

   	m_inputPriority3 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority3->setPosition(348, 154);
	m_inputPriority3->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString3));
	m_inputPriority3->setCommonFilter(CommonFilter::Any);
	m_inputPriority3->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString3, str));

	});
	layout->addChild(m_inputPriority3);

   	m_inputPriority4 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority4->setPosition(348, 114);
	m_inputPriority4->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString4));
	m_inputPriority4->setCommonFilter(CommonFilter::Any);
	m_inputPriority4->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString4, str));

	});
	layout->addChild(m_inputPriority4);

    m_inputPriority5 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority5->setPosition(348, 74);
	m_inputPriority5->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString5));
	m_inputPriority5->setCommonFilter(CommonFilter::Any);
	m_inputPriority5->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString5, str));

	});
	layout->addChild(m_inputPriority5);

	m_inputPriority6 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority6->setPosition(348, 34);
	m_inputPriority6->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString6));
	m_inputPriority6->setCommonFilter(CommonFilter::Any);
	m_inputPriority6->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString6, str));

	});
	layout->addChild(m_inputPriority6);

    m_inputPriority7 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority7->setPosition(348, -6);
	m_inputPriority7->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString7));
	m_inputPriority7->setCommonFilter(CommonFilter::Any);
	m_inputPriority7->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString7, str));

	});
	layout->addChild(m_inputPriority7);

   	m_inputPriority8 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority8->setPosition(348, -46);
	m_inputPriority8->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString8));
	m_inputPriority8->setCommonFilter(CommonFilter::Any);
	m_inputPriority8->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString8, str));

	});
	layout->addChild(m_inputPriority8);

    m_inputPriority9 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority9->setPosition(348, -86);
	m_inputPriority9->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString9));
	m_inputPriority9->setCommonFilter(CommonFilter::Any);
	m_inputPriority9->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString9, str));

	});
	layout->addChild(m_inputPriority9);

    m_inputPriority10 = TextInput::create(50, "", "bigFont.fnt");
	m_inputPriority10->setPosition(348, -126);
	m_inputPriority10->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString10));
	m_inputPriority10->setCommonFilter(CommonFilter::Any);
	m_inputPriority10->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_inputPriorityString10, str));

	});
	layout->addChild(m_inputPriority10);

	// Checkboxes

	m_toggle1 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox1), 1);
	layout->addChild(m_toggle1);
	m_toggle1->setPosition(288, 234);
	m_toggle1->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab1, false));

	m_toggle2 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox2), 1);
	layout->addChild(m_toggle2);
	m_toggle2->setPosition(288, 194);
	m_toggle2->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab2, false));

	m_toggle3 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox3), 1);
	layout->addChild(m_toggle3);
	m_toggle3->setPosition(288, 154);
	m_toggle3->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab3, false));

	m_toggle4 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox4), 1);
	layout->addChild(m_toggle4);
	m_toggle4->setPosition(288, 114);
	m_toggle4->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab4, false));

	m_toggle5 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox5), 1);
	layout->addChild(m_toggle5);
	m_toggle5->setPosition(288, 74);
	m_toggle5->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab5, false));

	m_toggle6 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox6), 1);
	layout->addChild(m_toggle6);
	m_toggle6->setPosition(288, 34);
	m_toggle6->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab6, false));

	m_toggle7 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox7), 1);
	layout->addChild(m_toggle7);
	m_toggle7->setPosition(288, -6);
	m_toggle7->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab7, false));

	m_toggle8 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox8), 1);
	layout->addChild(m_toggle8);
	m_toggle8->setPosition(288, -46);
	m_toggle8->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab8, false));

	m_toggle9 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox9), 1);
	layout->addChild(m_toggle9);
	m_toggle9->setPosition(288, -86);
	m_toggle9->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab9, false));

	m_toggle10 = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(NotepadLayer::saveCheckbox10), 1);
	layout->addChild(m_toggle10);
	m_toggle10->setPosition(288, -126);
	m_toggle10->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab10, false));

	// Clear Row Buttons

	auto onClearRowSpr = CCSprite::createWithSpriteFrameName("GJ_trashBtn_001.png");
	onClearRowSpr->setScale(0.75f);

	auto clearRowBtn1 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow1));
	layout->addChild(clearRowBtn1);
	clearRowBtn1->setPosition(404, 234);

	auto clearRowBtn2 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow2));
	layout->addChild(clearRowBtn2);
	clearRowBtn2->setPosition(404, 194);

	auto clearRowBtn3 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow3));
	layout->addChild(clearRowBtn3);
	clearRowBtn3->setPosition(404, 154);

	auto clearRowBtn4 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow4));
	layout->addChild(clearRowBtn4);
	clearRowBtn4->setPosition(404, 114);

	auto clearRowBtn5 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow5));
	layout->addChild(clearRowBtn5);
	clearRowBtn5->setPosition(404, 74);

	auto clearRowBtn6 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow6));
	layout->addChild(clearRowBtn6);
	clearRowBtn6->setPosition(404, 34);

	auto clearRowBtn7 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow7));
	layout->addChild(clearRowBtn7);
	clearRowBtn7->setPosition(404, -6);

	auto clearRowBtn8 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow8));
	layout->addChild(clearRowBtn8);
	clearRowBtn8->setPosition(404, -46);

	auto clearRowBtn9 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow9));
	layout->addChild(clearRowBtn9);
	clearRowBtn9->setPosition(404, -86);

	auto clearRowBtn10 = CCMenuItemSpriteExtra::create(onClearRowSpr, this, menu_selector(NotepadLayer::onClearRow10));
	layout->addChild(clearRowBtn10);
	clearRowBtn10->setPosition(404, -126);


	// Buttons

	auto onSettingsSpr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
	onSettingsSpr->setScale(0.6f);

	auto onSettingsBtn = CCMenuItemSpriteExtra::create(onSettingsSpr, this, menu_selector(NotepadLayer::onSettings));
	m_buttonMenu->addChild(onSettingsBtn);
	onSettingsBtn->setID("settings");
	onSettingsBtn->setPosition(411, 254);

	auto onClearSpr = CCSprite::createWithSpriteFrameName("GJ_trashBtn_001.png");
	onClearSpr->setScale(0.725f);

	auto clearAllBtn = CCMenuItemSpriteExtra::create(onClearSpr, this, menu_selector(NotepadLayer::onClearAll));
	m_buttonMenu->addChild(clearAllBtn);
	clearAllBtn->setID("clear-all");
	clearAllBtn->setPosition(375, 254);

	// Level Name

	auto levelNameLabel = CCTextInputNode::create(250, 0, "", "goldFont.fnt");
	levelNameLabel->setPosition(284.5f, 271);
	levelNameLabel->setString(Mod::get()->getSavedValue<std::string>("editor-level-name"));
	levelName->addChild(levelNameLabel);

	// ScrollLayer

	m_scroll = ScrollLayer::create({420, 204.4f}, true, true);
	m_scroll->m_contentLayer->addChild(numLabels);
	m_scroll->m_contentLayer->addChild(layout);	

	m_scroll->m_contentLayer->setLayout(

		ColumnLayout::create()
		->setAxisReverse(true)
        ->setAxisAlignment(AxisAlignment::End)
		->setAutoGrowAxis(500)

	);
	m_scroll->m_contentLayer->setPositionY(-208.1f);
	m_scroll->m_contentLayer->setContentHeight(412.5f);
	m_scroll->setScale(0.95f);
	m_scroll->setPosition(1.2f, 16.2f);
	m_mainLayer->addChild(m_scroll);

	auto scrollbar = Scrollbar::create(m_scroll);
	scrollbar->setPosition(423.7f, 118.25f);
	scrollbar->setScaleX(1.25f);
	m_mainLayer->addChild(scrollbar);

	layout->setPosition(screenSize / 2 + CCPoint{-11, 151});
	numLabels->setPosition(screenSize / 2 + CCPoint{-11, 151});
		
	return true;
}

void NotepadLayer::onSettings(CCObject*){
	this->removeFromParentAndCleanup(true);
	geode::openSettingsPopup(Mod::get());
}

void NotepadLayer::onClearAll(CCObject*){

	geode::createQuickPopup("Clear All Rows", "Are you sure you want to <cr>clear</c> all rows?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input1->setString(Mod::get()->getSavedValue<std::string>(m_inputTab1, Mod::get()->setSavedValue<std::string>(m_inputTab1, "")));
			m_input2->setString(Mod::get()->getSavedValue<std::string>(m_inputTab2, Mod::get()->setSavedValue<std::string>(m_inputTab2, "")));
			m_input3->setString(Mod::get()->getSavedValue<std::string>(m_inputTab3, Mod::get()->setSavedValue<std::string>(m_inputTab3, "")));
			m_input4->setString(Mod::get()->getSavedValue<std::string>(m_inputTab4, Mod::get()->setSavedValue<std::string>(m_inputTab4, "")));
			m_input5->setString(Mod::get()->getSavedValue<std::string>(m_inputTab5, Mod::get()->setSavedValue<std::string>(m_inputTab5, "")));
			m_input6->setString(Mod::get()->getSavedValue<std::string>(m_inputTab6, Mod::get()->setSavedValue<std::string>(m_inputTab6, "")));
			m_input7->setString(Mod::get()->getSavedValue<std::string>(m_inputTab7, Mod::get()->setSavedValue<std::string>(m_inputTab7, "")));
			m_input8->setString(Mod::get()->getSavedValue<std::string>(m_inputTab8, Mod::get()->setSavedValue<std::string>(m_inputTab8, "")));
			m_input9->setString(Mod::get()->getSavedValue<std::string>(m_inputTab9, Mod::get()->setSavedValue<std::string>(m_inputTab9, "")));
			m_input10->setString(Mod::get()->getSavedValue<std::string>(m_inputTab10, Mod::get()->setSavedValue<std::string>(m_inputTab10, "")));

			m_inputPriority1->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString1, Mod::get()->setSavedValue<std::string>(m_inputPriorityString1, "")));
			m_inputPriority2->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString2, Mod::get()->setSavedValue<std::string>(m_inputPriorityString2, "")));
			m_inputPriority3->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString3, Mod::get()->setSavedValue<std::string>(m_inputPriorityString3, "")));
			m_inputPriority4->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString4, Mod::get()->setSavedValue<std::string>(m_inputPriorityString4, "")));
			m_inputPriority5->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString5, Mod::get()->setSavedValue<std::string>(m_inputPriorityString5, "")));
			m_inputPriority6->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString6, Mod::get()->setSavedValue<std::string>(m_inputPriorityString6, "")));
			m_inputPriority7->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString7, Mod::get()->setSavedValue<std::string>(m_inputPriorityString7, "")));
			m_inputPriority8->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString8, Mod::get()->setSavedValue<std::string>(m_inputPriorityString8, "")));
			m_inputPriority9->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString9, Mod::get()->setSavedValue<std::string>(m_inputPriorityString9, "")));
			m_inputPriority10->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString10, Mod::get()->setSavedValue<std::string>(m_inputPriorityString10, "")));

			m_toggle1->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab1, Mod::get()->setSavedValue<bool>(m_toggleTab1, false)));
			m_toggle2->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab2, Mod::get()->setSavedValue<bool>(m_toggleTab2, false)));
			m_toggle3->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab3, Mod::get()->setSavedValue<bool>(m_toggleTab3, false)));
			m_toggle4->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab4, Mod::get()->setSavedValue<bool>(m_toggleTab4, false)));
			m_toggle5->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab5, Mod::get()->setSavedValue<bool>(m_toggleTab5, false)));
			m_toggle6->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab6, Mod::get()->setSavedValue<bool>(m_toggleTab6, false)));
			m_toggle7->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab7, Mod::get()->setSavedValue<bool>(m_toggleTab7, false)));
			m_toggle8->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab8, Mod::get()->setSavedValue<bool>(m_toggleTab8, false)));
			m_toggle9->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab9, Mod::get()->setSavedValue<bool>(m_toggleTab9, false)));
			m_toggle10->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab10, Mod::get()->setSavedValue<bool>(m_toggleTab10, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow1(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input1->setString(Mod::get()->getSavedValue<std::string>(m_inputTab1, Mod::get()->setSavedValue<std::string>(m_inputTab1, "")));
			m_inputPriority1->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString1, Mod::get()->setSavedValue<std::string>(m_inputPriorityString1, "")));
			m_toggle1->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab1, Mod::get()->setSavedValue<bool>(m_toggleTab1, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow2(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input2->setString(Mod::get()->getSavedValue<std::string>(m_inputTab2, Mod::get()->setSavedValue<std::string>(m_inputTab2, "")));
			m_inputPriority2->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString2, Mod::get()->setSavedValue<std::string>(m_inputPriorityString2, "")));
			m_toggle2->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab2, Mod::get()->setSavedValue<bool>(m_toggleTab2, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow3(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input3->setString(Mod::get()->getSavedValue<std::string>(m_inputTab3, Mod::get()->setSavedValue<std::string>(m_inputTab3, "")));
			m_inputPriority3->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString3, Mod::get()->setSavedValue<std::string>(m_inputPriorityString3, "")));
			m_toggle3->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab3, Mod::get()->setSavedValue<bool>(m_toggleTab3, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow4(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input4->setString(Mod::get()->getSavedValue<std::string>(m_inputTab4, Mod::get()->setSavedValue<std::string>(m_inputTab4, "")));
			m_inputPriority4->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString4, Mod::get()->setSavedValue<std::string>(m_inputPriorityString4, "")));
			m_toggle4->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab4, Mod::get()->setSavedValue<bool>(m_toggleTab4, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow5(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input5->setString(Mod::get()->getSavedValue<std::string>(m_inputTab5, Mod::get()->setSavedValue<std::string>(m_inputTab5, "")));
			m_inputPriority5->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString5, Mod::get()->setSavedValue<std::string>(m_inputPriorityString5, "")));
			m_toggle5->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab5, Mod::get()->setSavedValue<bool>(m_toggleTab5, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow6(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input6->setString(Mod::get()->getSavedValue<std::string>(m_inputTab6, Mod::get()->setSavedValue<std::string>(m_inputTab6, "")));
			m_inputPriority6->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString6, Mod::get()->setSavedValue<std::string>(m_inputPriorityString6, "")));
			m_toggle6->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab6, Mod::get()->setSavedValue<bool>(m_toggleTab6, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow7(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input7->setString(Mod::get()->getSavedValue<std::string>(m_inputTab7, Mod::get()->setSavedValue<std::string>(m_inputTab7, "")));
			m_inputPriority7->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString7, Mod::get()->setSavedValue<std::string>(m_inputPriorityString7, "")));
			m_toggle7->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab7, Mod::get()->setSavedValue<bool>(m_toggleTab7, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow8(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input8->setString(Mod::get()->getSavedValue<std::string>(m_inputTab8, Mod::get()->setSavedValue<std::string>(m_inputTab8, "")));
			m_inputPriority8->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString8, Mod::get()->setSavedValue<std::string>(m_inputPriorityString8, "")));
			m_toggle8->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab8, Mod::get()->setSavedValue<bool>(m_toggleTab8, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow9(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input9->setString(Mod::get()->getSavedValue<std::string>(m_inputTab9, Mod::get()->setSavedValue<std::string>(m_inputTab9, "")));
			m_inputPriority9->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString9, Mod::get()->setSavedValue<std::string>(m_inputPriorityString9, "")));
			m_toggle9->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab9, Mod::get()->setSavedValue<bool>(m_toggleTab9, false)));
            
        }
    });
	
}

void NotepadLayer::onClearRow10(CCObject*){

	geode::createQuickPopup("Clear Row", "Are you sure you want to <cr>clear</c> this row?", "No", "Yes", [this](auto, bool yes) {
        if (yes) {

			m_input10->setString(Mod::get()->getSavedValue<std::string>(m_inputTab10, Mod::get()->setSavedValue<std::string>(m_inputTab10, "")));
			m_inputPriority10->setString(Mod::get()->getSavedValue<std::string>(m_inputPriorityString10, Mod::get()->setSavedValue<std::string>(m_inputPriorityString10, "")));
			m_toggle10->toggle(Mod::get()->getSavedValue<bool>(m_toggleTab10, Mod::get()->setSavedValue<bool>(m_toggleTab10, false)));
            
        }
    });
	
}

void NotepadLayer::saveCheckbox1(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab1, !Mod::get()->getSavedValue<bool>(m_toggleTab1, false));
}

void NotepadLayer::saveCheckbox2(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab2, !Mod::get()->getSavedValue<bool>(m_toggleTab2, false));
}

void NotepadLayer::saveCheckbox3(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab3, !Mod::get()->getSavedValue<bool>(m_toggleTab3, false));
}

void NotepadLayer::saveCheckbox4(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab4, !Mod::get()->getSavedValue<bool>(m_toggleTab4, false));
}

void NotepadLayer::saveCheckbox5(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab5, !Mod::get()->getSavedValue<bool>(m_toggleTab5, false));
}

void NotepadLayer::saveCheckbox6(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab6, !Mod::get()->getSavedValue<bool>(m_toggleTab6, false));
}

void NotepadLayer::saveCheckbox7(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab7, !Mod::get()->getSavedValue<bool>(m_toggleTab7, false));
}

void NotepadLayer::saveCheckbox8(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab8, !Mod::get()->getSavedValue<bool>(m_toggleTab8, false));
}

void NotepadLayer::saveCheckbox9(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab9, !Mod::get()->getSavedValue<bool>(m_toggleTab9, false));
}

void NotepadLayer::saveCheckbox10(CCObject*){
	Mod::get()->setSavedValue<bool>(m_toggleTab10, !Mod::get()->getSavedValue<bool>(m_toggleTab10, false));
}

NotepadLayer* NotepadLayer::create(){
	auto ret = new NotepadLayer();
	if (ret && ret->init()){

		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}