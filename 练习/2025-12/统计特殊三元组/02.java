class Solution {
    public int specialTriplets(int[] nums) {
        int n = nums.length;
        int mod = 1_000_000_007;
        int ans = 0;
        Map<Integer, Integer> suf = new HashMap<>();

        for(int num : nums) {
            suf.put(num, suf.getOrDefault(num, 0) + 1);
        }

        Map<Integer, Integer> pre = new HashMap<>();
        for(int j = 0; j < n; j++) {
            suf.put(nums[j], suf.get(nums[j]) - 1);

            ans = (ans + pre.getOrDefault(nums[j] * 2, 0) * suf.getOrDefault(nums[j] * 2, 0)) % mod;
            pre.put(nums[j], pre.getOrDefault(nums[j], 0) + 1);
        }
        return ans;
    }
}