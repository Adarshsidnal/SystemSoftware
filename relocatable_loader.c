#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main()
{
     FILE *fp1, *fp2;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    char line[1000];
    int a;
    printf("Enter address\n");
    scanf("%x",&a);
    while (fgets(line, sizeof(line), fp1) != NULL)
    {
        int stringLength=strlen(line);
        line[stringLength]='\0';
        int i=0;
        if(line[0]=='T')
        {
        while(i<(stringLength+1))
        {
            char string[8];
            int k=0;
            while(line[i]!='^' && line[i]!='\0')
            {
               string[k++]=line[i];
               i++;
            }
            string[k]='\0';
            int d=strlen(string);
            if(d==8)
            {
               unsigned int b=strtol(string,NULL,16);
                b+=a;
                int c=i;
                i=i-8;
                int j=0;
                char str[8];
                sprintf(str, "%X", b);
                while(i!=c)
                {
                    line[i++]=str[j++];
                }
            }
            i++;
        }
        fprintf(fp2,"%s",line);
        }
        else
        {
            fprintf(fp2,"%s",line);
        }

    }
    return 0;

}

