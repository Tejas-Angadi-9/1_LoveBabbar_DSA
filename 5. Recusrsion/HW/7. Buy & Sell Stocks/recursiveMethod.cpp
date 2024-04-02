#include<bits/stdc++.h>
using namespace std;

void maxProfitFinder(vector<int> &arr, int i, int &minPrice, int &maxProfit){
    //bc
    if(i >= arr.size())
        return;
    
    // processing
    if(arr[i] < minPrice){
        minPrice = arr[i];
    }
    int todaysProfit = arr[i] - minPrice;
    if(todaysProfit > maxProfit)    maxProfit = todaysProfit;

    // rc
    maxProfitFinder(arr, i+1, minPrice, maxProfit);
}

int main(){
    vector<int> arr {7,1,5,3,6,4};
    int minPrice = INT_MAX, maxProfit = INT_MIN;
    maxProfitFinder(arr, 0, minPrice, maxProfit);
    cout<<maxProfit<<endl;
}