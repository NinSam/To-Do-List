#pragma once

using namespace geode::prelude;

class NotepadLayer: public FLAlertLayer{
protected:

size_t m_clicked = 0;

CCMenuItemSpriteExtra* m_page_5;
CCMenuItemSpriteExtra* m_page_1_fix;
CCMenuItemSpriteExtra* m_page_left;

CCMenu* m_page1;
CCMenu* m_page2;
CCMenu* m_page3;
CCMenu* m_page4;
CCMenu* m_page5;

ScrollLayer* m_scroll;

TextInput* m_inputname_1;
TextInput* m_inputname_2;
TextInput* m_inputname_3;
TextInput* m_inputname_4;
TextInput* m_inputname_5;

bool init();

void Close(CCObject* sender);
void OpenExtras(CCObject*);
void onPage(CCObject* sender);
void Nothing(CCObject* sender);


public:
   static NotepadLayer* create();
};

class ExtrasLayer: public FLAlertLayer{
protected:

bool init();


void Close(CCObject* sender);
void OpenSettings(CCObject*);
void Info(CCObject*);


public:
   static ExtrasLayer* create();
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