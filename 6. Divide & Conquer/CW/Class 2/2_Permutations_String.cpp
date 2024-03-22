#include<bits/stdc++.h>
using namespace std;

void printPermutation(string &str, int i){
    //* Base case 
    if(i >= str.length()){
        cout<<str<<" ";
        return;
    }

    //* Swapping
    for(int j=i; j<str.length(); j++){
        //* Swap the characters of i with j
        swap(str[i], str[j]);
        //* Recursive call for the next value of i not for j as we have used the for loop for j
        printPermutation(str, i+1);
        //! Backtracking -> To Recreate the original input. As we have passed by reference and we swap the string will be changed to get the string back to it's original position we swap it again. So that the rest of the operations work properly.
        swap(str[i], str[j]);

    }
}

int main(){
    string str = "abc";
    int i = 0;

    printPermutation(str, i);
    cout<<str<<endl;
}