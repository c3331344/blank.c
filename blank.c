#include <stdio.h>
#include <string.h>

void Cipher(char* InputText, int Key);

int main() {
    
    int n, shuffle, Key;
    char InputText[800];
    printf("Thank you for using the cipher I sold my soul to the devil for!\nNow if you would graciously input your text.\nPlease only input CAPITAL LETTERS\n");
    fgets(InputText, sizeof(InputText), stdin);
    
    printf("\nPlease input Key from 0-25. In the case of Key being 0, the input text will remian unchanged: ");
    scanf("%d", &shuffle);
    if(shuffle>=0&&shuffle<=25) {
            
        printf("\n| To encrypt enter '1' | To decrypt enter '2' |\nAlthough it is only fair to warn the user about the price they must pay.\nA slice of your soul!\n");
        //printf("To exit select anything else");
        scanf("%d", &n);
        
        if(n>=2&&n<=2) {
            printf("\nYou have selected to decrypt\n");
            Key=26-shuffle;
            printf("your decrypted text is: \n");
        }
        else if(n>=1&&n<=1) {
            printf("\nYou have selected to encrypt\n");
            Key=shuffle;
            printf("Your encrypted text is: \n");
        }
        Cipher(InputText, Key);
    }
    else
    printf("Guess the price of the black magic was too much... sorry");

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
