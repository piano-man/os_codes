int main(){
	FILE *p;
	char ch;
	printf("enter the filename");
	char ch[30];
	scanf("%d",ch);
	p=fopen("ch","r");
	while((ch=getc(p))!=-1)
		putchar(ch);
	fclose(p);
	return 0;
}
