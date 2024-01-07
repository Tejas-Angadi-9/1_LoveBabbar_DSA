#include<bits/stdc++.h>
using namespace std;

string removeAdjacents(string str){
    int n = str.size();
    string ans = "";
    for(int i=0; i<n; i++){
        if(ans.size() == 0 || ans.back() != str[i]) 
            ans.push_back(str[i]);
        else
            ans.pop_back();
    }
    return ans;
}

int main(){
    string str = "abbaca";
    string ans = removeAdjacents(str);
    if(ans.size() == 0)
        cout<<"No characters left"<<endl;
    cout<<ans;
}

// TC: O(n)     SC: O(1)