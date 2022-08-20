#include<iostream>
#include<cstdlib>
using namespace std;

class Queue{
    int front;
    int rear;
    int size;
    int *arr;

    public:
    Queue(int s){
        front=-1;
        rear=-1;
        size = s;
        arr = (int*)malloc(s*sizeof(int));
    }

    void enqueue(int num){
        if (front==0 && rear==size-1){    //front is 1st block and rear is last block so queue full
            cout<<"Queue is full"<<endl;
        }

        else if(front==-1 || rear==-1){  //queue is empty and change front rear to 0 to start filling queue
            front=rear=0;
            arr[rear]=num;  //adding numbers to rear
            cout<<arr[rear]<<" is added in queue"<<endl;
        }

        else if(rear==size-1 && front!=0){  //rear is at end and front is near 2 or 3(assume after removing some elements) so rear shifts to 0[start posn] and fills number there
            rear=0;
            arr[rear]=num;
            cout<<arr[rear]<<" is added in queue"<<endl;
        }

        else{  //normal way of adding
            rear++;  
            arr[rear]=num;
            cout<<arr[rear]<<" is added in queue"<<endl;
        }
    }

    void dequeue(){
        if (front==-1){
            cout<<"Queue is empty\n";
        }
        cout<<arr[front]<<" has been removed from queue\n";
        if(front==rear){  //only one element in the queue
            front=-1;  //after removing element queue becomes empty
            rear=-1;
        }
        else if(front==size-1){ //front is at the end of the queue
            front =0;
        }
        else{
            front++;
        }
    }

    void extractfront(){
        if(front==-1){
            cout<<"queue is empty\n";
        }
        else{
            cout<<arr[front]<<" is the first element\n";
        }
    }

    void extractrear(){
        if(rear==-1){
            cout<<"queue is empty\n";
        }
        else{
            cout<<arr[rear]<<" is the last element\n";
        }
    }

    void displayQueue(){
        if (front == -1){
            cout<<"\nQueue is empty\n";
        }
        cout<<"\nBelow are the elements of queue\n";
        if (rear >= front){
            for(int i=front;i<=rear; i++){
                cout<<arr[i]<<endl;
            }
        }
        else{
            for(int i=0; i<=rear; i++){
                cout<<arr[i]<<endl;
            }
            for(int i=front; i<size; i++){
                cout<<arr[i]<<endl;
            }
        }
    }
};

int main(){
    Queue q(4);
    q.enqueue(6);
    q.enqueue(45);
    q.enqueue(59);
    q.enqueue(38);
    q.displayQueue();
    q.dequeue();
    q.dequeue();
    q.displayQueue();
    q.enqueue(999);
    q.displayQueue();

}