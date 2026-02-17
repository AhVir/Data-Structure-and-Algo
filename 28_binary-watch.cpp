class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int i=0; i<12; i++){
            for(int j=0; j<60; j++){
                if(__builtin_popcount(i) + __builtin_popcount(j) == turnedOn){
                    string temp = "";
                    string h = to_string(i);
                    string m = to_string(j);
                    if(j < 10){
                        m = "0" + m;
                    }

                    temp = h + ":" + m;
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};
