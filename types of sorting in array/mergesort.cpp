//dividing array again and again into 2 till individual level, swapping to ascending and merging it again and again.

#include<iostream>
using namespace std;

void merge(int arr[],int st, int mid, int end){  //comparing elements and merging array
    int n1=mid-st+1;
    int n2=end-mid;
    
    int a[n1];
    int b[n2];   //temperory array to cmpare

    //assigning values in temp array
    for(int i=0;i<n1;i++){
        a[i]=arr[st+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }

    int j=0;
    int i=0;  //two pointers for 2 temp array
    int k=st;  //pointer for main array
    while(i<n1 && j<n2){   
        if(a[i]<=b[j]){     //putting element of first temp array into main array
            arr[k]=a[i];
            k++;
            i++;
        }
        else{             //putting element of second temp array into main array
            arr[k]=b[j];
            k++;
            j++;
        }
    }

    //putting the last element[biggest number] left in temp array into the main array in last position cuz there was no number to compare with so it was left alone in temp array
    while(i<n1){
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[],int st,int end){  //breaking array
    if(st<end){
        
        int mid=(st+end)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,st,mid,end);
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
    
    mergeSort(arr,0,n-1);
    
    //print
    cout<<"Below are all elements sorted in ascending order"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

