#include<stdio.h>
#include <string.h>

typedef long int li;
li digit(char c);
li roman_to_decimal(char roman[]);
li decimal_to_roman(long int num);




int main(){

  while(1){
    int select;
    
    printf("\nSelect an option : \n1. Addition \n2. Multiplication \n3. Exit\n");
    printf("choose an option:\n");
    
    
    scanf("%d",&select);
    if(select == 1){
      char roman_num_1[500], roman_num_2[500];
      printf("Enter two roman numerals : ");
      scanf("%s %s",roman_num_1, roman_num_2);
      
      li deci_num_1 = roman_to_decimal(roman_num_1);
      li deci_num_2 = roman_to_decimal(roman_num_2);
      if(deci_num_1 == -1 || deci_num_2 == -1){
        break;
      }
      else{
        li sum = deci_num_1 + deci_num_2;
        printf("The sum  of %s and %s  is : ",roman_num_1, roman_num_2);
        decimal_to_roman(sum);
        printf("\n");
      }
    }
    else if(select == 2){
      char roman_num_1[500], roman_num_2[500];
      printf("Enter two roman numeral: ");
      scanf("%s %s",roman_num_1, roman_num_2);
      li deci_num_1 = roman_to_decimal(roman_num_1);
      li deci_num_2 = roman_to_decimal(roman_num_2);
      if(deci_num_1 == -1 || deci_num_2 == -1){
        break;
      }
      else{
       li product = deci_num_1 * deci_num_2;
        printf("The product of %s and %s is : ",roman_num_1,roman_num_2);
        decimal_to_roman(product);
        printf("\n");
      }
    }
    else {
      printf("Exited.");
      break;
    }
  }

  return 0;
}



li  digit(char c){
 
    li  value=0;
 
    if(c=='I'){
      value = 1;
    }
    else if(c=='V'){
      value = 5;
    }
    else if(c=='X'){
      value = 10;
    }
    else if(c=='L'){
      value = 50;
    }
    else if(c=='C'){
      value  = 100;
    }
    else if(c=='D'){
      value = 500;
    }
    else if(c=='M'){
      value  = 1000;
    }
    else if(c=='\0'){
      value  = 0;
    }
    else {
      value = -1;
    }
 
    return value;
}

li  roman_to_decimal(char roman[]){
  int i = 0;
  li number = 0;
  while (roman[i]){
    
    if(digit(roman[i])<0){
      printf("Invalid roman literal\n");
      return -1;
    }

    if((strlen(roman)-i)>2){
      
      if(digit(roman[i]) < digit(roman[i+2])){
        printf("Invalid roman literal\n");
        return -1;
      }
    }

    if(digit(roman[i]) >= digit(roman[i+1])){
      number += digit(roman[i]);
    }
    else{
      number += digit(roman[i+1]) - digit(roman[i]);
      i++;
    }

    i++;
  }

  return number;
}

li  decimal_to_roman(long int num){
  if(num <= 0){
    return -1;
  }
  while(num != 0){

    if (num >= 1000) {
      printf("M");
      num -= 1000;
    }

    else if (num >= 900){
      printf("CM");
      num -= 900;
    }

    else if (num >= 500){
      printf("D");
      num -= 500;
    }

    else if (num >= 400){
      printf("CD");
      num -= 400;
    }

    else if (num >= 100){
      printf("C");
      num -= 100;
    }

    else if (num >= 90){
      printf("XC");
      num -= 90;
    }

    else if (num >= 50){
      printf("L");
      num -= 50;
    }

    else if (num >= 40){
      printf("XL");
      num -= 40;
    }

    else if (num >= 10){
      printf("X");
      num -= 10;
    }

    else if (num >= 9){
      printf("IX");
      num -= 9;
    }

    else if (num >= 5){
      printf("V");
      num -= 5;
    }

    else if (num >= 4){
      printf("IV");
      num -= 4;
    }

    else if (num >= 1){
      printf("I");
      num -= 1;
    }

  }
  return 1;
}
