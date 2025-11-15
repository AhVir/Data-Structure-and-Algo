class Solution {
    public int romanToInt(String s) {
        int res = 0;

        Map<Character, Integer> val = new HashMap<>();
        val.put('I', 1);
        val.put('V', 5);
        val.put('X', 10);
        val.put('L', 50);
        val.put('C', 100);
        val.put('D', 500);
        val.put('M', 1000);
        
        for(int i=0; i<s.length(); i++){
            if (i + 1 < s.length()) {
                char curr = s.charAt(i);
                char next = s.charAt(i + 1);

                if (curr == 'I' && next == 'V') { res += 4; i += 1; continue; }
                if (curr == 'I' && next == 'X') { res += 9; i += 1; continue; }
                if (curr == 'X' && next == 'L') { res += 40; i += 1; continue; }
                if (curr == 'X' && next == 'C') { res += 90; i += 1; continue; }
                if (curr == 'C' && next == 'D') { res += 400; i += 1; continue; }
                if (curr == 'C' && next == 'M') { res += 900; i += 1; continue; }
            }
            
            res += val.get(s.charAt(i));
        }

        return res;
    }
}
