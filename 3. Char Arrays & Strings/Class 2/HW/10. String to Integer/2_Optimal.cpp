#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s){
    int num=0, i=0, sign=1;
    // when white spaces are found remove it by moving the i ptr forward
    while(s[i] == ' '){
        i++;
    }
    // Determing the sign
    if(i < s.size() && (s[i] == '-' || s[i] == '+')){
        sign = s[i] == '+' ? 1 : -1;
        i++;
    }
    //Assuming we have a digit now after +/-
    while(i<s.size() && isdigit(s[i])){
        if(num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')){
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num * sign;
}

int main(){
    string s = "  -123Hello456";
    int ans = myAtoi(s);
    cout<<ans<<endl;
} 