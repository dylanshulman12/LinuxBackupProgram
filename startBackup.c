#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    

    char user[50];
    char config[100];
    char local[100];
    char etc[100] = "/etc/";
    char mkcmd[100];
    char destination[100] = "/home/dylan/Documents/test/";

    


    FILE *welcome = fopen("ascii.txt", "r");
    char line[500];

    while (fgets(line, sizeof(line), welcome)) {
        printf("%s", line);
    }

    // Close the file
    fclose(welcome);
    
   

        printf("\nPlease enter user name: ");
        fgets(user, sizeof(user), stdin);
        user[strcspn(user, "\n")] = '\0';  // This removes the newline character
        
        printf("\nPlease enter usb backup directory: (A Backup folder will be created. Dont enter \"/\" at end):\n\n");

        char temp[100];

        fgets(temp, sizeof(temp), stdin);        
        temp[strcspn(temp, "\n")] = '\0';


        snprintf(config, sizeof(config), "/home/%s/.config/", user);
        snprintf(local, sizeof(local), "/home/%s/.local/share/", user);

        //make folder cmd
        snprintf(mkcmd, sizeof(mkcmd), "cd %s; mkdir backup", temp);
        // printf(mkcmd);
        system(mkcmd);

        snprintf(destination, sizeof(destination), "%s/backup", temp);

        

        // printf("Please confirm directories: \nSource:%s\nDestination:%s", source, destination);
        
        printf("Please confirm directories: ");

        //printing sources
        // FILE *sourcesListed = fopen("locations.txt", "r");
        // char line2[500];

        // while (fgets(line2, sizeof(line2), sourcesListed)) {
        //     printf("%s", line2);
        // }

        printf("\n%s\n\n", destination);

        printf("\n%s", config);
        printf("\n%s", etc);
        printf("\n%s\n", local);

        printf("\nY/N: ");

        

        // printf(config);
        // printf(etc);
        // printf(local);



        char confirm = getchar();
        if (confirm != 'n') {
            //Double check
            printf("\nAre you sure you want to run this program? This program will replace ALL FILES in the selected directories.\n");
            printf("\nY/N: ");
            char confirm2[3];
            fgets(confirm2, sizeof(confirm2), stdin);
            confirm2[strcspn(confirm2, "\n")] = '\0';
           
            if(confirm2[0] == 'y') {
            printf("\nRunning Program...");
            char rsyncCommand[500];
            snprintf(rsyncCommand, sizeof(rsyncCommand), "rsync -avhr --progress %s %s %s %s", config, local, etc, destination);
            printf("%s\n", rsyncCommand);
            system(rsyncCommand);


            }
        }
        else {
            printf("\nEnd Program(Entered choice: 'n')");
            return(1);
            
        }

        
       



        fflush(stdout);

        

}











