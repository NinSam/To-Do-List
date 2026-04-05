#pragma once

using namespace geode::prelude;

class NotepadLayer: public Popup{
protected:

const char* m_savedValue = "input-name-1-tab-1";

const char* m_inputTab1 = "input-1-tab-1";
const char* m_inputTab2 = "input-2-tab-1";
const char* m_inputTab3 = "input-3-tab-1";
const char* m_inputTab4 = "input-4-tab-1";
const char* m_inputTab5 = "input-5-tab-1";
const char* m_inputTab6 = "input-6-tab-1";
const char* m_inputTab7 = "input-7-tab-1";
const char* m_inputTab8 = "input-8-tab-1";
const char* m_inputTab9 = "input-9-tab-1";
const char* m_inputTab10 = "input-10-tab-1";

const char* m_inputPriorityString1 = "input-priority-one-tab-1";
const char* m_inputPriorityString2 = "input-priority-two-tab-1";
const char* m_inputPriorityString3 = "input-priority-three-tab-1";
const char* m_inputPriorityString4 = "input-priority-four-tab-1";
const char* m_inputPriorityString5 = "input-priority-five-tab-1";
const char* m_inputPriorityString6 = "input-priority-six-tab-1";
const char* m_inputPriorityString7 = "input-priority-seven-tab-1";
const char* m_inputPriorityString8 = "input-priority-eight-tab-1";
const char* m_inputPriorityString9 = "input-priority-nine-tab-1";
const char* m_inputPriorityString10 = "input-priority-ten-tab-1";

const char* m_toggleTab1 = "checkbox-tab-1";
const char* m_toggleTab2 = "checkbox-2-tab-1";
const char* m_toggleTab3 = "checkbox-3-tab-1";
const char* m_toggleTab4 = "checkbox-4-tab-1";
const char* m_toggleTab5 = "checkbox-5-tab-1";
const char* m_toggleTab6 = "checkbox-6-tab-1";
const char* m_toggleTab7 = "checkbox-7-tab-1";
const char* m_toggleTab8 = "checkbox-8-tab-1";
const char* m_toggleTab9 = "checkbox-9-tab-1";
const char* m_toggleTab10 = "checkbox-10-tab-1";

size_t m_page;

CCMenuItemSpriteExtra* m_pageLeft;

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

TextInput* m_inputName;

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
void onPage(CCObject* sender);

void saveCheckbox(CCObject*);
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