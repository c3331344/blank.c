#include <stdio.h>
#include <string.h>

void Cipher(char* InputText, int Key);

int main() {

    int n, shuffle=1, Key;
    char InputText[800];
    printf("Thank you for using the cipher I sold my soul to the devil for!\nNow if you would graciously input your text.\nPlease only input CAPITAL LETTERS\n");
    fgets(InputText, sizeof(InputText), stdin);

    while(shuffle>=0) {
        if(shuffle==26) {
            shuffle=shuffle-25;
        }
        printf("Input '1' to decode your text | If your text has been decoded, input '2'\n");
        scanf("%d", &n);
        if(n==1) {
            Key=26-shuffle;
            printf("Text is: ");
        }
        else if(n>1&&n!=2||n<1&&n!=2) {
            printf("\nSorry but thats not the number you were told to input. Try again!\n");
            return 0;
        }
        else if(n==2) {
            printf("\nCrongrats on getting the black magic done!\n");
            return 0;
        }
        Cipher(InputText, Key);
        printf("\n");
        shuffle++;
        n=0;
    }

}

void Cipher(char* InputText, int Key) {
    int i=0, ShuffleValue;
    char cipher;
    while(InputText[i]!='\0'&&strlen(InputText)-1>i) {
        if(InputText[i]>=32&&InputText[i]<=64||InputText[i]>=91&&InputText[i]<=126) {
            ShuffleValue=((int)InputText[i]);
            cipher=(char)(ShuffleValue);
            printf("%c", cipher);
            //InputText[i]<=64&&InputText[i]>=91 just coz im lazy
        }
        else {
            ShuffleValue=((int)InputText[i]-65+Key) % 26+65;
            cipher=(char)(ShuffleValue);
            printf("%c", cipher);
        }
        i++;
    }
}