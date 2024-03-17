#pragma once

#include "Engine/Scripting/Plugins/GamePlugin.h"

API_CLASS() class DISCORDPRESENCE_API DiscordUpdater : public GamePlugin
{
    DECLARE_SCRIPTING_TYPE(DiscordUpdater);

    void Initialize() override;
    void Deinitialize() override;
    void Update();

    PluginDescription pluginDescription;
public:

    API_FUNCTION() void UpdateActivity(String state, String details);
    API_FIELD() String ActivityState = TEXT("");
    API_FIELD() String ActivityDetails = TEXT("");

};
