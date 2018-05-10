#include<stdio.h>
//#include<conio.h>
int main()
{
    FILE *fp;
    char ch;
    if((fp=fopen("string","w+"))==NULL) {
       printf("Cannot open file£¬strike any key exit!");
       //getch();
       exit(1);
    }
    printf("input a string:\n");
    ch=getchar();
    while (ch!='\n'){
       fputc(ch,fp);
       ch=getchar();
       }
    printf("\n");
    fclose(fp);
    return 0;
}
