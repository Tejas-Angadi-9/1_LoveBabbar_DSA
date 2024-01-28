#include<bits/stdc++.h>
using namespace std;

static bool compare(const string a, const string b){
    return a.length() > b.length() || (a.length() == b.length() && a < b);
}

bool isSubsequence(string S, string D){
    int i=0, j=0;
    if(D.length() > S.length())
        return false;
    while(i < S.length() && j < D.length()){
        if(S[i] == D[j])
            j++;
        i++;
    }
    return j == D.length();
}

string findLongestWord(string s, vector<string> dictionary){
    string ans = "";
    sort(dictionary.begin(), dictionary.end(), compare);
    for(string str : dictionary){
        if(isSubsequence(s, str)){
            ans = str;
            return ans;
            // return ans = str;
        }
    }
    return ans;
}

int main(){
    string s = "abpcleam";
    vector<string> dictionary {"ale", "apple", "monkey", "plea"};
    string ans = findLongestWord(s, dictionary);
    cout<<ans<<endl; 
}

// TC: O(min(m,n))      SC: O(1)
// At worst case TC: O(n)