#include <stdio.h>
#include<stdlib.h>
struct Node {
    int value ;
    Node *next ;
} ;

Node *SaveNode( Node *, int ) ;
Node *addNode( Node *, int ) ;
Node *DelNode( Node *item, int keyvalue ) {
    Node *temp, *walk = item ;
    while( walk -> next != NULL ) {
        
        if( walk -> value != keyvalue )
            walk = walk -> next ;
        else {
            temp = walk -> next -> next ;
            walk -> next = temp -> next ;
            free(temp) ;
            break ;
        }

    }
}

void showNode( Node * ) ;

int main() {

    Node *start,*n1,**n2 ;
    start = new Node ;
    start = addNode( NULL, 1 ) ;
    start = addNode( start, 2 ) ; 
    start = addNode( start, 3 ) ;
    n1 = start ;
    n2 = &start ;
    DelNode( start, 2 ) ;
    showNode( n1 ) ; 
    return 0 ;
} //end fuction

void showNode( Node *item ) {
    while( item != NULL ) {
        int value = item -> value ;
        printf( "cur item = %p , value %d \n", item, value ) ; 
        item = item -> next ;
    } // end while 
} // end function

Node *SaveNode( Node *NextNode, int newvalue ) {
    Node *newNode = new Node ;
    newNode -> value = newvalue ;
    newNode -> next = NextNode ;
    return newNode ;
}// end function

Node *addNode( Node *root, int value ) {
    if( root == NULL ) return SaveNode( NULL , value ) ;
    root -> next = addNode( root -> next , value ) ;
    return root ;
}// end function