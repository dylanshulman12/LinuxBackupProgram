#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    

    char user[50];
    char config[100];
    char local[100];
    char etc[100] = "/etc/";

    char usb[100];

    FILE *welcome = fopen("ascii.txt", "r");
    char line[500];

    //Print fun ASCII file
    while (fgets(line, sizeof(line), welcome)) {
        printf("%s", line);
    }
    // Close the file
    fclose(welcome);
    
   

        printf("\nPlease enter user name: ");
        fgets(user, sizeof(user), stdin);
        user[strcspn(user, "\n")] = '\0';  // Removes the newline character
        
        snprintf(config, sizeof(config), "/home/%s/.config/", user);
        snprintf(local, sizeof(local), "/home/%s/.local/share/", user);

        printf("\nPlease enter usb backup directory: ");
        fgets(usb, sizeof(usb), stdin);
        usb[strcspn(usb, "\n")] = '\0';

        
        printf("\nPlease confirm directories. USB Directory should include /backup folder.");

        printf("\nUSB: %s", usb);
        printf("\n\nDirectories to restore:\nConfig: %s", config);
        printf("\nLocal: %s", local);
        printf("\nETC: %s\n", etc);

        //Confirm program run
        printf("\nY/N: ");
        
        char confirm[3];
        fgets(confirm, sizeof(confirm), stdin);
        confirm[strcspn(confirm, "\n")] = '\0';
        if (confirm[0] != 'n') {
            //Double check
            printf("\nAre you sure you want to run this program? This program will replace ALL FILES in the selected directories.\n");
            printf("\nY/N: ");
            char confirm2[3];
            fgets(confirm2, sizeof(confirm2), stdin);
            confirm2[strcspn(confirm2, "\n")] = '\0';
            if(confirm2[0] == 'y') {
            
               printf("\nRunning Program...\n");
            //Sync Config folder
            char rsyncConfig[500];
            snprintf(rsyncConfig, sizeof(rsyncConfig), "rsync -avh --progress %s %s", usb, config);
            printf("%s\n", rsyncConfig);
            system(rsyncConfig);
    
            //Sync Local folder
            char rsyncLocal[500];
            snprintf(rsyncLocal, sizeof(rsyncLocal), "rsync -avh --progress %s %s", usb, local);
            printf("%s\n", rsyncLocal);
            system(rsyncLocal);

            //Sync ETC folder
            char rsyncETC[500];
            snprintf(rsyncETC, sizeof(rsyncETC), "rsync -avh --progress %s %s", usb, etc);
            printf("%s\n", rsyncETC);
            system(rsyncETC);

            printf("Program End\n");
          }

        }else {
            printf("\nEnd Program(Entered choice: 'n')\n");
            return(1);
            
        }

        
       



        fflush(stdout);

        

}











