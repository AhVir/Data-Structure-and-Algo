class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> orderMap = new HashMap<>();
        
        int i = 0;
        for(char x:order.toCharArray()){
            orderMap.put(x, i++);
        }

        for(i=0; i<words.length-1; i++){
            int word1 = words[i].length();
            int word2 = words[i+1].length();

            // if(word1 > word2) return false;

            int len = Math.min(word1, word2);
            boolean wasBroken = false;

            for(int j=0; j<len; j++){
                int val1 = orderMap.get(words[i].charAt(j));
                int val2 = orderMap.get(words[i+1].charAt(j));

                if(val1 > val2) return false;
                if(val1 < val2) {
                    wasBroken = true;
                    break;
                }
            }

            // if(word1 > word2) return false;
            if(!wasBroken && (word1 > word2)) return false;
        }

        return true;
    }
}
