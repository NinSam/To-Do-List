#include <Geode/ui/GeodeUI.hpp>
#include "NotepadManager.hpp"

using namespace geode::prelude;

	bool NotepadLayer::init(){

		if (!FLAlertLayer::init(150))

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
		auto screenSize = CCDirector::get()->getWinSize();
		
		// ->setPosition(CCPoint{screenSize.width / 2 - 200, screenSize.height -10});

		// Menus

		auto menu = CCMenu::create();
		auto layout = CCMenu::create();
		auto smallbutton = CCMenu::create();
		auto arrows = CCMenu::create();

		this->addChild(smallbutton);
		smallbutton->setPosition({75,0});
		smallbutton->setScale(0.675f * relativescale);
		smallbutton->setID("small-buttons");
		smallbutton->setZOrder(2);
	
		this->addChild(menu);
		menu->setPosition({0,0});
		menu->setZOrder(1);

		this->addChild(arrows);
		arrows->setPosition({0,0});
		arrows->setID("arrows");
		arrows->setZOrder(1);
		arrows->setScale(0.8f * relativescale);

		this->addChild(layout);
		layout->setPosition({0,35});
		layout->setScale(0.5f * relativescale);
		layout->setID("number-layout");
		layout->setZOrder(3);

		// bg

		CCScale9Sprite* bg = CCScale9Sprite::create("GJ_square01.png");
	    bg->setPosition({284.5f,160.0f});
		bg->setContentSize({213, 280});
		this->addChild(bg);


        // Labels

		CCLabelBMFont* goldtext = CCLabelBMFont::create("To-Do List", "goldFont.fnt");
		goldtext->setPosition({289.5f, 278});
		menu->addChild(goldtext);
		goldtext->setScale(0.8f * relativescale);

		CCLabelBMFont* first = CCLabelBMFont::create("1.", "bigFont.fnt");
		first->setPosition({109, 207});
		first->setScale(0.7f * relativescale);
		layout->addChild(first);

		CCLabelBMFont* second = CCLabelBMFont::create("2.", "bigFont.fnt");
		second->setPosition({109, 167});
		second->setScale(0.7f * relativescale);
		layout->addChild(second);

		CCLabelBMFont* third = CCLabelBMFont::create("3.", "bigFont.fnt");
		third->setPosition({109, 127});
		third->setScale(0.7f * relativescale);
		layout->addChild(third);

		CCLabelBMFont* fourth = CCLabelBMFont::create("4.", "bigFont.fnt");
		fourth->setPosition({109, 87});
		fourth->setScale(0.7f * relativescale);
		layout->addChild(fourth);

		CCLabelBMFont* fifth = CCLabelBMFont::create("5.", "bigFont.fnt");
		fifth->setPosition({109, 47});
		fifth->setScale(0.7f * relativescale);
		layout->addChild(fifth);

		CCLabelBMFont* sixth = CCLabelBMFont::create("6.", "bigFont.fnt");
		sixth->setPosition({109, 7});
		sixth->setScale(0.7f * relativescale);
		layout->addChild(sixth);

		CCLabelBMFont* seventh = CCLabelBMFont::create("7.", "bigFont.fnt");
		seventh->setPosition({109, -33});
		seventh->setScale(0.7f * relativescale);
		layout->addChild(seventh);

		CCLabelBMFont* eighth = CCLabelBMFont::create("8.", "bigFont.fnt");
		eighth->setPosition({109, -73});
		eighth->setScale(0.7f * relativescale);
		layout->addChild(eighth);

		CCLabelBMFont* ninth = CCLabelBMFont::create("9.", "bigFont.fnt");
		ninth->setPosition({109, -113});
		ninth->setScale(0.7f * relativescale);
		layout->addChild(ninth);

		CCLabelBMFont* tenth = CCLabelBMFont::create("10.", "bigFont.fnt");
		tenth->setPosition({109, -153});
		tenth->setScale(0.7f * relativescale);
		layout->addChild(tenth);

		// Buttons

		CCMenuItemSpriteExtra* closebutton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(NotepadLayer::Close)
		);
		menu->addChild(closebutton);
		closebutton->setID("close-button");
		closebutton->setPosition({180, 295});

		CCMenuItemSpriteExtra* opensettings = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
			this,
			menu_selector(NotepadLayer::OpenSettings)
		);
		smallbutton->addChild(opensettings);
		opensettings->setID("open-settings");
		opensettings->setPosition({297, 333});

		CCMenuItemSpriteExtra* info = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png"),
			this,
			menu_selector(NotepadLayer::Info)
		);
		smallbutton->addChild(info);
		info->setID("info");
		info->setPosition({73, 332});

		// Tabs

		CCMenuItemSpriteExtra* page_5 = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(NotepadLayer::onPage)
		);
		arrows->addChild(page_5);
		page_5->setTag(4);
		page_5->setPosition({221, 269});

		CCMenuItemSpriteExtra* page_1_fix = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(NotepadLayer::onPage)
		);
		arrows->addChild(page_1_fix);
		page_1_fix->setTag(-2);
		page_1_fix->setPosition({221, 269});


		CCMenuItemSpriteExtra* page_left = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(NotepadLayer::onPage)
		);
		arrows->addChild(page_left);
		page_left->setTag(-1);
		page_left->setPosition({221, 269});

		CCMenuItemSpriteExtra* page_right = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("edit_rightBtn_001.png"),
            this,
            menu_selector(NotepadLayer::onPage)
        );
        page_right->setPosition({348, 269});
        page_right->setTag(1);
        arrows->addChild(page_right);

		auto tab1 = Tab1::create();
		this->addChild(tab1);
		tab1->setPosition({0,0});

		auto tab2 = Tab2::create();
		this->addChild(tab2);
		tab2->setPosition({0,0});

		auto tab3 = Tab3::create();
		this->addChild(tab3);
		tab3->setPosition({0,0});

		auto tab4 = Tab4::create();
		this->addChild(tab4);
		tab4->setPosition({0,0});

		auto tab5= Tab5::create();
		this->addChild(tab5);
		tab5->setPosition({0,0});

		

		tab2->setVisible(false);
		tab3->setVisible(false);
		tab4->setVisible(false);
		tab5->setVisible(false);


        m_page1 = tab1;
		m_page2 = tab2;
		m_page3 = tab3;
		m_page4 = tab4;
		m_page5 = tab5;

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
	void NotepadLayer::Close(CCObject*){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
	}
	void NotepadLayer::OpenSettings(CCObject*){
		geode::openSettingsPopup(Mod::get());
	}
	void NotepadLayer::Info(CCObject*){
		FLAlertLayer::create("Info", "1. Level Name (Tabs). 2. Text Input. 3. Checkbox. 4. Priority (Low, Medium, High)", "OK")->show();
	}

	void NotepadLayer::onPage(CCObject* sender) {
        m_clicked += sender->getTag();

        auto page = static_cast<CCMenuItemSpriteExtra*>(sender);

		// theres definitely a better way but this works for now I spent way too long on this

			if (m_clicked > 0){
				m_page2->setVisible(true);
				m_page1->setVisible(false);
				m_page3->setVisible(false);
				m_page4->setVisible(false);
				m_page5->setVisible(false);

				m_page_5->setVisible(false);
				m_page_left->setVisible(false);
				m_page_1_fix->setVisible(true);
				
			}
			if (m_clicked > 1){
				m_page3->setVisible(true);
				m_page2->setVisible(false);

				m_page4->setVisible(false);
				m_page5->setVisible(false);
				m_page1->setVisible(false);

				m_page_1_fix->setVisible(false);

				m_page_left->setVisible(true);
				
			}
			if (m_clicked > 2){
				m_page4->setVisible(true);
				m_page3->setVisible(false);

				m_page5->setVisible(false);
				m_page2->setVisible(false);
				m_page1->setVisible(false);
			}
			if (m_clicked > 3){
				m_page5->setVisible(true);
				m_page4->setVisible(false);

				m_page1->setVisible(false);
				m_page3->setVisible(false);
				m_page2->setVisible(false);

				m_page_1_fix->setVisible(false);

				m_page_left->setVisible(true);
				
			}
			if (m_clicked > 4){
				m_page5->setVisible(false);
				m_page1->setVisible(true);

				m_page2->setVisible(false);
				m_page3->setVisible(false);
				m_page4->setVisible(false);

				m_page_5->setVisible(true);
				m_page_left->setVisible(false);

				m_page_1_fix->setVisible(false);

				m_clicked = 0;
			}
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