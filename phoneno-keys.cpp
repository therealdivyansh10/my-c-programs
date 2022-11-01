#include <iostream>
#include <vector>
using namespace std;
void solve(string digits,string output,int index,string mapping[],vector<string>& ans){
    if(index>=digits.length()){
        ans.push_back(output);
        return ;
    }
    int pos=digits[index]-'0';
    string str=mapping[pos];
    for(int i=0;i<str.length();i++){
        output.push_back(str[i]);
        solve(digits,output,index+1,mapping,ans);
        output.pop_back();
    }
}
vector<string> LetterCombinations(string digits){
    vector<string>ans;
    if(digits.length()==0) return ans;
    string mapping[]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output="";
    vector<string>ans;
    int index=0;
    solve(digits,output,index,mapping,ans);
    return ans;
}
int main(){
    string digits="43";
    vector<string>s=LetterCombinations(digits);
    return 0;
}