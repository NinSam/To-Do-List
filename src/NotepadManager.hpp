#pragma once

using namespace geode::prelude;

class NotepadLayer: public geode::Popup<>{
protected:

const char* m_savedValue = "input-name-1-tab-1";

size_t m_page = 0;

CCMenuItemSpriteExtra* m_pageLeft;

CCLayer* m_page1;
CCLayer* m_page2;
CCLayer* m_page3;
CCLayer* m_page4;
CCLayer* m_page5;

ScrollLayer* m_scroll;

TextInput* m_inputName;

bool setup();

void OpenSettings(CCObject*);
void onPage(CCObject*);
void onTouchFix(CCObject*);

public:
   static NotepadLayer* create();
};

class Tab1: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject*);
void SaveCheckbox2(CCObject*);
void SaveCheckbox3(CCObject*);
void SaveCheckbox4(CCObject*);
void SaveCheckbox5(CCObject*);
void SaveCheckbox6(CCObject*);
void SaveCheckbox7(CCObject*);
void SaveCheckbox8(CCObject*);
void SaveCheckbox9(CCObject*);
void SaveCheckbox10(CCObject*);

public:
   static Tab1* create();
};

class Tab2: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject*);
void SaveCheckbox2(CCObject*);
void SaveCheckbox3(CCObject*);
void SaveCheckbox4(CCObject*);
void SaveCheckbox5(CCObject*);
void SaveCheckbox6(CCObject*);
void SaveCheckbox7(CCObject*);
void SaveCheckbox8(CCObject*);
void SaveCheckbox9(CCObject*);
void SaveCheckbox10(CCObject*);

public:
   static Tab2* create();
};

class Tab3: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject*);
void SaveCheckbox2(CCObject*);
void SaveCheckbox3(CCObject*);
void SaveCheckbox4(CCObject*);
void SaveCheckbox5(CCObject*);
void SaveCheckbox6(CCObject*);
void SaveCheckbox7(CCObject*);
void SaveCheckbox8(CCObject*);
void SaveCheckbox9(CCObject*);
void SaveCheckbox10(CCObject*);

public:
   static Tab3* create();
};

class Tab4: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject*);
void SaveCheckbox2(CCObject*);
void SaveCheckbox3(CCObject*);
void SaveCheckbox4(CCObject*);
void SaveCheckbox5(CCObject*);
void SaveCheckbox6(CCObject*);
void SaveCheckbox7(CCObject*);
void SaveCheckbox8(CCObject*);
void SaveCheckbox9(CCObject*);
void SaveCheckbox10(CCObject*);

public:
   static Tab4* create();
};

class Tab5: public CCMenu{
protected:

bool init();

void SaveCheckbox(CCObject*);
void SaveCheckbox2(CCObject*);
void SaveCheckbox3(CCObject*);
void SaveCheckbox4(CCObject*);
void SaveCheckbox5(CCObject*);
void SaveCheckbox6(CCObject*);
void SaveCheckbox7(CCObject*);
void SaveCheckbox8(CCObject*);
void SaveCheckbox9(CCObject*);
void SaveCheckbox10(CCObject*);

public:
   static Tab5* create();
};