#include<bits/stdc++.h>
using namespace std;

int findLength(char name[50]){
    int cnt = 0, i=0;
    while(name[i] != '\0'){
        cnt++, i++;
    }
    return cnt;
}


void reverseString(char name[50]){
    int n = findLength(name);
    int i = 0, j = n-1;
    while(i<=j){
        swap(name[i++], name[j--]);
    }
    
}

int main(){
    char name[50] = "Tejas Angadi";
    reverseString(name);
    cout<<name<<endl;
    
}