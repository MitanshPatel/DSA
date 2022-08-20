//making a sub array (initializing all to 0) of size of highest number in main array.
//if an element is 6 in main array, then 6th position of sub array is incremented by 1. this is done for all elements.
//if sub array is from 0-6 and has elements 0 1 0 3 2 4 at position 0th 1st 2nd till 5th.
//changin it to 0 0+1 0+1+0 0+1+0+3....... and finally getting 0 1 1 4 6 10.
//taking last element of main array and assuming it to be 3, then position 3rd of sub array is decremented [from 4 to 3] and 3 is added to 3rd position of main array.
//second last element be 5, so 5th posn of sub array becomes from 10 to 9, and 5 is assigned to 9th posiotn of main array.

#include<iostream>
using namespace std;

void countSort(int arr[],int n){
    int k=arr[0];  
    for(int i=0;i<n;i++){ //finding max element in the main array to become size of subarray
        k=max(k,arr[i]);
    }
    
    int counter[k+1]; //including 0, so k+1.
    for(int i=0;i<k+1;i++){  //created a sub array and initializing with 0.
        counter[i]=0;
    }
    
    for(int i=0;i<n;i++){
        counter[arr[i]]++;  //incrementing at the position of the number of main array in sub array
    }

    for(int i=1;i<=k;i++){
        counter[i]+=counter[i-1]; //doing the same as in line 4
    }

    int output[n]; //a temp array to save answers
    for(int i=n-1;i>=0;i--){  //saving the sorted order in temp array
        output[--counter[arr[i]]]=arr[i];  // doing the same as line 6
    }

    for(int i=0;i<n;i++){  //putting temp array into main array
        arr[i]=output[i];
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
    
    countSort(arr,n);
    
    //print
    cout<<"Below are all elements sorted in ascending order"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}