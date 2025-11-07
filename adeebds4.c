#include<stdio.h>
#define SIZE 5
int items[SIZE];
int front=-1,rear=-1;
int isFull(){
    if ((front==rear+1)||(front==0&&rear==SIZE-1))return 1;
    return 0;

}

int isEmpty (){
    if (front==1) return 1;
    return 0;

}

void enQueue (int element){
    if (isFull())
        printf("\n Queue is full! !!\n");
    else{
        if (front==-1)front=0;
        rear=(rear+1)% SIZE;
        items [rear]=element;
        printf("enter element");
            scanf("%d",element);
        printf("\n inserted -> %d ", element);

    }    
}

int deQueue(){
    int element ;
    if (isEmpty()){
        printf("\n Queue is empty !!\n");
        return (-1);

    }
    else{
        element=items[front];
        if (front ==rear){
            front=-1;
            rear=-1;

        }
        else{
            front=(front+1)%SIZE;

        }
        printf("\n DEleted element -> %d \n",element);
        return(element);

    }
}

void display (){
    int i;
    if (isEmpty())
        printf("\n Empty Queue\n");
    else{
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for (i=front;i!=rear;i=(i+1)%SIZE ){
            printf("%d ",items[i]);

        }
        printf("%d ",items[i]);
        printf("\n Rear-> %d \n",rear);

    }    
}

int main()
{
   int choice,element;
    while (1)
    {
        printf("1.insert \n 2. delete \n  3.display\n 4.exit \n Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            printf("enter element");
            scanf("%d",element);
            enQueue(int element);
            break;
            case 2:
            deQueue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("invalid choice \n");
            

        }
    }
    return 0;
}