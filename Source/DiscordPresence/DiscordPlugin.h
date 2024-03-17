#pragma once

#include "Engine/Scripting/Plugins/GamePlugin.h"

/// <summary>
/// Main plugin class used for updating Discord.
/// </summary>
API_CLASS() class DISCORDPRESENCE_API DiscordPlugin : public GamePlugin
{
    DECLARE_SCRIPTING_TYPE(DiscordPlugin);

    void Initialize() override;
    void Deinitialize() override;
    void Update();

public:
    /// <summary>
    /// Call to update the current activity. Make sure to update all other parameters before calling this.
    /// </summary>
    /// <param name="startTime">If set will show "Elapsed" on a players profile. Call GetCurrenTime() to easily set this.</param>
    /// <param name="endTime">If set will show "left" on a players profile.</param>
    /// <returns></returns>
    API_FUNCTION() void UpdateActivity(int64 startTime = 0, int64 endTime = 0);

    /// <summary>
    /// The current activity state.
    /// </summary>
    API_FIELD() String ActivityState = TEXT("");

    /// <summary>
    /// The current activity details.
    /// </summary>
    API_FIELD() String ActivityDetails = TEXT("");

    /// <summary>
    /// The name of the small image that should be shown. Must be uploaded to the Discord Developer Portal
    /// </summary>
    API_FIELD() String ActivitySmallImage = TEXT("");

    /// <summary>
    /// The text that will be shown when hovering the small image.
    /// </summary>
    API_FIELD() String ActivitySmallText = TEXT(""); 

    /// <summary>
    /// The name of the large image that should be shown. Must be uploaded to the Discord Developer Portal
    /// </summary>
    API_FIELD() String ActivityLargeImage = TEXT("");

    /// <summary>
    /// The text that will be shown when hovering the large image.
    /// </summary>
    API_FIELD() String ActivityLargeText = TEXT("");

    /// <summary>
    /// Gets the current epoch time.
    /// </summary>
    /// <returns>The current epoch time.</returns>
    API_FUNCTION() long GetCurrentTime();

};
