#include<stdio.h>
#include<conio.h>

#define N 5 

int Q[ N ] ;
int x, Qnumber = 0, F = 0, R = 0 ;
char status = 'N' ;
char ch ;

void insertCQ( int ) ;
int deleteCQ() ;
int DatainQueue() ;
void ShowAllQueue() ;

int main() {
    printf( "CIRCULAR QUEUE PROGRAM....." ) ;
    printf( "\n=======================\n" ) ;
    ch = ' ' ;
    while( ch != 'e' ) {
        printf( "[ 1 = INSERT : 2 = DELETE  E: Exit ]" ) ;
        ch = getch() ;
        switch ( ch ) {
        case '1' :
            printf( "\nInsert Number :" ) ;
            scanf( " %d", &x ) ;
            insertCQ( x ) ;
            ShowAllQueue() ;
            break;
        case '2' :
            x = deleteCQ() ;
            printf( "\n+++Data from Queue = %d +++ \n", x ) ;
            ShowAllQueue() ;
        }
    }
    printf( "\n" ) ;
    return 0  ;
}
void insertCQ( int y ) {
    if( ( R == F -1 ) || ( R == N -1  && F == 1 ) ) {
        printf( "!!OVER FLOW!! \n" ) ;
        status = 'O' ;
    }else {
        if( R == N-1 ) {
            R = 1 ;

        } else {
            R++ ;
            if( F== 0 ) F = 1 ;
        }
        Qnumber++ ;
        printf( "Your are queue number : %d\n", Qnumber ) ; 
        Q[ R ] = y ;
        status = 'N' ;
    }
} 

int deleteCQ() {
    int y ; 
    if( F == 0 ) {
        printf( "\n!!!!UNDER FLOW!!!!\n" ) ;
        status = 'U' ;
    } else {
        y = Q[ F ] ;
        if( F == R ) {
            F = 0 ; R = 0 ;
        } else {
            if( F == N-1 ) F = 1 ;
            else F++ ; 
        }
        status = 'N' ;
        return( y ) ;
    }
}

int DataInQueue() {
    int y = 0 ;
    if ( F != 0 && R != 0 ) {
        if( F < R )  y = R - F + 1 ;
        else y = ( N-1 ) - F + 1 + R ;
    }
    return ( y ) ;
}

void ShowAllQueue() {
    int i ;
    printf( "\nN : %d \n", N-1 ) ;
    printf( "Status = %c \n", status ) ;
    printf( "Data Waiting in queue = %d \n", DataInQueue() ) ;
    printf( "F = %3d  / R = %3d\n", F, R ) ;
    for( i = 1 ; i < N ; i++ )  printf( "%d : %d /", i, Q[i] ) ;
    printf( "\n=======================\n" ) ;
}

