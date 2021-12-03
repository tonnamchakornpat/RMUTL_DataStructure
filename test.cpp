#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value ;
    Node *next ;
} ;

Node *insertNode( int, Node * ) ;
Node *createNode( int , Node * ) ;
Node *saveNode( int , Node * ) ;
void delNode( int , Node ** ) ;
void showNode( Node * ) ;

int main() {
    
    printf( "์\n\n--------create Node-------\n" ) ;
    Node *start = saveNode( 1, NULL ) ;
    start = saveNode( 2, start ) ;
    start = saveNode( 4, start ) ;
    showNode( start ) ;

    start = insertNode( 3, start ) ;
    printf( "์\n\n--------insert-------\n" ) ;
    showNode( start ) ; 
  
    printf( "์\n\n---------Delete 3 ------\n" ) ;
    delNode( 3 , &start ) ;
    showNode( start ) ;

    return 0;
} // end function

//? show all data in linklist
void showNode( Node *item ) {
    while( item != NULL ) {
        int value = item -> value ;
        printf( "cur item = %p , value %d \n", item, value ) ; 
        item = item -> next ;
    } // end while  item
} // end function

void delNode( int key, Node **root ) {
   Node *temp ;
   if( (*root) -> value == key) {
       temp = *root ;
       *root = (*root) -> next ;
       free( temp );
    } else {
        Node *walk  = *root;
        while( walk -> next != NULL) 
            if( walk -> next -> value == key) {
                temp = walk -> next;
                walk -> next = walk -> next -> next;
                free( temp );
            } else
                walk = walk -> next;
    } //end if 
} // end function delNode 

Node *insertNode( int newValue, Node *root ) {
    if( root == NULL ) return createNode( newValue, NULL ) ;
    if( root -> value >= newValue ) { 
        return createNode( newValue, root ) ;
    } else{
        root -> next = insertNode( newValue, root -> next ) ;
        return root ;
    } // end if 
} // end function insertNode 

Node *saveNode( int newValue, Node *root ) {
    if( root == NULL ) return createNode( newValue, NULL ) ; 
    root -> next = saveNode( newValue, root -> next ) ;
    return root ;
} // end function saveNode

Node *createNode( int newValue, Node *NextNode ) {
    Node* newNode = (Node *)malloc( sizeof(Node) ) ;
    newNode -> value = newValue ;
    newNode -> next = NextNode ;
    return newNode ;
} //end function createnode
