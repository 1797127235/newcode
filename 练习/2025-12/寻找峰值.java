class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int left = 0, right = n - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] < nums[mid + 1]){
                left = mid + 1;
            }else if(nums[mid] > nums[mid + 1]){
                right = mid;
            }
        }
        return left;
    }
}