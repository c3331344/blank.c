#include <stdio.h>
#include <string.h> //Lets us use the strlen() function
void Cipher(char* DT, int Key); //DT is just the deciphered text or unencrypted text
void Decipher(char* CT, int Key); //CT is just the ciphered text or encrypted text
int main() {
int n;
int Key; 

char DT[101]; //Set to a max lenth of 101 characters since that was the example I was shown in a vid and I've just ran with it
char CT[101]; //Same reason as just above
printf("Please insert text to cipher/decipher:\n");
fgets(DT, sizeof(DT), stdin); //Allows user input of the unencrypted text
//fgets must be before scanf of the Key or the code will not run | I have yet to understand why...

printf("\nPlease specify if you wish to encrypt or decrypt text\n");
printf("To encrypt select '1' | To decrypt select '2'\n");
scanf("%d", &n);
switch(n) {
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    case 1: //CIPHER CASE

    printf("You have selected to encrypt\n");
    printf("\nPlease input Key of any number 1-25: ");
    scanf("%d", &Key); //Lets the user set the Key
    if(Key>=1&&Key<=25) {
    printf("Encrypted text is: ");
    Cipher(DT, Key); //The function that does the encrypting
    }
    else //Error message... coz its fun
    printf("Try running again and following insrtuctions... if still fails, then... sorry I guess ;P");

    break;
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    case 2: //DECIPHER CASE
    
    printf("You have selected to decrypt\n");
    printf("\nPlease input Key of any number 1-25: ");
    scanf("%d", &Key); //Lets the user set the Key
    if(Key>=1&&Key<=25) {
    printf("Deciphered text is: ");
    Decipher(CT, Key); //The function that does the decrypting
    }
    else //Error message... coz its fun
    printf("Try running again and following insrtuctions... if still fails, then... sorry I guess ;P");
    
    break;
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
}
//CIPHERING
void Cipher(char* DT, int Key) {
    int i=0; //Index variable that can be added to
    int ShiftValue; //Basically the real Key | Just the number of shifts the alphabet needs to go to the right for the encryption alphabet
    char cipher; //Kinda sounds like a shitty pokemon name
    while(DT[i]!='\0'&&strlen(DT)-1>i) { // \0 Enter by the user | Null
        ShiftValue=((int)DT[i]-97+Key) % 26+97; //ASCII Text has a=97, b=98... etc | so we minus 97 to 0 it...
        cipher=(char)(ShiftValue); //Must be thingoed to a char and given to cipher or it will come out in a sequence of numbers rather than a word/s
        printf("%c", cipher); //Prints the encrypted text to the screen
        i++; //To continue adding to the index valriable
    }
}
//DECIPHERING
void Decipher(char* CT, int Key) {
    int i=0; //Index variable that can be added to
    int NegKey=26-Key; //See bellow code for explanation starting at **
    int ShiftValue; //Basically the real Key | Just the number of shifts the alphabet needs to go to the right for the encryption alphabet
    char cipher; //Really does sound like a shitty pokemon name
    while(CT[i]!='\0'&&strlen(CT)-1>i) { // \0 Enter by the user | Null
    //And only continues if the length of the text inputted minus 1 is greater than i, thus cutting it off at the end of the inputted text
        ShiftValue=((int)CT[i]-97+NegKey) % 26+97;//ASCII Text has a=97, b=98... etc | so we minus 97 to 0 it...
        cipher=(char)(ShiftValue); //Must be thingoed to a char and given to cipher or it will come out in a sequence of numbers rather than a word/s
        printf("%c", cipher); //Prints the decrypted text to the screen
        i++; //To continue adding to the index valriable
    }
}
// Explanation of the NegKey**: Really this whole decryption code is just an encryption code that loops right back around to being
// the unencrypted message... so the NegKey is just the number 26 (because of the number of letters in the alphabet) minus the number
// of shifts to the right that the encrypted message went through to be encrypted. This means that the encrypted message just gets 
// encrypted further to the right by 26 charcters minus the key, thus looping right back around to being the unencrypted message...
// its not complicated, its just stupid. 
