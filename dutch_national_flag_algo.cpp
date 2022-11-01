#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int *arr,int n){
    int low=0,high=n-1,mid=0;
        while(mid<high){
        if(arr[mid]==0){
            swap(&arr[mid],&arr[low]);
            mid++;
            low++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(&arr[high],&arr[mid]);
            mid++;
            high--;
        }
    }
}
int main(){
    int arr[]={1,0,1,0,0,2,0,1,2};
    int n=9;
    sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}