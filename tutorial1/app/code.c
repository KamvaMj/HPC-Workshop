// INCLUDES
#include <stdio.h>
#include "code.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// GLOBALS


//FUNCTIONS
// welcome message
void welcome_message()
{
    printf("Welcome!\n");
}
// get group name
void get_name(char* name)
{
    printf("Enter group name : ");
    gets(name);
}

// 1. Function to create a folder using the name variable as its name
void create_folder(char* name)
{
if(mkdir(name, 0777)== -1){
		perror("Error creating folder");
		}
else{printf("Folder '%s'created successfully./n", name);}
}

// 2. Function to create a file in the folder <folder_name> called group.txt where you insert the <group_name> as text
void create_file(char* folder_name, char* group_name)
{
char file_path[256];
snprintf(file_path, sizeof(file_path), "%s/file.txt", folder_name);

FILE *file=fopen(file_path, "w");
if(file == NULL){
perror("Error creating file");
return;
}
fprintf(file, "%s\n", group_name);
fclose(file);
printf("File 'file.txt' created in folder '%s' with content: '%s'\n",folder_name, group_name);
}
