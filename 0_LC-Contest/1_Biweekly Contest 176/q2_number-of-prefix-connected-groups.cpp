class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int ans = 0;
        int n = words.size();

        unordered_set<string> uq;
        for(int i=0; i<n; i++){
            if(words[i].length() < k) continue;
            string temp = "";
            for(int j=0; j<k; j++){
                temp += words[i][j];
            }
            uq.insert(temp);
        }

        unordered_map<string, int> freq;
        for(int i=0; i<n; i++){
            if(words[i].length() < k) continue;
            string temp(words[i].begin(), words[i].begin()+k);
            freq[temp]++;
        }

        for (auto &p : freq) {
            cout << p.first << " -> " << p.second << endl;
        }

        for(string st:uq){
            if(freq.find(st) != freq.end()){
                int cnt = freq[st];
                if(cnt >= 2) ans++;
            }
        }


        return ans;
    }
};