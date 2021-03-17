/*MOTSI POLYXENI
dit18125
dit18125@uop.gr
AM 2022201800125*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>

#include "macros.h"
#include "struct.h"
#include "functions.h"

int main(int argc, unsigned char **argv)
{
  re;
  srand(time(NULL));

  unsigned char *file_name;
  FILE *mf;
  Pgm c1;


  if(argc>=1&&argc<=3)
    printf("Error: Missing parameters.\n");
  else if(argc==4)
    if(strstr(*(argv+1),"-n")!=NULL&&argv[1][2]=='\0')
    {
      int n;
      file_name=strdup(*(argv+2));
      myMalloc(file_name);
      strncat(file_name,".pgm", 4);
      mf=fopen(file_name,"rb");
      filee(mf,file_name)
      free(file_name);
      read_ff(&c1, mf);
      n=1+rand()%9;
      printf("Random: %d%%\n",n);
      n*=(atoi(c1.row)*atoi(c1.column));
      n/=100;
      img(atoi(c1.row),atoi(c1.column),&c1,mf);
      int flag=1;
      int i,j;
      while(n--)
      {
        flag=(flag)?0:1;
        i=rand()%atoi(c1.row);
        j=rand()%atoi(c1.column);
        if(c1.pixl[i][j]==0&&flag==0)
          n++;
        else if(c1.pixl[i][j]==255&&flag==1)
          n++;
        else
          c1.pixl[i][j]=(flag==0)?0:255;
      }
      new_file(&c1,argv,-1);
      fclose(mf);
    }
    else if(!strncmp(*(argv+1),"-f",2))
    {
      if((*(*(argv+1)+2)=='H'||*(*(argv+1)+2)=='V')&&*(*(argv+1)+3)=='\0')
      {
        file_name=(unsigned char*)malloc(sizeof(unsigned char)*strlen(*(argv+2)));
        myMalloc(file_name);
        strncpy(file_name,*(argv+2),strlen(*(argv+2)));
        strncat(file_name,".pgm", 4);
        mf=fopen(file_name,"rb");
        filee(mf,file_name)
        free(file_name);
        read_ff(&c1,mf);
        img(atoi(c1.row),atoi(c1.column),&c1,mf);
        new_file(&c1,argv,(!strncmp(*(argv+1),"-fH",3))?6:7);
        fclose(mf);
      }
      else
        printf("FOR THE FLIP YOU CAN CHOOSE ONLY:\n β†³ -fH = FLIP HORIZONTAL\n β†³ -fV = FLIP VERTICAL\n ");
    }
    else if(!strncmp(*(argv+1),"-rR",3)||!strncmp(*(argv+1),"-rL",3))
    {
      if(*(*(argv+1)+3)>='1'&&*(*(argv+1)+3)<='4')
      {
        int ch;
        file_name=(unsigned char*)malloc(sizeof(unsigned char)*strlen(*(argv+2)));
        myMalloc(file_name);
        strncpy(file_name,*(argv+2),strlen(*(argv+2)));
        strncat(file_name,".pgm", 4);
        mf=fopen(file_name,"rw");
        filee(mf,file_name)
        free(file_name);
        read_ff(&c1, mf);
        img(atoi(c1.row),atoi(c1.column),&c1,mf);
        ch=(*(*(argv+1)+2)=='R'&&*(*(argv+1)+3)=='1')?3:(*(*(argv+1)+2)=='R'&&*(*(argv+1)+3)=='3')?1:atoi(*(argv+1)+3);
        new_file(&c1,argv,ch);
		    fclose(mf);
      }
      else
        printf("FOR THIS COMMAND YOU CAN CHOOSE ONLY BETWEEN [1,4]. \n β†³ 1=90ΒΊ\n β†³ 2=180ΒΊ\n β†³ 3=270ΒΊ\n β†³ 4=360ΒΊ\n");
    }
    else
    {
      printf("Error: Wrong command\n");
      return 0;
    }
  else
    printf("Error: Too many parameters.\n");
  return 0;
}

