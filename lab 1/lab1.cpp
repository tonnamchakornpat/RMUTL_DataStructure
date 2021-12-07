#include<stdio.h>
#include<conio.h>

char ch ;

void UnsignedShortInt() ;
void boolean() ;
void UnsignedInt() ;
void Character() ;
void SFloat() ;
void UnsignedLongInt() ;
void Double() ;
void Int() ;
void UnsignedChar() ;
void SignedChar() ;

int main() {

    printf( "\nData REPRESENTATION PROGRAM \n" ) ;
    printf("================================\n") ;
    while( ch != '0' ) {
        printf("\n") ;
        printf( "[1]Unsign ShortInt     [2]Boolean    [3]Unsigned Int     [4]Character\n" ) ;
        printf( "[5]Single Prec Float   [6]Double     [7]Unsign LongInt   [8]Int \n" ) ;
        printf( "[9]Unsign Char         [a]sign Char                     [0]Exit" ) ;
        printf("\n") ;
        ch = getch() ;
        switch(ch) {

            case '1' : UnsignedShortInt() ;
                            break ;
            case '2' : boolean() ;
                            break ;
            case '3' : UnsignedInt() ;
                            break ;
            case '4' : Character() ;
                            break ;
            case '5' : SFloat() ;
                            break ;
            case '6' : Double() ;
                            break ; 
            case '7' : UnsignedLongInt() ;
                            break ; 
            case '8' : Int() ;
                            break ;
            case '9' : UnsignedChar() ;
                            break ;
            case 'a' : SignedChar() ;
                            break ;
        }
    }  
    printf( "\n" ) ;

    return 0 ;
}

void DecToBin( int data2, int byt ) {
    int count, chk, bits ;
    bits = ( byt*8 ) - 1 ;
    for ( count = bits ; count >= 0 ; count -- ) {
        chk = data2 >> count ;
        if( chk & 1 )  
            printf( "1" ) ;
        else
            printf( "0" ) ;
        if( count %4 == 0 && count > 3 ) 
            printf( " " ) ;
    }
    printf( "B \n" ) ;
}

void UnsignedShortInt() {
    unsigned short int data ;
    printf( "\nUNSIGNED SHORT INTERGER MODE [0 to 65,255]\n" ) ;
    printf("================================\n") ;
    printf( "Enter Raw Data : " ) ; 
    scanf( "%hu",&data ) ;
    printf( "Data in Decimal = %huD\n", data ) ;
    printf( "Data in Hexamal = %xH\n", data ) ;
    printf( "Data in Binary  =" ) ;
    DecToBin( data, sizeof(data) ) ;
    printf( "Size            = %d Bytes \n", sizeof(data) ) ;
    getch() ;
} 

void UnsignedInt() {
    unsigned int data ; 
    printf( "\nUNSIGNED INTEGER MODE [ 0 to 4,294,967,295 ]\n" ) ;
    printf("================================\n") ; 
    printf( "Enter Raw Data : " ) ; 
    scanf( "%u", &data ) ;
    printf( "Data in Decimal = %uD\n", data ) ;
    printf( "Data in Hexamal = %xH\n", data ) ;
    printf( "Data in Binary  = " ) ;
    DecToBin( data, sizeof( data ) ) ; 
    printf( "Size            = %d Bytes \n", sizeof(data) ) ;
    getch() ;
} 

void boolean() {
    bool data ;
    printf( "\nBOOLEAN MODE [0 to 255]\n" ) ;
    printf("================================\n") ; 
    printf( "Enter Raw Data : " ) ; 
    scanf( "%hu", &data ) ;
    printf( "Data Meaning " ) ;
    if( data ) 
        printf("True \n") ;
    else 
        printf("False \n") ;
    printf( "Data in Decimal = %uD\n", data ) ;
    printf( "Data in Hexamal = %xH\n", data ) ;
    printf( "Character       = %c\n", data ) ;
    printf( "Data in Binary  = " ) ;
    DecToBin( data, sizeof( data ) ) ; 
    printf( "Size            = %d Bytes \n", sizeof(data) ) ;
    getch() ;
}

void Character () {
    char data ;
    printf( "\nCHARACTER MODE [0 to 255]\n" ) ;
    printf("================================\n") ; 
    printf( "Enter Raw Data : " ) ; 
    scanf( "%c", &data ) ;
    printf( "Data in Decimal = %uD\n", data ) ;
    printf( "Data in Hexamal = %xH\n", data ) ;
    printf( "Character       = %c\n", data ) ;
    printf( "Data in Binary  = " ) ;
    DecToBin( data, sizeof( data ) ) ; 
    printf( "Size            = %d Bytes \n", sizeof(data) ) ;
    getch() ;
}

