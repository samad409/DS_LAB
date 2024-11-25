#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node* link;
};
struct node* top = 0;
void push(int x){
        struct node* newnode;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode -> data = x;
        newnode -> link = top;
        top = newnode;
}

void pop(){
        struct node* temp;
        temp = top;
        if(top == 0){
                printf("\n Underflow\n");
        }
        else{
                printf("popped item %d \n", top->data);
                top = top->link;
                free(temp);
        }

}


void display(){
        struct node* temp;
        temp = top;
        if(top == 0){
                printf("\n List is empty\n");
        }
        else{
                printf("Stack elements\n");
                while(temp != 0){
                        printf("%d ", temp->data);
                        temp = temp->link;
                }
                printf("\n");
        }
}

void search(int y){
        struct node* temp;
        if(top == NULL){
                printf("Stack is empty\n");
        }
        else{
                temp = top;
                int f = 0;
                while(temp != NULL){
                        if(temp-> data == y){
                                printf("%d is  present in the stack", y);
                                f = 1;
                        }
                        temp = temp->link;

                }
                if(f == 0){
                        printf("%d is not present in the stack", y);
                }
        }
}

void main(){
        int choice;
        do{
                printf("Select an operation\n");
                printf("1.PUSH\n2.POP\n3.DISPLAY\n4.SEARCH\n");
                scanf("%d", &choice);
                switch(choice){
                        case 1 :int x;
                                printf("Enter the value push\n");
                                scanf("%d", &x);
                                push(x);
                        break;
                        case 2 : pop();
                        break;
                        case 3 : display();
                        break;
                        case 4 :int y;
                                printf("Enter the value to search ");
                                scanf("%d", &y); 
                                search(y);
                        break;
                        default : printf("Invalid choice\n");
                }
        }while(choice != 0);

}
