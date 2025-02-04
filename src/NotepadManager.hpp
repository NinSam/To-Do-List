#pragma once

using namespace geode::prelude;

// I wasted over 3 hours trying to make these tabs into CCMenu's but the page switch system was so buggy that I just reverted it back...

class LayerSetup: public CCMenu{
protected:

bool init();

void CloseTab(CCObject*);
void OpenSettings(CCObject*);
void Info(CCObject*);


public:
   static LayerSetup* create();
};

class Tab1: public FLAlertLayer{
protected:

bool init();

void CloseTab(CCObject*);
void PreviousTab(CCObject*);
void NextTab(CCObject*);
void OpenSettings(CCObject*);
void Info(CCObject*);

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

class Tab2: public FLAlertLayer{
protected:

bool init();

void CloseTab(CCObject*);
void PreviousTab(CCObject*);
void NextTab(CCObject*);
void OpenSettings(CCObject*);
void Info(CCObject*);

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

class Tab3: public FLAlertLayer{
protected:

bool init();

void CloseTab(CCObject*);
void PreviousTab(CCObject*);
void NextTab(CCObject*);
void OpenSettings(CCObject*);
void Info(CCObject*);

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

class Tab4: public FLAlertLayer{
protected:

bool init();

void CloseTab(CCObject*);
void PreviousTab(CCObject*);
void NextTab(CCObject*);
void OpenSettings(CCObject*);
void Info(CCObject*);

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

class Tab5: public FLAlertLayer{
protected:

bool init();

void CloseTab(CCObject*);
void PreviousTab(CCObject*);
void NextTab(CCObject*);
void OpenSettings(CCObject*);
void Info(CCObject*);

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