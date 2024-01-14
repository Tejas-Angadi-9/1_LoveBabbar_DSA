#include<bits/stdc++.h>
using namespace std;

int checkForAns(string s, int i, int j){
    int cnt = 0;
    while(i>=0 && j<s.length() && s[i] == s[j]){
        cnt++, i--, j++;
    }
    return cnt;
}

int countSubStrings(string s){
    int count = 0, n = s.length();
    for(int i=0; i<n; i++){
        int oddPatternAns = checkForAns(s, i, i);
        count = count + oddPatternAns;
        int evenPatternAns = checkForAns(s, i, i+1);
        count = count + evenPatternAns;
    }
    return count;
}

int main(){
    string s = "noon";
    int ans = countSubStrings(s);
    cout<<ans<<endl;
}