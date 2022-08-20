// Given an unsorted array A of size N of non-negative integers, find a continuous
// subarray which adds to a given number S.


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
    int s,m,k,chck;
    cout<<"Enter sum\n";
    cin>>s;
    chck=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==s){
                if(i!=j){
                    m=i+1;
                    k=j+1;
                    chck=1;
                }
            }
        }
    }
    if(chck==1){
        cout<<m<<" to "<<k<<endl;
    }
    
    else cout<<"No required subarray found"<<endl;
}