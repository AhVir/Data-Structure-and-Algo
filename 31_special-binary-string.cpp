class Solution {
public:
    string specialString(string s){
        vector<string>blocks;
        int n = s.length();

        int total = 0;
        string tempSt = "";
        for(int i=0; i<n; i++){
            if(s[i] == '1') total++;
            else total--;

            tempSt += s[i];
            if(total == 0){
                string removeStartEnd = tempSt.substr(1, tempSt.size()-2);
                string largest = specialString(removeStartEnd);

                tempSt = "1" + largest + "0";

                blocks.push_back(tempSt);
                tempSt = "";
            }
        }

        // for(auto x:blocks) cout << x << " ";
        // cout << endl;
        
        sort(blocks.begin(), blocks.end(), greater<string>());

        string merged = "";
        for(string x:blocks) merged += x;

        return merged;
    }


    string makeLargestSpecial(string s) {
        return specialString(s);
    }
};
