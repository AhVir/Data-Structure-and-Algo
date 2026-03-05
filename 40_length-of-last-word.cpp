class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;

        string temp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(temp.length() != 0){
                    words.push_back(temp);
                }
                temp = "";
            }
            else temp += s[i];
        }

        if(temp.size() != 0) words.push_back(temp);

        cout << "last word: '" << words[words.size()-1] << "'" << endl;
        cout << "last word: " << words[words.size()-1].size() << endl;



        return words[words.size()-1].size();
    }
};
