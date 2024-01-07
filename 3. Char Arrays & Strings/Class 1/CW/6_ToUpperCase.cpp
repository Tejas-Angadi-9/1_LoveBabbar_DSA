#include<bits/stdc++.h>
using namespace std;

int findLength(char name[50]){
    int cnt = 0, i=0;
    while(name[i] != '\0'){
        cnt++, i++;
    }
    return cnt;
}

void convertToUpperCase(char ch[50], int n){
    for(int i=0; i<n; i++){
        ch[i] = ch[i] - 'a' + 'A';
    }
}

void convertToLowerCase(char ch[50], int n){
    for(int i=0; i<n; i++){
        ch[i] = ch[i] - 'A' + 'a';
    }
}

int main(){
    char ch[100] = "rar";
    int n = findLength(ch);
    convertToUpperCase(ch, n);
    cout<<ch<<endl;
    convertToLowerCase(ch, n);
    cout<<ch<<endl;
}

// TC: O(n)     SC: O(1)