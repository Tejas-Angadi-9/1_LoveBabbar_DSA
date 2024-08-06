#include<bits/stdc++.h>
using namespace std;
int main(){
    // Creation of the stack
    stack<int> st;
    // Pushing the values into the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // Print the stack size
    int n = st.size();
    cout<<n<<endl;
    // Print the stack
    // while(st.size() != 0){
    //     cout<<"\nIs Stack empty: "<<st.empty()<<endl;
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    while(!st.empty()){
        cout<<"\nIs Stack empty: "<<st.empty()<<endl;
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    cout<<"Is Stack empty: "<<st.empty()<<endl;
}