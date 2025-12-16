class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;

        // 1) 找最小值位置 pivot
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[n - 1]) right = mid;
            else left = mid + 1;
        }
        int pivot = left;

        // 2) 决定在哪一段二分
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            left = pivot;
            right = n - 1;
        } else {
            left = 0;
            right = pivot - 1;
        }

        // 3) 标准二分（允许 right 变成 -1，不会越界）
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
}


/*
    一次二分
    旋转数组有个性质：
    第一段所有值大于 > last
    第二段所有值 < last
*/

class Solution {
    public int search(int[] nums, int target) {
        int last = nums[nums.length - 1];
        int left = -1;
        int right = nums.length - 1; // 开区间 (-1, n-1)
        while (left + 1 < right) { // 开区间不为空
            int mid = (left + right) >>> 1;
            int x = nums[mid];
            if (target > last && x <= last) { // target 在第一段，x 在第二段
                right = mid; // 下轮循环去左边找
            } else if (x > last && target <= last) { // x 在第一段，target 在第二段
                left = mid; // 下轮循环去右边找
            } else if (x >= target) { // 否则，x 和 target 在同一段，这就和方法一的 lowerBound 一样了
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[right] == target ? right : -1;
    }
}