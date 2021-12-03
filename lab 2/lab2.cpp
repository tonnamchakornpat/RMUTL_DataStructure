#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define l 1 
#define u 5 
#define l1 1
#define u1 3 
#define l2 1 
#define u2 4 
#define l3 1
#define u3 5

int *BA1, *BA2, *BA3, *p ;
int i, j, k ;
char ch ;


void Create1DArray() ; 
void Create2DArray() ; 
void Create3DArray() ; 

void A1( int, int )  ;

void A2RM( int, int, int ) ;
void A2CM( int, int, int ) ;

void A3PRC( int, int, int, int ) ;
void A3PCR( int, int, int, int ) ;
void A3RPC( int, int, int, int ) ;
void A3RCP( int, int, int, int ) ;
void A3CPR( int, int, int, int ) ;
void A3CRP( int, int, int, int ) ;


int ReadA1( int ) ;

int ReadA2RM( int, int ) ;
int ReadA2CM( int, int ) ;

int ReadA3PRC( int, int, int ) ;
int ReadA3PCR( int, int, int ) ;
int ReadA3RPC( int, int, int ) ;
int ReadA3RCP( int, int, int ) ;
int ReadA3CPR( int, int, int ) ;
int ReadA3CRP( int, int, int ) ;


int main() {
    Create1DArray() ;
    Create2DArray() ;
    Create3DArray() ;


    printf( " 1-3 DIMENSION ARRAY FUNCTION... \n" ) ;
    printf( "=============================\n" ) ;
    while( ch != 'e' ) {
        printf( "[0]1D          [1]2D(RM) \n" ) ;
        printf( "[2]2D(CM)      [3]3D(PRC) \n" ) ;
        printf( "[4]3D(PCR)     [5]3D(RPC) \n" ) ;
        printf( "[6]3D(RCP)     [7]3D(CPR) \n" ) ;
        printf( "[8]3D(CRP)     [e]EXIT \n" ) ;
        ch = getch() ;
        switch (ch) {
        case '0' : 
            i = 2 ;
            A1( i , 9 ) ;
            printf( "\nA1 (%2d )          = %4d ", i, ReadA1( i ) ) ;
            printf( "\nAddress BA1       = %d ", BA1 ) ;
            printf( "\nAddress ARR       = %d ", p ) ;
            getch() ;
            break ;
        case '1' :
            i = 2, j = 3 ;
            A2RM( i, j, 99 ) ;
            printf( "\nA2 RM(%2d, %2d )      = %4d ", i, j, ReadA2RM( i, j ) ) ;
            printf( "\nAddress BA2       = %d ", BA2 ) ;
            printf( "\nAddress ARR       = %d ", p ) ;
            getch() ;
            break ;
        case '2' :
            i = 2, j = 3 ;
            A2CM( i, j, 99 ) ;
            printf( "\nA2 CM(%2d, %2d )      = %4d ", i, j, ReadA2CM( i, j ) ) ;
            printf( "\nAddress BA2       = %d ", BA2 ) ;
            printf( "\nAddress ARR       = %d ", p ) ;
            getch() ;
            break ;
        case '3' :
            i = 3, j = 4, k = 5 ;
            A3PRC( i, j, k, 999 ) ;
            printf( "\nA3 PRC(%2d, %2d, %2d )  = %4d ", i, j, k, ReadA3PRC( i, j, k ) ) ;
            printf( "\nAddress BA3       = %d ", BA3 ) ;
            printf( "\nAddress ARR       = %d ", p ) ;
            getch() ;
            break ;
        case '4' :
            i = 3, j = 4, k = 5 ;
            A3PCR( i, j, k, 999 ) ;
            printf( "\nA3 PCR(%2d, %2d, %2d )  = %4d ", i, j, k, ReadA3PCR( i, j, k ) ) ;
            printf( "\nAddress BA3       = %d ", BA3 ) ;
            printf( "\nAddress ARR       = %d ", p ) ;
            getch() ;
            break ;
        case '5' :
            i = 3, j = 4, k = 5 ;
            A3RPC( i, j, k, 999 ) ;
            printf( "\nA3 RPC(%2d, %2d, %2d )  = %4d ", i, j, k, ReadA3RPC( i, j, k ) ) ;
            printf( "\nAddress BA3       = %d ", BA3 ) ;
            printf( "\nAddress ARR       = %d ", p ) ;
            getch() ;
            break ;
        case '6' :
            i = 3, j = 4, k = 5 ;
            A3RCP( i, j, k, 999 ) ;
            printf( "\nA3 RCP(%2d, %2d, %2d )  = %4d ", i, j, k, ReadA3RCP( i, j, k ) ) ;
            printf( "\nAddress BA3       = %d ", BA3 ) ;
            printf( "\nAddress ARR       = %d ", p ) ;
            getch() ;
            break ;
        case '7' :
            i = 3, j = 4, k = 5 ;
            A3CPR( i, j, k, 999 ) ;
            printf( "\nA3 CPR(%2d, %2d, %2d )  = %4d ", i, j, k, ReadA3CPR( i, j, k ) ) ;
            printf( "\nAddress BA3       = %d ", BA3 ) ;
            printf( "\nAddress ARR       = %d ", p ) ;
            getch() ;
            break ;
        case '8' :
            i = 3, j = 4, k = 5 ;
            A3CRP( i, j, k, 999 ) ;
            printf( "\nA3 CRP(%2d, %2d, %2d )  = %4d ", i, j, k, ReadA3CRP( i, j, k ) ) ;
            printf( "\nAddress BA3       = %d ", BA3 ) ;
            printf( "\nAddress ARR       = %d ", p ) ;
            getch() ;
            break ;
        }
        printf( "\n\n" ) ;
        
    }
    free( BA1 ) ;
    free( BA2 ) ;
    free( BA3 ) ;

    return 0 ;
} 

