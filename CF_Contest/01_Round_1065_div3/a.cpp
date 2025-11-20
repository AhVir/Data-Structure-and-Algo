#include<bits/stdc++.h>
using namespace std;

int main(){
  int t; cin >> t;
  while(t--){
    int legs; cin >> legs;

    if(legs%2 != 0){
      cout << "0" << endl;
      continue;
    }

    int cows = legs/4;
    int chicks = (legs/4)%2;

    cout << cows + 1 << endl;
  }

  return 0;
}
