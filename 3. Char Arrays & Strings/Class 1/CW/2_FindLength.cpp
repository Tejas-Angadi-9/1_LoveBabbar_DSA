#include<bits/stdc++.h>
using namespace std;

int findLength(char name[50]){
    int cnt = 0, i=0;
    while(name[i] != '\0'){
        cnt++, i++;
    }
    return cnt;
}

int main(){
    char name[50] = "Tejas Angadi";
    // name = "Tejas";
    int length = findLength(name);
    cout<<"Length: "<<length<<endl;
}

// TC: O(n)     SC: O(1)