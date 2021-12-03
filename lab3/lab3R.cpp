#include <stdio.h>
#include <conio.h>
#define MaxStack 6 

int stack[MaxStack] ;
int x ;
int SP = MaxStack ;                      //? edit SP = 0 to SP = MaxStack
char status = 'N' ;
char ch ;

void push( int ) ;
int pop() ;
void ShowAllStack() ;

int main() {
    printf( "STACK PROGRAM \n" ) ;
    printf( "=========================\n" ) ;
    while ( status == 'N' ) {
        printf( "[ 1 = PUSH  : 2 = POP ]" ) ;
        ch = getch() ;
        switch (ch)
        {
        case '1' :
            printf( "\nEnter Number : " ) ;
            scanf( " %d", &x ) ;
            push( x ) ;
            ShowAllStack() ;
            break;
        case '2' : 
            x = pop() ;
            printf( "\n\n--Data : %d --\n", x ) ;
            ShowAllStack() ;
            break ;

        }
        
    }
    
    return 0 ;
}

void push( int x ) {
    
    if( SP == 1 ) {                     //? SP == MaxStack - 1
        printf( "!!!OVER FLOW!!!\n" ) ;
        status = 'O' ;
    } else {
        SP = SP - 1 ;                   //?edit SP = SP + 1 TO SP = SP - 1
        stack[ SP ] = x ;
    }
}

int pop() {
    int x ;
    if( SP != MaxStack ) {              //? edit SP !=  0 to SP != MaxStack
        x = stack[ SP ] ;
        SP++ ; 
        return(x) ;
    } else {
        printf( "\n!!!UNDER FLOW!!!\n" ) ;
        status = 'U' ;
    }
}

void ShowAllStack() {
    int i ; 
    printf("\n") ;
    printf( "   N : %d \n", MaxStack - 1 ) ;
    printf( "   Status : %c \n",status ) ;
    printf( "   SP : %d \n", SP ) ;
    for( i = 1 ; i < MaxStack ; i++ ) {
        printf( "%d:%d ", i, stack[ i ] ) ;
    }
    printf("\n------------------------\n\n") ;
}
