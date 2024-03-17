#pragma once

#include "Engine/Scripting/ScriptingObject.h"
#include "Engine/Core/Config/Settings.h"

API_CLASS() class DISCORDPRESENCE_API DiscordSettings : public SettingsBase
{
	API_AUTO_SERIALIZATION();
	DECLARE_SCRIPTING_TYPE_NO_SPAWN(DiscordSettings);
	DECLARE_SETTINGS_GETTER(DiscordSettings);

public:

	API_FIELD(Attributes="EditorOrder(0)")
	int64 ClientID = 0;

	API_FIELD()
	bool RichPresenceEnabled = true;
};
