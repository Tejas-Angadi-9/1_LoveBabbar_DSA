#include<bits/stdc++.h>
using namespace std;

void findNextSmaller(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    for(int i=n-1; i>=0; i--){
        while(st.top() > arr[i]){
            st.pop();
        }
        if(st.top() < arr[i]){
            int topValue = st.top();
            st.push(arr[i]);
            arr[i] = topValue;
        }
    }
}

void print(vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr {2, 5, 3, 7, 1, 5, 2, 6, 3, 1};
    print(arr);
    findNextSmaller(arr);
    print(arr);
}