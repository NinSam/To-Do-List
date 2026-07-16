#pragma once

using namespace geode::prelude;

class NotepadLayer: public Popup, public FLAlertLayerProtocol{
protected:

std::string m_levelID = Mod::get()->getSavedValue<std::string>("editor-level-id");

std::string m_inputTab1 = m_levelID + "-input-1";
std::string m_inputTab2 = m_levelID + "-input-2";
std::string m_inputTab3 = m_levelID + "-input-3";
std::string m_inputTab4 = m_levelID + "-input-4";
std::string m_inputTab5 = m_levelID + "-input-5";
std::string m_inputTab6 = m_levelID + "-input-6";
std::string m_inputTab7 = m_levelID + "-input-7";
std::string m_inputTab8 = m_levelID + "-input-8";
std::string m_inputTab9 = m_levelID + "-input-9";
std::string m_inputTab10 = m_levelID + "-input-10";

std::string m_inputPriorityString1 = m_levelID + "-input-priority-1";
std::string m_inputPriorityString2 = m_levelID + "-input-priority-2";
std::string m_inputPriorityString3 = m_levelID + "-input-priority-3";
std::string m_inputPriorityString4 = m_levelID + "-input-priority-4";
std::string m_inputPriorityString5 = m_levelID + "-input-priority-5";
std::string m_inputPriorityString6 = m_levelID + "-input-priority-6";
std::string m_inputPriorityString7 = m_levelID + "-input-priority-7";
std::string m_inputPriorityString8 = m_levelID + "-input-priority-8";
std::string m_inputPriorityString9 = m_levelID + "-input-priority-9";
std::string m_inputPriorityString10 = m_levelID + "-input-priority-10";

std::string m_toggleTab1 = m_levelID + "-checkbox-1";
std::string m_toggleTab2 = m_levelID + "-checkbox-2";
std::string m_toggleTab3 = m_levelID + "-checkbox-3";
std::string m_toggleTab4 = m_levelID + "-checkbox-4";
std::string m_toggleTab5 = m_levelID + "-checkbox-5";
std::string m_toggleTab6 = m_levelID + "-checkbox-6";
std::string m_toggleTab7 = m_levelID + "-checkbox-7";
std::string m_toggleTab8 = m_levelID + "-checkbox-8";
std::string m_toggleTab9 = m_levelID + "-checkbox-9";
std::string m_toggleTab10 = m_levelID + "-checkbox-10";

CCMenuItemToggler* m_toggle1;
CCMenuItemToggler* m_toggle2;
CCMenuItemToggler* m_toggle3;
CCMenuItemToggler* m_toggle4;
CCMenuItemToggler* m_toggle5;
CCMenuItemToggler* m_toggle6;
CCMenuItemToggler* m_toggle7;
CCMenuItemToggler* m_toggle8;
CCMenuItemToggler* m_toggle9;
CCMenuItemToggler* m_toggle10;

ScrollLayer* m_scroll;

TextInput* m_input1;
TextInput* m_input2;
TextInput* m_input3;
TextInput* m_input4;
TextInput* m_input5;
TextInput* m_input6;
TextInput* m_input7;
TextInput* m_input8;
TextInput* m_input9;
TextInput* m_input10;

TextInput* m_inputPriority1;
TextInput* m_inputPriority2;
TextInput* m_inputPriority3;
TextInput* m_inputPriority4;
TextInput* m_inputPriority5;
TextInput* m_inputPriority6;
TextInput* m_inputPriority7;
TextInput* m_inputPriority8;
TextInput* m_inputPriority9;
TextInput* m_inputPriority10;


bool init();

void onSettings(CCObject*);
void onClearAll(CCObject*);

void onClearRow1(CCObject*);
void onClearRow2(CCObject*);
void onClearRow3(CCObject*);
void onClearRow4(CCObject*);
void onClearRow5(CCObject*);
void onClearRow6(CCObject*);
void onClearRow7(CCObject*);
void onClearRow8(CCObject*);
void onClearRow9(CCObject*);
void onClearRow10(CCObject*);

void saveCheckbox1(CCObject*);
void saveCheckbox2(CCObject*);
void saveCheckbox3(CCObject*);
void saveCheckbox4(CCObject*);
void saveCheckbox5(CCObject*);
void saveCheckbox6(CCObject*);
void saveCheckbox7(CCObject*);
void saveCheckbox8(CCObject*);
void saveCheckbox9(CCObject*);
void saveCheckbox10(CCObject*);

public:
   static NotepadLayer* create();
};