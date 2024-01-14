#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){
    if(s.size() != t.size())    return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    // return (!s.compare(t));
    // if(s.compare(t))
    //     return false;
    // else 
    //     return true;
    return s == t;
}

int main(){
    string s = "anagram", t = "nagarma";
    bool ans = isAnagram(s, t);
    cout<<ans;
}