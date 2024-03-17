// This code was auto-generated. Do not modify it.

#include "Engine/Scripting/BinaryModule.h"
#include "DiscordPresence.Gen.h"

StaticallyLinkedBinaryModuleInitializer StaticallyLinkedBinaryModuleDiscordPresence(GetBinaryModuleDiscordPresence);

extern "C" BinaryModule* GetBinaryModuleDiscordPresence()
{
    static NativeBinaryModule module("DiscordPresence");
    return &module;
}
