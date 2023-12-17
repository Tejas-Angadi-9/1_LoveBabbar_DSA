#include<bits/stdc++.h>
using namespace std;

vector<int> addition(vector<int> a, vector<int> b){
    vector<int> ans;
    int n=a.size(), m=b.size();
    int i=n-1, j=m-1;
    int carry = 0;

    while(i >=0 && j >=0){
        int val = carry + a[i] + b[j];
        int digit = val % 10;
        carry = val / 10;
        ans.push_back(digit);
        i--, j--;
    }
    while(i >= 0){
        int val = carry + a[i];
        int digit = val % 10;
        carry = val / 10;
        ans.push_back(digit);
        i--;
    }
    while(j >= 0){
        int val = carry + b[j];
        int digit = val % 10;
        carry = val / 10;
        ans.push_back(digit);
        j--;
    }

    if(carry){
        ans.push_back(carry);
    }
    while(ans[ans.size()-1] == 0){
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> a {9,5,4,9};
    vector<int> b {2,1,4};

    vector<int> ans = addition(a, b);
    for(auto it:ans)
        cout<<it<<" ";
}

// TC: O(n + m)     SC: O(n)