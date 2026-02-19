class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        vector<int> groups;

        int cur = 1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                cur++;
            }
            else{
                groups.push_back(cur);
                cur = 1;
            }
        }
        groups.push_back(cur);

        int ans = 0;
        for(int i=1; i<groups.size(); i++){
            ans += min(groups[i], groups[i-1]);
        }

        return ans;
    }
};
