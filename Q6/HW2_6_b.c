#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_SIZE 2
#define MAX_BUF_SIZE 256

int main(int argc, char* argv[])
{
    FILE *pFile_src=NULL;
    FILE *pFile_dest=NULL;

    char* mychar;
    char *SRC, *DEST;
    int i=0,j;

    char char_buff[MAX_BUF_SIZE];
    mychar= (char *)malloc(sizeof(char *));

    if(argv[1]!=NULL)
        SRC=argv[1];
    else
        printf("\nUSAGE: ./Ex_ManualCP_prog src_file dest_file.\nFirst arg should be a filename, cannot be empty.\n");

    if(argv[2]!=NULL)
        DEST=argv[2];
    else
        printf("\nSecond arg should be a filename, cannot be empty.\n");

    mychar= (char *)malloc(MAX_SIZE*sizeof(char *));

    //initialize text buffer
    for(j=0;j<MAX_BUF_SIZE;j++)
        char_buff[j]='\0';

    pFile_src=fopen(SRC,"r");     //Open file to read and store in a character buffer

    pFile_dest=fopen(DEST,"w");  //open destination file

    if(pFile_dest==NULL)
        printf("\nFile specified as Destination DOES NOT EXIST.\n");

    if(pFile_src==NULL)
        printf("\nFile specified as Source, DOES NOT EXIST.\n");
    else
    {
        //printf("\n----File opened successfully-----\n");

        while(((*mychar=fgetc(pFile_src))!=EOF))
        {
            if(i>=MAX_BUF_SIZE)
            {
                i=0;
            }

            char_buff[i]=*mychar;
            fputc(char_buff[i],pFile_dest); //write buffer data into opened file
            ++i;
        }

        char_buff[i]='\0';
        fclose(pFile_src);  //close source file

    }

    fclose(pFile_dest);

    if(pFile_src!=NULL && pFile_dest!=NULL)
        printf("\n\n-----Copy Done!----\n-----Reached end of file.-----\n");

    return 0;
}