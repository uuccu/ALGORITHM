
class Solution {
    fun removeElement(nums: IntArray, `val`: Int): Int {
        var ans = 0

        val temp = nums.sortedWith(
            compareBy(
                { it == `val` },
                )
        )
        ans = nums.count { it == `val` }

        temp.forEachIndexed { index,it ->
            nums[index] = temp[index]
        }
        return nums.size - ans
    }
}