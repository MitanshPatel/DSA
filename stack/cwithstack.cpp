//Last in First out

#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;

struct STACK{
    int top; // position of the last element of stack
    unsigned capacity; // how big should the stack be
    int *array; //dynamic array in which all elements of stack will be stored
};

STACK *createStack(unsigned n) // STACK is written first so that the function createStack can return stack
{
    STACK *stack;  
    stack=(STACK*)malloc(sizeof(STACK));
    stack ->top = -1;    // top in stack is being pointed and is given -1 as default value
    stack ->capacity = n;
    stack ->array = (int*)malloc(sizeof(int));
    return stack;
}

int isFULL(STACK *stack)
{
    return stack ->top == stack ->capacity -1; //if the position of the top is equal to capacity assigned by user, then stack is full

}

int isEMPTY(STACK *stack)
{
    return stack ->top == -1; //top has default value of -1 specified in struct STACK
}

void PUSH(STACK *stack, int item) // item is number given by user to be pushed in the stack
{
    if (isFULL(stack))
    {
        cout<<"Cannot add anymore items in the stack\n";
    }

    else{
        stack ->array[++stack ->top]=item; // ++(stack ->top) is incremented first
        cout<<item<<" is pushed in the stack in "<<stack ->top<<" position\n";
    }

}

void POP(STACK *stack)
{
    if(isEMPTY(stack)){
        cout<<"No items there to remove\n";
    }

    else{
        stack ->array[stack ->top--];
        cout<<stack ->array[stack ->top +1]<<" has been removed from the top position\n";

    }
}

void TOP(STACK *stack)
{
    cout<<stack ->array[stack ->top]<<" is the top item in the stack\n";
}

int main()
{
    int n;
    cout<<"Enter the size of the stack\n";
    cin>>n;
    STACK *stack = createStack(n);

    //taking elements in the stack
    for (int i=0; i<n; i++){
        int item;
        cout<<"Enter element " <<i+1<< " to be pushed in the stack\n";
        cin>>item;
        PUSH(stack,item);
    }
    POP(stack);
    POP(stack);
    PUSH(stack,103);

    //printing all elements in the stack
    cout<<"\nBelow are all the elements of the stack\n";
    for (int i=0; i<n ; i++)
    {
        cout<< stack ->array[i]<<" \n";
    }
}

// NOTE : if the user pops an element then the top element doesnt get removed fron the stack it stays there, but the stack is then considered from top-1 element.
// NOTE : if user pops element and then pushes 53, then the element which is popped gets overwritten and edited to 53
