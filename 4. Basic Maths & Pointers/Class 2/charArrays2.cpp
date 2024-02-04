#include<bits/stdc++.h>
using namespace std;
int main(){
    char name[10] = "SherBano";
    char *cptr = &name[0];
    cout<<name<<endl;
    cout<<&name<<endl;
    cout<<(name+3)<<endl;
    cout<<cptr<<endl;
    cout<<&cptr<<endl;
    cout<<*(cptr+3)<<endl;
    cout<<name[1]<<endl;
    cout<<&name[1]<<endl;
    cout<<*cptr<<endl;
    cout<<cptr+2<<endl;
    cout<<cptr+8<<endl;
    cout<<cptr+8<<endl;
}