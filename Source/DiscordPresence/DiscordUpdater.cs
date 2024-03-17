#if FLAX_EDITOR

using System;
using FlaxEditor;
using FlaxEditor.Content;
using FlaxEngine;

namespace DiscordPresence;

/// <summary>
/// DiscordPresence Script.
/// </summary>
public class DiscordPresenceEditor : EditorPlugin
{
    private AssetProxy _assetProxy;

    /// <summary>
    /// Constructor
    /// </summary>
    public DiscordPresenceEditor()
    {
        _description = new PluginDescription
        {
            Name = "Discord Presence"
        };
    }

    /// <summary>
    /// Set plugin type
    /// </summary>
    public override Type GamePluginType => typeof(DiscordUpdater);

    /// <summary>
    /// Init
    /// </summary>
    public override void InitializeEditor()
    {
        base.InitializeEditor();
        _assetProxy = new CustomSettingsProxy(typeof(DiscordSettings), "Discord Settings");
        Editor.ContentDatabase.Proxy.Add(_assetProxy);
    }

    /// <summary>
    /// Deinit
    /// </summary>
    public override void DeinitializeEditor()
    {
        Editor.ContentDatabase.Proxy.Remove(_assetProxy);
        _assetProxy = null;

        base.DeinitializeEditor();
    }
}


#endif