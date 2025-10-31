#include<bits/stdc++.h>
using namespace std;

int main(){
  int t; cin >> t;

  while(t--){
    int n; cin >> n; // length of the array

    vector<int> nums;

    for(int i=0; i<n; i++){
      int temp; cin >> temp;
      nums.push_back(temp);
    }
    
    int l = 0, r = n-1;
    int val = 1;
    bool flag = true;

    while(l<=r){
      if(nums[l] == val) l++;
      else if(nums[r] == val) r--;
      else{
        cout << "No" << endl;
        flag = false;
        break;
      }

      val++;
    }

    if(flag) cout << "Yes" << endl;
  }

  return 0;
}
