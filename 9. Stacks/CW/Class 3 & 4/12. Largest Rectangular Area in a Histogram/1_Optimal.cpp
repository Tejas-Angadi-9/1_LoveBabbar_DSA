#include<bits/stdc++.h>
using namespace std;

vector<int> findPrevSmaller(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    
    stack<int> st;
    st.push(-1);

    for(int i=0; i<n; i++){
        int curr = arr[i];

        while(st.top() != -1 && arr[st.top()] > curr){
            st.pop();
        }
        // if(st.top() < arr[i]){
        //     int topValue = st.top();
        //     st.push(arr[i]);
        //     arr[i] = topValue;
        // }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findNextSmaller(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);

    stack<int> st;
    st.push(-1);
    for(int i=n-1; i>=0; i--){
        int curr = arr[i];

        while(st.top() != -1 && arr[st.top()] > curr){
            st.pop();
        }
        // if(st.top() < arr[i]){
        //     int topValue = st.top();
        //     st.push(arr[i]);
        //     arr[i] = topValue;
        // }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

void print(vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int getRectangularAreaHistogram(vector<int> arr){
    // Step1: prev smaller's output
    vector<int>prev = findPrevSmaller(arr);
    
    // Step2: Next smaller's output
    vector<int>next = findNextSmaller(arr);

    int maxArea = INT_MIN;
    int size = arr.size();
    
    for(int i=0; i<arr.size(); i++){
        int length = arr[i];
        if(next[i] == -1){
            next[i] = size;
        }
        int width = next[i] - prev[i] - 1;
        int area = length * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main(){
    vector<int> arr {2,1,5,6,2,3};
    // print(arr);
    int ans = getRectangularAreaHistogram(arr);
    cout<<ans<<endl;
}