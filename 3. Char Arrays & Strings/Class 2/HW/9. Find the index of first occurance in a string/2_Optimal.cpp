#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle){
    int n = haystack.size(), m = needle.size();
    for(int i=0; i<=n-m; i++){
        for(int j=0; j<m; j++){
            if(needle[j] != haystack[i+j])
                break;
            else{
                if(j == m-1)
                    return i;
            }
        }
    }
    return -1;
}

int main(){
    string haystack = "leetcodesadhero", needle = "sad";
    int index = strStr(haystack, needle);
    cout<<"Index: "<<index<<endl;
}

// TC: O(n*m)   SC: O(1)