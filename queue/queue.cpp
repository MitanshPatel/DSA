#include<iostream>
#include<cstdlib>
using namespace std;

class queue{
    int *arr;
    int front;
    int rear;
    int n;

    public:
    queue(int nn){
        n=nn;
        arr=(int*)malloc(n*sizeof(int));
        front=-1;
        rear=-1;  
    }

    void push(int x){
        if (rear == n-1){
            cout<<"Queue is full"<<endl;
            return;
        }
        else{
            rear++;
            arr[rear]=x;
            cout<<arr[rear]<<" is added in queue"<<endl;
            if (front == -1){
                front++;
            }
        }
        
    }

    void pop(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        
        front++;
    }

    void peek(){
        if(front==-1 || front>rear){
            cout<<"No element in queue"<<endl;
            return;
        }

        cout<<arr[front]<<" is the top element"<<endl;
    }

    void empty(){
        if(front==-1 || front>rear){
            cout<<"empty\n";
        }
        cout<<"not empty\n";
    }

};

int main(){
    queue q(4);
    q.push(41);
    q.push(1);
    q.push(81);
    q.push(16);
    q.peek();
    q.pop();
    q.pop();
    q.peek();
}