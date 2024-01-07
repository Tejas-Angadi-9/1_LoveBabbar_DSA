#include<bits/stdc++.h>
using namespace std;

string removeOccurances(string s, string part){
    int pos = s.find(part);
    while(pos != string::npos){
        s.erase(pos, part.size());
        pos = s.find(part);
    }
    return s;
}

int main(){
    string s = "axxxxyyyyc", part = "xy";
    string ans = removeOccurances(s, part);
    cout<<ans<<endl;
}

// TC: O(n)     SC: O(1)