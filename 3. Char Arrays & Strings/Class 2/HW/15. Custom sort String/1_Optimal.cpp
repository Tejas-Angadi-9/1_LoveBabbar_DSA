#include<bits/stdc++.h>
using namespace std;

string customSort(string order, string s){
    string s1, s2;
    int hash[26] = {0};
    for(char c : order)
        hash[c - 'a']++;
    for(char c : s){
        if(hash[c - 'a'] == 0)
            s2 += c;
        else
            hash[c - 'a']++;
    }
    for(char c : order){
        while(hash[c - 'a'] > 1){
            s1 += c;
            hash[c - 'a']--;
        }
    }
    return s1+s2;
}

int main(){
    string order = "cbafg", s = "abcd";
    string ans = customSort(order, s);
    cout<<ans<<endl;
}

// TC: O(max(M,N))      SC: O(1)