#include<bits/stdc++.h>
using namespace std;

int strStr(string haystick, string needle){
    return haystick.find(needle);
}

int main(){
    string haystick = "leetcodesadhero", needle = "sad";
    int index = strStr(haystick, needle);
    cout<<"Index: "<<index<<endl;
}

// TC: O(n*m)   SC: O(1)