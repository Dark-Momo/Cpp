#include <iostream>
#include <cstdio>
#include <cstring>

/*
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <cerrno>
*/

typedef enum
{
  MODE_UNKNOWN = 0,
  MODE_OFF = 1,
  MODE_HOME = 2,
  MODE_AWAY = 3,
} ModeState_t;

struct MotionSettings
{
    ModeState_t mode;
    bool offMotionEnabled;
    bool homeMotionEnabled;
    bool awayMotionEnabled;
};

const char * const MOTION_SETTINGS_FILE = "./motion_settings.txt";

int main(void)
{
    MotionSettings Settings;

    Settings.mode = MODE_HOME;
    Settings.offMotionEnabled  = false;
    Settings.homeMotionEnabled = true; 
    Settings.awayMotionEnabled = false;

    std::cout << "sizeof(ModeState_t) is " << sizeof(ModeState_t) << "\n";	// 4
    std::cout << "sizeof(Settings.mode) is " << sizeof(Settings.mode) << "\n";  // 4
    
    std::cout << "sizeof(Settings.offMotionEnabled) is " << sizeof(Settings.offMotionEnabled) << "\n"; 		// 1
    std::cout << "sizeof(Settings.homeMotionEnabled) is " << sizeof(Settings.homeMotionEnabled) << "\n";	// 1
    std::cout << "sizeof(Settings.awayMotionEnabled) is " << sizeof(Settings.awayMotionEnabled) << "\n";	// 1

    std::cout << "sizeof(Settings) is " << sizeof(Settings) << "\n";		// 8

    /*
    auto handle = LockedFileHandle::openRW(MOTION_SETTINGS_FILE);
    if (!handle)
    {
	std::cout << "MOTION_SETTINGS_FILE is not there.";
        return 1;
    }

    int lseek_ret;
    if (0 != ftruncate(handle.fd(), 0) )
    {
	std::cout << "ftruncate failed, error: " << strerror(errno);
        return false;
    }
    if ( 0 != (lseek_ret = lseek(handle.fd(), 0, SEEK_SET)) )
    {
	std::cout << "lseek failed, " << lseek_ret << ", error: " << strerror(errno);
        return false;
    }
    */

    char settingArray[sizeof(Settings)]; 			// 8 bytes for array 
    memset(settingArray, '\0', sizeof(Settings));
    snprintf(settingArray, sizeof(Settings), "%d%d%d%d",	// 4 byte to input. Not 16 bytes! %d means the argument is a signed interger.
                                              Settings.mode,    // Here, integer doesn't mean "int" which is 4 byte.
                                              Settings.offMotionEnabled,
                                              Settings.homeMotionEnabled,
                                              Settings.awayMotionEnabled);

    std::cout << "settingArray after Ser is " << settingArray << ", occupied " << std::strlen(settingArray) << " Bytes.\n";
    // Output : settingArray after Ser is 2010, occupied 4 Bytes.

    // write(handle.fd(), settingArray, sizeof (settingArray));

    return 0;
}
