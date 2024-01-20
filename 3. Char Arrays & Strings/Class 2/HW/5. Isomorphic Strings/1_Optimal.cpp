#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t){
    unordered_map<char, char> mpp;
    if(s.size() != t.size())    return false;
    int i = 0;
    for(int i=0; i<s.size(); i++){
        if(mpp.find(s[i]) != mpp.end()){
            if(mpp[s[i]] != t[i])
                return false;
        }else{
            for(auto it = mpp.begin(); it != mpp.end(); it++){
                if(it->second == t[i])
                    return false;
            }
            //! Can also use this and we should use .second for this for loop
            // for(const auto &it:mpp){
            //     if(it.second == t[i])
            //         return false;
            // }
            mpp[s[i]] = t[i];
        }
    }
    return true;
}

int main(){
    string s = "add", t = "egg";
    bool ans = isIsomorphic(s, t);
    cout<<ans<<endl;
}

// TC: O(n)     SC: O(1)