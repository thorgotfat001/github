/*
 * main.c
 *
 *  Created on: 2019/5/2
 *      Author: j
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


FILE *fp1,*fp2;




int main( void )
{ int i;
    char filename2[90];
    char c;
   char appletree[90]="appletree.c";


  printf("%s","請輸入檔名");
  scanf("%s",filename2);

    fp1=fopen(appletree,"r");
    fp2=fopen(filename2,"w");
    if(fp1==NULL||fp2==NULL)
    {    printf("檔案錯誤\n");

    exit(1);
    }

    printf("讀取寫入中\n");


    for(i=0;i<9;i++)
        printf(".");

    usleep(10000);
    while((c=fgetc(fp1))!=EOF){
        printf("%c",c);
        fputc(c,fp2);
    }
        printf("讀取寫入完畢\n");
        fclose(fp1);
        fclose(fp2);





}




