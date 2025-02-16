#include "NotepadManager.hpp"
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

	bool NotepadLayer::setup(){

		if (!FLAlertLayer::init(150))

		return false;

		geode::cocos::handleTouchPriority(this);
		this->registerWithTouchDispatcher();
		this->m_noElasticity = true;

		auto screenSize = CCDirector::sharedDirector()->getWinSize();
	

		// Menus

		auto menu = CCMenu::create();
		auto smallbutton = CCMenu::create();
		auto arrows = CCMenu::create();
		auto touchfixes = CCMenu::create();
		auto tabs = CCMenu::create();
		auto numlabels = CCLayer::create();

		numlabels->setID("numbers");

		m_mainLayer->addChild(smallbutton,2);
		smallbutton->setScale(0.8f);
		smallbutton->setID("small-buttons");
		smallbutton->setPosition(0,0);
	
		m_mainLayer->addChild(menu,1);
		menu->setPosition(0,0);
		menu->setID("close-button");

		m_mainLayer->addChild(touchfixes,1);
		touchfixes->setPosition(0,0);
		touchfixes->setID("touchfixes");

		m_mainLayer->addChild(tabs,1);
		tabs->setPosition(0,0);
		tabs->setID("tabs");

		m_mainLayer->addChild(arrows,1);
		arrows->setPosition(0,0);
		arrows->setID("arrows");

		// CCTouchDispatcher::get()->addTargetedDelegate(this, int, true);

		menu->setTouchPriority(-508);
		smallbutton->setTouchPriority(-507);
		touchfixes->setTouchPriority(-506);
		arrows->setTouchPriority(-507);
		tabs->setTouchPriority(-506);

		// bg

		auto bg = CCScale9Sprite::create("GJ_square01.png");
	    bg->setPosition(screenSize/2);
		bg->setContentSize({466, 280});
		m_mainLayer->addChild(bg);

		// touch fix

		auto touchfix = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("block008_topcolor_15_001.png"),
			this,
			menu_selector(NotepadLayer::onTouchFix)
		);
		touchfix->setPosition(screenSize/2 + CCPoint{0,170});
		#ifdef GEODE_IS_WINDOWS
		touchfix->setContentSize({385, 181});
		#endif
		#ifdef GEODE_IS_ANDROID
		touchfix->setContentSize({385, 152});
		#endif
		#ifdef GEODE_IS_MACOS
		touchfix->setContentSize({385, 181});
		#endif
		touchfixes->addChild(touchfix);
		touchfix->setOpacity(0);

		// Labels

		auto first = CCLabelBMFont::create("1.", "bigFont.fnt");
		first->setPosition(32, 206);
		first->setScale(0.7f);
		numlabels->addChild(first);
 
		auto second = CCLabelBMFont::create("2.", "bigFont.fnt");
		second->setPosition(32, 166);
		second->setScale(0.7f);
		numlabels->addChild(second);
 
		auto third = CCLabelBMFont::create("3.", "bigFont.fnt");
		third->setPosition(32, 126);
		third->setScale(0.7f);
		numlabels->addChild(third);
 
		auto fourth = CCLabelBMFont::create("4.", "bigFont.fnt");
		fourth->setPosition(32, 86);
		fourth->setScale(0.7f);
		numlabels->addChild(fourth);
 
		auto fifth = CCLabelBMFont::create("5.", "bigFont.fnt");
		fifth->setPosition(32, 46);
		fifth->setScale(0.7f);
		numlabels->addChild(fifth);
 
		auto sixth = CCLabelBMFont::create("6.", "bigFont.fnt");
		sixth->setPosition(32, 6);
		sixth->setScale(0.7f);
		numlabels->addChild(sixth);
 
		auto seventh = CCLabelBMFont::create("7.", "bigFont.fnt");
		seventh->setPosition(32, -34);
		seventh->setScale(0.7f);
		numlabels->addChild(seventh);
 
		auto eighth = CCLabelBMFont::create("8.", "bigFont.fnt");
		eighth->setPosition(32, -74);
		eighth->setScale(0.7f);
		numlabels->addChild(eighth);
 
		auto ninth = CCLabelBMFont::create("9.", "bigFont.fnt");
		ninth->setPosition(32, -114);
		ninth->setScale(0.7f);
		numlabels->addChild(ninth);
 
		auto tenth = CCLabelBMFont::create("10.", "bigFont.fnt");
		tenth->setPosition(32, -154);
		tenth->setScale(0.7f);
		numlabels->addChild(tenth);

		// Tabs

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
		inputname_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-3-tab-3", "")));
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

		// outline

		auto outline = CCScale9Sprite::createWithSpriteFrameName("block008_topcolor_15_001.png");
		outline->setPosition(screenSize/2 + CCPoint{0,80});
		outline->setContentSize({461, 2.5f});
		outline->setColor(ccc3(0,0,0));
		m_mainLayer->addChild(outline);


		// Buttons

		auto closebutton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(NotepadLayer::Close)
		);
		menu->addChild(closebutton);
	    closebutton->setPosition(screenSize/2 + CCPoint{-231.5f, 135});

		auto opensettings = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
			this,
			menu_selector(NotepadLayer::OpenSettings)
		);
		smallbutton->addChild(opensettings);
		opensettings->setID("settings");
		opensettings->setPosition(screenSize/2 + CCPoint{249.5f, 137});

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
		auto tab2 = Tab2::create();
		auto tab3 = Tab3::create();
		auto tab4 = Tab4::create();
		auto tab5 = Tab5::create();

		inputname_2->setVisible(false);
		inputname_3->setVisible(false);
		inputname_4->setVisible(false);
		inputname_5->setVisible(false);

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

		// ScrollLayer

		m_scroll = ScrollLayer::create({445,204.5f},true, true);

		m_scroll->m_contentLayer->addChild(numlabels);	
		m_scroll->m_contentLayer->addChild(tab1);
		m_scroll->m_contentLayer->addChild(tab2);
		m_scroll->m_contentLayer->addChild(tab3);
		m_scroll->m_contentLayer->addChild(tab4);
		m_scroll->m_contentLayer->addChild(tab5);
		m_scroll->m_contentLayer->setLayout(

			ColumnLayout::create()
			->setAxisReverse(true)
            ->setAxisAlignment(AxisAlignment::End)
			->setAutoGrowAxis(500)

		);
		
		m_scroll->m_contentLayer->setPositionY(-208);
		m_scroll->m_contentLayer->setContentHeight(412.5f);
		m_scroll->setPosition(screenSize/2 + CCPoint{-230.5f, -125});
		m_mainLayer->addChild(m_scroll);

		auto scrollbar = Scrollbar::create(m_scroll);
		scrollbar->setPosition(screenSize/2 + CCPoint{220, -28});
		m_mainLayer->addChild(scrollbar);

		tab1->setPosition(screenSize/2 + CCPoint{0, 181});
		tab2->setPositionY(99999);
		tab3->setPositionY(99999);
		tab4->setPositionY(99999);
		tab5->setPositionY(99999);
		numlabels->setPosition(screenSize/2 + CCPoint{0,181});

		scrollbar->setScaleX(1.25f);

		m_page1 = tab1;
		m_page2 = tab2;
		m_page3 = tab3;
		m_page4 = tab4;
		m_page5 = tab5;

		
		m_mainLayer->setTouchEnabled(true);
		m_mainLayer->updateLayout();
		
		return true;

	}
	void NotepadLayer::onTouchFix(CCObject* sender){

	}
	void NotepadLayer::Close(CCObject* sender){
		this->keyBackClicked(); // THIS FIXED THE setTouchPriority ISSUE!
	}
	void NotepadLayer::OpenSettings(CCObject*){
		this->keyBackClicked(); // TouchPriority issue
		geode::openSettingsPopup(Mod::get());
	}
	void NotepadLayer::onPage(CCObject* sender) {
        m_clicked += sender->getTag();

        auto page = static_cast<CCMenuItemSpriteExtra*>(sender);
		auto screenSize = CCDirector::sharedDirector()->getWinSize();

		// there's definitely a better way but this works for now I spent way too much time on this.

			if (m_clicked > 0){
				m_page2->setPosition(screenSize/2 + CCPoint{0, 181});
				m_scroll->scrollToTop();
				m_page2->setVisible(true);
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
				m_page3->setPosition(screenSize/2 + CCPoint{0, 181});
				m_scroll->scrollToTop();
				m_page3->setVisible(true);
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
				m_page4->setPosition(screenSize/2 + CCPoint{0, 181});
				m_scroll->scrollToTop();
				m_page4->setVisible(true);
				m_page3->setPositionY(99999);
				m_page5->setPositionY(99999);
				m_page1->setPositionY(99999);


				m_inputname_4->setVisible(true);
				m_inputname_3->setVisible(false);
				m_inputname_5->setVisible(false);
				m_inputname_1->setVisible(false);

			}
			if (m_clicked > 3){
				m_page5->setPosition(screenSize/2 + CCPoint{0, 181});
				m_scroll->scrollToTop();
				m_page5->setVisible(true);
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
				m_page1->setPosition(screenSize/2 + CCPoint{0, 181});
				m_scroll->scrollToTop();
				m_page1->setVisible(true);
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

	NotepadLayer* NotepadLayer::create(){
		auto ret = new NotepadLayer;
		if (ret && ret->setup()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}