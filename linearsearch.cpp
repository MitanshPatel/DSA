//normal way

#include<iostream>
using namespace std;

//using function
int LinearSearch(int arr[],int n, int key){  //use int instead of void or else not finding the element part wont be executed

    for(int i=0;i<n; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1; //key not found
}

int main(){
    //take input
    int n;
    cout<<"Number of elements in array?\n";
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter "<< i+1 << " element of array\n";
        cin>>num;
        arr[i]=num;
    }
    int key;
    cout<<"Enter element to find"<<endl;
    cin>>key;
    int b=LinearSearch(arr,n,key);
    if (b==-1){
        cout<<"Element not found"<<endl;
    }
    else cout<<"Element at "<<b+1<<" position"<<endl;

}