#include <stdio.h>
#include <stdbool.h>
bool check_prime(int a);
int main(){
    int n;
    printf("Enter n (n<m): ");
    scanf("%i", &n);

    int m;
    printf("Enter m (n<m): ");
    scanf("%i", &m);
    int counter = 0;
    printf("Primes from %i to %i:\n",n,m);
    for(int i = n; i<=m; i++){
        if(check_prime(i)){
            printf("%i ",i);
            counter++;
        }
    }
    if(counter == 0){
        puts("No prime found!");
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