class Solution {
	val K = 2
    
	fun removeDuplicates(nums: IntArray): Int {
        var i = 0
        val n = nums.size
        var left = 0
        val freq = mutableMapOf<Int,Int>()
        
        while(i < n){
            freq.put(nums[i], freq.getOrDefault(nums[i],0) + 1)
            if( freq.getOrDefault(nums[i],0) <= K){
                nums[left++] = nums[i]
            }
          
            i += 1
        }
        
        return left
    }
}