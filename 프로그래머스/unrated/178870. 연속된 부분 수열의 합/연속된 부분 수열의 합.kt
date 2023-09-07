class Solution {
    fun solution(sequence: IntArray, k: Int): IntArray {

        var right = sequence.size - 1
        var left = sequence.size - 1
        var sum = sequence[left]
        

        while (true) {
            if (k < sum) {
                sum -= sequence[right--]
            } else if (k == sum) {
                break
            }else {
                sum += sequence[--left]
            }
        }

        while (left > 0 && right > 0) {
            val r1 = sequence[left]
            val r2 = sequence[left - 1]
            val l1 = sequence[right]
            val l2 = sequence[right - 1]

            if (r1 == r2 && l1 == l2 && r2 == l2) {
                left--
                right--
            } else {
                break
            }
        }

        return intArrayOf(left, right)
    }
}