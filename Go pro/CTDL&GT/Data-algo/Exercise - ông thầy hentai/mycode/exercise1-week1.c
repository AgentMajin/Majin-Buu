#include <stdio.h>
#include <stdbool.h>
bool check_prime(int a);
int main(){
    int a;
    printf("Enter an integer to check if it is a prime or not: ");
    scanf("%i", &a);
    if(check_prime(a)){
        printf("Its a prime integer!\n");
    }
    else{
        printf("Its not a prime integer!\n");
    }
}

bool check_prime(int a){
    if(a<2){
        return false;
    }

    int counter = 0;
    for(int i = 1; i<= a; i++){
        if(a%i==0){
            counter++;
        }
    }

    if(counter>2){
        return false;
    }
    else{
        return true;
    }
}