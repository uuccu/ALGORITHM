class Solution {
    fun majorityElement(nums: IntArray): Int {
        var map = mutableMapOf<Int,Int>()

        nums.forEach{ it->
            map.set(it, map.getOrDefault(it,0) + 1)
        }
        
        var max = 0
        var maxKey = 0
        map.forEach{ (key, value) ->
            if(value > max){
                max = value
                maxKey = key
            }
        }
        return maxKey
    }
}