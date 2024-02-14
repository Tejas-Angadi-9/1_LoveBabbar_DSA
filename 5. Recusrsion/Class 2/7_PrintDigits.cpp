#include <bits/stdc++.h>
using namespace std;

void printDigits(int n){
  //bc
  if(n == 0)
    return;

  //processing
  int val = n % 10;

  //rc
  printDigits(n/10);

  cout<<val<<" ";
}

void reversePrintDigits(int n){
    //bc
  if(n == 0)
    return;

  //processing
  int val = n % 10;
  cout<<val<<" ";

  //rc
  reversePrintDigits(n/10);

}

int main() {
  int n = 647;
  if(n == 0)
    cout<<0<<endl;
  printDigits(n);
  cout<<endl;
  reversePrintDigits(n);
}