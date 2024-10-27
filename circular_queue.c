#include<stdio.h>
#define max 5
int cq[max];
int front=-1,rear=-1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % max == front;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % max;
    }
    printf("\n");
}

void enque()
{
  int data;
  printf("Enter value to be inserted : ");
  scanf("%d",&data);
  if (front==-1 && rear ==-1){
  front=0;
  rear=0;
  cq[rear]=data;
  }
else if(((rear+1)%max)==front)
  printf("overflow");
else{
  rear=(rear+1)%max;
  cq[rear]=data;
}
}
void deque(){
  if (front==-1 && rear==-1){
    printf("underflow");
  }

  else if(rear==front)
  front=rear=-1;
else{
  front=(front+1)%max;
}
}
int main(){
  int ch;
  do{
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    printf("Enter your choice\t");
    scanf("%d",&ch);
    switch(ch){
      case 1:enque();
      break;
      case 2:deque();
      break;
      case 3:display();
      break;
  
    }}while(1);
}
