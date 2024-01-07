#include<bits/stdc++.h>
using namespace std;

int findLength(char name[50]){
    int cnt = 0, i=0;
    while(name[i] != '\0'){
        cnt++, i++;
    }
    return cnt;
}

void fillVoid(char ch[100], int n, char symbol){
    int i = 0;
    for(int i=0; i<n; i++){
        if(ch[i] == ' ')
            ch[i] = symbol;
    }
}

int main(){
    char ch[100] = "Hello This is Echo 3 1";
    int n = findLength(ch);
    char symbol;
    cout<<"Enter a symbol to insert: ";
    cin>>symbol;
    fillVoid(ch, n, symbol);

    for(int i=0; i<n; i++)
        cout<<ch[i];
}

// TC: O(n)     SC: O(1)