// TODO Array 1D
//!------------------------------------------
void Create1DArray () {
    int element, c, total_mem ;
    c = sizeof( *BA1 ) ;
    total_mem = element * c ;
    BA1 = (int*)malloc( total_mem ) ;
}

void A1( int i, int x ) {
    p = BA1 +( i + l ) ;
    *p = x ;
}

int ReadA1( int i ) {
    p = BA1 + ( i+l ) ;
    return ( *p ) ;}


// TODO Array 2D
//!------------------------------------------
void Create2DArray() {
    int element, c, total_mem ; 
    element = ( u1 - l1 + 1 ) * ( u2 - l2 + 1 ) ;
    c = sizeof( *BA2 ) ;
    total_mem = element * c ;
    BA2 = (int*) malloc( total_mem ) ;
}

void A2RM( int i, int j, int x ) {
    p  = BA2 + ( ( i - l1 ) * ( u2 -l2 + 1 ) + ( j - l2 ) ) ;
    *p = x ;
}

void A2CM( int i, int j, int x ) {
    p = BA2 + ( ( j - l2) * ( u1 - l2 + 1 ) + ( i -l1 ) ) ;
    *p = x ;
}

int ReadA2RM( int i, int j ) {
    p = BA2 + ( ( i - l1 ) * ( u2 - l2 + 1 ) + ( j - l2 ) ) ;
    return ( *p ) ;
}

int ReadA2CM( int i, int j ) {
    p = BA2 + ( ( i - l1 ) * ( u2 - l2 + 1 ) + ( j - l2 ) ) ;
    return ( *p ) ;
}


// TODO Array 3D
//!--------------------------------------------
void Create3DArray() {
    int element, c, total_mem ;
    element = ( u1 - l1 + 1 ) * ( u2 - l2 + 1 ) * ( u3 - l3 + 1 ) ;
    c = sizeof( *BA3 ) ;
    total_mem = element * c ;
    BA3 = ( int* ) malloc( total_mem ) ;
} 
//-----------PRC Type------------------
void A3PRC( int i, int j, int k, int x ) {
    p = BA3 + ( ( i - l1 ) * ( u2 - l2 + 1 ) * ( u3 - l3 + 1 ) + ( j - l2 ) * ( u3 - l3 + 1 ) + ( k - l3 ) ) ;
    *p = x ;
} 

