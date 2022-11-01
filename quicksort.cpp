#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int *arr,int s,int e){
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(pivot>arr[i]){
            cnt++;
        }
    }
    int pivotindex=cnt+s;
    swap(&arr[s],&arr[pivotindex]);
    int i=s,j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<arr[pivotindex]) i++;
        while(arr[j]>arr[pivotindex]) j--;
        if(arr[i]>arr[pivotindex] && arr[j]<arr[pivotindex]){
            swap(&arr[i],&arr[j]);
        }
    }
    return pivotindex;
}
void quicksort(int *arr,int s,int e){
    if(s>e) return ;
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main(){
    int arr[]={3,1,6,12,76,21,4,5};
    int size=sizeof(arr)/arr[0];
    int s=0,e=size-1;
    quicksort(arr,s,e);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}