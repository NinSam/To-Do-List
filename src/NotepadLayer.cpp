#include "NotepadManager.hpp"
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

bool NotepadLayer::setup(){

	geode::cocos::handleTouchPriority(this);

	this->m_noElasticity = true;

	auto screenSize = CCDirector::sharedDirector()->getWinSize();

	auto themePresets = Mod::get()->getSettingValue<std::string>("theme-presets");
	auto customColorTheme = Mod::get()->getSettingValue<ccColor3B>("custom-theme");
	
	// Menus

	auto pageMenu = CCMenu::create();
	auto touchFixes = CCMenu::create();
	auto numLabels = CCLayer::create();

	numLabels->setID("numbers");

	m_mainLayer->addChild(touchFixes, 1);
	touchFixes->setPosition(-64, -19.0f);
	touchFixes->setID("touch-fixes");

	m_mainLayer->addChild(pageMenu, 1);
	pageMenu->setPosition(-64.5f, -22.9f);
	pageMenu->setID("page-menu");

	m_buttonMenu->setTouchPriority(-507);
	touchFixes->setTouchPriority(-506);
	pageMenu->setTouchPriority(-507);

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
		png = "geode.loader/GE_square01.png";
	}
	else if (themePresets == "Geode Theme Color 2"){
		png = "geode.loader/GE_square02.png";
	}
	else if (themePresets == "Geode Theme Color 3"){
		png = "geode.loader/GE_square03.png";
	}

    m_bgSprite->initWithFile(png);
   	m_bgSprite->setContentSize({440.0f, 280.0f});

    if (Mod::get()->getSettingValue<bool>("custom-theme-enable")){

       	auto bgoutline = CCScale9Sprite::create("GJ_square07.png");
	    bgoutline->setContentSize({440.0f, 280.0f});

		m_bgSprite->initWithFile("GJ_square06.png"); 
		m_bgSprite->setColor(customColorTheme);
        m_bgSprite->setContentSize({440.0f, 280.0f});
        m_bgSprite->addChildAtPosition(bgoutline, Anchor::Center);

	}

	// ScrollLayer bg

	auto bg = CCScale9Sprite::create("square02_001.png");
	bg->setPosition(211.2f, 118.1f);
	bg->setOpacity(75);
	bg->setContentSize({399, 194.1f});
	m_mainLayer->addChild(bg);

	// touch fix

	auto touchfix = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("block008_topcolor_15_001.png"), this, menu_selector(NotepadLayer::onTouchFix));
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

	// Settings

	auto settingsspr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
	settingsspr->setScale(0.6f);

	auto openSettings = CCMenuItemSpriteExtra::create(settingsspr, this, menu_selector(NotepadLayer::OpenSettings));
	m_buttonMenu->addChild(openSettings);
	openSettings->setID("settings");
	openSettings->setPosition(411, 254);

	// pageMenu

	m_inputName = TextInput::create(100, "1/5", "bigFont.fnt");
	m_inputName->setPosition(284.5f, 268);
	m_inputName->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>(m_savedValue, "")));
	m_inputName->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_savedValue, str));

	});
	pageMenu->addChild(m_inputName);

	m_pageLeft = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"), this, menu_selector(NotepadLayer::onPage));
	pageMenu->addChild(m_pageLeft);
	m_pageLeft->setTag(4);
	m_pageLeft->setPosition(221.0f, 268.0f);

	auto pageRight = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("edit_rightBtn_001.png"), this, menu_selector(NotepadLayer::onPage));
	pageRight->setPosition(348.0f, 268.0f);
    pageRight->setTag(1);
    pageMenu->addChild(pageRight);

	m_page1 = Tab1::create();
	m_page2 = Tab2::create();
	m_page3 = Tab3::create();
	m_page4 = Tab4::create();
	m_page5 = Tab5::create();

	// ScrollLayer

	m_scroll = ScrollLayer::create({420, 204.4f},true, true);

	m_scroll->m_contentLayer->addChild(numLabels);	
	m_scroll->m_contentLayer->addChild(m_page1);
	m_scroll->m_contentLayer->addChild(m_page2);
	m_scroll->m_contentLayer->addChild(m_page3);
	m_scroll->m_contentLayer->addChild(m_page4);
	m_scroll->m_contentLayer->addChild(m_page5);
	m_scroll->m_contentLayer->setLayout(

		ColumnLayout::create()
		->setAxisReverse(true)
        ->setAxisAlignment(AxisAlignment::End)
		->setAutoGrowAxis(500)

	);
	m_scroll->m_contentLayer->setPositionY(-208);
	m_scroll->m_contentLayer->setContentHeight(412.5f);
	m_scroll->setScale(0.95f);
	m_scroll->setPosition(1.2f, 16.2f);
	m_mainLayer->addChild(m_scroll);
		
	numLabels->setVisible(true);
	m_page1->setVisible(true);

	auto scrollbar = Scrollbar::create(m_scroll);
	scrollbar->setPosition(423.7f, 118.25f);
	m_mainLayer->addChild(scrollbar);

	m_page1->setPosition(screenSize / 2 + CCPoint{-11, 151});
	m_page2->setPositionY(99999);
	m_page3->setPositionY(99999);
	m_page4->setPositionY(99999);
	m_page5->setPositionY(99999);
	numLabels->setPosition(screenSize / 2 + CCPoint{-11, 151});

	scrollbar->setScaleX(1.25f);
		
	return true;
}

