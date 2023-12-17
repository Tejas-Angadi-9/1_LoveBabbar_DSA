#include<bits/stdc++.h>
using namespace std;
int main(){

    // assining 3 rows and 4 cols with -1 value
    // vector<vector<int>>arr(3, vector<int> (4,-1));
 
    // creation of vector matrix
    vector<vector<int>> arr;

    // creating each 1D array
    vector<int> a {1,2,3};
    vector<int> b {4,5,6};
    vector<int> c {7,8,9};
    
    // pushing the values into the vector
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    // Printing
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}