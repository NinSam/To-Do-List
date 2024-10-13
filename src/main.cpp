#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

// somehow lost all of my files from using first commit

class $modify(MyNotepadLayer, EditorUI) {
	struct Fields{
		CCMenuItemSpriteExtra* notepadbutton;
	};
	bool init(LevelEditorLayer* p0) {	
		if (!EditorUI::init(p0)) 
			return false;
		if (Mod::get()->getSettingValue<int64_t>("string-setting-example") == 0){
			CCSprite* spr = CCSprite::create("notepad_default.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));
		}
		else if (Mod::get()->getSettingValue<int64_t>("string-setting-example") == 1){
			CCSprite* spr = CCSprite::create("notepad_red.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));
		}
	    else if (Mod::get()->getSettingValue<int64_t>("string-setting-example") == 2){
			CCSprite* spr = CCSprite::create("notepad_orange.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));
		}
		else if (Mod::get()->getSettingValue<int64_t>("string-setting-example") == 3){
			CCSprite* spr = CCSprite::create("notepad_yellow.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));
		}
		else if (Mod::get()->getSettingValue<int64_t>("string-setting-example") == 4){
			CCSprite* spr = CCSprite::create("notepad_green.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));
		}
		else if (Mod::get()->getSettingValue<int64_t>("string-setting-example") == 5){
			CCSprite* spr = CCSprite::create("notepad_blue.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));
		}
		else if (Mod::get()->getSettingValue<int64_t>("string-setting-example") == 6){
			CCSprite* spr = CCSprite::create("notepad_purple.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));
		}
		else if (Mod::get()->getSettingValue<int64_t>("string-setting-example") == 7){
			CCSprite* spr = CCSprite::create("notepad_pink.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));
		}
		
		auto undomenu = getChildByID("undo-menu");
		undomenu->addChild(m_fields->notepadbutton);
		undomenu->updateLayout();
		return true;
	}
	void Onnotepadbutton(CCObject*) {
		geode::openSettingsPopup(Mod::get());
		// NotepadLayer::create()->show();
	}
	void showUI(bool show){
		EditorUI::showUI(show);
		m_fields->notepadbutton->setVisible(show);
		
	}
};
/*
TextInput* text;
 
class NotepadLayer : public FLAlertLayer, TextInputDelegate{
public:
	static NotepadLayer* create(){
		auto ret = new NotepadLayer;
		if (ret && ret->init())
		{
			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}
	bool init(){
		if(!this->initWithColor({0,0,0,0}))
		
		return false;
		geode::cocos::handleTouchPriority(this);
		registerWithTouchDispatcher();
		m_noElasticity = true;
 
		auto menu = CCMenu::create();
		auto layer = CCLayer::create();
		layer->addChild(menu);
		this->addChild(layer);
		auto winSize = CCDirector::get()->getWinSize();
		auto bg = CCScale9Sprite::create("GJ_square01.png");
	    bg->setPosition(winSize / 2);
		bg->setContentSize({243.0f, 280.0f});
		layer->addChild(bg);
		bg->setZOrder(-1);
		auto spr = CCSprite::create("bg_new.png"_spr);
	    spr->setPosition(winSize / 2);
		spr->setScale(5.0f);
		layer->addChild(spr);
		spr->setZOrder(-2);
		auto goldtext = CCLabelBMFont::create("To-Do List", "goldFont.fnt");
		goldtext->setPosition(winSize / 2);
		goldtext->setContentSize({129.0f, -212.0f});
		layer->addChild(goldtext);
		goldtext->setZOrder(1);
		
		auto closebutton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(NotepadLayer::CloseNotepad)
		);
		menu->addChild(closebutton);
		closebutton->setID("my-button"_spr);
		closebutton->setPosition({-119.0f, 133.0f});
		text = TextInput::create(200, "", "chatFont.fnt");
		layer->addChild(text);
		text->setPosition(winSize / 2);
		text->setContentSize({200.0f, -120.0f});
		text->setID("text-input");
	 // text->setString(); // savetextstring
		text->setZOrder(2);
		this->setKeypadEnabled(true);
		this->setTouchEnabled(true);
		menu->updateLayout();
		
		return true;
	}
	void CloseNotepad(CCObject*){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
 	}
};
*/