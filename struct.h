typedef struct
{
  unsigned char kwd[3];
  unsigned char *row;
  unsigned char *column;
  unsigned char col[5];
  unsigned int **pixl;
}Pgm;
extern Pgm c1;
