#include<stdio.h>
int main(){
	int windowSize, totalFrames, i;
	int frames[50];
	printf("Enter window size: ");
	scanf("%d", &windowSize);
	printf("\nEnter number of frames to transmit: ");
	scanf("%d", &totalFrames);
	printf("\nEnter %d Frames: ", totalFrames);
	for(i=1;i<=totalFrames;i++){
		scanf("%d", &frames[i]);
	}
	printf("\nSlidind window protocol simulation(Assuming no frame loss/corruption)\n");
	printf("Sender send %d frames at a time and waits for acknowledgement.\n\n", windowSize);
	for(i=1;i<=totalFrames;i++){
		printf("%d", frames[i]);
		if(i%windowSize==0){
			printf("\nAcknowledgment of above frames is received by sender\n\n");
		}
	}
	if(totalFrames%windowSize!=0){
		printf("\nAcknowledgment of above frames is received by sender\n");
	}
	return 0;
}
