#include<bits/stdc++.h>
using namespace std;

int compress(vector<char> &s){
    int index = 0, cnt = 1;
    char prev = s[0];
    for(int i=1; i<s.size(); i++){
        if(s[i] == prev)
            cnt++;
        else{
            s[index++] = prev;
            if(cnt > 1){
                int start = index;
                while(cnt){
                    s[index++] = (cnt % 10) + '0';
                    cnt /= 10;
                }
                reverse(s.begin()+start, s.begin()+index-1);
            }
            prev = s[i];
            cnt = 1;
        }
    }
    s[index++] = prev;
    if(cnt > 1){
        int start = index;
        while(cnt){
            s[index++] = (cnt % 10) + '0';
            cnt /= 10;
        }
        reverse(s.begin()+start, s.begin()+index-1);
    }
    return index;
}

int main(){
    vector<char> s = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'd'};
    int ans = compress(s);
    cout<<"Length of new array: "<<ans<<endl;
}