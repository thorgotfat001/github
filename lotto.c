
////////////////////****done迴圈****///////
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/dutch/lotto.h"

int checktwo ( int target , int *arr , int buy , int arr_index ) ;
int judge ( int *arr , int arr_index ) ;
int judgetwo ( int *arr , int arr_index ) ;

int checktwo ( int target , int *arr , int buy , int arr_index )
{
    int i , j ;

    i = buy ;
    for ( j = 0 ; j < arr_index ; j ++ )
    {

        if ( target == * ( arr + ( arr_index * i ) + j ) )
        {
//** printf("中!!%2d\t\n",target);中獎數字**//
            return 1 ;
        }
    }
    return 0 ;
}

int judge ( int *arr , int arr_index )
{
    int i ;
 /*   for ( i = 0 ; i < arr_index ; i ++ )
    {
        printf ( "3333333333333333%2d\t" , arr [ i ] ) ;
    }
    */
    for ( i = 0 ; i < arr_index ; i ++ )
    {

        if ( arr [ i ] == 0 )
        {
            /*    printf ( "超出範圍1111\n" ) ; */

            return 1 ;
        }
        if ( ! ( ( arr [ i ] > 0 ) && ( arr [ i ] <= 50 ) ) )
        {
            /*     printf ( "超出範圍2222\n" ) ; */
            return 2 ;
        }

    }
    return 5 ;

}

///*****輸入重複****////
int judgetwo ( int *arr , int arr_index )
{
    int i , j , dist ;

    for ( i = 0 ; i < arr_index ; i ++ )
    {
        dist = 0 ;
        for ( j = 0 ; j < arr_index ; j ++ )
        {
            if ( arr [ i ] == arr [ j ] )
            {
                dist ++ ;
            }
            if ( dist >= 2 )
            {

                return 1 ;
            }
        }

    }

    return 3 ;

}

