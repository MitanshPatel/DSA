//ONLY FOR ASCENDING SORTED ARRAYS

//spliting array into first half and second half by 2, if middle element == key number to be found, print that
//else if key number is less than middle element, break first half again by 2, find new middle of first half, and again compare.
//break array again and again until middle element = key number.

#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key){
    int start=0; //start position of array
    int end=n; //end position of array
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
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
    int b=BinarySearch(arr,n,key);
    if (b==-1){
        cout<<"Element not found"<<endl;
    }
    else cout<<"Element at "<<b+1<<" position"<<endl;

}