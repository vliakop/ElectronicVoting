#include "FileOperations.h"
#include "../Structures/Voter.h"
#include <cstdio>
#include <cstring> // TODO remove this line and snipet for tokenizing the line
#include <cstdlib> // TODO remove this line and snipet for tokenizing the line

// Source: https://www.tutorialspoint.com/c-program-to-count-the-number-of-lines-in-a-file
int countLines(char *filename) {

    char ch;
    int linesCount=0;
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL) {
        printf("File \"%s\" does not exist!!!\n",filename);
        return -1;
    }

    //read character by character and check for new line
    while((ch=fgetc(fp))!=EOF) {
        if(ch=='\n')
            linesCount++;
    }
    //close the file
    fclose(fp);
    //print number of lines
    printf("Total number of lines are: %d\n",linesCount);
    return 0;
}

void readRecords(char *filename) {

    char line[500];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File \"%s\" does not exist!!!\n", filename);
        return;
    }

    while(fgets(line, sizeof(line), fp) != NULL) {
        //fputs(line, stdout);
        // TODO add to intimidating structure

        char *token = strtok(line, " ");
        char *identity_number = new char[strlen(token) + 1];
        strcpy(identity_number, token);

        token = strtok(NULL, " ");
        char *name = new char[strlen(token) + 1];
        strcpy(name, token);

        token = strtok(NULL, " ");
        char *surname = new char[strlen(token) + 1];
        strcpy(surname, token);

        token = strtok(NULL, " ");
        int age = atoi(token);

        token = strtok(NULL, " ");
        char gender = token[0];

        token = strtok(NULL, "\n");
        char *postal_code = new char[strlen(token) + 1];
        strcpy(postal_code, token);

        Voter *voter = new Voter(identity_number, name, surname, age, gender, postal_code);
        voter->print();
        delete voter;

        delete [] postal_code;
        delete []surname;
        delete []name;
        delete []identity_number;

    }
    fclose(fp);

}