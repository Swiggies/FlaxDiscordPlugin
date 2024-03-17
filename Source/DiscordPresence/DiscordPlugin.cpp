#include "DiscordPlugin.h"
#include "Engine/Core/Log.h"
#include "Engine/Scripting/Events.h"
#include "Engine/Scripting/Scripting.h"
#include <DiscordPresence/discord-files/discord.h>
#include "DiscordSceneObject.h"
#include <Engine/Level/Actor.h>
#include <Engine/Level/Level.h>
#include <Engine/Level/Scene/Scene.h>
#include <Engine/Level/Actors/EmptyActor.h>
#include "Engine/Core/Config/GameSettings.h"
#include "Engine/Content/Content.h"
#include "Engine/Content/JsonAsset.h"
#include "DiscordSettings.h"
#include <chrono>

IMPLEMENT_GAME_SETTINGS_GETTER(DiscordSettings, "Discord Settings");

DiscordPlugin::DiscordPlugin(const SpawnParams& params)
    : GamePlugin(params)
{
    _description.Name = "Discord";
    _description.Author = "Swiggies";
    _description.Category = "Utility";
    _description.Version = Version(0, 1);
}

discord::Core* core{};
discord::Activity activity{};
discord::Result result{};

void DiscordPlugin::Initialize()
{
    GamePlugin::Initialize();

    const auto settings = DiscordSettings::Get();

    if (!settings->RichPresenceEnabled) return;

    result = discord::Core::Create(settings->ClientID, DiscordCreateFlags_Default, &core);

    Guid sceneGuid;
    if (!Guid::Parse(TEXT("9a0387574ab2ad0ab6ec1dba4f9f953f"), sceneGuid)) {
        Level::LoadScene(sceneGuid);
    }
    else {
        LOG(Warning, "Couldn't find scene");
    }
}

void DiscordPlugin::Deinitialize()
{
    GamePlugin::Deinitialize();
    core->ActivityManager().ClearActivity([](discord::Result result) {
        LOG(Info, "Discord Clear Activity: {0}", (int)result);
    });
    // Have to call this because otherwise it doesn't remove status
    core->~Core();
}

void DiscordPlugin::Update()
{
    // Here you can add code that needs to be called every frame
    ::core->RunCallbacks();
}

API_FUNCTION() void DiscordPlugin::UpdateActivity(int64 startTime, int64 endTime)
{
    activity.SetState(ActivityState.ToStringAnsi().GetText());
    activity.SetDetails(ActivityDetails.ToStringAnsi().GetText());

    activity.GetAssets().SetLargeImage(ActivityLargeImage.ToStringAnsi().GetText());
    activity.GetAssets().SetLargeText(ActivityLargeText.ToStringAnsi().GetText());
    activity.GetAssets().SetSmallImage(ActivitySmallImage.ToStringAnsi().GetText());
    activity.GetAssets().SetSmallText(ActivitySmallText.ToStringAnsi().GetText());

    if (startTime != 0) {
        activity.GetTimestamps().SetStart(discord::Timestamp(startTime));
        if (endTime != 0)
            activity.GetTimestamps().SetEnd(discord::Timestamp(endTime));
    }

    core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
        LOG(Info, "Discord Update Activity: {0}", (int)result);
        });
}

API_FIELD()long DiscordPlugin::GetCurrentTime()
{
    return (long)std::time(0);   
}

