#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices, int n){
    // STEP 1: Initialize the variables
    int maxProfit = 0, profit = 0;

    // STEP 2: First for loop to pick a buying date which is minimum
    for(int i=0; i<n; i++){
        // STEP 3: Second for loop to pick a selling date which produces the maximum profit
        for(int j=i+1; j<n; j++){
            // STEP 4: Check if selling price > buying price
            if(prices[j] > prices[i]){
                // If Yes Find the diff
                profit = prices[j] - prices[i];
                // Updating the maxProfit
                maxProfit = max(maxProfit, profit);
            }
        }
    }

    // STEP 5: Return the MaxProfit
    return maxProfit;
}

int main(){
    vector<int> prices {7,1,5,3,6,4};
    int n = prices.size();

    cout<<"Max Profit: "<<maxProfit(prices, n)<<endl;
}