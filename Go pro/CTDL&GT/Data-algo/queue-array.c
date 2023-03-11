#include <stdio.h>
#include <stdlib.h>

//declare functions:
void popping(void);
void pushing();
void show();

//Define variables and array
const int max = 1000;
int array[1000];
int track = 0;

int main(){
    int choice;
    while(1){
        printf("Choose what you want to perform on the stack:\n\n");
        printf("\n1. Push 1 element,\n2. Pop 1 element.\n3. End program.\n4. Show the stack.\n\n");
        printf("Enter your choice here: ");
        scanf("%i",&choice);

        switch(choice){
            case 1:
                pushing();
                break;

            case 2:
                popping();
                break;

            case 3:
                exit(0);

            case 4:
                show();
                break;

            default:
                printf("Invalid choice\n");
        }

    }

}

void popping(void){
    if(track==0){
        printf("Empty stack for now!\n");
        return;
    }
    else{
        printf("Element %i has been eliminated\n\n", array[0]);
        for(int i = 0; i<track-1; i++){
            array[i] = array[i+1];
        }
        track--;
    }
}

void pushing(){
    if(track == max){
        printf("Stack is full now, please pop out to release spaces\n");
        return;
    }
    else{
        int a;
        printf("Enter an interger to push into the stack: ");
        scanf("%i",&a);
        array[track] = a;
        track++;
        printf("Stack has been updated! \n\n");
    }
}

void show(){
    printf("Current Stack: \n");
    for(int i = 0; i<track; i++){
        printf("%i ",array[i]);
    }
    printf("\n");
}