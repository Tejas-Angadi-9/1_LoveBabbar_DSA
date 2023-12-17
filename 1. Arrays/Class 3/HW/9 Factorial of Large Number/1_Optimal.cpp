#include<bits/stdc++.h>
using namespace std;

vector<int> findFactorial(int n){
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for(int i=2; i<=n; i++){
        for(int j=0; j<ans.size(); j++){
            int val = ans[j] * i + carry;
            ans[j] = val % 10;
            carry = val / 10;
        }
        while(carry){
            int digit = carry % 10;
            ans.push_back(digit);
            carry /= 10;
        }
        carry = 0;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n = 6;
    vector<int> ans = findFactorial(n);
    for(auto it:ans){
        cout<<it;
    }
}

// TC: O(n^2)      SC: O(n)