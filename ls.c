#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
int main(int argc,char *argv[])
{
	DIR *dp;
	struct dirent *sd;
	dp=opendir(argv[1]); 
	while((sd=readdir(dp))!=NULL)
	{
		printf("%s\t",sd->d_name);
	}
	closedir(dp);
}
/*#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    mydir = opendir(argv[1]);
    while((myfile = readdir(mydir)) != NULL)
    {
        stat(myfile->d_name, &mystat);    
        printf("%d",mystat.st_size);
        printf(" %s\n", myfile->d_name);
    }
    closedir(mydir);
}*/

