class Solution {
    public long minCost(String s, int[] cost) {
        int n = s.length();
        long totalcost = 0;
        for (int c : cost) {
            totalcost += c;
        }
        Map<Character, Long> costmap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            long c =cost[i];
            costmap.put(ch,costmap.getOrDefault(ch,0L) + c);
        }

        long ans = totalcost;


        for(Map.Entry<Character,Long> entry : costmap.entrySet()) {
            long currcost = totalcost - entry.getValue();
            ans = Math.min(ans,currcost);
        }

        if(ans == totalcost) {
            return 0;
        }

        return ans;

    }
}