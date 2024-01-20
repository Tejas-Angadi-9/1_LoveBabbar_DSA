#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs){
    map<string, vector<string>> mpp;

    for(auto str : strs){
        string s = str;
        sort(s.begin(), s.end());
        mpp[s].push_back(str);
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