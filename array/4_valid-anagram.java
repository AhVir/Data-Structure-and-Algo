class Solution {
    public boolean isAnagram(String s, String t) {
        // int[] freqS = new int[26];
        // int[] freqT = new int[26];

        if(s.length() != t.length()) return false;

        // 1st Approach:
        // ------------

        // for(char c:s.toCharArray()){
        //     int temp = c-'a';
        //     freqS[temp]++;
        // }

        // for(char c:t.toCharArray()){
        //     int temp = c-'a';
        //     freqT[temp]++;
        // }


        // for(int i=0; i<26; i++){
        //     if(freqS[i] != freqT[i]) return false;
        // }



        // 2nd Approach:
        // -------------

        int[] freq = new int[26];

        for(int i=0; i<s.length(); i++){
            int char1 = s.charAt(i) - 'a';
            int char2 = t.charAt(i) - 'a';

            freq[char1]++;
            freq[char2]--;
        }

        for(int x:freq) if(x != 0) return false;

        return true;
    }
}
