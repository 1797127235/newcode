class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int n = happiness.length;
        long ans = 0;
        int cnt = 0;
        Arrays.sort(happiness);
        for(int i = n - 1; i >= 0; i--) {
            if(happiness[i] <= cnt) {
                break;
            }
            ans = ans + happiness[i] - cnt;
            cnt++;
            if(cnt == k) {
                break;
            }
        }

        return ans;
    }
}