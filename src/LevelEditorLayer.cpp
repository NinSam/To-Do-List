#include <Geode/Geode.hpp>
#include <cvolton.level-id-api/include/EditorIDs.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include "NotepadLayer.hpp"

class $modify(MyEditLevelLayer, LevelEditorLayer){

	bool init(GJGameLevel* level, bool noUI){
		if(!LevelEditorLayer::init(level, noUI))
		return false;

		if (level->m_levelType == GJLevelType::Editor){

			auto levelID = std::to_string(EditorIDs::getID(level));
			Mod::get()->setSavedValue<std::string>("editor-level-id", levelID);
			Mod::get()->setSavedValue<std::string>("editor-level-name", level->m_levelName);

		}
		
		return true;
	}

};