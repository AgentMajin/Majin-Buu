//Bài 1
//Lập chương trình quản lý danh sách học sinh, tuỳ chọn loại danh sách cho phù hợp, chương
// trình có những chức năng sau: (Hồ sơ một học sinh giả sử có: Tên, lớp, số điện thoại, điểm TB …)
// - Cho phép nhập danh sách học sinh từ bàn phím hay từ file.
// - Cho phép in ra danh sách học sinh gồm có tên và xếp loại
// - Cho phép in ra danh sách học sinh gồm các thông tin đầy đủ
// - Cho phép nhập vào từ bàn phím một tên học sinh và một tên lớp, tìm xem có học sinh có tên
// nhập vào trong lớp đó không ?. Nếu có thì in ra số điện thoại của học sinh đó
// - Cho phép vào một hồ sơ học sinh mới từ bàn phím, bổ sung học sinh đó vào danh sách học
// sinh, in ra danh sách mới.
// - Cho phép nhập vào từ bàn phím tên một lớp, loại bỏ tất cả các học sinh của lớp đó khỏi danh
// sách, in ra danh sách mới.
// - Có chức năng sắp xếp danh sách học sinh theo thứ tự giảm dần của điểm trung bình
// - Cho phép nhập vào hồ sơ một học sinh mới từ bàn phím, chèn học sinh đó vào danh sách mà không làm
//thay đổi thứ tự đã sắp xếp, in ra danh sách mới.
// Cho phép lưu trữ lại trên đĩa danh sách học sinh khi đã thay đổi.

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//Define a struct included 4 informations and a pointer which point to previous and next position in link list.
typedef struct node{
    char name[100];
    char class[20];
    struct node *next;
    long phone;
    float gpa;
}
node;

void ini_linked_list();
void adding();
void print_name_gpa();
void print_all();
void search_name();
void search_name_class();
void remove_class();
bool swap(node *prev, node *x, node *y);
void sorting();
void adding_to_last();

//max number of students in the list:
const int max = 1000;

//Adding some sample students' information as separated arrays
char *names[] = {"Truong", "Tien","Loan","Hai","Quoc","Nghia"};
int len_names = sizeof(names) / sizeof(names[0]);
char *classes[] = {"A1","A2","A2","A1","A3","A3"};
long phones[] = {123,345,456,567,6885,312};
float gpas[] = {9.0,8.2,5.6,9.5,9.1 ,8.5};

//Initial a start_point (or a header)
node *start_point = NULL;


int main(){
    int selection;
    ini_linked_list();
    while(1){
        puts("Hello, this program include below functions related to a list a student, please select a function to perform:");
        printf("1/ Add a new student into the list.\n2/ Print name and GPAs of all student in the current list.\n3/ Print all informations of every student in the current list.\n4/ Search student's phone number by name and class.\n5/ Remove every student in a class from the list.\n6/ Sort the list in the order of descending of GPA.\n7/ Add a student to the end of the list\n8/ Exit.\n\n");
        printf("----------------\n");
        printf("Enter your selection here: ");
        scanf("%i",&selection);

        switch(selection){
            case 1:
                adding();
                break;
            
            case 2:
                print_name_gpa();
                break;
            
            case 3:
                print_all();
                break;
            
            case 4:
                search_name_class();
                break;

            case 5:
                remove_class();
                break;

            case 6:
                sorting();
                break;

            case 7:
                adding_to_last();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid selection!\n\n");
        }
    }
}

//create a link list of nodes that include all informations of students
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

//Adding student student function
void adding(){
    //Check if the number of students in the list exceed the int max:
    if(len_names == max){
        printf("Het cho roi be oi\n");
        return;
    }
    else{
        //Get input
        char a[100];
        printf("Nhap ten hs moi: ");
        scanf("%s",a);

        char b[20];
        printf("Nhap lop cua hs moi: ");
        scanf("%s",b);

        long c;
        printf("Nhap sdt hs: ");
        scanf("%ld", &c);

        float d;
        printf("Nhap GPA hs moi: ");
        scanf("%f",&d);
        //Add new student to linked list
        node *new = malloc(sizeof(node));
        strcpy(new->name,a);
        strcpy(new->class,b);
        new -> phone = c;
        new -> gpa = d;
        new->next = start_point;
        start_point = new;
        len_names++;

        //Print new list
        print_all();
    }
}

//Print name and GPA of students
void print_name_gpa(){
    for(node *n = start_point; n != NULL; n = n->next){
        printf("Name: ");
        printf("%s\n", n->name);
        printf("GPA: ");
        printf("%f\n", n->gpa);
        printf("\n--------------------\n");
    }
}
}

