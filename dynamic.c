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
int setBackground(char *wallpaperName, int hour) {
    char* wallpaperIndex[1001] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};
    int index = 0;

    switch(hour) {
        case 1: index = 1; break;
        case 2: index = 1; break;
        case 3: index = 2; break;
        case 4: index = 3; break;
        case 5: index = 3; break;
        case 6: index = 4; break;
        case 7: index = 5; break;
        case 8: index = 6; break;
        case 9: index = 6; break;
        case 10: index = 7; break;
        case 11: index = 7; break;
        case 12: index = 8; break;
        case 13: index = 8; break;
        case 14: index = 9; break;
        case 15: index = 10; break;
        case 16: index = 10; break;
        case 17: index = 11; break;
        case 18: index = 12; break;
        case 19: index = 13; break;
        case 20: index = 14; break;
        case 21: index = 15; break;
        case 22: index = 15; break;
        case 23: index = 16; break;
        case 24: index = 16; break;
    }
    
    strcat(filePath, strLocalDirectory);
    strcat(filePath,wallpaperName);
    strcat(filePath, "\\");
    strcat(filePath, wallpaperIndex[index-1]);
    strcat(filePath, extension);

    const int return_value = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, filePath, SPIF_UPDATEINIFILE);

    return return_value;
}