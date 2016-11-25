#include <stdio.h>
int main()
{
	int sz;
	printf("Enter the frame size\n");
	scanf("%d",&sz);
	int n;
	int frm[sz];
	printf("Enter number of pages\n");
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	int j,pos = 0,ctr = 0, max, k;
	int temp[sz], f;
	for(i=0;i<sz;i++)
		temp[sz] = 0;
	int freq[100], removed[100];
	for(i=0;i<100;i++){
		freq[i] = 0;
		removed[i] = 0;
	}
	for(i=0;i<n;i++){
		f = 0;
		for(j = 0; j < sz && j <= i; j++){
			if(frm[j] == arr[i]){
				f = 1;
				break;
			}
		}
		if(f == 1){
			freq[arr[i]] += 1;
		}
		if(f == 0){
			ctr += 1;
			if(pos < sz){
				frm[pos] = arr[i];
				freq[arr[i]] += 1;
				pos += 1;
			}
			else{
				int tpos;
				int min = freq[frm[0]];
				for(k=0;k<sz;k++){
					if(freq[frm[k]] < min){
						min = freq[arr[k]];
					}
				}
				//printf("mmmmmm%d\n", min);
				int rpos;
				for(j=0;j<n;j++){
					int x = 0;
					for(k=0;k<sz;k++){
						if(arr[j] == frm[k]){
							if(freq[arr[j]] == min && removed[j] == 0){
								x = 1;
								tpos = k;
								break;
							}
						}
					}
					if(x == 1){
						rpos = j;
						break;
					}
				}
				freq[frm[tpos]] = 0;
				removed[rpos] = 1;
				frm[tpos] = arr[i];
				freq[arr[i]] = 1;
			}
			//for(k=0;k<sz;k++){
			//	temp[k] += 1;
			//}
			//temp[pos] = 0;
		}
		for(j=0;j<sz;j++){
			printf("%d ",frm[j]);
		}
		printf("\n");
	/*	for(j=0;j<=7;j++){
			printf("%d %d\n",freq[j],removed[j]);
		}*/
	}	
	printf("The number of page faults: %d\n",ctr);
	return 0;
}
