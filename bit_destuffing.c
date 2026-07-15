#include<stdio.h>
void main(){
	int ip_frame[100], op_frame[200];
	int i , j = 0, n;
	int count = 0;
	printf("Enter the stuffed frame length: ");
	scanf("%d", &n);
	printf("Enter the stuffed frame: \n");
	for(i=0;i<n;i++){
		scanf("%d", &ip_frame[i]);
	}
	for(i=0;i<n;i++){
		op_frame[j++] = ip_frame[i];
		if(ip_frame[i] == 1){
			count++;
			if(count == 5){
				i++;
				count = 0;
			}
		}else{
			count = 0;
		}
	}
	printf("\nAfter bit destuffing, the frame is: \n");
	for(i=0;i<j;i++){
		printf("%d",op_frame[i]);
	}
	printf("\n");
}
