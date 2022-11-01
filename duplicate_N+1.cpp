#include <iostream>
#include <vector>
using namespace std;
int duplicate(vector<int> &v){
    int slow=v[0];
    int fast=v[0];
    do{
        slow=v[slow];
        fast=v[v[fast]];
    }while(slow!=fast);
    slow=v[0];
    do{
        slow=v[slow];
        fast=v[fast];
    }while(slow!=fast);
    return fast;
}
int main(){
    vector<int>v{1,2,3,4,5,6,6,9};
    cout<<duplicate(v);
    return 0; 