int main ( )
{
    int buy = 0 ;
    char str [ 100 ] = { 0 } ;

    int show [ 1000 ] [ 6 ] = { 0 } ;
    int a [ 1000 ] = { 0 } ;
    char delim1 [ ] = ":,;, " ;
    int lottotwo [ 49 ] ;
    int i = 0 , j = 0 , b = 0 ;
    int lotto [ 49 ] , ball_qty = 6 , c = 0 , targetin = 0 , value = 0 , decide = 0 ;
    int choice = 0 , choice_one = 0 ;
    char *Token = ( char * ) malloc ( sizeof(char) ) ; /*分割字串*/
    int ball_numb [ 6 ]= { 0 } ;

    while ( choice != 5 )
    {
        choice = 0 ;
        printf ( "\n" ) ;
        printf ( "1.購買彩卷\n2.查詢已購買彩卷\n3.開獎\n4.清除購買紀錄\n5.結束\n" ) ;
        scanf ( "%d" , & choice ) ;
        fflush ( stdin ) ;
        decide = 2 ;

        switch ( choice )
        {
            while ( decide != 1 )
            {
                case 1 :
                printf ( "1.電腦選號\n2.手動輸入\n" ) ;
                scanf ( "%d" , & choice_one ) ;
                fflush ( stdin ) ;
                switch ( choice_one )
                {
                    case 1 :
                        generate_lotto_sort ( lotto , ball_qty ) ;
                        for ( j = 0 ; j < ball_qty ; j ++ )
                        {

                            show [ buy ] [ j ] = lotto [ j ] ;
                        }
                        buy ++ ;
                        break ;
                    case 2 :
                        fflush ( stdin ) ;
                        while ( b != 3 )
                        {
                            fflush ( stdin ) ;
                            printf ( "請輸入\n" ) ;
                            fgets ( str , 100 , stdin ) ;
                            fflush ( stdin ) ;
                            Token = strtok ( str , delim1 ) ; /* 將第一個句元存入Token */
                            c = 0 ;
                            while ( Token != NULL )
                            { /* 使用迴圈取出剩餘句元 */
                                ball_numb [ c ] = atoi ( Token ) ;     ///**把輸入轉為數字儲存**///
                                Token = strtok ( NULL , delim1 ) ;
                                c ++ ;

                            }
                            for ( j = 0 ; j < ball_qty ; j ++ )
                                                                        {
                                                    printf ( "baaa%d\n",ball_numb [ j ])   ;

                                                                        }
                            if ( judge ( ball_numb , ball_qty ) != 5 )
                            {
                                printf ( "超出範圍\n" ) ;
                                continue ;
                            }
                            for ( j = 0 ; j < ball_qty ; j ++ )
                                                                        {
                                                    printf ( "baaa%d\n",ball_numb [ j ])   ;

                                                                        }
                            if ( judgetwo ( ball_numb , ball_qty ) != 3 )
                            {
                                printf ( "重複輸出\n" ) ;
                                continue ;
                            }

                            b = 3 ;
                        }
                        printf ( "儲存成功\n" ) ;
                        BubbleSort ( ball_numb , ball_qty ) ;

                        for ( j = 0 ; j < ball_qty ; j ++ )
                        {
                            show [ buy ] [ j ] = ball_numb [ j ] ;

                        }
                        buy ++ ;
                        b = 0 ;

                        break ;

                    default :

                        break ;

                }/* switch ( choice_one )*/

                decide = 1 ;

            }/* while ( decide != 1 )*/

            break ;

        case 2 :

            printf ( "樂透號碼如下.....\n" ) ;
            for ( i = 0 ; i < buy ; i ++ )
            {
                for ( j = 0 ; j < ball_qty ; j ++ )
                {
                    if ( j == 0 )
                    {
                        printf ( "第%d張\t" , i + 1 ) ;
                        printf ( " [\t" ) ;
                    }
                    printf ( "%2d\t" , show [ i ] [ j ] ) ;

                }
                printf ( "]\n" ) ;
            }
            printf ( "\n" ) ;


            break ;

        case 3 :

            printf ( "開獎\n" ) ;

            generate_lotto ( lottotwo , ball_qty ) ;

            printf ( "開獎號碼:\n" ) ;
            for ( j = 0 ; j < ball_qty ; j ++ )
            {
                if ( j == 0 )
                {
                    printf ( "樂透號碼原始\t" ) ;
                    printf ( " [\t" ) ;
                }
                printf ( "%2d\t" , lottotwo [ j ] ) ;
            }
            printf ( "]\n" ) ;

///////////////////////////////////////////////////////////////************排序****************////////////////////

            BubbleSort ( lottotwo , ball_qty ) ;
            printf ( "開獎號碼:\n" ) ;
            for ( j = 0 ; j < ball_qty ; j ++ )
            {
                if ( j == 0 )
                {
                    printf ( "樂透號碼排序\t" ) ;
                    printf ( " [\t" ) ;
                }
                printf ( "%2d\t" , lottotwo [ j ] ) ;
            }
            printf ( "]\n" ) ;

            printf ( "================================================開獎==========================================\n" ) ;
            for ( i = 0 ; i < buy ; i ++ )
            {

                for ( j = 0 ; j < ball_qty ; j ++ )
                {
                    targetin = lottotwo [ j ] ;
                    if ( checktwo ( targetin , ( int * ) show , i , ball_qty ) == 1 )
                    {
                        value ++ ;
                        a [ i ] = value ;

                    }

                }
                value = 0 ;
            }
            for ( i = 0 ; i < buy ; i ++ )
            {
                for ( j = 0 ; j < ball_qty ; j ++ )
                {
                    if ( j == 0 )
                    {
                        printf ( "第%d張\t" , i + 1 ) ;
                        printf ( " [\t" ) ;
                    }
                    printf ( "%2d\t" , show [ i ] [ j ] ) ;

                }
                printf ( "]\t" ) ;
                printf ( "中了%2d個\t\n" , a [ i ] ) ;
                if ( value >= 4 )
                {
                    printf ( "中了!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\t\n" ) ;
                    printf ( " \t" ) ;
                }

            }

            printf ( "Press Enter key to continue..." ) ;
            fgetc ( stdin ) ;
            fflush ( stdin ) ;
            break ;
        case 4 :
            printf ( "清除購買紀錄中\n" ) ;

            buy = 0 ;
            printf ( "清除購買紀錄完成\n" ) ;

            break ;

        default :

            break ;

        }     ///* switch(choice) *///
        system ( "clear" ) ;
    }     ///* while(choice!=5) *///
}/***main*/     //


