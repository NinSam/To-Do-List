#pragma once

using namespace geode::prelude;

class NotepadLayer: public FLAlertLayer{
protected:

CCScale9Sprite* bg;
size_t m_clicked = 0;

CCMenuItemSpriteExtra* m_page_5;
CCMenuItemSpriteExtra* m_page_1_fix;
CCMenuItemSpriteExtra* m_page_left;

CCLayer* m_page1;
CCLayer* m_page2;
CCLayer* m_page3;
CCLayer* m_page4;
CCLayer* m_page5;

ScrollLayer* m_scroll;

TextInput* m_inputname_1;
TextInput* m_inputname_2;
TextInput* m_inputname_3;
TextInput* m_inputname_4;
TextInput* m_inputname_5;

bool setup();

void Close(CCObject* sender);
void OpenSettings(CCObject*);
void onPage(CCObject* sender);
void onTouchFix(CCObject* sender);

public:
   static NotepadLayer* create();
};

class Tab1: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject* sender);
void SaveCheckbox2(CCObject* sender);
void SaveCheckbox3(CCObject* sender);
void SaveCheckbox4(CCObject* sender);
void SaveCheckbox5(CCObject* sender);
void SaveCheckbox6(CCObject* sender);
void SaveCheckbox7(CCObject* sender);
void SaveCheckbox8(CCObject* sender);
void SaveCheckbox9(CCObject* sender);
void SaveCheckbox10(CCObject* sender);

public:
   static Tab1* create();
};

class Tab2: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject* sender);
void SaveCheckbox2(CCObject* sender);
void SaveCheckbox3(CCObject* sender);
void SaveCheckbox4(CCObject* sender);
void SaveCheckbox5(CCObject* sender);
void SaveCheckbox6(CCObject* sender);
void SaveCheckbox7(CCObject* sender);
void SaveCheckbox8(CCObject* sender);
void SaveCheckbox9(CCObject* sender);
void SaveCheckbox10(CCObject* sender);

public:
   static Tab2* create();
};

class Tab3: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject* sender);
void SaveCheckbox2(CCObject* sender);
void SaveCheckbox3(CCObject* sender);
void SaveCheckbox4(CCObject* sender);
void SaveCheckbox5(CCObject* sender);
void SaveCheckbox6(CCObject* sender);
void SaveCheckbox7(CCObject* sender);
void SaveCheckbox8(CCObject* sender);
void SaveCheckbox9(CCObject* sender);
void SaveCheckbox10(CCObject* sender);

public:
   static Tab3* create();
};

class Tab4: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject* sender);
void SaveCheckbox2(CCObject* sender);
void SaveCheckbox3(CCObject* sender);
void SaveCheckbox4(CCObject* sender);
void SaveCheckbox5(CCObject* sender);
void SaveCheckbox6(CCObject* sender);
void SaveCheckbox7(CCObject* sender);
void SaveCheckbox8(CCObject* sender);
void SaveCheckbox9(CCObject* sender);
void SaveCheckbox10(CCObject* sender);

public:
   static Tab4* create();
};

class Tab5: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject* sender);
void SaveCheckbox2(CCObject* sender);
void SaveCheckbox3(CCObject* sender);
void SaveCheckbox4(CCObject* sender);
void SaveCheckbox5(CCObject* sender);
void SaveCheckbox6(CCObject* sender);
void SaveCheckbox7(CCObject* sender);
void SaveCheckbox8(CCObject* sender);
void SaveCheckbox9(CCObject* sender);
void SaveCheckbox10(CCObject* sender);

public:
   static Tab5* create();
};