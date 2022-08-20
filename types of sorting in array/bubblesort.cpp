//1st element is compared to adjacent and if big, then swapped. and then 2nd[which was 1st earlier] and 3rd is compared and on and on, until biggest number is in the last of array.
//once biggest number in last of array, 1st number is compared to adjacent, 2nd to 3rd till last-1 element until last-1 element is biggest.

#include<iostream>
using namespace std;

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

    for(int i=0;i<n-1;i++){ //increment of i helps in removing last element to be compared in next loop. i<n-1 because last element cannot be compared to adjacent
        for(int j=0; j<n-i-1; j++){ //n-i-1 parameter leaves last element after every loop.
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    //print
    cout<<"Below are all elements sorted in ascending order"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

}