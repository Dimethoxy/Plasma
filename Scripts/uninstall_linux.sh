#!/usr/bin/env bash

# Define the path to the VST3 plugin
VST3_PATH="$HOME/.vst3/Plasma.vst3"

# Check if the VST3 plugin exists
if [ -d "$VST3_PATH" ]; then
  # Remove the plugin
  rm -rf "$VST3_PATH"
  echo "Uninstallation complete"
else
  echo "Plasma.vst3 not found, nothing to uninstall"
fi
