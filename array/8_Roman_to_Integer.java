class Solution {
    public int romanToInt(String s) {
        // Some Other Approach
        // -------------------
        
        // int res = 0;

        // Map<String, Integer> val = new HashMap<>();
        // val.put("I", 1);
        // val.put("V", 5);
        // val.put("X", 10);
        // val.put("L", 50);
        // val.put("C", 100);
        // val.put("D", 500);
        // val.put("M", 1000);
        // val.put("IV", 4);
        // val.put("IX", 9);
        // val.put("XL", 40);
        // val.put("XC", 90);
        // val.put("CD", 400);
        // val.put("CM", 900);
        
        // for(int i=0; i<s.length(); i++){
        //     if(i+1 < s.length()){
        //         String str = s.substring(i, i+2);
        //         if(val.containsKey(str)){
        //             res += val.get(str);
        //             i++;
        //             continue;
        //         }
        //     }

        //     String str = s.substring(i, i+1);
        //     res += val.get(str);
        // }

        // return res;


        
        // Another ONE
        // ----------
        
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
