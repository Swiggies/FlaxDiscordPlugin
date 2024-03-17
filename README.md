Just a simple plugin that allows you to use Discord Rich Presence within a Flax game. 

## Installation
Easiest to install through Flax's plugin window. Just add the github link and give it a name!
Make sure to create a Discord Setting asset for your project. This is where you can add the Discord Client ID for your application from the Discord Developer Portal.

Create a new script, then add the following to it
```cs
DiscordPlugin discordPlugin = PluginManager.GetPlugin<DiscordPlugin>();
discordPlugin.ActivityDetails = "Activity Details";
discordPlugin.ActivityState = "Activity State";
discordPlugin.ActivitySmallImage = "smallimage"; // Uses name from Developer Portal
discordPlugin.ActivitySmallText = "Small Text";
discordPlugin.ActivityLargeImage = "largeimage"; // Uses name from Developer Portal
discordPlugin.ActivityLargeText = "Large Text";
discordPlugin.UpdateActivity(discordPlugin.GetCurrentTime()); // Leave parameter empty to exclude time from status.
```
Just change the fields as you need them and call `DiscordPlugin.UpdateActivity()` when you want to update things.
