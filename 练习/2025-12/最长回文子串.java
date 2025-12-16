class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        String res = s.substring(0, 1);

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++)
            {
                if(s.charAt(i) == s.charAt(j)){
                    if(j - i == 1 || dp[i + 1][j - 1]){
                        dp[i][j] = true;
                        if(j - i + 1 > res.length()){
                            res = s.substring(i, j + 1);
                        }
                    }
                }
            }
        }
        return res;
    }
}