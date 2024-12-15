#include<bits/stdc++.h>
using namespace std;

void solveMyMethod(vector<int> &weights, vector<int> &values, int index, int maxCapacity, int &maxi, int currWeight, int currValue){
    // bc
    if(index >= weights.size()){
        maxi = max(maxi, currValue);
        return; 
    }

    // Include
    if(weights[index] + currWeight <= maxCapacity){
        solveMyMethod(weights, values, index+1, maxCapacity, maxi, currWeight + weights[index], currValue + values[index]);
    }
    // Exclude
    solveMyMethod(weights, values, index+1, maxCapacity, maxi, currWeight, currValue);
}

// Indexing starts from the last index of the array and moves to 0th index
int babbarBhaiyasRecursion(vector<int> &weights, vector<int> &values, int index, int capacity){
    // bc
    if(index == 0){
        if(weights[0] <= capacity)
            return values[0];   // It's like including
        else    
            return 0;           // It's like excluding
    }

    // Include and exclude
    int include = 0;
    if(weights[index] <= capacity){
        include = values[index] + babbarBhaiyasRecursion(weights, values, index-1, capacity-weights[index]);
    }
    int exclude = 0 + babbarBhaiyasRecursion(weights, values, index-1, capacity);

    return max(include, exclude);
}

int main(){
    vector<int> weights = {4,5,1};
    vector<int> values = {1,2,3};
    int maxCapacity = 4;
    int index = 0;
    int maxi = INT_MIN;
    int currWeight = 0;
    int currValue = 0;
    // solveMyMethod(weights, values, index, maxCapacity, maxi, currWeight, currValue);
    // cout<<maxi<<endl;
    int ans = babbarBhaiyasRecursion(weights, values, weights.size()-1, maxCapacity);
    cout<<ans<<endl;
}