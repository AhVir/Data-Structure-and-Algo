class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> vec;

        for(int x:arr){
            int Ones = __builtin_popcount(x);
            vec.push_back({x, Ones});
        }

        sort(vec.begin(), vec.end(), [](pair<int,int> &a, pair<int,int> &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;  // ascending by 1-bits
        });

        vector<int> ans;

        for(auto &p:vec){
            // cout << "Number: " << p.first << ", 1-bits: " << p.second << endl;
            ans.push_back(p.first);
        }

        return ans;
    }
};
