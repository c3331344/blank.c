#include <stdio.h>
#include <string.h> //for strlen

void Cipher(char* InputText, int Key); //again im tired and i think its calling the function... sorry. oh and for refernce by again, i wrote the comments for the blank.c first.

int main() {

    int n, shuffle=1, Key; //intialising n, shuffle to equal 1, and Key.
    char InputText[800]; //capped the number of total input characters to 800
    printf("Thank you for using the cipher I sold my soul to the devil for!\nNow if you would graciously input your text.\nPlease only input CAPITAL LETTERS\n"); //letting the user know its time to input their text.
    fgets(InputText, sizeof(InputText), stdin); //takes the input text from the user and number of inputted characters

    while(shuffle>=0) { //while loop so that code reats until the user is satified and wishes to exit
        if(shuffle==26) { //the if statement ensurse that shuffle never equals 27 and thus is allways letters since it never exceeds the alphabet
            shuffle=shuffle-25;
        }
        printf("Input '1' to decode your text | If your text has been decoded, input '2'\n"); //tells the user to input
        scanf("%d", &n); //takes the input of the user and assigns it to n
        if(n==1) { //when n is equal to 1, the key equals the 26 minus shuffle
            Key=26-shuffle;
            printf("Text is: "); //iforms user of the shuffled text
        }
        else if(n>1&&n!=2||n<1&&n!=2) { //if n is less than or greater than 1 and is not equal to 2, then an error message is printed and the code exits
            printf("\nSorry but thats not the number you were told to input. Try again!\n");
            return 0;
        }
        else if(n==2) { //if n equals 2, then message is printed to crongradulate the user on the successful decoding of their code. and the code is exited
            printf("\nCrongrats on getting the black magic done!\n");
            return 0;
        }
        Cipher(InputText, Key); //letting the compiler know that we wanna use this function
        printf("\n"); //prints a new line for ease of human reading form the terminal
        shuffle++; //shuffle is added to by 1 so that the key may be changed
        n=0; //n is made 0... it probably has no need, but idc its there now.
    }

}

void Cipher(char* InputText, int Key) { //where the previous function is defined
    int i=0, ShuffleValue; //intialising i to equal 0, and ShuffleValue as ints
    char cipher; //cipher is intitialised as a char
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
