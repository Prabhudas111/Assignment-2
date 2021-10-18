#include<stdio.h>
#include<string.h>

typedef long int li;

int valid_unary(char unary[])
{
    int i=0;
    while(unary[i])
    {
        if(unary[i]!='1')
        {
            return -1;
        }
        i++;
    }
    return 1;
}


int main()
{
    while(1)
    {
        int choice;
        printf("options : \n 1.Addition \n 2.Multiplication \n 3.Exit \n");
        printf("choose an option: ");
        scanf("%d", &choice);
        if(choice==1)
        {
            char unary1[500],unary2[500];
            printf("Enter two unary numbers (eg:1,2,3,.. as 1,11,111,..) : ");
            scanf("%s %s", unary1,unary2);
            if(valid_unary(unary1)==1 && valid_unary(unary2)==1)
            {
                strcat(unary1,unary2);
                printf("Sum is: %s\n",unary1);
            }
        }
        else if(choice==2)
        {
            char unary1[500],unary2[500];
            printf("Enter two unary numbers (eg:1,2,3,.. as 1,11,111,..): ");
            scanf("%s %s", unary1,unary2);
            if(valid_unary(unary1)==1 && valid_unary(unary2)==1)
            {
                printf("Product is: ");
                for(int i=0;i<strlen(unary2);i++)
                {
                    printf("%s",unary1);
                }
                printf("\n");
            }
        }
        else if(choice==3)
        {
            printf("---EXITED---\n\n");
            break;
        }else {
            printf("Invalid input\n\n");
        }
    }
    return 0;
}
