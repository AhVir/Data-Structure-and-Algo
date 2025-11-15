class Solution {
    public boolean isAnagram(String s, String t) {
        int[] freqS = new int[26];
        int[] freqT = new int[26];

        if(s.length() != t.length()) return false;

        for(char c:s.toCharArray()){
            int temp = c-'a';
            freqS[temp]++;
        }

        for(char c:t.toCharArray()){
            int temp = c-'a';
            freqT[temp]++;
        }


        for(int i=0; i<26; i++){
            if(freqS[i] != freqT[i]) return false;
        }

        return true;
    }
}
