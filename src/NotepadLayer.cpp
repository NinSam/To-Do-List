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

		this->addChild(smallbutton);
		smallbutton->setScale(0.675f);
		smallbutton->setID("small-buttons");
		smallbutton->setPosition(ccp(0,0));
		smallbutton->setZOrder(2);
	
		this->addChild(menu);
		menu->setPosition(ccp(0,0));
		menu->setZOrder(1);

		this->addChild(arrows);
		arrows->setPosition(ccp(0,0));
		arrows->setID("arrows");
		arrows->setZOrder(1);

		// bg

		auto bg = CCScale9Sprite::create("GJ_square01.png");
	    bg->setPosition(screenSize/2);
		bg->setContentSize({466, 280});
		this->addChild(bg);

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
		closebutton->setID("close-button");
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
        page_right->setPosition(ccp(348.5f, 268));
		page_right->setPosition(screenSize/2 + CCPoint{64, 108});
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
	void NotepadLayer::OpenExtras(CCObject*){
		ExtrasLayer::create()->show();
	}

	void NotepadLayer::onPage(CCObject* sender) {
        m_clicked += sender->getTag();

        auto page = static_cast<CCMenuItemSpriteExtra*>(sender);

		// there's definitely a better way but this works for now I spent way too much time on this

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