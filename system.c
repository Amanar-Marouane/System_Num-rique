#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define MAX_DIGITS 12

void BinToDec(int theCode);
void BinToOctal(int theCode);
void BinToHexa(int theCode);

void DecToBin(int theCode);
void DecToOctal(int theCode);
void DecToHexa(int theCode);

void OctalToBin(int theCode);
void OctalToDec(int theCode);
void OctalToHexa(int theCode);

void HexaToBin(char HexaCode[MAX_DIGITS]);
void HexaToDec(char HexaCode[MAX_DIGITS]);
void HexaToOctal(char HexaCode[MAX_DIGITS]);

int main(){
    int codeType,conTypeFromBin,conTypeFromDec,conTypeFromOctal,conTypeFromHexa;
    int theCode;
    char HexaCode[MAX_DIGITS] = {'\0'};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("press 1 to enter binary code.\npress 2 to enter decimal code.\npress 3 to enter octal code.\npress 4 to enter hexa-decimal code.\npress 0 to quit.\n");
    scanf("%i",&codeType);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (codeType == 0)
    {
        printf("U quit, bye Bitch :)");
        exit(codeType);
    }else if ((codeType < 0 || codeType > 4))
    {
        printf("Press valid number");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Enter the code ==> ");
    if (codeType == 4)
    {
        scanf("%11s",HexaCode);
    }else{
        scanf("%11i",&theCode);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        switch (codeType)
        {
        case 0:
            break;
        case 1:
            printf("press 1 to convert your code to decimal.\npress 2 to convert your code to octal.\npress 3 to convert your code to hexa-decimal.\n");
            scanf("%i",&conTypeFromBin);
            break;
        case 2:
            printf("press 1 to convert your code to binary.\npress 2 to convert your code to octal.\npress 3 to convert your code to hexa-decimal.\n");
            scanf("%i",&conTypeFromDec);
            break;
        case 3:
            printf("press 1 to convert your code to binary.\npress 2 to convert your code to decimal.\npress 3 to convert your code to hexa-decimal.\n");
            scanf("%i",&conTypeFromOctal);
            break;
        case 4:
            printf("press 1 to convert your code to binary.\npress 2 to convert your code to decimal.\npress 3 to convert your code to octal.\n");
            scanf("%i",&conTypeFromHexa);
            break;
        default:
            printf("Press valid number\n");
            break;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (codeType == 1)
    {
        switch (conTypeFromBin)
        {
        case 1:
            BinToDec(theCode);
            break;
        case 2:
            BinToOctal(theCode);
            break;
        case 3:
            BinToHexa(theCode);
            break;
        default:
            printf("R U fokin damp.\n");
            break;
        }
    }else if (codeType == 2)
    {
        switch (conTypeFromDec)
        {
        case 1:
            DecToBin(theCode);
            break;
        case 2:
            DecToOctal(theCode);
            break;
        case 3:
            DecToHexa(theCode);
            break;
        default:
            printf("R U fokin damp.\n");
            break;
        }
    }else if (codeType == 3)
    {
        switch (conTypeFromOctal)
        {
        case 1:
            OctalToBin(theCode);
            break;
        case 2:
            OctalToDec(theCode);
            break;
        case 3:
            OctalToHexa(theCode);
            break;
        default:
            printf("R U fokin damp.\n");
            break;
        }
    }else if (codeType == 4)
    {
        switch (conTypeFromHexa)
        {
        case 1:
            HexaToBin(HexaCode);
            break;
        case 2:
            HexaToDec(HexaCode);
        case 3:
            HexaToOctal(HexaCode);
            break;
        default:
            printf("R U fokin damp.\n");
            break;
        }
    }

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BinToDec(int theCode){
    int decimalCode = 0, base = 1;

    while (theCode > 0)
    {
        int last_digit = theCode%10;
        decimalCode += last_digit * base;
        base *= 2;
        theCode /= 10;
    }

    printf("Ur decimal converted code is ==> %i.\n",decimalCode);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BinToOctal(int theCode){
    int octalCode = 0, basePosition = 1;
    while (theCode > 0)
    {
        int theLast_ThreeDigits = theCode % 1000, base = 1, primaryPosition = 0;

        while (theLast_ThreeDigits)
        {
            int last_digit = theLast_ThreeDigits%10;
            primaryPosition += last_digit * base;
            base *= 2;
            theLast_ThreeDigits /= 10;
        }

        octalCode += primaryPosition * basePosition;
        basePosition *= 10;
        theCode /= 1000;
    }
    printf("Ur octal converted code is ==> %i.\n",octalCode);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BinToHexa(int theCode){
    char hexaCode[MAX_DIGITS];
    int index = 0;

    while (theCode > 0)
    {
        int theLast_FourDigits = theCode % 10000, base = 1, primaryPosition = 0;

        while (theLast_FourDigits > 0)
        {
            int last_digit = theLast_FourDigits%10;
            primaryPosition += last_digit * base;
            base *= 2;
            theLast_FourDigits /= 10;
        }
        if (primaryPosition < 10) {
            hexaCode[index] = primaryPosition + '0';
        } else {
            hexaCode[index] = primaryPosition - 10 + 'A';
        }
        index++;
        theCode /= 10000;
    }
    printf("Ur Hexa-Decimal converted code is ==> ");
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c",hexaCode[i]);
    }
    printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DecToBin(int theCode){
    int binaryDigits[MAX_DIGITS], index = 0;

    if (theCode == 0)
    {
        printf("Ur decimal converted code is ==> 0000.\n");
        return;
    }

    while (theCode > 0)
    {
        binaryDigits[index] = theCode % 2;
        index ++;
        theCode /= 2;
    }
    printf("Ur decimal converted code is ==> ");
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%i",binaryDigits[i]);
    }
    printf(".\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DecToOctal(int theCode){
    int octalDigits[MAX_DIGITS], index = 0;

    if (theCode == 0)
    {
        printf("Ur octal converted code is ==> 0.\n");
        return;
    }
    while (theCode > 0)
    {
        octalDigits[index] = theCode%8;
        index++;
        theCode /= 8;
    }
    printf("Ur octal converted code is ==> ");
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%i",octalDigits[i]);
    }
    printf(".\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DecToHexa(int theCode){
    int hexaCode[MAX_DIGITS], index = 0;

    while (theCode > 0)
    {
        hexaCode[index] = theCode % 16;
        if (hexaCode[index] <= 9)
        {
            hexaCode[index] = hexaCode[index] + '0';
        }else if (hexaCode[index] > 9)
        {
            hexaCode[index] = (hexaCode[index] - 10) + 'A';
        }
        index++;
        theCode /= 16;
    }
    printf("Ur hexa-decimal converted code is ==> ");
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c",hexaCode[i]);
    }
    printf(".\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OctalToBin(int theCode){
    int binDigits[MAX_DIGITS], index = 0;

    if (theCode == 0)
    {
        printf("Ur octal converted code is ==> 0000.\n");
        return;
    }

    int FirsDigit;
    while (theCode > 0)
    {
        FirsDigit = theCode % 10;
        while (FirsDigit > 0)
        {
            binDigits[index] = FirsDigit%2;
            FirsDigit /= 2;
            index ++;
        }
        theCode /= 10;
    }
    printf("Ur binary converted code is ==> ");
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%i",binDigits[i]);
    }
    printf(".\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OctalToDec(int theCode){
    int decCode = 0, firstDigit, power = 0;
    while (theCode > 0)
    {
        firstDigit = theCode % 10;
        decCode += firstDigit * pow(8,power);
        power++;
        theCode /= 10;
    }
    printf("Ur decimal converted code is ==> %i.\n",decCode);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OctalToHexa(int theCode){
    int decCode = 0, firstDigit, power = 0;
    while (theCode > 0)
    {
        firstDigit = theCode % 10;
        decCode += firstDigit * pow(8,power);
        power++;
        theCode /= 10;
    }

    int hexaCode[MAX_DIGITS], index = 0;
    while (decCode > 0)
    {
        hexaCode[index] = decCode % 16;
        if (hexaCode[index] <= 9)
        {
            hexaCode[index] = hexaCode[index] + '0';
        }else if (hexaCode[index] > 9)
        {
            hexaCode[index] = (hexaCode[index] - 10) + 'A';
        }
        index++;
        decCode /= 16;
    }

    printf("Ur hexa-decimal converted code is ==> ");
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c",hexaCode[i]);
    }
    printf(".\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HexaToBin(char HexaCode[MAX_DIGITS]){
    const char* BinMap[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    int i = 0;

    while (HexaCode[i] != '\0')
    {
        char hexDigit = HexaCode[i];
        int index;

        if (hexDigit >= '0' && hexDigit <= '9')
        {
            index = hexDigit - '0';
        }else if (hexDigit >= 'A' && hexDigit <= 'F')
        {
            index = hexDigit - 'A' + 10;
        }else if (hexDigit >= 'a' && hexDigit <= 'f')
        {
            index = hexDigit - 'a' + 10;
        }else {
            printf("Invalid hexadecimal digit: %c\n", hexDigit);
            return;
        }
        printf("%s",BinMap[index]);
        i++;
    }
    printf(".\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HexaToDec(char HexaCode[MAX_DIGITS]){
    int integer, DecCode = 0, i = 0;

    while (HexaCode[i] != '\0')
    {   
        char hexDigit = HexaCode[i];
        int SixteenP = pow(16,strlen(HexaCode) - i - 1);
        if (hexDigit >= '0' && hexDigit <= '9')
        {
            integer = hexDigit - '0';
        }else if (hexDigit >= 'A' && hexDigit <= 'F')
        {
            integer = hexDigit - 'A' + 10;
        }else if (hexDigit >= 'a' && hexDigit <= 'f')
        {
            integer = hexDigit - 'a' + 10;
        }else {
            printf("Invalid hexadecimal digit: %c\n", hexDigit);
            return;
        }
        DecCode += integer * SixteenP;
        i++;
    }
    printf("Ur decimal converted code is ==> %i.\n", DecCode);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HexaToOctal(char HexaCode[MAX_DIGITS]){
    int integer, DecCode = 0, i = 0;

    while (HexaCode[i] != '\0')
    {   
        char hexDigit = HexaCode[i];
        int SixteenP = pow(16,strlen(HexaCode) - i - 1);
        if (hexDigit >= '0' && hexDigit <= '9')
        {
            integer = hexDigit - '0';
        }else if (hexDigit >= 'A' && hexDigit <= 'F')
        {
            integer = hexDigit - 'A' + 10;
        }else if (hexDigit >= 'a' && hexDigit <= 'f')
        {
            integer = hexDigit - 'a' + 10;
        }else {
            printf("Invalid hexadecimal digit: %c\n", hexDigit);
            return;
        }
        DecCode += integer * SixteenP;
        i++;
    }
    int OctalCode = 0, base = 1, OctalDigit;
    while (DecCode > 0)
    {
        OctalDigit = DecCode % 8 * base;
        OctalCode += OctalDigit;
        DecCode /= 8;
        base *= 10;
    }
    
    printf("Ur Octal converted code is ==> %i.\n", OctalCode);
}