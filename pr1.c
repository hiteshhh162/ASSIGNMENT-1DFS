
#include<stdio.h>
int main ()
{
    FILE *fp;
    char str[20],str2[20];
    fp=fopen("data.txt","w");
    printf("\nEnter string :");
    scanf("%s",str);
    fprintf(fp,"%s",str);
    fclose(fp);

    fp=fopen("data.txt","r");
    fscanf(fp,"%s",str2);
    printf("%s",str2);
    fclose(fp);
    return 0;
}