#define re printf("\e[1;1H\e[2J")

#define ftellme(u) printf("POINTER -> %lu\n", ftell(u))

#define myMalloc(x) if(x==NULL)\
                    {\
                    printf("ERROR: OUT OF MEMORY\n");\
                    exit(0);\
                    }
#define filee(_x_,_y_) if(_x_==NULL)\
                 {\
                   printf("ERROR: FILE <<%s>> COULDN'T OPEN\n",_y_);\
                   exit(0);\
                 }\
                 printf("File %s opened succesfully\n",_y_);
