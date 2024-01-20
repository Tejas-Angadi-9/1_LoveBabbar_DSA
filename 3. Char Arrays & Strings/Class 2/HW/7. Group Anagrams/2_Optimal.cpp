#include<bits/stdc++.h>
using namespace std;

std::array<int, 256> hashe(string s){
    std::array<int, 256> hash = {0};
    for(int i=0; i<s.size(); i++)
        hash[s[i]]++;
    return hash;
}

vector<vector<string>> groupAnagrams(vector<string> &strs){
    map<std::array<int, 256>, vector<string>> mpp;

    for(auto str : strs){
        mpp[hashe(str)].push_back(str);
    } 
    vector<vector<string>> ans;
    for(auto it=mpp.begin(); it != mpp.end(); it++){
        ans.push_back(it -> second);
    }
    return ans;
}

int main(){
    vector<string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(auto group : ans){
        for(auto word:group){
            cout<<word<<", ";
        }
        cout<<endl;
    }

}