void NotepadLayer::onTouchFix(CCObject*){

}

void NotepadLayer::OpenSettings(CCObject*){
	this->removeFromParentAndCleanup(true);
	geode::openSettingsPopup(Mod::get());
}
	
void NotepadLayer::onPage(CCObject* sender) {
    m_page += sender->getTag();
	m_scroll->scrollToTop();

    auto page = static_cast<CCMenuItemSpriteExtra*>(sender);
	auto screenSize = CCDirector::sharedDirector()->getWinSize();

	if (m_page > 0){
		m_page2->setPosition(screenSize / 2 + CCPoint{-11, 151});
		m_page2->setVisible(true);
		m_page1->setPositionY(99999);
		m_page3->setPositionY(99999);
		m_page5->setPositionY(99999);

		m_savedValue = "input-name-1-tab-2";
		m_inputName->setPlaceholder("2/5");
	 	m_pageLeft->setTag(-2);	
				
	}
	if (m_page > 1){
		m_page3->setPosition(screenSize / 2 + CCPoint{-11, 151});
		m_page3->setVisible(true);
		m_page2->setPositionY(99999);
		m_page4->setPositionY(99999);
		m_page1->setPositionY(99999);

		m_savedValue = "input-name-1-tab-3";
		m_inputName->setPlaceholder("3/5");
		m_pageLeft->setTag(-1);
				
	}
	if (m_page > 2){
		m_page4->setPosition(screenSize / 2 + CCPoint{-11, 151});
		m_page4->setVisible(true);
		m_page3->setPositionY(99999);
		m_page5->setPositionY(99999);
		m_page1->setPositionY(99999);

		m_savedValue = "input-name-1-tab-4";
		m_inputName->setPlaceholder("4/5");

	}
	if (m_page > 3){
		m_page5->setPosition(screenSize / 2 + CCPoint{-11, 151});
		m_page5->setVisible(true);
		m_page4->setPositionY(99999);
		m_page1->setPositionY(99999);
		m_page2->setPositionY(99999);

		m_savedValue = "input-name-1-tab-5";
		m_inputName->setPlaceholder("5/5");
		m_pageLeft->setTag(-1);
				
	}
	if (m_page > 4){
		m_page1->setPosition(screenSize / 2 + CCPoint{-11, 151});
		m_page1->setVisible(true);
		m_page5->setPositionY(99999);
		m_page2->setPositionY(99999);
		m_page4->setPositionY(99999);

		m_savedValue = "input-name-1-tab-1";
		m_inputName->setPlaceholder("1/5");
		m_pageLeft->setTag(4);
		
		m_page = 0;
	}

	m_inputName->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>(m_savedValue, "")));
	m_inputName->setCallback([this](std::string const& str){

    (Mod::get()->setSavedValue<std::string>(m_savedValue, str));
		
	});
}

NotepadLayer* NotepadLayer::create(){
	auto ret = new NotepadLayer();
	if (ret && ret->initAnchored(440.0f, 280.0f)){

		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}