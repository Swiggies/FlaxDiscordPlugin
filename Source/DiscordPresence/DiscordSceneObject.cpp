#include "DiscordSceneObject.h"
#include "DiscordPlugin.h"
#include "Engine/Scripting/Plugins/PluginManager.h"

DiscordSceneObject::DiscordSceneObject(const SpawnParams& params)
    : Script(params)
{
    // Enable ticking OnUpdate function
    _tickUpdate = true;
}

DiscordPlugin* plugin;

void DiscordSceneObject::OnEnable()
{
    // Here you can add code that needs to be called when script is enabled (eg. register for events)
    plugin = PluginManager::GetPlugin<DiscordPlugin>();
}

void DiscordSceneObject::OnUpdate()
{
    // Here you can add code that needs to be called every frame
    plugin->Update();
}
