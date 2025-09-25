#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char command[800];
char path[200] = "/data/data/com.termux/files/home/MyTasks/Library";
char path2[200] = "/data/data/com.termux/files/home/MyTasks/Library/Music";
char path3[200] = "/data/data/com.termux/files/home/MyTasks/Download-And-Play-Music-C/Library";

int playmusic(){
    int result;
    int exit;
    char song[200];
    while(1){
        snprintf(song, sizeof(song), "mpv %s/", path2);
        printf("%s\n\n", song);
        result = system(song);

        if(result == 0){
            printf("Do you want to exit? \n1.Yes 2.No\n");
            scanf("%d", &exit);
            if(exit == 2){
                continue;
            }
            else{
                printf("Thank you for tring my code\n");
                system("sleep 3");
                break;
            }
        }
        else{
            printf("Error: Unknown error!\n");
        }
    }
    return 0;
}

int main(){
    int download;

    snprintf(command, sizeof(command), "ls %s", path);
    int result = system(command);

    if(result == 0){
        printf("The library has been downloaded\nStarting...\n");
        system("sleep 3");

        playmusic();
    }

    else{
        snprintf(command, sizeof(command), "ls %s", path3);
        result = system(command);
        if(result == 0){
            snprintf(command, sizeof(command), "mv %s %s", path3, path);
            system(command);
            system("sleep 1");
            playmusic();
        }
        else{
            printf("We have to download the Library of the music. Do you want to download the Library?\n1.Yes 2.No\n");
            scanf("%d", &download);

            if(download == 1){
                printf("Ok. The download will start in 5s\n");

                system("sleep 5");

                snprintf(command, sizeof(command), "rm -rf Download-And-Play-Music-C && git clone https://github.com/MainHub-Code/Download-And-Play-Music-C.git");
                system(command);
            
                snprintf(command, sizeof(command), "mv %s %s", path3, path);
                result = system(command);

                if(result == 0){
                    printf("Starting...");
                    system("sleep 3");
                    playmusic();
                }
                else{
                    printf("Error: The Library doesn't exest!\n");
                }
            }
           else{
               printf("Ok. Exiting\n");
           }
        }   
    }
    return 0;
}
