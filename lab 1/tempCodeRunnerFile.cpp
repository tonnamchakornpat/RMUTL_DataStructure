#include <stdio.h>

struct NODE{
    int value ;
    NODE *next ;
} ;

void Addnode() ;
void InsertNode() ;
void DeleteNode() ;

int main() {
    NODE n1 = (NODE)( 1, NULL ) ;
    NODE n2 = (NODE)( 2, &n1 ) ;
    NODE n3 = (NODE)( 3, &n2 ) ;
    NODE *start = &n1 ;

    return 0 ;
} // end of function