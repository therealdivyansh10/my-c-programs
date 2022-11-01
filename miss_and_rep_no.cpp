#include <iostream>
using namespace std;
int *findTwoElement(int *arr, int n) {
    int H[n+1]={0};
    for(int i=0;i<n;i++){
        H[arr[i]]++;
    }
    int ans[2]={0},j=0;
    for(int i=0;i<=n;i++){
        if(H[i]==2){
            ans[j]=i;
            j++;
        }else if(H[i]==0){
            ans[j]=i;
        }
    }
    return ans;
}
int main(){
    int arr[]={1,3,3};
    int n=3;
    int *ans=findTwoElement(arr,n);
    cout<<ans<<" "<<(ans+1)<<endl;
}