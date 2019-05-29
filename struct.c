/*
 * fileoopen.c
 *
 *  Created on: 2019年5月27日
 *      Author: dutch
 */
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
#include <time.h>
#include <ctype.h>
struct student
{
    int id ;
 char name[10];
} ;

struct student create (int id,char *pname){
        struct student temp={0};
        temp.id=id;
        memcpy(temp.name,pname,strlen(pname)+1);


        return temp;
}


int main ( void )
{
struct student s={0};
s=create(123,"test");
printf("%d,%s",s.id,s.name);


}



