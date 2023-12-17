#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> a, vector<int> b, vector<int> c){
    int n1 = a.size(), n2=b.size(), n3=c.size();
    vector<int> ans;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            for(int k=0; k<n3; k++){
                if(a[i] == b[j] && b[j] == c[k])
                    ans.push_back(a[i]);
            }
        }
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

// TC: O(n^3)   SC: O(n)