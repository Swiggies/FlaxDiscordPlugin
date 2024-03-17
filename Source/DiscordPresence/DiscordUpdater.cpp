#include "DiscordUpdater.h"
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

IMPLEMENT_GAME_SETTINGS_GETTER(DiscordSettings, "Discord Settings");

DiscordUpdater::DiscordUpdater(const SpawnParams& params)
    : GamePlugin(params)
{
    pluginDescription.Name = "Discord";
    pluginDescription.Author = "Swiggies";
    pluginDescription.Category = "Utility";
    pluginDescription.Version = Version(0, 1);

    _description = pluginDescription;
}

discord::Core* core{};
discord::Activity activity{};
discord::Result result{};

void DiscordUpdater::Initialize()
{
    GamePlugin::Initialize();

    const auto settings = DiscordSettings::Get();

    if (!settings->RichPresenceEnabled) return;

    result = discord::Core::Create(settings->ClientID, DiscordCreateFlags_Default, &core);

    UpdateActivity(ActivityState, ActivityDetails);

    Guid sceneGuid;
    if (!Guid::Parse(TEXT("9a0387574ab2ad0ab6ec1dba4f9f953f"), sceneGuid)) {
        Level::LoadScene(sceneGuid);
    }
    else {
        LOG(Warning, "Couldn't find scene");
    }
}

void DiscordUpdater::Deinitialize()
{
    GamePlugin::Deinitialize();
    core->ActivityManager().ClearActivity([](discord::Result result) {
        LOG(Info, "Discord Clear Activity: {0}", (int)result);
    });
    // Have to call this because otherwise it doesn't remove status
    core->~Core();
}

void DiscordUpdater::Update()
{
    // Here you can add code that needs to be called every frame
    ::core->RunCallbacks();
}

API_FUNCTION() void DiscordUpdater::UpdateActivity(String state, String details) {

    activity.SetState(state.ToStringAnsi().GetText());
    activity.SetDetails(details.ToStringAnsi().GetText());

    core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
        LOG(Info, "Discord Update Activity: {0}", (int)result);
    });
}
