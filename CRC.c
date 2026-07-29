#include <stdio.h>

int main() {
    int data[100], div[10], temp[100];
    int datalen = 0, divlen = 0;
    int i, j;
    char ch;
    printf("Enter the data (binary): ");
    while ((ch = getchar()) != '\n') {
        if (ch == '0' || ch == '1')
            data[datalen++] = ch - '0';
    }
    printf("Enter the divisor (generator polynomial): ");
    while ((ch = getchar()) != '\n') {
        if (ch == '0' || ch == '1')
            div[divlen++] = ch - '0';
    }
    for (i = 0; i < datalen; i++)
        temp[i] = data[i];
    for (i = 0; i < divlen - 1; i++)
        temp[datalen + i] = 0;

    int totallen = datalen + divlen - 1;
    for (i = 0; i <= totallen - divlen; i++) {
        if (temp[i] == 1) {
            for (j = 0; j < divlen; j++) {
                temp[i + j] ^= div[j];
            }
        }
    }
    printf("\nData: ");
    for (i = 0; i < datalen; i++)
        printf("%d", data[i]);
    printf("\nCRC: ");
    for (i = datalen; i < totallen; i++) {
        printf("%d", temp[i]);
        data[i] = temp[i];
    }
    printf("\nTransmitted Data: ");
    for (i = 0; i < totallen; i++)
        printf("%d", data[i]);
    printf("\n");
    return 0;
}
