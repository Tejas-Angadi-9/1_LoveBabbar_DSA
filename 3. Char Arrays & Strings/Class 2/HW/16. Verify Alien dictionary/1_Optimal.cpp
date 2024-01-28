#include<bits/stdc++.h>
using namespace std;

bool compareWords(string word1,  string word2, vector<int> hash) {
    int len1 = word1.size(), len2 = word2.size();

    for (int i = 0; i < min(len1, len2); i++) {
        char char1 = word1[i];
        char char2 = word2[i];

        if (hash[char1 - 'a'] < hash[char2 - 'a'])
            return true;
        else if (hash[char1 - 'a'] > hash[char2 - 'a'])
            return false;
    }
    return len1 <= len2;
}

bool isAlienSorted(vector<string>& words, string order) {
    vector<int> hash(26, 0);

    // building the alien dictionary mapping
    for (int i = 0; i < order.size(); i++)
        hash[order[i] - 'a'] = i;

    // compare the adjacent words
    for (int i = 0; i < words.size() - 1; i++) {
        if (!compareWords(words[i], words[i + 1], hash)) {
            return false;
        }
    }
    return true;
}

int main(){
    vector<string> words {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    bool ans = isAlienSorted(words, order);
    cout<<ans<<endl;
}

// TC: O(n)     SC: O(1) / O(26)