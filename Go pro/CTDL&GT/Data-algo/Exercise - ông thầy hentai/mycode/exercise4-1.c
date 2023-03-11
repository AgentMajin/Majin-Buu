//Convert n from decimal to binary, print the result
#include <stdio.h>

void deci_to_bina(int a){
    //Create an array of interger to store 0 & 1 converted from an interger.
    //The 32 element stands for the maximum length of a binary converted from integers that below 4,294,967,296
    int binary_converted[32];
    //Create an int to track the length of the binary
    int binary_length = 0;
    
    while(a>=1){
        binary_converted[binary_length] = a % 2;
        a = a/2;
        binary_length++;
    }

    for(int i = binary_length-1; i>=0; i--){
        printf("%i",binary_converted[i]);
    }
}

int main(){
    int a;
    puts("Enter a decimal to convert into binary: ");
    scanf("%i",&a);
    deci_to_bina(a);
}