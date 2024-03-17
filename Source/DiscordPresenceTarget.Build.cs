using Flax.Build;

public class DiscordPresenceTarget : GameProjectTarget
{
    /// <inheritdoc />
    public override void Init()
    {
        base.Init();

        // Reference the modules for game
        Modules.Add("DiscordPresence");
        Modules.Add("DiscordPresenceEditor");
    }
}
