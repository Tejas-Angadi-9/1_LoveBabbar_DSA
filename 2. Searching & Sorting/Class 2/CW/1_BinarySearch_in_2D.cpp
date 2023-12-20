#include<bits/stdc++.h>
using namespace std;

vector<int> findInMatrix(vector<vector<int>> matrix, int target){
    int n = matrix.size(), m=matrix[0].size();
    vector<int> ans {-1, -1};
    int s = 0, e = n*m-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        
        int rowIndex = mid / m;
        int colIndex = mid % m;
        int value = matrix[rowIndex][colIndex];
        if(target == value){
            ans[0] = rowIndex;
            ans[1] = colIndex;
            return ans;
        }
        else if(value > target) e = mid - 1;
        else s = mid + 1;

        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
    };
    int target = 7;
    vector<int> ans = findInMatrix(matrix, target);
    for(auto it:ans)
        cout<<it<<" ";
}

// TC: O(logN)  SC: O(1)