#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

    TrieNode(char d){
        this->data = d;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
        this->childCount = 0;
    }
};

void insertWordIntoTrie(TrieNode*root, string word){
    // bc
    if(word.size() == 0){
        root->isTerminal = true;
        return;
    }

    // Solving for one case
    // Check if the root's children's array contains a non-null value or not
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        // That means the root has a child so just move the root
        child = root->children[index];
    }
    else{
        // So the child doesn't exist. Here we can create a new child and connect it to root
        child = new TrieNode(ch);
        root->children[index] = child;
        root->childCount++;
    }

    // RC -> by removing the starting letter
    insertWordIntoTrie(child, word.substr(1));  
}

void storeSuggestions(TrieNode* curr, vector<string> &temp, string &prefix){
    if(curr->isTerminal){ 
        temp.push_back(prefix);
    }

    // We have to give the choice from a-z for the current node and check if there is any possibility available to get the suggestion
    for(char ch = 'a'; ch<='z'; ch++){
        int index = ch - 'a';

        TrieNode* next = curr->children[index];

        if(next != NULL){
            // Child exists. Can go
            prefix.push_back(ch);
            storeSuggestions(next, temp, prefix);
            prefix.pop_back(); // As we are coming back and we will not get any unwanted string or repeated string
        }
    }
}

vector<vector<string>> getSuggestions(TrieNode* root, string input){
    // To store and return the ans.
    vector<vector<string>> output;

    TrieNode* prev = root;
    string prefix = ""; // This stores the each char from the suggestions. Then we can push this into the 1D vector string 

    for(int i=0; i<input.length(); i++){
        char lastCh = input[i];

        int index = lastCh - 'a';
        TrieNode* curr = prev->children[index];

        if(curr == NULL){
            break;
        }
        else{
            vector<string> temp;
            prefix.push_back(lastCh);
            storeSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}

int main(){
    vector<string> v;

    TrieNode* root = new TrieNode('-');

    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");
    for(int i=0; i<v.size(); i++){
        insertWordIntoTrie(root, v[i]);
    }

    string input = "la";

    vector<vector<string>> ans = getSuggestions(root, input);
    cout<<"Printing the answer: "<<endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<", ";
        }
        cout<<endl;
    }
}