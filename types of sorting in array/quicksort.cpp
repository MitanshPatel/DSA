#include<iostream>
using namespace std;

int partition(int arr[],int st,int end){

    int pi=arr[end];
    int i=st-1;

    for(int j=st;j<end;j++){
        if(arr[j]<pi){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    int temp=arr[i+1];
    arr[i+1]=arr[end];
    arr[end]=temp;

    return i+1;

}   


void quickSort(int arr[],int st,int end){
    if(st<end){
        int pi=partition(arr,st,end);

        quickSort(arr,st,pi-1);
        quickSort(arr,pi+1,end);
    }
}

int main(){
    // take input
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

    quickSort(arr,0,n-1);

    //print
    cout<<"Below are all elements sorted in ascending order"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

}