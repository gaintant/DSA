class Solution {
    public long minimumDifference(int[] nums) {
        int n = nums.length / 3;

        long[] left = new long[n + 1];  // Stores max sums of smallest n elements from left
        long sum = 0;

        // Max heap to keep track of largest elements on left side
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < 2 * n; i++) {
            sum += nums[i];
            maxHeap.add(nums[i]);

            // Maintain only n elements in heap
            if (maxHeap.size() > n) {
                sum -= maxHeap.poll();
            }

            if (maxHeap.size() == n) {
                left[i - n + 1] = sum;
            }
        }

        // Now process the right part
        long[] right = new long[n + 1];
        sum = 0;

        // Min heap to keep track of smallest elements on right side
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int i = nums.length - 1; i >= n; i--) {
            sum += nums[i];
            minHeap.add(nums[i]);

            // Maintain only n elements in heap
            if (minHeap.size() > n) {
                sum -= minHeap.poll();
            }

            if (minHeap.size() == n) {
                right[i - n] = sum;
            }
        }

        // Now calculate minimum difference
        long ans = Long.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            ans = Math.min(ans, left[i] - right[i]);
        }

        return ans;
    }
}