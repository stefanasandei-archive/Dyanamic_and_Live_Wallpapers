#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define DEBUG 0

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

    if(argv[1]) 
        strcpy(argument,argv[1]);
    else strcpy(argument, "earth");
    for(;;)
        for(unsigned int i=0;i<14;i++) 
        {
            memset(filePath, 0, sizeof filePath);
            if(setBackground(argument, i)) 
            { 
                #if DEBUG
                printf("Applied Background number: %d\n", i);
                #endif
            } else {  
                #if DEBUG
                DWORD DWLastError = GetLastError();
                printf("Error: 0x%x", DWLastError);
                #endif
            }
            Sleep(350); 
        }
  return EXIT_SUCCESS;
}

int setBackground(char *wallpaperName, int index) {
    char cindex[1001];
    sprintf(cindex, "%d", index+1);
    strcat(filePath, strLocalDirectory);
    strcat(filePath,wallpaperName);
    strcat(filePath, "\\");
    strcat(filePath, cindex);
    strcat(filePath, extension);

    #if DEBUG
    printf("%s\n", filePath);
    #endif

    const int return_value = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, filePath, SPIF_UPDATEINIFILE);

    return return_value;
}