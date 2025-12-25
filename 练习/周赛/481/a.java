class Solution {
    public int mirrorDistance(int n) {
        String str = String.valueOf(n);
        StringBuilder sb = new StringBuilder(str);
        sb.reverse();
        int reversedNum = Integer.parseInt(sb.toString());
        return Math.abs(n - reversedNum);
    }
}