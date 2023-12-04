#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices, int n){
    // STEP 1: Initializing variables
    int maxProfit = 0, minPrice = INT_MAX;
    
    // STEP 2: Traversing the array linearly
    for(int i=0; i<n; i++){
        // STEP 3: Updating the minPrice as we need to select a minimum buying date of the stock
        minPrice = min(minPrice, prices[i]);

        // STEP 4: Update the maxProfit after finding the difference between selling price and the buying price.
        maxProfit = max(maxProfit, prices[i] - minPrice);     // Why prices[i] - minPrice ? B'coz current index of i value is always > minPrice
    }

    // STEP 5: Return maxProfit
    return maxProfit;
}

int main(){
    vector<int> prices {7,1,5,3,6,4};
    int n = prices.size();

    cout<<"Max Profit: "<<maxProfit(prices, n)<<endl;
}