void SFloat() {
    float data ;
    printf( "\nSingle Precision Float MODE (1.2E-38 to 3.4E+38)\n" ) ;
    printf("================================\n") ; 
    printf( "Enter Raw Data : " ) ; 
    scanf( "%f", &data ) ;
    printf( "Data in Decimal = %fD\n", data ) ;
    printf( "Data in Hexamal = %xH\n", data ) ;
    printf( "Data in Binary  = " ) ;
    DecToBin( data, sizeof( data ) ) ; 
    printf( "Size            = %d Bytes \n", sizeof(data) ) ;
    getch() ;
}

void UnsignedLongInt() {
    unsigned long int data ; // ? declare data variable type Unsigned Long Int 
    printf( "\nUNSIGNED LONG INTERGER MODE [0 to 4,294,967,295]\n" ) ;
    printf("================================\n") ; 
    printf( "Enter Raw Data : " ) ; 
    scanf( "%lu",&data ) ; 
    printf( "Data in Decimal = %lu\n", data ) ;    // ? Show in Decimal format 
    printf( "Data in Hexamal = %xH\n", data ) ;     // ? Show in Hexamal format
    printf( "Data in Binary  = " ) ;                 
    DecToBin( data, sizeof(data) ) ;                // ? Show in Binary format 
    printf( "Size            = %d Bytes \n", sizeof(data) ) ; // ? Show  size of Unsigned Long Int 
    getch() ;
}

void Double() {
    double data ;
    printf( "\nDouble MODE [2.3E-308 to 3.4E+38]\n" ) ;
    printf("================================\n") ; 
    printf( "Enter Raw Data : " ) ; 
    scanf( "%lf", &data ) ;
    printf( "Data in Decimal = %lfD\n", data ) ;  //? Show in Decimal format       
    printf( "Data in Hexamal = %xH\n", data ) ;  //? Show in Hexamal format    
    printf( "Data in Binary  = " ) ;         
    DecToBin( data, sizeof( data ) ) ;       //? Show in Binary format
    printf( "Size            = %d Bytes \n", sizeof(data) ) ; //? Show size of Double 64 bit 
    getch() ;
}

void Int() {
    int data ;                              //? declare data type int 
    printf( "\nINTERGER MODE [-32768 to 32768]\n" ) ;
    printf("================================\n") ;
    printf( "Enter Raw Data : " ) ; 
    scanf( "%d",&data ) ;
    printf( "Data in Decimal = %dD\n", data ) ; //? show data type decimal format
    printf( "Data in Hexamal = %xH\n", data ) ; //? show data  type Hex format
    printf( "Data in Binary  =" ) ;
    DecToBin( data, sizeof(data) ) ;
    printf( "Size            = %d Bytes \n", sizeof(data) ) ;
    getch() ;
}

void UnsignedChar(){
    unsigned char data ;
    printf( "\nUNSIGN CHARACTER MODE [ Character  0 to 255 ]\n" ) ;
    printf( "================================\n" ) ; 
    printf( "Enter Raw Data : " ) ; 
    scanf( "%c", &data ) ;
    printf( "Data in Decimal = %uD\n", data ) ;
    printf( "Data in Hexamal = %xH\n", data ) ;
    printf( "Character       = %c\n", data ) ;
    printf( "Data in Binary  = " ) ;
    DecToBin( data, sizeof( data ) ) ; 
    printf( "Size            = %d Bytes \n", sizeof(data) ) ;
    getch() ;
}

void SignedChar() {
    signed char data ;
    printf( "\nCHARACTER MODE [ Character  -128 to 127 ]\n" ) ;
    printf( "================================\n" ) ; 
    printf( "Enter Raw Data : " ) ; 
    scanf( "%d", &data ) ;
    printf( "Data in Decimal = %dD\n", data ) ;
    printf( "Data in Hexamal = %xH\n", data ) ;
    printf( "Character       = %c\n", data ) ;
    printf( "Data in Binary  = " ) ;
    DecToBin( data, sizeof( data ) ) ; 
    printf( "Size            = %d Bytes \n", sizeof(data) ) ;
    getch() ;
}