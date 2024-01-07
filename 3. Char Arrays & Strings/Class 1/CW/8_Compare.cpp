#include<bits/stdc++.h>
using namespace std;

bool compareFunction(string a, string b){
    int i=0, j=0, n = a.length(), m=b.length();
    if(n != m)  return false;
    while(i<n && j<m){
        if(a[i] != b[j])
            return false;
        i++, j++;
    }
    return true;
}

int main(){
    string a = "Love";
    string b = "Love";
    cout<<compareFunction(a, b);
}

// TC: O(n)     SC: O(1)