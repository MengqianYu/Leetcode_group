class Solution {
    public int maxEqualFreq(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        Map<Integer, Integer> map = new HashMap<>();
        int max = 1;
        int min = 1;
        int res = 0;
        for (int i = 0; i < nums.length; i++){
            int freq = count.getOrDefault(nums[i], 0);
            if (count.containsKey((nums[i]))){
                map.put(freq, map.get(freq)-1);
                if (map.get(freq) == 0){
                    map.remove(freq);
                    if (freq == min){
                        min++;
                    }
                }
            }
            else{
                min = 1;
            }
            freq++;
            count.put(nums[i], count.getOrDefault(nums[i], 0)+1);
            map.put(freq, map.getOrDefault(freq, 0) + 1);
            max = Math.max(max, freq);
            min = Math.min(min, freq);
            if (map.size() == 2){
                if (map.get(max) == 1 && max - 1 == min){
                    res = i+1;
                }
                else if (min == 1 && map.get(min) == 1){
                    res = i+1;
                }
            }
            else if (min == 1 && max == 1){
                res = i+1;
            }
            else if (min == max && map.get(min) == 1){
                res = i+1;
            }
        }
        return res;
    }
}