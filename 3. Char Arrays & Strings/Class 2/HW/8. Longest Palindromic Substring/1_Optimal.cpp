#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j){
    while(i < j){
        if(s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}

string longestPalindrome(string s){
    string ans = "";
    for(int i=0; i<s.size(); i++){
        for(int j = i; j<s.size(); j++){
            if(isPalindrome(s, i, j)){
                string t = s.substr(i, j-i+1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    return ans;
}

int main(){
    string s = "babad";
    string ans = longestPalindrome(s);
    cout<<ans<<endl;
}

// CHECK IF WE CAN USE ODD/EVEN palindrome where we used to check the number of palindromic substrings
// TC: O(n^3)   SC: O(1)    
// We can further optimize it by using DP algo.