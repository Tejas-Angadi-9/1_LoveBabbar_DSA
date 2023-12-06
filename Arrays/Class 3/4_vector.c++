#include<bits/stdc++.h>
using namespace std;
int main(){

    // assining 3 rows and 4 cols with -1 value
    vector<vector<int>>arr(3, vector<int> (4,-1));
 
    // Printing
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}