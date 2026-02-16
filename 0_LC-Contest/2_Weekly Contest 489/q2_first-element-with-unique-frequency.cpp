class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> freq;
        unordered_map<int, int> freqCount;


        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        for (auto const& pair : freq) {
            freqCount[pair.second]++;
        }

        for(int i=0; i<n; i++){
            int num = nums[i];

            if(freqCount[freq[num]] == 1) return num;
        }


        return -1;
    }
};