//Print all informations of students
void print_all(){
    printf("\nHere's the current list: \n\n----------------\n");
    for(node *n = start_point; n != NULL; n = n->next){
        printf("Name: ");
        printf("%s\n", n->name);
        printf("Class: ");
        printf("%s\n", n->class);
        printf("Phone: ");
        printf("%ld\n", n->phone);
        printf("GPA: ");
        printf("%f\n", n->gpa);
        printf("\n--------------------\n");
    }
}

//Seaching for student's phone number via name
void search_name(){
    //Get input
    char a[100];
    printf("Nhap ten hs: ");
    scanf("%s",a);
    for(node *n = start_point; n != NULL; n = n->next){
        if (strcmp(a,n->name) == 0)
        {
            printf("%ld",n->phone);
            return;
        }
    }
    return;
}

//Searching student's phone number via name and class
void search_name_class(){

    //Get input
    char a[100];
    printf("Nhap ten hs: ");
    scanf("%s",a);

    char b[20];
    printf("Nhap lop cua hs: ");
    scanf("%s",b);

    //Create an array of pointers to save addresses of students have class = lop
    node *temp_array[max];
    //Create an int to track the array length
    int array_len = 0;

    //Iterate through the linked list to take addresses of student in searching class into the array
    for(node *n = start_point; n != NULL; n = n->next){
        if(strcmp(b, n->class) == 0){
            temp_array[array_len] = n;
            array_len++;
            continue;;
            }
        else if(n->next == NULL && array_len == 0){
            printf("Khong co lop %s",b);
        }
    }

    //Check names in the array and print out phone number if found
    for(int i = 0; i< array_len; i++){
        if(strcmp(temp_array[i]->name,a) == 0){
            printf("%ld\n",temp_array[i]->phone);
            return;
        }
    }

    //print this if cannot found student name in the class
    printf("Khong co %s trong lop %s\n",a,b);
    return;
}

//remove all student of a class from the list
void remove_class(){

    //Get input
    char b[20];
    printf("Nhap lop cua hs moi: ");
    scanf("%s",b);

    int counter=0;
    for(node *n = start_point; n != NULL; n = n->next){
        if(strcmp(n->class,b)==0){
            counter++;
            continue;
        }
    }
    if(counter==0){
        printf("Khong co lop %s",b);
        return;
    }
    node *n = start_point;
    node *prev = start_point;
    while(n != NULL){
        //Create a temp pointer pointing to the next node, to use in case we free the current node
        node *next = n->next;
        //Iterate through the list and find the node containing searching class
        if(strcmp(b, n->class) == 0){
            //At the end of the list:
            if(n->next == NULL){
                prev->next = NULL;
                free(n);
            }
            //At the begining of the list:
            else if(n = start_point){
                start_point = n->next;
                free(n);
            }
            //At other positions:
            else{
                prev->next = n->next;
                free(n);
            }
        }
        else{
            prev = n;
        }
        n = next;
    }
    print_all();
}

//Sorting the student list by the decensding order of gpa. And dont give a fuck about big O notation
void sorting(){
    for(int i = 0; i<len_names - 1; i++){
        node *prev = start_point;
        node *n = start_point;
        for(int j = 0; j<len_names-i-1; j++){
            node *temp = n->next;
            if(swap(prev,n,temp)){
                prev = temp;
                continue;
            }
            else{
                prev = n;
                n = n->next;
            }
        }   
   } 
   print_all();
}

//Adding student to the last position
void adding_to_last(){
    //Get input
    char a[100];
    printf("Nhap ten hs moi: ");
    scanf("%s",a);

    char b[20];
    printf("Nhap lop cua hs moi: ");
    scanf("%s",b);

    long c;
    printf("Nhap sdt hs: ");
    scanf("%ld", &c);

    float d;
    printf("Nhap GPA hs moi: ");
    scanf("%f",&d);

    //Create new node for new student infor im the last position of the list.
    node *new = malloc(sizeof(node));
    strcpy(new->name,a);
    strcpy(new->class,b);
    new -> phone = c;
    new -> gpa = d;
    for(node *n = start_point; n!=NULL;n=n->next){
        if(n->next==NULL){
            n->next = new;
            break;
        }
    }
    new->next = NULL;
    //Print new list
    print_all();
}

bool swap(node *prev, node *x, node *y){
    if(x->gpa<y->gpa){
        //The first couple of element
        if(x == start_point){
            x->next = y->next;
            y->next = x;
            start_point = y;
            return true;
        }
        //The last couple of element
        else if(y->next == NULL){
            prev->next = y;
            x->next = NULL;
            y->next = x;
            return true;
        }
        //Other couples
        else{
            prev -> next = y;
            x->next = y->next;
            y->next = x;
            x = y;
            return true;
        }
    }
    else{
        return false;
    }
}
