class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;

        //移除区间的最小数量，剩余区间不重叠
        Arrays.sort(intervals,(a,b) -> Integer.compare(a[1], b[1]));
        int ans = 0;
        if(n == 0) return 0;
        int ed = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < ed) {
                ans++;
            } else {
                ed = Math.max(ed, intervals[i][1]);
            }
        }
        return ans;
    }
}