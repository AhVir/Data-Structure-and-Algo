class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        bool firstActive = true;
        bool secActive = false;
        int first = 0, second = 0;

        for(int i=0; i<n; i++){
            int num = nums[i];
            if((num % 2 == 1)){
                if(firstActive){
                    firstActive = false;
                    secActive = true;
                }
                else{
                    firstActive = true;
                    secActive = false;
                }
            }

            if((i+1)%6 == 0){
                if(firstActive){
                    firstActive = false;
                    secActive = true;
                }
                else{
                    firstActive = true;
                    secActive = false;
                }
            }

            if(firstActive){
                first += num;
                // cout << "i: " << i << ", first active" << endl;
            } 
            else{
                // cout << "i: " << i << ", sec active" << endl;
                second += num;
            }
        }

        // cout << "first score: " << first << endl;
        // cout << "sec score: " << second << endl;

        return first-second;
    }
};