#include<bits/stdc++.h>
using namespace std;

int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> nums;
    int hasNeg = 0;
    
    for(int i=0; i<n; i++){
      int t; cin >> t;
      if(t < 0) hasNeg = 1;
      nums.push_back(t);
    }

    int diffSum = 0;

    // if no neg value
    if(hasNeg == 0){
      int diffSum = 0;
      for(int i=1; i<n; i++){
        diffSum += (nums[i]-nums[i-1]);
      }
      cout << abs(diffSum) << endl;
      for(int x:nums) cout << x << " ";
      cout << endl;
      
      continue;
    }


    // Main Calculation
    int first = nums[0], last = nums[n-1];

    if(first == -1|| last == -1){
      if(first == -1 && last == -1){
        nums[0] = 0, nums[n-1] = 0;
      }
      else if(first == -1) nums[0] = nums[n-1];
      else nums[n-1] = nums[0];
    }

    for(int i=0; i<n; i++){
      if(nums[i] == -1) nums[i] = 0;
    }

    diffSum = 0;
    for(int i=0; i<n-1; i++){
      diffSum += (nums[i+1]-nums[i]);
    }


    cout << abs(diffSum) << endl;
    for(int x:nums) cout << x << " ";
    cout << endl;
  }

  return 0;
}
