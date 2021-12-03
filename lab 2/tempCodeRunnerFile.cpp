      case '8' :
            Create3DArray() ;
            i = 3, j = 4, k = 5 ;
            A3CRP( i, j, k, 999 ) ;
            printf( "\nA3 (%2d, %2d, %2d )  = %4d ", i, j, k, ReadA3CRP( i, j, k ) ) ;
            printf( "\nAddress BA3       = %d ", BA3 ) ;
            free( BA3 ) ;
            break ;