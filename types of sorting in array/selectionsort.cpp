//finding a small number from 2nd to last posn of array and swapping it to the first posn of array. 
//Then finding small from 3rd to last posn and swapping to 2nd posn of array
//swapping happens multiple times

#include<iostream>
using namespace std;

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

    for(int i=0;i<n-1;i++){  //not to take last posn as it has no more elements ahead in array to compare. smaller number ahead will be swapped to i'th posn
        for(int j=i+1;j<n;j++){ //remaining elements that will be swapped to i'th posn
            if(arr[j]<arr[i]){  //for descending change < to >
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        } 
    }

    //print
    cout<<"Below are all elements sorted in ascending order"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
