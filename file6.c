#include<stdio.h>
int main(){
  FILE *p;
  int i,a[10];
  if((p=fopen("myfile.dat","wb"))==NULL){
      printf("\nUnable to open file myfile.dat");
      exit(1);
  }
  printf("\nEnter ten values, one value on each line\n");
  for(i=0;i<10;i++)
      scanf("%d",&a[i]);
  fwrite(a,sizeof(a),1,p);
  fclose(p);
  return 0;
}
