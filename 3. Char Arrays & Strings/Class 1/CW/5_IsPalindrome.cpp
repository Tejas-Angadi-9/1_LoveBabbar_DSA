#include<bits/stdc++.h>
using namespace std;

int findLength(char name[50]){
    int cnt = 0, i=0;
    while(name[i] != '\0'){
        cnt++, i++;
    }
    return cnt;
}

bool isPalindrome(char ch[50], int n){
    int i=0, j=n-1;
    while(i<=j){
        if(ch[i] != ch[j])
            return false;
        i++, j--;
    }
    return true;
}

int main(){
    char ch[100] = "rar";
    int n = findLength(ch);
    bool ans = isPalindrome(ch, n);
    if(ans)
        cout<<"It is a palindrome"<<endl;
    else    
        cout<<"Not a palindrome"<<endl;
}

// TC: O(n)     SC: O(1)