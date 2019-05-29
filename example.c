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
char *inverse(char* src);
char *inverse(char* src){
    char *dest=(char*)malloc(sizeof(src));
    int i,len;
    len=strlen(src);
    for(i=len-1;i>=0;i--)
        *(dest+len-1-i)=*(src+i);
    *(dest+len)='\0';
    return dest;
}

int main ( void )
{
char *s1="welcome";
char *s2=inverse(s1);

printf("si=%s\n",s1);
printf("s2=%s\n",s2);


}


