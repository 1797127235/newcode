class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        int ans = 0;
        Map<Integer,Integer> row_min = new HashMap<>();
        Map<Integer,Integer> row_max = new HashMap<>();
        Map<Integer,Integer> col_min = new HashMap<>();
        Map<Integer,Integer> col_max = new HashMap<>();

        for(int[] building : buildings){
            int x = building[0];
            int y = building[1];
            row_min.put(x, Math.min(row_min.getOrDefault(x, Integer.MAX_VALUE), y));
            row_max.put(x, Math.max(row_max.getOrDefault(x, Integer.MIN_VALUE), y));
            col_min.put(y, Math.min(col_min.getOrDefault(y, Integer.MAX_VALUE), x));
            col_max.put(y, Math.max(col_max.getOrDefault(y, Integer.MIN_VALUE), x));
        }

        for(int[] building : buildings)
        {
            int x = building[0];
            int y = building[1];
            boolean f1 = (x > col_min.get(y) && x < col_max.get(y));
            boolean f2 = (y > row_min.get(x) && y < row_max.get(x));

            if(f1 && f2)
            {
                ans++;
            }
        }
        return ans;
    }
}