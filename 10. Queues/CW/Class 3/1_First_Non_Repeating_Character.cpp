#include<bits/stdc++.h>
using namespace std;



int main(){
    string str = "aabc";
    int freq[26] = {0};
    queue<char> q;

    string ans = "";

    for(int i=0; i<str.size(); i++){
        char ch = str[i];

        // Increment Frequency
        freq[ch - 'a']++;
        // q.push
        q.push(ch);
        // Check the ans is it repeating or not from the q.front
        while(!q.empty()){
            if(freq[q.front() - 'a'] > 1)   
                // 
                q.pop();
            else{
                // Non repeating. So store the ans and come out of the while loop
                ans.push_back(q.front());
                break;
            }
        } 

        // If Queue is empty and the non repeating value is not found
        if(q.empty()){
            ans.push_back('#');
        }
    }

    cout<<"Final Ans: "<<ans<<endl;
}