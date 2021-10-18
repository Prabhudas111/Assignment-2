#include<stdio.h>

typedef long int li;

li binary_product(li,li);

li binary_product(li binary1,li binary2)
{
    int i=0,remainder = 0,sum[20];
    int binarySum=0;

    while(binary1!=0||binary2!=0){
         sum[i++] =  (binary1 %10 + binary2 %10 + remainder ) % 2;
         remainder = (binary1 %10 + binary2 %10 + remainder ) / 2;
         binary1 = binary1/10;
         binary2 = binary2/10;
    }

    if(remainder!=0)
         sum[i++] = remainder;
    --i;
    while(i>=0)
         binarySum = binarySum*10 + sum[i--];

    return binarySum;
}

int main()
{
    while(1)
    {
        int choice;
        printf("\nSelect a choice: \n 1. Addition \n 2. Multiplication \n 3. Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            long binary1,binary2;
                printf("Enter any first binary number: ");
                scanf("%ld",&binary1);
                printf("Enter any second binary number: ");
                scanf("%ld",&binary2);
            int i=0,reminder=0,sum[20];
            while(binary1!=0 || binary2!=0)
            {
                sum[i++]=(binary1%10 + binary2%10 + reminder)%2;
                reminder=(binary1%10 + binary2%10 + reminder)/2;
                binary1=binary1/10;
                binary2=binary2/10;
            }
            if(reminder!=0)
            {
                sum[i++]=reminder;
                i--;
                printf("Sum is: ");
                while(i>=0)
                { 
                    printf("%d",sum[i--]);
                    
                }
                printf("\n");
            }
        }
        else if(choice==2)
        {
           li binary1,binary2,multiply=0;
       int digit,factor=1;

          printf("Enter any first binary number: ");
          scanf("%ld",&binary1);
          printf("Enter any second binary number: ");
          scanf("%ld",&binary2);

    while(binary2!=0){
         digit =  binary2 %10;

         if(digit ==1){
                 binary1=binary1*factor;
                 multiply = binary_product(binary1,multiply);
         }
         else
             binary1=binary1*factor;
   
         binary2 = binary2/10;
         factor = 10;
    }

    printf("Product of two binary numbers: %ld\n",multiply);
        }
        else
        {
            printf("--EXITED--");
            break;
        }
    }
    printf("\n\n");
    return 0;
}
