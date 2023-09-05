class Solution {
    fun solution(targets: Array<IntArray>): Int {
        var answer: Int = 0

        targets.sortBy {
            it[0]
            it[1]
        }
//        lateinit var cur: IntArray
        var prev: IntArray = IntArray(2)

        targets.forEach {
            if(prev[1] <= it[0]){
                prev = it
                answer++
            }
        }
        return answer
    }
}