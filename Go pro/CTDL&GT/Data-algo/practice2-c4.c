//Có n người đánh số từ 1 tới n ngồi quanh một vòng tròn (n ≤ 10000), 
//cùng chơi một trò chơi: Một người nào đó đếm 1, người kế tiếp, theo chiều kim đồng hồ đếm 2… 
//cứ như vậy cho tới người đếm đến một số nguyên tố thì phải ra khỏi vòng tròn, người kế tiếp lại đếm bắt đầu từ 1: 
//Hãy lập chương trình Nhập vào 2 số n và S từ bàn phím 
//• Cho biết nếu người thứ nhất là người đếm 1 thì người còn lại cuối cùng trong vòng tròn là người thứ mấy 
//• Cho biết nếu người còn lại cuối cùng trong vòng tròn là người thứ k thì người đếm 1 là người nào?. 
//Giải quyết hai yêu cầu trên trong trường hợp: đầu tiên trò chơi được đếm theo chiều kim đồng hồ, khi có một người bị ra khỏi cuộc chơi thì 
//vẫn là người kế tiếp đếm 1 nhưng quá trình đếm ngược lại (tức là ngược chiều kim đồng hồ).

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


//Define a node:
typedef struct node{
    struct node *next;
    int value;
    int identify;
}node;

//Define a start point:
node *start_point = NULL;
node *end_point = NULL;
//Initialize a circle singly linked list
void ini_linked_list(int n){
    for(int i = 0; i<n ; i++){
        node *new = malloc(sizeof(node));
        new->identify = i + 1;
        new->next = NULL;
        new -> next = start_point;
        start_point = new;
    }
    for(node *i = start_point; i != NULL; i = i->next){
        if(i->next = NULL){
            i->next = start_point;
            end_point = i;
            break;
        }
    }
}



void print(){
    node *temp = start_point->next;
    for(node *i = start_point; i != temp; i = i->next){
        printf("%i",i->value);
        if(i == start_point){
            temp = start_point;
        }
    }
}

// void eliminate(node *prev, node *n){
//     prev -> next = n -> next;
//     free(n);
// }

bool check_prime(int a){
    if(a<=2){
        return false;
    }
    int counter = 0;
    for(int i = 1; i <= a; i++){
        if(a%i == 0){
            counter++;
        }
    }
    if(counter < 3){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int candidate;
    puts("Nhap so nguoi choi (<10000): ");
    scanf("%i",candidate);
    if(candidate>=10000){
        printf("So nguoi choi phai duoi 10000!\n");
        return 0;
    }
    ini_linked_list(candidate);
    node *prev = end_point;
    node *n = start_point;
    start_point->value = 1;
    while(n!=n->next){
        if(check_prime(n->value)){
            node *next = n -> next;
            prev -> next = next;
            printf("%i",n->identify);
            free(n);
            next -> value = 1;
            n = next;
        }
        else{
            node *next = n->next;
            next -> value = n -> value +1;
            prev = n;
            n = next;
        }
    }
    printf("%i", n->identify);
}
