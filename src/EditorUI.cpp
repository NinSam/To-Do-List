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
		const char* png;

		if (buttoncolor == "Default"){
			png = "notepad.png"_spr;
		}
		else if (buttoncolor == "Red"){
			png = "notepad_red.png"_spr;
		}
		else if (buttoncolor == "Orange"){
			png = "notepad_orange.png"_spr;
		}
		else if (buttoncolor == "Yellow"){
			png = "notepad_yellow.png"_spr;
		}
		else if (buttoncolor == "Green"){
			png = "notepad_green.png"_spr;
		}
		else if (buttoncolor == "Blue"){
			png = "notepad_blue.png"_spr;
		}
		else if (buttoncolor == "Purple"){
			png = "notepad_purple.png"_spr;
		}
		else if (buttoncolor == "Pink"){
			png = "notepad_pink.png"_spr;
		}

		auto undomenu = getChildByID("undo-menu");
		auto spr = CCSprite::create(png);
		m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));
		m_fields->notepadbutton->setID("To-Do List"_spr);
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