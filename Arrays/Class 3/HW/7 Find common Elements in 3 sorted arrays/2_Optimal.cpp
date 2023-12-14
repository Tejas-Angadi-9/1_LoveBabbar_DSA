#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> a, vector<int> b, vector<int> c){
    vector<int> ans;
    int n1 = a.size(), n2 = b.size(), n3 = c.size();
    int i=0, j=0, k=0;
    while(i<n1){
        if(a[i] == b[j] && b[j] == c[k]){
            ans.push_back(a[i]);
            i++, j++, k++;
        }
        else if(a[i] < b[j])    i++;
        else if(b[j] < c[k])    j++;
        else    k++;
    }
    return ans;
}

int main(){
    vector<int> a{1,5,10,20,40,80};
    vector<int> b{6,7,20,80,100};
    vector<int> c{3,4,15,20,30,70,80,120};

    vector<int> ans = commonElements(a, b, c);
    for(auto it:ans)
        cout<<it<<" ";
}

// TC: O(n)     SC: O(1)