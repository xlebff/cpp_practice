[Setup]
AppName=Where is My Sock
AppVersion=1.0
AppPublisher=Ririsa
AppPublisherURL=https://github.com/xlebff/
DefaultDirName={autopf}\WhereIsMySock
DefaultGroupName=Where is My Sock
OutputDir=Output
OutputBaseFilename=WhereIsMySockSetup
UninstallDisplayIcon={app}\WhereIsMySock.exe
Compression=lzma
SolidCompression=yes
UninstallDisplayName=Where is My Sock

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"

[Files]
Source: "C:\Data\Projects\cpp_practice\WhereIsMySock\x64\Debug\WhereIsMySock.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\Where is My Sock"; Filename: "{app}\WhereIsMySock.exe"; IconFilename: "{app}\sock.ico"
Name: "{autodesktop}\Where is My Sock"; Filename: "{app}\WhereIsMySock.exe"; IconFilename: "{app}\sock.ico"; Tasks: desktopicon

[Run]
Filename: "{app}\WhereIsMySock.exe"; Description: "Launch Where is My Sock"; Flags: nowait postinstall skipifsilent