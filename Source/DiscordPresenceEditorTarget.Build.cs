﻿using Flax.Build;

public class DiscordPresenceEditorTarget : GameProjectEditorTarget
{
    /// <inheritdoc />
    public override void Init()
    {
        base.Init();

        // Reference the modules for editor
        Modules.Add("DiscordPresence");
    }
}
