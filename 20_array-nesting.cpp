class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) { 
                int current = i;
                // int count = 0;
                // while (!visited[current]) {
                //     visited[current] = true;     
                //     current = nums[current];     
                //     count++;
                // }
                unordered_set<int> count;
                while(count.find(nums[current]) == count.end()){
                    count.insert(nums[current]);
                    visited[current] = true;
                    current = nums[current];
                }


                ans = max(ans, (int)count.size());  

                count.clear();         
            }
        }


        return ans;
    }
};
