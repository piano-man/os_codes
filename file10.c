 #include "time.h"
#include "sys/stat.h"
#include "stdio.h"
void main(){
    struct stat status;
    FILE *fp;
    stat("test.txt",&status);
    clrscr();
    if (status.st_mode & S_IREAD)
         printf("You have read permission.\n");
    if (status.st_mode & S_IWRITE)
         printf("You have write permission.");
    getch();

}
