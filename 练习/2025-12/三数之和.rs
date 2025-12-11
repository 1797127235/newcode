impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut res: Vec<Vec<i32>> = Vec::new();
        nums.sort_unstable();
        for i in 0..n {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            let mut l = i + 1;
            let mut r = n - 1;
            while l < r {
                if l > i + 1 && nums[l] == nums[l - 1] {
                    l += 1;
                    continue;
                }
                if r < n - 1 && nums[r] == nums[r + 1] {
                    r -= 1;
                    continue;
                }
                let sum = nums[i] + nums[l] + nums[r];
                if sum == 0 {
                    res.push(vec![nums[i], nums[l], nums[r]]);
                    l += 1;
                    r -= 1;
                } else if sum < 0 {
                    l += 1;
                } else {
                    r -= 1;
                }
            }


        }
        res
    }
}