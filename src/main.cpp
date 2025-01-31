#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
// #include "NotepadLayer.cpp"

using namespace geode::prelude;

class NotepadLayer : public FLAlertLayer{
public:
	static NotepadLayer* create(){
		auto ret = new NotepadLayer;
		if (ret && ret->init()){

			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}
	bool init(){
		if(!FLAlertLayer::init(150))
		
		return false;

		// this code is going to be a mess...

		geode::cocos::handleTouchPriority(this);
		registerWithTouchDispatcher();
		m_noElasticity = true;

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
		auto screenSize = CCDirector::get()->getWinSize();

		auto menu = CCMenu::create();
		auto smallbutton = CCMenu::create();
		
		this->addChild(smallbutton);
		smallbutton->setPosition({75,0 * relativescale});
		smallbutton->setScale(0.675f * relativescale);
		smallbutton->setZOrder(2);

		this->addChild(menu);
		menu->setPosition({0,0 * relativescale});

		// bg

		CCScale9Sprite* bg = CCScale9Sprite::create("GJ_square01.png");
	    bg->setPosition(screenSize / 2);
		bg->setContentSize({400, 280 * relativescale});
		menu->addChild(bg);
		bg->setZOrder(-1);

		// Labels


		CCLabelBMFont* goldtext = CCLabelBMFont::create("To-Do List", "goldFont.fnt");
		goldtext->setPosition({294.5f, 278 * relativescale});
		menu->addChild(goldtext);
		goldtext->setZOrder(1);

		CCLabelBMFont* first = CCLabelBMFont::create("1.", "bigFont.fnt");
		first->setPosition({109, 207 * relativescale});
		first->setScale(0.7f * relativescale);
		menu->addChild(first);
		first->setZOrder(1);

		CCLabelBMFont* second = CCLabelBMFont::create("2.", "bigFont.fnt");
		second->setPosition({109, 167 * relativescale});
		second->setScale(0.7f * relativescale);
		menu->addChild(second);
		second->setZOrder(1);

		CCLabelBMFont* third = CCLabelBMFont::create("3.", "bigFont.fnt");
		third->setPosition({109, 127 * relativescale});
		third->setScale(0.7f * relativescale);
		menu->addChild(third);
		third->setZOrder(1);

		CCLabelBMFont* fourth = CCLabelBMFont::create("4.", "bigFont.fnt");
		fourth->setPosition({109, 87 * relativescale});
		fourth->setScale(0.7f * relativescale);
		menu->addChild(fourth);
		fourth->setZOrder(1);

		CCLabelBMFont* fifth = CCLabelBMFont::create("5.", "bigFont.fnt");
		fifth->setPosition({109, 47 * relativescale});
		fifth->setScale(0.7f * relativescale);
		menu->addChild(fifth);
		fifth->setZOrder(1);

		// Buttons
		
		CCMenuItemSpriteExtra* closebutton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(NotepadLayer::CloseNotepad)
		);
		menu->addChild(closebutton);
		closebutton->setID("close-button"_spr);
		closebutton->setZOrder(1);
		closebutton->setPosition({86, 295 * relativescale});

		CCMenuItemSpriteExtra* opensettings = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
			this,
			menu_selector(NotepadLayer::OpenSettings)
		);
		smallbutton->addChild(opensettings);
		opensettings->setID("open-settings"_spr);
		opensettings->setZOrder(1);
		opensettings->setPosition({428, 331 * relativescale});

