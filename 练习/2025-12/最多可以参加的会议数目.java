class Solution {
    public int maxEvents(int[][] events) {
        int n = events.length;
        int mx = 0;
        for(int[] event : events) {
            mx = Math.max(mx, event[1]);
        }
        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        int i = 0;
        for(int day = 1; day <= mx; day++) {
            while(i < n && events[i][0] == day) {
                pq.offer(events[i][1]);
                i++;
            }
            while(!pq.isEmpty() && pq.peek() < day) {
                pq.poll();
            }

            if(!pq.isEmpty()) {
                pq.poll();
                ans++;
            }
        }

        return ans;

    }
}