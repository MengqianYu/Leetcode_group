class Solution {

    int[] preSum;
    int sum;
    public Solution(int[] w) {
        preSum = new int[w.length];
        this.sum = 0;
        for (int i = 0; i < w.length; i++) {
            this.sum += w[i];
            this.preSum[i] = sum; 
        }
    }
    
    public int pickIndex() {
        int cur = (int)(Math.random() * this.sum + 1);
        int l = 0;
        int r = this.preSum.length - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (preSum[mid] == cur) {
                return mid;
            } else if (cur < preSum[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } 
        return l;
    }
}
