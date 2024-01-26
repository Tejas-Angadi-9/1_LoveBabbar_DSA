#include<bits/stdc++.h>
using namespace std;

static bool mycomp(string a, string b){
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
}

string largestNumber(vector<int> &nums){
    vector<string> snums;
    for(auto n : nums){
        snums.push_back(to_string(n));
    }
    sort(snums.begin(), snums.end(), mycomp);
    string ans = "";
    for(int i=snums.size() - 1; i>=0; i--){
        ans += snums[i];
    }
    return ans;
}

int main(){
    vector<int> nums {10, 2};
    string ans = largestNumber(nums);
    cout<<ans<<endl;
}