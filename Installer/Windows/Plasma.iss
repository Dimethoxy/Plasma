[Setup]
AppName=Plasma
AppVersion=1.2.0
DefaultDirName={commoncf64}\VST3\Dimethoxy
DefaultGroupName=Plasma
OutputBaseFilename=plasma-1.2.0-windows
DirExistsWarning=no
UninstallFilesDir={app}\Plasma
UninstallDisplayIcon={app}\Plasma\uninstall.ico

[Files]
Source: "..\..\Builds\VisualStudio2022\x64\Release\VST3\Plasma.vst3"; DestDir: "{app}\Plasma"; Flags: recursesubdirs
Source: "..\..\Resources\uninstall.ico"; DestDir: "{app}\Plasma";


