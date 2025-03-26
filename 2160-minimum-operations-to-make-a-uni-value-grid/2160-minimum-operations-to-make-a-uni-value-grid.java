class Solution {
    public int minOperations(int[][] grid, int x) {int[] nums = Arrays.stream(grid)
                           .flatMapToInt(Arrays::stream)
                           .sorted()
                           .toArray(); // Convert to array to avoid consuming stream multiple times
        
        int r = nums[0] % x; // Remainder reference
        int n = nums.length;

        // Check if all elements have the same remainder when divided by x
        if (Arrays.stream(nums).anyMatch(a -> a % x != r)) return -1;

        // Find median
        int median = nums[n / 2];

        // Calculate the number of operations
        return Arrays.stream(nums)
                     .map(a -> Math.abs((a - median) / x))
                     .sum();
    }
}