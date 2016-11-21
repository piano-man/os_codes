#include<stdio.h>
void concatenate(FILE *fp1,FILE *fp2,char *argv[],int argc);
int main(int argc,char *argv[]){
	FILE *fp1,*fp2;
	concatenate(fp1,fp2,argv,argc);
	return 0;
}

void concatenate(FILE *fp1,FILE *fp2,char **argv,int argc){
	int i,ch;
	fp2=fopen("files","a");
	for(i=1;i<argc-1;i++){
		fp1=fopen(argv[i],"r");
		while((ch=getc(fp1))!=EOF)
			putc(ch,fp2);
	}
} 
