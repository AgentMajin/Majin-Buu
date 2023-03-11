#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct node{
    char name[100];
    char class[20];
    struct node *next;
    long phone;
    float gpa;
}
node;

void ini_linked_list();
void print_all(void);
void ini_linked_list();
void adding(char *name, char *class, long phone, float gpa);
void swap(node *prev, node *x, node *y);

node *start_point = NULL;

//Adding some sample students' information as separated arrays
char *names[] = {"Truong", "Tien","Loan","Hai","Quoc","Nghia"};
int len_names = sizeof(names) / sizeof(names[0]);
char *classes[] = {"A1","A2","A2","A1","A3","A3"};
long phones[] = {123,345,456,567,6885};
float gpas[] = {9.0,8.2,5.6,9.5,9.1 ,8.5};

int main(){
    // char a[100];
    // printf("Nhap ten hs moi: ");
    // scanf("%s",a);

    // char b[20];
    // printf("Nhap lop cua hs moi: ");
    // scanf("%s",b);

    // long c;
    // printf("Nhap sdt hs: ");
    // scanf("%ld", &c);

    // float d;
    // printf("Nhap GPA hs moi: ");
    // scanf("%f",&d);

    // ini_linked_list();
    // adding(a,b,c,d);

    node *x = start_point;
    node *y = x->next;
    swap(x,x,y);
    print_all();
}

void swap(node *prev, node *x, node *y){
    if(x->gpa > y->gpa){
        //The first couple of element
        if(x == start_point){
            x->next = y->next;
            y->next = x;
            start_point = y;
            x = y;
        }
        //The last couple of element
        else if(y->next == NULL){
            prev->next = y;
            x->next = NULL;
            y->next = x;
            x = y;
        }
        //Other couples
        else{
            prev -> next = y;
            x->next = y->next;
            y->next = x;
            x = y;
        }
    }
}


//Print all informations of students
void print_all(void){
    for(node *n = start_point; n != NULL; n = n->next){
        printf("%s: ", n->name);
        printf("%s; ", n->class);
        printf("%ld; ", n->phone);
        printf("%f; ", n->gpa);
    }
}

void ini_linked_list(){
    for(int i =0; i<len_names;i++){
        node *tmp = malloc(sizeof(node));
        strcpy(tmp->name,names[i]);
        strcpy(tmp->class,classes[i]);
        tmp -> phone = phones[i];
        tmp -> gpa = gpas[i];
        tmp->next = NULL;
        tmp->next = start_point;
        start_point = tmp;
    }
}