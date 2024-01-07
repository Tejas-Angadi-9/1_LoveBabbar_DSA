#include<bits/stdc++.h>
using namespace std;

void usingCin(char name[50]){
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Your name is: "<<name<<endl;
}

void usingCinGeline(char name[50]){
    cout<<"Enter your name: ";
    cin.getline(name, 50);
    cout<<"Your name is: "<<name<<endl;
}

int main(){
    char name[50];
    usingCin(name);     // prints till '\0' is not found
    // usingCinGeline(name);    // This prints the entire sentence
}