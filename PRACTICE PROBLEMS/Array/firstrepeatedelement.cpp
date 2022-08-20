//The task is to find the first repeating element in an
//array of integers, i.e., an element that occurs more than once and whose index of
//first occurrence is smallest.

#include<iostream>
using namespace std;

int main(){
    //input
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
    
    int repposn=INT_MAX;  //max value
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                repposn=min(repposn,i+1);  //to find least position. 
                
            }
            
        }
        
    }
    if(repposn==INT_MAX){
        cout<<"no repeated elements in the array\n";
    }
    else cout<<repposn<<" is first repeated position in array\n";
}