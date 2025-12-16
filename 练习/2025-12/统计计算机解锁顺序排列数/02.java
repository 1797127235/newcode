class Solution {
    public int countPermutations(int[] complexity) {
        int n = complexity.length;
        int mod = (int)(1e9 + 7);
        int mn = Integer.MAX_VALUE;
        for(int num : complexity){
            mn = Math.min(mn, num);
        }

        if(complexity[0] != mn){
            return 0;
        }
        int cnt = 0;
        for(int num : complexity){
            if(num == mn){
                cnt++;
            }
            if(cnt > 1)
            {
                return 0;
            }
        }
        long ans = 1;

        for(int i = 1; i < n; i++)
        {
            ans = (ans * i) % mod;
        }

        return (int)ans;
    }
}