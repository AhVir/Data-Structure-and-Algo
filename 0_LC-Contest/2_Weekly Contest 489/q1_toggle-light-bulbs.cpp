class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>lights(101, 0);
        int n = bulbs.size();

        for(int x=0; x<n; x++){
            int bulb = bulbs[x];

            if(lights[bulb] == 0) lights[bulb] = bulb;
            else if(lights[bulb] != 0) lights[bulb] = 0;
        }

        vector<int> ans;
        sort(lights.begin(), lights.end());

        for(int x:lights){
            if(x != 0) ans.push_back(x);
        }


        return ans;
    }
};