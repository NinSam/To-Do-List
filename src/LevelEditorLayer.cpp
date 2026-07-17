#include <Geode/Geode.hpp>
#include <cvolton.level-id-api/include/EditorIDs.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include "NotepadLayer.hpp"

class $modify(LevelEditorLayer){

	bool init(GJGameLevel* level, bool noUI){
		if(!LevelEditorLayer::init(level, noUI))
		return false;

		Mod::get()->setSavedValue<std::string>("editor-level-id", fmt::to_string(EditorIDs::getID(level)));
		Mod::get()->setSavedValue<std::string>("editor-level-name", level->m_levelName);

		return true;
	}

};