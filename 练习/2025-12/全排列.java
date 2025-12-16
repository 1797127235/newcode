class Solution {
    void dfs(int [] nums, boolean[] used, List<Integer> path, List<List<Integer>> res) {
        if(path.size() == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }

        for(int i = 0; i < nums.length; i++) {
            if(used[i]) continue;

            used[i] = true;
            path.add(nums[i]);
            dfs(nums, used, path, res);
            path.remove(path.size() - 1);
            used[i] = false;
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        int n = nums.length;
        boolean[] used = new boolean[n];
        List<List<Integer>> res = new ArrayList<>();
        dfs(nums, used, new ArrayList<>(), res);
        return res;
    }
}