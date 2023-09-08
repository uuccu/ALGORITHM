class Solution {
    fun solution(name: Array<String>, yearning: IntArray, photo: Array<Array<String>>): IntArray {
        var answer: IntArray = IntArray(photo.size)
        
        val map = mutableMapOf<String,Int>()
        name.forEachIndexed{ index, i ->
            map.set(i, yearning[index])
        }
        photo.forEachIndexed{index, subArray ->
            var sum = 0
            subArray.forEach{ it ->
                sum += map.getOrDefault(it,0)
            }
            answer[index] = sum
        }
        
        
        
        return answer
    }
}