#include<bits/stdc++.h>

using namespace std;
int main(){
    vector<int> arr {-12, 11, -13,-5,6,-7,5,-3,-6};
    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
}

// TC: O(nLogn)     SC: O(1)