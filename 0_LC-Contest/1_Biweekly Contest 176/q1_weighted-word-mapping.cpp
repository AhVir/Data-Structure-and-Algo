class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(int i=0; i<words.size(); i++){
            int wt = 0;
            for(char x:words[i]){
                wt += weights[x-'a'];
            }
            // wt += 61;
            wt = wt % 26;

            cout << "wt: " << wt << endl;
            
            char res = 'z' - wt;
            ans = ans+res;
        }


        cout << ans << endl;

        return ans;
    }
};