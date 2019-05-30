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

FILE *fp1;




int main( void )
{
    char filename[90];
    printf("%s","請輸入檔名");
  scanf("%s",filename);
    fp1=fopen(filename,"w");///*mode w=touch功能*//

    if(fp1!=NULL)
    {    printf("%s開你檔案\n",filename);
    }
    else
    {
        printf("%s開你失敗\n",filename);
        exit(1);
    }
    fclose(fp1);
    printf("關閉%s",filename);
}



