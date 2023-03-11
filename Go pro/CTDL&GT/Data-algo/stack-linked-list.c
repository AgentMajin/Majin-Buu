#include <stdio.h>
#include <stdlib.h>

//declare functions:
void popping();
void pushing();
void show();

//Define node and start_point

typedef struct node{
    int value;
    struct node *next;
}node;

node *start_point = NULL;

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
                printf("\n\n---------Invalid choice--------\n\n");
        }

    }

}

void popping(void){
    if(start_point == NULL){
        printf("\n\n-----------------Stack is empty now\n\n----------------\n\n");
    }
    else{
        int temp = start_point->value;
        node *next = start_point -> next;
        free(start_point);
        start_point = next;
        printf("\n\n-------------Value %i has been eliminated from the stack-----------\n\n",temp);
    }
}

void pushing(){
    int a;
    printf("Enter a value to push into the stack: ");
    scanf("%i",&a);
    node *new = malloc(sizeof(node));
    new->value = a;
    new->next = start_point;
    start_point = new;
    printf("\n\n--------Stack has been updated-----------------\n\n");
}

void show(){
    printf("Current Stack:\n\n");
    for(node *n = start_point; n != NULL; n = n->next){
        printf("%i ||",n->value);
    }
    printf("\n\n");
}