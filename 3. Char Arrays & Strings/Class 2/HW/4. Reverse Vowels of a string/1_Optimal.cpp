#include<bits/stdc++.h>
using namespace std;

bool isVowel(char s){
    if(s == 'a' ||s == 'e' ||s == 'i' ||s == 'o' ||s == 'u' ||s == 'A' ||s == 'E' ||s == 'I' ||s == 'O' ||s == 'U'){
        return true;
    }
    return false;
}

string reverseVowels(string s){
    int i = 0, j = s.size()-1;
    while(i<j){
        if(isVowel(s[i]) && isVowel(s[j]))
            swap(s[i++], s[j--]);
        else if(isVowel(s[i]) && !isVowel(s[j]))
            j--;
        else if(!isVowel(s[i]) && isVowel(s[j]))
            i++;
        else 
            i++, j--;
    }
    return s;
}

int main(){
    string s = "leetcode";
    string ans = reverseVowels(s);
    cout<<ans<<endl;
}