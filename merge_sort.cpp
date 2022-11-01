#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(int arr,int s,int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int* arr1=new int[len1];
    int* arr2=new int[len2];
    int *array=new int[len1+len2];
    for(int i=0;i<len1;i++){
        arr1[i]=arr[s+i];
    }
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mid+i+1];
    }


}
void mergesort(int *arr,int s,int e){
    if(s>e) return ;
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e)
}   
int main(){
    int arr[]={43,21,41,6,3,5,65};
    mergesort(arr,0,7);
    return 0;
}