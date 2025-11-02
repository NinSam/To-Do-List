#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include "NotepadManager.hpp"

using namespace geode::prelude;

class $modify(MyNotepadLayer, EditorUI) {

	struct Fields{
		CCMenuItemSpriteExtra* notepadButton;
	};
	
	bool init(LevelEditorLayer* p0) {	
		if (!EditorUI::init(p0)) 
		return false;

		auto customButtonColor = Mod::get()->getSettingValue<ccColor3B>("custom-button-color");
		auto buttonColorPresets = Mod::get()->getSettingValue<std::string>("button-color-presets");

		auto undoMenu = getChildByID("undo-menu");
		auto spr = CCSprite::create("notepad_btn.png"_spr);

		m_fields->notepadButton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::onNotepadButton));
		m_fields->notepadButton->setID("To-Do List"_spr);
		undoMenu->addChild(m_fields->notepadButton);

		spr->setPositionY(17.875f);
		spr->setZOrder(1);

		auto circle = CCSprite::createWithSpriteFrameName("d_circle_02_001.png");
		circle->setPosition({18,18});
		circle->setScale(0.675f);

		if (buttonColorPresets == "Default"){
			circle->setColor(ccc3(65, 222, 255));
		}
		else if (buttonColorPresets == "Red"){
			circle->setColor(ccc3(255, 58, 19));
		}
		else if (buttonColorPresets == "Orange"){
			circle->setColor(ccc3(255, 134, 36));
		}
		else if (buttonColorPresets == "Yellow"){
			circle->setColor(ccc3(255, 231, 65));
		}
		else if (buttonColorPresets == "Green"){
			circle->setColor(ccc3(65, 255, 88));
		}
		else if (buttonColorPresets == "Blue"){
			circle->setColor(ccc3(37, 140, 255));
		}
		else if (buttonColorPresets == "Purple"){
			circle->setColor(ccc3(114, 66, 255));
		}
		else if (buttonColorPresets == "Pink"){
			circle->setColor(ccc3(255, 65, 247));
		}
		if (Mod::get()->getSettingValue<bool>("custom-button-color-enable")){
			circle->setColor(customButtonColor);
		}

		m_fields->notepadButton->addChild(circle);

		undoMenu->updateLayout();

		return true;
	}

	void onNotepadButton(CCObject*) {
		NotepadLayer::create()->show();
	}

	void showUI(bool show){
		EditorUI::showUI(show);
		m_fields->notepadButton->setVisible(show);
	}
};