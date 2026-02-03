class Solution {
public:
    int trap(vector<int>& height) {
        int maX = 20009;
        int left[maX], right[maX], water[maX];
        for(int i=0; i<maX; i++){
            left[i] = 0;
            right[i] = 0;
            water[i] = 0;
        }


        int n = height.size();
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i=1; i<n; i++){
            left[i] = max(height[i], left[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            right[i] = max(height[i], right[i+1]);
        }

        int trapWater = 0;
        for(int i=0; i<n; i++){
            water[i] = min(left[i], right[i]) - height[i];
            trapWater += water[i];
        }

        return trapWater;
    }
};
