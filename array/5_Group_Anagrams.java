class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs.length == 0) return new ArrayList<>();

        Map<String, List<String>> ans = new HashMap<>();

        int[] freqCnt = new int[26];

        for(String str:strs){
            Arrays.fill(freqCnt, 0);

            for(char c:str.toCharArray()){
                int temp = c - 'a';
                freqCnt[temp]++;
            }

            StringBuilder stbdr = new StringBuilder();

            for(int x:freqCnt){
                stbdr.append(x).append('$');
            }

            String freqStr = stbdr.toString();

            // ans.get(freqStr).add(str);
            if(!ans.containsKey(freqStr)){
                ans.put(freqStr, new ArrayList<>());
            }

            ans.get(freqStr).add(str);
        }

        return new ArrayList<>(ans.values());
    }
}
