class Solution {
    static class SegmentNode{
        //longest "OFF" bulbs sequence length in this range so far
        public int max;
        //left border
        public int begin;
        //right border
        public int end;
        //is left border has not "ON" bulb
        public boolean isLeft;
        //is right border has not "ON" bulb
        public boolean isRight;
        public SegmentNode left;
        public SegmentNode right;
        
        public SegmentNode(int max, int begin, int end, boolean isLeft, boolean isRight){
            this.max = max;
            this.begin = begin;
            this.end = end;
            this.isLeft = isLeft;
            this.isRight = isRight;
        }
        
        //returns true if turning bulb on at index spot will be resulted in
        //existance of two turned on bulbs that have exactly K bulbs between them that are all turned off.
        public boolean cutAt(int spot, int k){
            if (max < k) {
                return false;
            }
            // if this range is whole so far (left and right subranges are null or not null in the same time)
            if (left == null){
                //length of left side
                int leftSide = spot - begin-1;
                //length of right side
                int rightSide = end - spot-1;
                //left subrange has "ON" bulb on right side after cut
                left = new SegmentNode(leftSide, begin, spot, isLeft, false);
                //right subrange has "ON" bulb on left side after cut
                right = new SegmentNode(rightSide, spot, end, false, isRight);
                //parent range longest "OFF" bulbs sequence length should be updated after cut
                max = Math.max(leftSide, rightSide);
                return (!isLeft && k == leftSide) || (!isRight && k == rightSide);
            }else{
                boolean result;
                //this cut will be in left or right subrange territory?
                if (left.contains(spot)) {
                    result = left.cutAt(spot, k);
                }else{
                    result = right.cutAt(spot, k);
                }
                
                //parent range longest "OFF" sequence length should be updated after cut
                max = Math.max(left.max, right.max);
                return result;
            }
        }
        
        private boolean contains(int spot){
            return (begin<spot) && (spot<end);
        }
    }
    
    public int kEmptySlots(int[] bulbs, int K) {
        //for whole range before first day we have no "ON" bulbs on left and right side 
        SegmentNode root = new SegmentNode(bulbs.length, 0, bulbs.length+1, true, true);
        for(int i=0; i<bulbs.length; i++){
            int spot = bulbs[i];
            //when we turn "ON" bulb it results in cutting range of "OFF" bulbs to to parts
            boolean result = root.cutAt(spot, K);
            //if result is true, then we succeeded on (i+1)th step
            if (result) {
                return i+1;
            }
            //if longest "OFF" bulbs sequence length is less than K we should give up
            if (root.max < K){
                return -1;
            }
        }
        //we will not reach this line
        return -1;
    }
}