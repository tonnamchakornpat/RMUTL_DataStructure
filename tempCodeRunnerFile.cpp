#include <stdio.h>

int main() {
    int arr[4] = { 4, 2, 3, 1 } ;
    int temp ;
    for( int i = 0 ; i < 4 ; i++ ) 
        for( int j = 0 ; j < 4 ; j++ ) {
            if( arr[ j ] > arr[ j + 1 ] ) {
            temp = arr[ j ] ;
            arr[ j ] = arr[ j + 1 ] ;
            arr[ j + 1 ] = temp ;
            }
        }
    
    for( int i  = 0 ; i < 4 ; i++ ) 
        printf(" %d " , arr[ i ]) ;
    return 0 ;
}