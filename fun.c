#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "functions.h"
#include "macros.h"


void img(int Row,int Column, Pgm *c1, FILE *myfile)
{
  int i,j;
  unsigned char c;

  c1->pixl=(unsigned int**)malloc(sizeof(unsigned int*)*Row);
  myMalloc(c1->pixl)
  for(i=0;i<Row;i++)
  {
    c1->pixl[i]=(unsigned int*)malloc(sizeof(unsigned int)*(Column));
    myMalloc(c1->pixl+i)
  }
  fseek(myfile,1,SEEK_CUR);
  for(i=0;i<Row;i++)
    for(j=0;j<Column;j++)
    {
      fread(&c,sizeof(unsigned char),1,myfile);
      c1->pixl[i][j]=c;
    }
  fseek(myfile,-(sizeof(unsigned char)*Row*Column),SEEK_CUR);
}


void read_ff(Pgm *c1, FILE *mf)
{
  unsigned char k,lol;
  int i;
  if(2==fread(c1->kwd,sizeof(unsigned char),2,mf))
    c1->kwd[2]='\0';
  fseek(mf,1,SEEK_CUR);
  fread(&k,sizeof(unsigned char),1,mf);
  if(k=='#')
  {
    i=0;
    do {
      fread(&lol,sizeof(unsigned char),1,mf); //na kanw elegxo
    } while(lol!='\n');
	c1->column=(unsigned char*)malloc(sizeof(unsigned char));
	for(i=0;;i++)
	{
		fread(c1->column+i,sizeof(unsigned char),1,mf);	
		if(c1->column[i]==' ')
		{
			c1->column[i]='\0';
			break;
		}
		else
			c1->column=(unsigned char*)realloc(c1->column,1);
	}
	c1->row=(unsigned char*)malloc(sizeof(unsigned char));
	for(i=0;;i++)
	{
		fread(c1->row+i,sizeof(unsigned char),1,mf);	
		if(c1->row[i]=='\n')
		{
			c1->row[i]='\0';
			break;
		}
		else
			c1->row=(unsigned char*)realloc(c1->row,1);
	}
  }
  else
  {
	fseek(mf,-1,SEEK_CUR);
	c1->column=(unsigned char*)malloc(sizeof(unsigned char));
	for(i=0;;i++)
	{
		fread(c1->column+i,sizeof(unsigned char),1,mf);	
		if(c1->column[i]==' ')
		{
			c1->column[i]='\0';
			break;
		}
		else
			c1->column=(unsigned char*)realloc(c1->column,1);
	}
	c1->row=(unsigned char*)malloc(sizeof(unsigned char));
	for(i=0;;i++)
	{
		fread(c1->row+i,sizeof(unsigned char),1,mf);
		if(c1->row[i]=='\n')
		{
			c1->row[i]='\0';
			break;
		}
		else
			c1->row=(unsigned char*)realloc(c1->row,1);
	}
  }
  fread(c1->col,sizeof(unsigned char),2,mf);
  fread(c1->col+2,sizeof(unsigned char),1,mf);
  if(c1->col[2]!='\n')
    c1->col[3]='\0';
  else
    c1->col[2]='\0';
}
void new_file(Pgm *c1, unsigned char **new, int ch)
{
  FILE *new_mf;
  int i, j,flag=1;
  unsigned char line_feed=10, space=32, c;
  char *alf;


  alf=(unsigned char*)malloc(sizeof(unsigned char)*(strlen(*(new+3))+4));
  strncat(alf,*(new+3),strlen(*(new+3)));
  //strncat_s(alf,_countof(alf),*(new+3),strlen(*(new+3)));
  if(strstr(alf,".pgm")!=NULL)
  {
    printf("The name <<%s>> is wrong. Not type the <<.pgm>>\n",alf);
    exit(0);
  }
  strncat(alf,".pgm",4);
  //strncat_s(alf,_countof(alf),".pgm",4);
  new_mf=fopen(alf,"wb");
  filee(new_mf,alf)
  free(alf);
  fwrite(c1->kwd,sizeof(unsigned char),2,new_mf);
  fwrite(&line_feed,sizeof(unsigned char),1,new_mf);
  if(ch!=1&&ch!=3&&ch!=5&&ch!=15)
    fwrite(c1->column,sizeof(unsigned char),strlen(c1->column),new_mf);
  else
    fwrite(c1->row,sizeof(unsigned char),strlen(c1->row),new_mf);
  fwrite(&space,sizeof(unsigned char),1,new_mf);
  if(ch!=1&&ch!=3&&ch!=5&&ch!=15)
    fwrite(c1->row,sizeof(unsigned char),strlen(c1->row),new_mf);
  else
    fwrite(c1->column,sizeof(unsigned char),strlen(c1->column),new_mf);
  fwrite(&line_feed,sizeof(unsigned char),1,new_mf);
  fwrite(c1->col,sizeof(unsigned char),strlen(c1->col),new_mf);
  fwrite(&line_feed,sizeof(unsigned char),1,new_mf);
  for(i=(ch==7||ch==2)?atoi(c1->row)-1:(ch==1)?atoi(c1->column)-1:0;(ch==7||ch==1||ch==2)?i>-1:(ch==3)?i<atoi(c1->column):i<atoi(c1->row);(ch==7||ch==1||ch==2)?i--:i++)
     for(j=(ch==6||ch==2)?atoi(c1->column)-1:(ch==3)?atoi(c1->row)-1:0;(ch==6||ch==3||ch==2)?j>-1:(ch==1)?j<atoi(c1->row):j<atoi(c1->column);(ch==6||ch==3||ch==2)?j--:j++)
     {
       c=c1->pixl[(ch==3||ch==1)?j:i][(ch==3||ch==1)?i:j];
       fwrite(&c,sizeof(unsigned char),1,new_mf);
     }
  fclose(new_mf);
  free(c1->row);
  free(c1->column);
}

