# Plasma

Thank you for choosing Plasma by Dimethoxy! Visit [GitHub](https://github.com/Dimethoxy/Plasma) or our [Website](https://dimethoxy.com) for more info.

### Windows - VST3:

1. **Download:** Download Plasma from [here](https://github.com/Dimethoxy/Plasma/releases).
2. **Unzip:** Unzip the downloaded archive. \
   Ensure you have a utility like WinRAR or 7-Zip installed for this process.
3. **Locate Files:** After extraction, you should find a file named `Plasma.vst3`.
4. **Move Files:** Move the `Plasma.vst3` file to your VST3 plugins directory. \
   The default location for VST3 plugins on Windows is `%CommonProgramFiles%\VST3`.

### MacOS - VST3:

1. **Download:** Download Plasma from [here](https://github.com/Dimethoxy/Plasma/releases).
2. **Unzip:** Unzip the downloaded archive. \
   Most macOS systems can unzip files by double-clicking the zip file.
3. **Locate Files:** After extraction, you should find a file named `Plasma.vst3`.
4. **Move Files:** Move the `Plasma.vst3` file to your VST3 plugins directory. \
   The default location for VST3 plugins on MacOS is `/Library/Audio/Plug-ins/VST3`.
5. **Remove Quarantine:**
   - Open the folder containing the "Plasma.vst3" file in Finder.
   - Open Terminal.
   - Type the following command: `sudo xattr -rd com.apple.quarantine` (Note: Do not hit enter yet).
   - Ensure there is a single space after "quarantine".
   - Drag and drop the "Plasma.vst3" file into the Terminal, its path should now appear in the Terminal.
   - Hit enter and enter your administrator password if prompted.

### Linux - VST3:

1. **Download:** Download the pre-release version of Plasma 1.1.0 from [here](https://github.com/Dimethoxy/Plasma/releases/tag/1.1.0).
2. **Unzip:** Extract the downloaded archive. You can use archive manager tools like tar.
3. **Locate Files:** After extraction, you should find a file named `Plasma.so`.
4. **Move Files:** Move the `Plasma.so` file to your VST3 plugins directory. \
   The location of this directory may vary depending on your Linux distribution and DAW. \
   Common directories include `~/.vst3/` or `/usr/lib/vst3/`.

### Note:

You can choose a different directory for installation, but some Digital Audio Workstations (DAWs) may not automatically detect the plugin if it's not in the default directory.

### Troubleshooting:

- If your Digital Audio Workstation (DAW) doesn't recognize the plugin after installation, ensure it is scanning the correct directory for VST3 plugins.
- If you encounter persistent issues, please open an issue on GitHub for assistance.
