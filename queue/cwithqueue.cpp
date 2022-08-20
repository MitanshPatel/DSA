//First in first out

#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;

struct Queue{
    int front; 
    int rear;
    int size;
    unsigned capacity; 
    int *array; 
};

Queue *createQueue(unsigned capacity) // STACK is written first so that the function createStack can return queue
{
    Queue *queue;  
    queue=(Queue*)malloc(sizeof(Queue));
    queue ->front = 0;  // top in queue is being pointed and is given -1 as default value
    queue -> size = 0;
    queue -> rear = capacity;
    queue ->array = (int*)malloc(capacity*sizeof(int));
    return queue;
}

int isFull(Queue *queue)
{
    return (queue -> size == queue -> capacity);
}

int isEmpty(Queue *queue)
{
    return (queue -> size == 0);
}

void enqueue(Queue *queue, int item){
    if(isFull(queue)){
        return;
    }
    queue -> rear = queue -> rear +1;
    queue -> array[queue -> rear] = item;
    cout<<item<<" enqueued\n";
}

void dequeue (Queue *queue){
    if(isEmpty(queue)){
        return;
    }
    int item = queue ->array[queue -> front];
    queue -> front = queue -> front +1;
    cout<<item<<" is the deleted item\n";
    
}

int extractfront(Queue *queue){
    int front = queue -> array[front];
    return front;
}

int extractrear(Queue *queue){
    int rear = queue -> array[rear];
    return rear;
}

int main(){
    Queue *queue;
    queue = createQueue(100);
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue,80);
    int c=extractfront(queue);
    cout<<c<<endl;
    extractrear(queue);
}