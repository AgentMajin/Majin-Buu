#include <stdio.h>
#include <stdbool.h>
bool check_prime(int a);
int main(){
    int n;
    printf("Enter n: ");
    scanf("%i", &n);

    int counter = 0;
    printf("10 primes greater than %i are:\n",n);
    while(counter<10){
        if(check_prime(n+1)){
            printf("%i ",n+1);
            counter++;
        }
        n++;
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