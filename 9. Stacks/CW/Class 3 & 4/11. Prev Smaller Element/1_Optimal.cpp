#include<bits/stdc++.h>
using namespace std;

void findPrevSmaller(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    for(int i=0; i<n; i++){
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
    vector<int> arr {2,1,4,3};
    print(arr);
    findPrevSmaller(arr);
    print(arr);
}