#include <stdio.h>
#include <string.h> //For strlen

void Cipher(char* InputText, int Key); //calling the function i think... sorry i forgot. im very tired rn. nut its there now so it can be used later.

int main() {
    
    int n, shuffle, Key; //initializing important variables for the success of the code. 'n' will be used to choose between decryption and encryption, 'shuffle' is there to know how many places the alphabet will move to the right, and 'Key' is the bassically shuffle except that it is updated depending on then encryption or decryption choice.
    char InputText[800]; //set the max amount of charcters the user can input to InputText to 800 for good measure... it is easily changed.
    printf("Thank you for using the cipher I sold my soul to the devil for!\nNow if you would graciously input your text.\nPlease only input CAPITAL LETTERS\n");
    //printf to let the user know its time to input the text and that this assignment ate my soul.
    fgets(InputText, sizeof(InputText), stdin); //this lets the user input their text, and then determines the number of characters in the text.
    
    printf("\nPlease input Key from 0-25. In the case of Key being 0, the input text will remian unchanged: "); //leting the user know its time to input the key they wish to use
    scanf("%d", &shuffle); //this takes the input from the user and gives it to the variable called shuffle.
    if(shuffle>=0&&shuffle<=25) { //the if statement determines if the key follows instructions. if it doesnt, then an error message occurs.
            
        printf("\n| To encrypt enter '1' | To decrypt enter '2' |\nAlthough it is only fair to warn the user about the price they must pay.\nA slice of your soul!\n");
        //another printf to let the user know its time to input
        printf("To exit input any other number");
        scanf("%d", &n); //takes the input of the user and assigns it to n
        
        if(n>=2&&n<=2) { //these three if statements make sure that n is equal to 1 or 2, encryption or decryption respectively, or n equals anything else, and the code exits.
            printf("\nYou have selected to decrypt\n"); //informing the user of their selection
            Key=26-shuffle; //this is how shuffle is turned into Key for dycryption. works by making the alphabet move to the right in almost a full rotation and thus becoming deciphered.
            printf("your decrypted text is: \n"); //printf to inform the user of what the decrypted text is
        }
        else if(n>=1&&n<=1) {
            printf("\nYou have selected to encrypt\n"); //also informing the user of their selection
            Key=shuffle; //just straight up letting shuffle be the Key
            printf("Your encrypted text is: \n"); //also a printf to let the user know what their encrypted text is
        }
        else if(n!=1&&n!=2) {
            printf("Exited the black magic successfully"); //to inform the user of their selection
            return 0; //this exits the code and stops it from running
        }
        Cipher(InputText, Key); //the function that was shown earlier, put in place to let the compiler know we want to use it.
    }
    else
    printf("Guess the price of the black magic was too much... sorry"); //teases the user for inputting a Key or shuffle value that was not within the given specifications.
    return 0; //same as before
}

void Cipher(char* InputText, int Key) { //this is where the earlier function is defined.
    int i=0, ShuffleValue; //intialising i to equal 0, and ShuffleValue.
    char cipher; //also intialising cipher, only as a char for characters rather than an int for intergers.
    while(InputText[i]!='\0'&&strlen(InputText)-1>i) { //while loop that operates so long as a character of the inputted text doesnt equal null, and the total number of inputted characters minus 1, is greater than the i value.
        if(InputText[i]>=32&&InputText[i]<=64||InputText[i]>=91&&InputText[i]<=126) { //the if statement asks if inputted text value is greater than or equal to 32 and less than or equal to 64, or if its greater than or equal to 91 and less than or equal to 126, then those characters get printed without editting. e.g whitespaces
            ShuffleValue=((int)InputText[i]); //we let ShuffleValue equal the inputted text characters int value unchanged.
            cipher=(char)(ShuffleValue); //we then let cipher equal ShuffleValues characters char value.
            printf("%c", cipher); //and then then cipher is prited to the screen.
        }
        else {
            ShuffleValue=((int)InputText[i]-65+Key) % 26+65; //the ShuffleValue equals the inutted text characters int value, but it has been subtracted by 65 and then the Key value was added. The -65 uses the ascii code of capital letters to zer0 them, and the Key value shuffles the alphabet to the right.
            cipher=(char)(ShuffleValue); //same as before
            printf("%c", cipher); //then also printed
        }
        i++; //i goes up by 1 every loop until its a higher number than the total number of inputted characters.
    }
}
