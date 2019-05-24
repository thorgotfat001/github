/*
 * 556.c
 *
 *  Created on: 2019年5月24日
 *      Author: dutch
 */

/*含市linklist */
/*  Created on: 2019年5月17日
 *      Author: dutch
 int *ptr =new int;
 int *ptr=new int(100);


 *
 */

#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
struct girl
{
   char data ;
    struct girl *next ;

} ;
typedef struct girl sexy ;
typedef sexy *special ;

void insert ( special *sptr , char val ) ;
void insert ( special *sptr , char val )
{
    special newptr ;
    special preptr ;
    special curptr ;
    newptr = malloc ( sizeof(sexy) ) ;
    if ( newptr != NULL )
    {
        newptr->data = val ;
        newptr->next = NULL ;

        preptr = NULL ;
        curptr = * sptr ;

        while ( curptr != NULL )
        {
            preptr = curptr ;
            curptr = curptr->next;
        }
        if ( preptr == NULL )
        {
            newptr->next = * sptr ;
            * sptr = newptr ;
        }
        else
        {
            preptr->next = newptr ;
            newptr->next = curptr ;
        }
    }
    else
    {
        printf ( "%d not insert\n" , val ) ;
    }
}



char delete(special *sptr,char val);
char delete(special *sptr,char val){
    special preptr;
    special curptr;
    special temptr;
    if(val==(*sptr)->data){
        temptr=*sptr;
        *sptr=(*sptr)->next;
        free(temptr);
        return val;
    }
    else{
        preptr=*sptr;
        curptr=(*sptr)->next;
        while(curptr !=NULL && curptr->data!=val){
            preptr=curptr;
            curptr=curptr->next;
        }
        if(curptr!=NULL){
            temptr=curptr;
            preptr->next=curptr->next;
            free(temptr);
            return val;
        }


    }
    return '\0';

}


void printlist ( special currptr ) ;
void printlist ( special currptr )
{
sexy *node = currptr ;     ///*int *p=&K*///
if ( currptr == NULL )
{
printf ( "life is empty\n" ) ;
}
else
{
while ( node != NULL )
{
    printf ( "%2c--->" , node->data ) ;
    node = node->next ;

}
printf ( "\n" ) ;
}

}


void instructions ( void ) ;
void instructions ( void )
{
puts ( "enter your choice:\n"
        "1 insert\n"
        "2 delete\n"
        "3 3nd\n" ) ;
printf ( "%s" , "?" ) ;
}


int main(void)
{
special startptr = NULL ;
unsigned int choice ;
char item,val ;
instructions ( ) ;

scanf ( "%d" , & choice ) ;

while ( choice != 3 )
{
switch ( choice )
{
    case 1 :
        printf ( "%s" , "enter" ) ;
        scanf ( "\n%c" , & item ) ;
        insert(&startptr,item);
        printlist ( startptr ) ;
        break ;
    case 2 :

            printf("enter character to be deleted:");
            scanf("\n%c",&item);
          val=delete(&startptr,item);
          printf("%c delete\n",val);
          printlist ( startptr ) ;




        break ;
    default :
        puts ( "invalid choice\n" ) ;
        instructions ( ) ;
        break ;

}
instructions ( ) ;
printf ( "%s" , "?" ) ;
scanf ( "%u" , & choice ) ;

}
puts ( "end\n" ) ;

}







