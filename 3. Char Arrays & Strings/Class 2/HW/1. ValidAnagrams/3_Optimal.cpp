// HASHING
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){
    if(s.size() != t.size())
        return false;

    int freqTable[256] = {0};  

    // int freqTable[26] = {0};  
    
    for(int i=0; i<s.size(); i++){
        freqTable[s[i]]++;  
    //  freqTable[s[i] - 'a']++;
    }

    for(int i=0; i<t.size(); i++){
            freqTable[t[i]]--;
    //  freqTable[s[i] - 'a']--;
    }

    // i = 0; i<256; i++
    for(int i=0; i<256; i++){
        if(freqTable[i] > 0)
            return false;
    }
    return true;
}

int main(){
    string s = "anagram", t = "nagrama";
    bool ans = isAnagram(s, t);
    cout<<ans<<endl;
}