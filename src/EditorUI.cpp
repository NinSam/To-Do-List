#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include "NotepadManager.hpp"

using namespace geode::prelude;

class $modify(MyNotepadLayer, EditorUI) {

	struct Fields{
		CCMenuItemSpriteExtra* notepadbutton;
	};
	bool init(LevelEditorLayer* p0) {	
		if (!EditorUI::init(p0)) 

		return false;

		auto buttoncolor = Mod::get()->getSettingValue<std::string>("button-color");

		if (buttoncolor == "Default"){

			CCSprite* spr = CCSprite::create("notepad.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Red"){
			CCSprite* spr = CCSprite::create("notepad_red.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Orange"){

			CCSprite* spr = CCSprite::create("notepad_orange.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Yellow"){

			CCSprite* spr = CCSprite::create("notepad_yellow.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Green"){

			CCSprite* spr = CCSprite::create("notepad_green.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Blue"){

			CCSprite* spr = CCSprite::create("notepad_blue.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Purple"){

			CCSprite* spr = CCSprite::create("notepad_purple.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Pink"){

			CCSprite* spr = CCSprite::create("notepad_pink.png"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		m_fields->notepadbutton->setID("To-Do List"_spr);
		auto undomenu = getChildByID("undo-menu");
		undomenu->addChild(m_fields->notepadbutton);
		undomenu->updateLayout();

		return true;
	}
	void Onnotepadbutton(CCObject*) {
		NotepadLayer::create()->show();
	}
	void showUI(bool show){
		EditorUI::showUI(show);
		m_fields->notepadbutton->setVisible(show);
		
	}
};