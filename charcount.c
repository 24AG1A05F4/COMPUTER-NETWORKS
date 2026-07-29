#include <stdio.h>
#include <string.h>

char data[20][20];
char temp[20][30];
int n;

int main() {
    int i, j, ch;

    printf("Enter the number of frames: ");
    scanf("%d", &n);
    getchar();

    // Read frames
    for (i = 0; i < n; i++) {
        printf("Frame %d: ", i + 1);
        fgets(data[i], sizeof(data[i]), stdin);
        data[i][strcspn(data[i], "\n")] = '\0';
    }

    // Sender side
    for (i = 0; i < n; i++) {
        int len = strlen(data[i]);
        temp[i][0] = len + '0';
        temp[i][1] = '\0';
        strcat(temp[i], data[i]);
    }

    printf("\n\t\tAT THE SENDER\n");
    printf("Data as frames:\n");

    for (i = 0; i < n; i++) {
        printf("Frame %d: %s\n", i + 1, temp[i]);
    }

    printf("\nData transmitted: ");
    for (i = 0; i < n; i++) {
        printf("%s", temp[i]);
    }

    // Receiver side
    printf("\n\n\t\tAT THE RECEIVER\n");
    printf("Data received: ");

    for (i = 0; i < n; i++) {
        ch = temp[i][0] - '0';

        for (j = 0; j < ch; j++) {
            data[i][j] = temp[i][j + 1];
        }
        data[i][j] = '\0';
    }

    printf("\nData after removing count characters: ");
    for (i = 0; i < n; i++) {
        printf("%s", data[i]);
    }

    printf("\n\nData in frame form:\n");
    for (i = 0; i < n; i++) {
        printf("Frame %d: %s\n", i + 1, data[i]);
    }

    return 0;
}
