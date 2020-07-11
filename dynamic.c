#include <stdio.h>
#include <windows.h>
#include <string.h>

#define DEBUG 1

int setBackground(char *wallpaperName, int hour);
const char strLocalDirectory[101] = "D:\\wallpaperer\\";
const char extension[11] = ".jpeg";
char filePath[101];
char argument[101];
int hour, init_hour; 

int main(int argc, char *argv[]) 
{   
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    #if DEBUG
    ShowWindow(GetConsoleWindow(), SW_SHOW);
    #endif

    if(argv[1]) strcpy(argument, argv[1]);
    else strcpy(argument, "earth");

    SYSTEMTIME SystemTime;
    GetLocalTime(&SystemTime);
    init_hour = SystemTime.wHour;
    setBackground(argument, init_hour);

    for(;;) 
    {
        GetLocalTime(&SystemTime);
        hour = SystemTime.wHour;
        #if DEBUG
        printf("Current our is %i\n", hour);
        #endif
        if(hour > init_hour) 
        {
            init_hour = hour;
            memset(filePath, 0, sizeof filePath);

            if(setBackground(argument, hour)) 
            { 
                #if DEBUG
                printf("Applied Background number: %d\n", hour);
                #endif
            } else 
            {  
                #if DEBUG
                DWORD DWLastError = GetLastError();
                printf("Error: 0x%x", DWLastError);
                #endif
            } 
        }
        Sleep(6000);
    }
  return EXIT_SUCCESS;
}
int getIntex(int hour) {
    switch(hour) {
        case 1:  return 1; 
        case 2: return 1;  
        case 3: return 2; 
        case 4: index = 3;return 3; 
        case 5: index = 3; return 3; 
        case 6: index = 4; return 4; 
        case 7: index = 5; return 5; 
        case 8: index = 6; return 6; 
        case 9: index = 6; return 6; 
        case 10: index = 7; return 7; 
        case 11: index = 7; return 7; 
        case 12: index = 8; return 8; 
        case 13: index = 8; return 8; 
        case 14: index = 9; return 9; 
        case 15: index = 10; return 10; 
        case 16: index = 10; return 10; 
        case 17: index = 11; return 11; 
        case 18: index = 12; return 12; 
        case 19: index = 13; return 13; 
        case 20: index = 14; return 14; 
        case 21: index = 15; return 15; 
        case 22: index = 15; return 16; 
        case 23: index = 16; return 16; 
        case 24: index = 16; return 16; 
    }
}
int setBackground(char *wallpaperName, int hour) {
    char* wallpaperIndex[1001] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};
    int index = 0;

    index = getIndex(hour);
    
    strcat(filePath, strLocalDirectory);
    strcat(filePath,wallpaperName);
    strcat(filePath, "\\");
    strcat(filePath, wallpaperIndex[index-1]);
    strcat(filePath, extension);

    const int return_value = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, filePath, SPIF_UPDATEINIFILE);

    return return_value;
}