		CCMenuItemSpriteExtra* info = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png"),
			this,
			menu_selector(NotepadLayer::Info)
		);
		smallbutton->addChild(info);
		info->setID("info"_spr);
		info->setZOrder(1);
		info->setPosition({65, 332 * relativescale});


		// Level Name (Tabs)

		TextInput* inputname_1 = TextInput::create(100,"","bigFont.fnt");
		inputname_1->setPosition({217.5f, 243 * relativescale});
		inputname_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-name-1", "")));
		inputname_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-name-1", str));
		
		});
		menu->addChild(inputname_1);

		

		// Pages

		TextInput* page_1 = TextInput::create(50,"","bigFont.fnt");
		page_1->setPosition({361, 243 * relativescale});
		page_1->setString("1/2");
		menu->addChild(page_1);
		page_1->setZOrder(1);



		// TextInputs

		TextInput* input_1 = TextInput::create(200,"","bigFont.fnt");
		input_1->setPosition({231,205 * relativescale});
		input_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-1", "")));
		input_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-1", str)); // finally figured it out after "insert" attempts I have on Spectre
		
		});
		menu->addChild(input_1);

		TextInput* input_2 = TextInput::create(200,"","bigFont.fnt");
		input_2->setPosition({231,164.5f * relativescale});
		input_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-2", "")));
		input_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-2", str));
		
		});
		menu->addChild(input_2);

		TextInput* input_3 = TextInput::create(200,"","bigFont.fnt");
		input_3->setPosition({231,124 * relativescale});
		input_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-3", "")));
		input_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-3", str));
		
		});
		menu->addChild(input_3);

		TextInput* input_4 = TextInput::create(200,"","bigFont.fnt");
		input_4->setPosition({231,84.5f * relativescale});
		input_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-4", "")));
		input_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-4", str));
		
		});
		menu->addChild(input_4);

		TextInput* input_5 = TextInput::create(200,"","bigFont.fnt");
		input_5->setPosition({231,45 * relativescale});
		input_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-5", "")));
		input_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-5", str));
		
		});
		menu->addChild(input_5);


		// Priority

        TextInput* input_priority_1 = TextInput::create(50,"","bigFont.fnt");
		input_priority_1->setPosition({435,205 * relativescale});
		input_priority_1->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-one", "")));
		input_priority_1->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-one", str));
		
		});
		menu->addChild(input_priority_1);

        TextInput* input_priority_2 = TextInput::create(50,"","bigFont.fnt");
		input_priority_2->setPosition({435,164.5f * relativescale});
		input_priority_2->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-two", "")));
		input_priority_2->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-two", str));
		
		});
		menu->addChild(input_priority_2);

        TextInput* input_priority_3 = TextInput::create(50,"","bigFont.fnt");
		input_priority_3->setPosition({435,124 * relativescale});
		input_priority_3->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-three", "")));
		input_priority_3->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-three", str));
		
		});
		menu->addChild(input_priority_3);

        TextInput* input_priority_4 = TextInput::create(50,"","bigFont.fnt");
		input_priority_4->setPosition({435,84.5f * relativescale});
		input_priority_4->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-four", "")));
		input_priority_4->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-four", str));
		
		});
		menu->addChild(input_priority_4);

        TextInput* input_priority_5 = TextInput::create(50,"","bigFont.fnt");
		input_priority_5->setPosition({435,45 * relativescale});
		input_priority_5->setString(fmt::format("{}", Mod::get()->getSavedValue<std::string>("input-priority-five", "")));
		input_priority_5->setCallback([this](std::string const& str){

        (Mod::get()->setSavedValue<std::string>("input-priority-five", str));
		
		});
		menu->addChild(input_priority_5);


		// Checkboxes

		CCMenuItemSpriteExtra* check_1 = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
			this,
			menu_selector(NotepadLayer::PlaceHolder)
		);
		menu->addChild(check_1);
		check_1->setZOrder(1);
		check_1->setPosition({371, 205 * relativescale});

		CCMenuItemSpriteExtra* check_2 = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
			this,
			menu_selector(NotepadLayer::PlaceHolder)
		);
		menu->addChild(check_2);
		check_2->setZOrder(1);
		check_2->setPosition({371, 164.5f * relativescale});

		CCMenuItemSpriteExtra* check_3 = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
			this,
			menu_selector(NotepadLayer::PlaceHolder)
		);
		menu->addChild(check_3);
		check_3->setZOrder(1);
		check_3->setPosition({371, 124 * relativescale});

		CCMenuItemSpriteExtra* check_4 = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
			this,
			menu_selector(NotepadLayer::PlaceHolder)
		);
		menu->addChild(check_4);
		check_4->setZOrder(1);
		check_4->setPosition({371, 84.5f * relativescale});

		CCMenuItemSpriteExtra* check_5 = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
			this,
			menu_selector(NotepadLayer::PlaceHolder)
		);
		menu->addChild(check_5);
		check_5->setZOrder(1);
		check_5->setPosition({371, 45 * relativescale});

		// Arrows

		CCMenuItemSpriteExtra* arrow_1 = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(NotepadLayer::PlaceHolder)
		);
		menu->addChild(arrow_1);
		arrow_1->setZOrder(1);
		arrow_1->setPosition({151, 242 * relativescale});

		CCMenuItemSpriteExtra* page_right = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_rightBtn_001.png"),
			this,
			menu_selector(NotepadLayer::PlaceHolder)
		);
		menu->addChild(page_right);
		page_right->setZOrder(1);
		page_right->setPosition({284, 242 * relativescale});

		CCMenuItemSpriteExtra* layer_left = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_leftBtn_001.png"),
			this,
			menu_selector(NotepadLayer::PlaceHolder)
		);
		menu->addChild(layer_left);
		layer_left->setZOrder(1);
		layer_left->setPosition({320, 242 * relativescale});

		CCMenuItemSpriteExtra* layer_right = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("edit_rightBtn_001.png"),
			this,
			menu_selector(NotepadLayer::PlaceHolder)
		);
		menu->addChild(layer_right);
		layer_right->setZOrder(1);
		layer_right->setPosition({401.5f, 242 * relativescale});

		// this
		
		this->setKeypadEnabled(true);
		this->setTouchEnabled(true);
		this->updateLayout();
		
		return true;
	}
	void CloseNotepad(CCObject*){
		this->setTouchEnabled(false);
		this->removeFromParentAndCleanup(true);
 	}
	void OpenSettings(CCObject*){
		geode::openSettingsPopup(Mod::get());
	}
	void Info(CCObject*){
		FLAlertLayer::create("Info", "1. Level Name (Tabs). 2. Pages. 3. Text Input. 4. Checkbox. 5. Priority (Low, Medium, High)", "OK")->show();
	}
	void PlaceHolder(CCObject*){

	}
};

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
			spr->setID("To-Do List"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Red"){
			CCSprite* spr = CCSprite::create("notepad_red.png"_spr);
			spr->setID("To-Do List"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Orange"){

			CCSprite* spr = CCSprite::create("notepad_orange.png"_spr);
			spr->setID("To-Do List"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Yellow"){

			CCSprite* spr = CCSprite::create("notepad_yellow.png"_spr);
			spr->setID("To-Do List"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Green"){

			CCSprite* spr = CCSprite::create("notepad_green.png"_spr);
			spr->setID("To-Do List"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Blue"){

			CCSprite* spr = CCSprite::create("notepad_blue.png"_spr);
			spr->setID("To-Do List"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Purple"){

			CCSprite* spr = CCSprite::create("notepad_purple.png"_spr);
			spr->setID("To-Do List"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
		else if (buttoncolor == "Pink"){

			CCSprite* spr = CCSprite::create("notepad_pink.png"_spr);
			spr->setID("To-Do List"_spr);
			m_fields->notepadbutton = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyNotepadLayer::Onnotepadbutton));

		}
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