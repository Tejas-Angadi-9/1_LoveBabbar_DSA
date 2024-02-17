#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string str, string output, int i){
  // bc
  if(i >= str.size()){
    if(output.size() == 0){
      cout<<"{ }"<<", ";
    }else{
      cout<<"{"<<output<<"}"<<", ";
    }
    return;
  }

  // exclude
  printSubsequences(str, output, i+1);

  // include
  output.push_back(str[i]);
  printSubsequences(str, output, i+1);

}

int main() {
  string str = "abc";
  string output = "";

  int i = 0;
  printSubsequences(str, output, i);
}