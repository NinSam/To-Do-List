#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool NotepadLayer::init(){

		if (!FLAlertLayer::init(150))

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();

		auto screenSize = CCDirector::sharedDirector()->getWinSize();
	

		// Menus

		auto menu = CCMenu::create();
		auto smallbutton = CCMenu::create();
		auto arrows = CCMenu::create();
		auto touchfixes = CCMenu::create();
		auto tabs = CCMenu::create();

		this->addChild(smallbutton);
		smallbutton->setScale(0.675f);
		smallbutton->setID("small-buttons");
		smallbutton->setPosition(0,0);
		smallbutton->setZOrder(2);
		smallbutton->setTouchPriority(-507);
	
		this->addChild(menu);
		menu->setPosition(0,0);
		menu->setZOrder(1);
		menu->setID("close-button");

		this->addChild(touchfixes);
		touchfixes->setPosition(0,0);
		touchfixes->setID("touchfixes");
		touchfixes->setZOrder(1);
		touchfixes->setTouchPriority(-506);

		this->addChild(tabs);
		tabs->setPosition(0,0);
		tabs->setID("tabs");
		tabs->setZOrder(1);
		tabs->setTouchPriority(-508);

		this->addChild(arrows);
		arrows->setPosition(0,0);
		arrows->setID("arrows");
		arrows->setZOrder(1);
		arrows->setTouchPriority(-507);

		// bg

		auto bg = CCScale9Sprite::create("GJ_square01.png");
	    bg->setPosition(screenSize/2);
		bg->setContentSize({466, 280});
		this->addChild(bg);


		// Tabs (touch fix)

		TextInput* inputname_1 = TextInput::create(100,"1/5","bigFont.fnt");
		inputname_1->setPosition(screenSize/2 + CCPoint{0, 108});
		inputname_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-1-tab-1", "")));
		inputname_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-1-tab-1", str));
		
		});
		tabs->addChild(inputname_1);

		TextInput* inputname_2 = TextInput::create(100,"2/5","bigFont.fnt");
		inputname_2->setPosition(screenSize/2 + CCPoint{0, 108});
		inputname_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-2-tab-2", "")));
		inputname_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-2-tab-2", str));
		
		});
		tabs->addChild(inputname_2);

		TextInput* inputname_3 = TextInput::create(100,"3/5","bigFont.fnt");
		inputname_3->setPosition(screenSize/2 + CCPoint{0, 108});
		inputname_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-2-tab-2", "")));
		inputname_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-3-tab-3", str));
		
		});
		tabs->addChild(inputname_3);

		TextInput* inputname_4 = TextInput::create(100,"4/5","bigFont.fnt");
		inputname_4->setPosition(screenSize/2 + CCPoint{0, 108});
		inputname_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-4-tab-4", "")));
		inputname_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-4-tab-4", str));
		
		});
		tabs->addChild(inputname_4);

		TextInput* inputname_5 = TextInput::create(100,"5/5","bigFont.fnt");
		inputname_5->setPosition(screenSize/2 + CCPoint{0, 108});
		inputname_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-5-tab-5", "")));
		inputname_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-5-tab-5", str));
		
		});
		tabs->addChild(inputname_5);

		// touch fix

		auto touchfix_3 = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("block008_topcolor_15_001.png"),
			this,
			menu_selector(NotepadLayer::Nothing)
		);
		touchfix_3->setPosition(screenSize/2 + CCPoint{0,170});
		touchfix_3->setContentSize({385, 181});
		touchfixes->addChild(touchfix_3);
		touchfix_3->setOpacity(0);


		// outline

		auto outline = CCScale9Sprite::createWithSpriteFrameName("block008_topcolor_15_001.png");
		outline->setPosition(screenSize/2 + CCPoint{0,80});
		outline->setContentSize({461, 2.5f});
		this->addChild(outline);
		outline->setColor(ccc3(0,0,0));


		// Buttons

		auto closebutton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(NotepadLayer::Close)
		);
		menu->addChild(closebutton);
	    closebutton->setPosition(screenSize/2 + CCPoint{-231.5f, 135});

		auto openextras = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_menuBtn_001.png"),
			this,
			menu_selector(NotepadLayer::OpenExtras)
		);
		smallbutton->addChild(openextras);
		openextras->setID("open-extras");
		openextras->setPosition(screenSize/2 + CCPoint{292.5f, 164});

		// Tabs

		CCMenuItemSpriteExtra* page_5 = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(NotepadLayer::onPage)
		);
		arrows->addChild(page_5);
		page_5->setTag(4);
		page_5->setPosition(screenSize/2 + CCPoint{-63.5f, 108});

		CCMenuItemSpriteExtra* page_1_fix = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(NotepadLayer::onPage)
		);
		arrows->addChild(page_1_fix);
		page_1_fix->setTag(-2);
		page_1_fix->setPosition(screenSize/2 + CCPoint{-63.5f, 108});


		CCMenuItemSpriteExtra* page_left = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(NotepadLayer::onPage)
		);
		arrows->addChild(page_left);
		page_left->setTag(-1);
		page_left->setPosition(screenSize/2 + CCPoint{-63.5f, 108});

		CCMenuItemSpriteExtra* page_right = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("edit_rightBtn_001.png"),
            this,
            menu_selector(NotepadLayer::onPage)
        );
		page_right->setPosition(screenSize/2 + CCPoint{64, 108});
        page_right->setTag(1);
        arrows->addChild(page_right);

		auto tab1 = Tab1::create();
		this->addChild(tab1);
		tab1->setPosition(0,0);

		auto tab2 = Tab2::create();
		this->addChild(tab2);
		tab2->setPositionX(0);

		auto tab3 = Tab3::create();
		this->addChild(tab3);
		tab3->setPositionX(0);

		auto tab4 = Tab4::create();
		this->addChild(tab4);
		tab4->setPositionX(0);

		auto tab5 = Tab5::create();
		this->addChild(tab5);
		tab5->setPositionX(0);

		tab2->setPositionY(99999); // to fix scrollbar issues. TableView might fix the scrollwheel issue between tabs but not really sure how to set it up properly. I spent way too many late nighters fixing these bugs lol.
		tab3->setPositionY(99999);
		tab4->setPositionY(99999);
		tab5->setPositionY(99999);

		inputname_2->setVisible(false);
		inputname_3->setVisible(false);
		inputname_4->setVisible(false);
		inputname_5->setVisible(false);


        m_page1 = tab1;
		m_page2 = tab2;
		m_page3 = tab3;
		m_page4 = tab4;
		m_page5 = tab5;

		m_inputname_1 = inputname_1;
		m_inputname_2 = inputname_2;
		m_inputname_3 = inputname_3;
		m_inputname_4 = inputname_4;
		m_inputname_5 = inputname_5;
		
		m_page_5 = page_5;
		m_page_left = page_left;

		m_page_1_fix = page_1_fix;

		m_page_left->setVisible(false);
		page_1_fix->setVisible(false);


		// this
		
		this->setTouchEnabled(true);
		this->updateLayout();
		
		return true;

	}
	void NotepadLayer::Close(CCObject* sender){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
	}
	void NotepadLayer::OpenExtras(CCObject*){
		ExtrasLayer::create()->show();
	}

	void NotepadLayer::onPage(CCObject* sender) {
        m_clicked += sender->getTag();

        auto page = static_cast<CCMenuItemSpriteExtra*>(sender);

		// there's definitely a better way but this works for now I spent way too much time on this

			if (m_clicked > 0){
				m_page2->setPositionY(0);
				m_page1->setPositionY(99999);
				m_page3->setPositionY(99999);
				m_page5->setPositionY(99999);

				m_inputname_2->setVisible(true);
				m_inputname_1->setVisible(false);
				m_inputname_3->setVisible(false);
				m_inputname_5->setVisible(false);

				m_page_5->setVisible(false);
				m_page_left->setVisible(false);
				m_page_1_fix->setVisible(true);
				
			}
			if (m_clicked > 1){
				m_page3->setPositionY(0);
				m_page2->setPositionY(99999);
				m_page4->setPositionY(99999);
				m_page1->setPositionY(99999);

				m_inputname_3->setVisible(true);
				m_inputname_2->setVisible(false);
				m_inputname_4->setVisible(false);
				m_inputname_1->setVisible(false);

				m_page_1_fix->setVisible(false);
				m_page_left->setVisible(true);
				
			}
			if (m_clicked > 2){
				m_page4->setPositionY(0);
				m_page3->setPositionY(99999);
				m_page5->setPositionY(99999);
				m_page1->setPositionY(99999);

				m_inputname_4->setVisible(true);
				m_inputname_3->setVisible(false);
				m_inputname_5->setVisible(false);
				m_inputname_1->setVisible(false);

			}
			if (m_clicked > 3){
				m_page5->setPositionY(0);
				m_page4->setPositionY(99999);
				m_page1->setPositionY(99999);
				m_page2->setPositionY(99999);

				m_inputname_5->setVisible(true);
				m_inputname_4->setVisible(false);
				m_inputname_1->setVisible(false);
				m_inputname_2->setVisible(false);

				m_page_1_fix->setVisible(false);
				m_page_left->setVisible(true);
				
			}
			if (m_clicked > 4){
				m_page1->setPositionY(0);
				m_page5->setPositionY(99999);
				m_page2->setPositionY(99999);
				m_page4->setPositionY(99999);

				m_inputname_5->setVisible(false);
				m_inputname_1->setVisible(true);
				m_inputname_2->setVisible(false);
				m_inputname_4->setVisible(false);

				m_page_5->setVisible(true);
				m_page_left->setVisible(false);
				m_page_1_fix->setVisible(false);

				m_clicked = 0;
			}
    }
	void NotepadLayer::Nothing(CCObject* sender){
	
	}

	NotepadLayer* NotepadLayer::create(){
		auto ret = new NotepadLayer;
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}