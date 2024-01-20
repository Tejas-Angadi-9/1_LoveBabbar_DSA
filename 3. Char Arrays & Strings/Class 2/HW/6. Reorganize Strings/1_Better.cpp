#include<bits/stdc++.h>
using namespace std;

string reorganizeString(string s){
    int hash[26] = {0};
    for(int i=0; i<s.size(); i++)
        hash[s[i]-'a']++;

    // finding max occurant character
    int max_freq = 0;
    char max_freq_char;
    for(int i=0; i<26; i++){
        if(hash[i] > max_freq){
            max_freq = hash[i];
            max_freq_char = i + 'a';
        }
    }

    // now will be placing the max occuring character non-adjacently
    int index = 0;
    while(max_freq > 0 && index < s.size()){
        s[index] = max_freq_char;
        max_freq--;
        index += 2;
    }
    //when max_occurant character is not placed within s size
    if(max_freq != 0)
        return "";
    
    // Resetting value of max_occuring char in hash as 0
    hash[max_freq_char - 'a'] = 0;

    // filling the rest of the elements in the s
    for(int i=0; i<26; i++){
        while(hash[i] > 0){
            //! We can also do
            // if(index >= s.size())
            //     index = 1;
            
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }
    return s;
}

int main(){
    string s = "aab";
    string ans = reorganizeString(s);
    if(ans.size() == 0)
        cout<<"can't reorganize the strings"<<endl;
    cout<<ans<<endl;
}