int ReadA3PRC( int i, int j, int k ) {
    p = BA3 + ( i - l1 ) * ( u2 - l2 + 1 ) * ( u3 - l3 + 1 ) + ( j - l2 ) * ( u3 - l3 + 1 ) + ( k - l3 ) ;
    return ( *p ) ;
}

//-----------PCR Type------------------
void A3PCR( int i, int j, int k, int x ) {
    p = BA3 + ( ( i - l1 ) * ( u2 - l2 + 1 ) * ( u3 - l3 + 1 ) + ( k - l3 ) * ( u2 - l2 + 1 ) + ( j - l2 ) ) ;
    *p = x ;
} 

int ReadA3PCR( int i, int j, int k ) {
    p = BA3 + ( ( i - l1 ) * ( u2 - l2 + 1 ) * ( u3 - l3 + 1 ) + ( k - l3 ) * ( u2 - l2 + 1 ) + ( j - l2 ) ) ;
    return ( *p ) ;
}

//-----------RPC Type------------------
void A3RPC( int i, int j, int k, int x ) {
    p = BA3 + ( ( j - l2 ) * ( u1 - l1 + 1 ) * ( u3 - l3 + 1 ) + ( i - l1 ) * ( u3 - l3 + 1 ) + ( k - l3 ) ) ;
    *p = x ;
} 

int ReadA3RPC( int i, int j, int k ) {
    p = BA3 + ( ( j - l2 ) * ( u1 - l1 + 1 ) * ( u3 - l3 + 1 ) + ( i - l1 ) * ( u3 - l3 + 1 ) + ( k - l3 ) ) ;
    return ( *p ) ;
}

// -----------RCP Type------------------
void A3RCP( int i, int j, int k, int x ) {
    p = BA3 + ( ( j - l2 ) * ( u1 - l1 + 1 ) * ( u3 - l3 + 1 ) + ( k - l3 ) * ( u1 - l1 + 1 ) + ( i - l1 ) ) ;
    *p = x ;
} 

int ReadA3RCP( int i, int j, int k ) {
    p = BA3 + ( ( j - l2 ) * ( u1 - l1 + 1 ) * ( u3 - l3 + 1 ) + ( k - l3 ) * ( u1 - l1 + 1 ) + ( i - l1 ) ) ;
    return ( *p ) ;
}

// -----------CPR Type------------------
void A3CPR( int i, int j, int k, int x ) {
    p = BA3 + ( ( k - l3 ) * ( u1 - l1 + 1 ) * ( u2 - l2 + 1 ) + ( i - l1 ) * ( u2 - l2 + 1 ) + ( j - l2 ) ) ;
    *p = x ;
} 

int ReadA3CPR( int i, int j, int k ) {
    p = BA3 + ( ( k - l3 ) * ( u1 - l1 + 1 ) * ( u2 - l2 + 1 ) + ( i - l1 ) * ( u2 - l2 + 1 ) + ( j - l2 ) ) ;
    return ( *p ) ;
}
//-----------CRP Type------------------
void A3CRP( int i, int j, int k, int x ) {
    p = BA3 + ( ( k - l3 ) * ( u1 - l1 + 1 ) * ( u2 - l2 + 1 ) + ( j - l2 ) * ( u1 - l1 + 1 ) + ( i - l1 ) ) ;
    *p = x ;
} 

int ReadA3CRP( int i, int j, int k ) {
    p = BA3 + ( ( k - l3 ) * ( u1 - l1 + 1 ) * ( u2 - l2 + 1 ) + ( j - l2 ) * ( u1 - l1 + 1 ) + ( i - l1 ) ) ;
    return ( *p ) ;
} 
//!--------------------------------------------