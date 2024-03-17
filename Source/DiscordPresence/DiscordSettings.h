#pragma once

#include "Engine/Scripting/ScriptingObject.h"
#include "Engine/Core/Config/Settings.h"

/// <summary>
/// The settings class for the plugin.
/// </summary>
API_CLASS() class DISCORDPRESENCE_API DiscordSettings : public SettingsBase
{
	API_AUTO_SERIALIZATION();
	DECLARE_SCRIPTING_TYPE_NO_SPAWN(DiscordSettings);
	DECLARE_SETTINGS_GETTER(DiscordSettings);

public:

	/// <summary>
	/// The Client ID from the Discord Developer Portal.
	/// </summary>
	API_FIELD(Attributes="EditorOrder(0)")
	int64 ClientID = 0;

	/// <summary>
	/// Whether rich presence should even be used. (Turn off for privacy)
	/// </summary>
	API_FIELD()
	bool RichPresenceEnabled = true;
};
