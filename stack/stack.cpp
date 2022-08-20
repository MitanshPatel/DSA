#include<iostream>
#include<cstdlib>
using namespace std;

class stack{
    int *arr;
    int top;
    int n;

    public:
    stack(int nn){
        n = nn;
        arr = (int*)malloc(n*sizeof(int));
        top=-1;
    }

    void push(int x){
        if (top == n-1){
            cout<<"Stack is full"<<endl;
            return;
        }
        else{
            top++;
            arr[top]=x;
            cout<<arr[top]<<" is added in stack"<<endl;
        }
        
    }

    void pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<arr[top]<<" has been removed from stack\n";
        top--;
    }

    void Top(){
        if(top==-1){
            cout<<"No element in stack"<<endl;
            return;
        }

        cout<<arr[top]<<" is the top element"<<endl;
    }

    void empty(){
        if (top==-1){
            cout<<"empty\n";
        }
        else cout<<"Not empty\n";
    }
};

int main(){
    int siz;
    cout<<"Enter the size of the stack"<<endl;
    cin>>siz;
    stack st(siz);
    for (int i=0;i<siz;i++){ //for(int i=top; i<capacity; i++) smart loop for adding elements from input user after popping
        int num;
        cout<<"Enter the "<<i+1<<" element to insert"<<endl;
        cin>>num;
        st.push(num);
    }
    st.Top();
    st.pop();
    st.pop();
    st.Top();
    st.empty();

    return 0;

}