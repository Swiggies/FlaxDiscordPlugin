#include "DiscordSceneObject.h"
#include "DiscordUpdater.h"
#include "Engine/Scripting/Plugins/PluginManager.h"

DiscordSceneObject::DiscordSceneObject(const SpawnParams& params)
    : Script(params)
{
    // Enable ticking OnUpdate function
    _tickUpdate = true;
}

DiscordUpdater* updater;

void DiscordSceneObject::OnEnable()
{
    // Here you can add code that needs to be called when script is enabled (eg. register for events)
    updater = PluginManager::GetPlugin<DiscordUpdater>();
}

void DiscordSceneObject::OnUpdate()
{
    // Here you can add code that needs to be called every frame
    updater->Update();
}
