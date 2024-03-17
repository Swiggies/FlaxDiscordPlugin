#pragma once

#include "Engine/Scripting/Script.h"

/// <summary>
/// The actor that is placed in the scene that updates the Discord plugin.
/// </summary>
API_CLASS() class DISCORDPRESENCE_API DiscordSceneObject : public Script
{
    API_AUTO_SERIALIZATION();
    DECLARE_SCRIPTING_TYPE(DiscordSceneObject);

    // [Script]
    void OnEnable() override;
    void OnUpdate() override;
};
