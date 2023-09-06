class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        nums.distinct().forEachIndexed { index, i ->
            nums[index] = i
        }
        return nums.distinct().size
    }
}