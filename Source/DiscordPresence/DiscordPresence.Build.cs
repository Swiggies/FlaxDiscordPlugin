using Flax.Build;
using Flax.Build.NativeCpp;
using System.IO;

/// <summary>
/// 
/// </summary>
public class DiscordPresence : GameModule
{
    /// <inheritdoc />
    public override void Setup(BuildOptions options)
    {
        base.Setup(options);

        // Here you can modify the build options for your game module
        // To reference another module use: options.PublicDependencies.Add("Audio");
        // To add C++ define use: options.PublicDefinitions.Add("COMPILE_WITH_FLAX");
        // To learn more see scripting documentation.
        BuildNativeCode = true;

        string discordPath = Path.Combine(FolderPath, "Third Party");
        options.LinkEnv.InputFiles.Add(Path.Combine(discordPath, "discord_game_sdk.dll.lib"));
        options.DependencyFiles.Add(Path.Combine(discordPath, "discord_game_sdk.dll"));
    }
}
