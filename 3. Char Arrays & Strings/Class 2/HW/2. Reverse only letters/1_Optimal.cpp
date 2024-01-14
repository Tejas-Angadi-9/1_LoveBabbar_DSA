#include<bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string s){
    int i=0, j=s.size()-1;
    while(i<j){
        if(isalpha(s[i]) && isalpha(s[j]))
            swap(s[i++], s[j--]);
        else if(isalpha(s[i]) && !isalpha(s[j]))
            j--;
        else if(!isalpha(s[i]) && isalpha(s[j]))
            i++;
        else
            i++, j--;
    }
    return s;
}

int main(){
    string s = "a-bC-dEf-ghIj";
    string ans = reverseOnlyLetters(s);
    cout<<ans<<endl;
}