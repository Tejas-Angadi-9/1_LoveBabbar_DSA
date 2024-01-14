#include<bits/stdc++.h>
using namespace std;

int findMinimumTime(vector<int> minutes){
    int n = minutes.size();
    int mini = INT_MAX;
    for(int i=0; i<n-1; i++){
        int diff = minutes[i+1] - minutes[i];
        mini = min(mini, diff);
    }
    int lastDiff = (minutes[0] + 1440) - minutes[n-1];
    mini = min(mini, lastDiff);
    return mini;
}

int findMinimumDifference(vector<string> timePoints){
  vector<int> minutes;
  int n = timePoints.size();
  for(int i=0; i<n; i++){
    string curr = timePoints[i];
    int hr = stoi(curr.substr(0, 2));
    int mn = stoi(curr.substr(3, 2));
    int totalMinutes = hr * 60 + mn;
    minutes.push_back(totalMinutes);
  }
  sort(minutes.begin(), minutes.end());
  int mini = findMinimumTime(minutes);
  return mini;
}

int main(){
    vector<string> timePoints {"12:10", "10:15", "13:15", "17:20", "18:00", "19:47", "23:59"};
    int ans = findMinimumDifference(timePoints);
    cout<<ans<<endl;
}