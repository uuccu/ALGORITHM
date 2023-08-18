fun main() {
    val nums1 = intArrayOf(2,0)
    val nums2 = intArrayOf(1)
    val m = 1
    val n = 1

    Solution().merge(nums1, m, nums2, n)

    println(nums1.toList())
}

class Solution {
    fun merge(nums1: IntArray, m: Int, nums2: IntArray, n: Int): Unit {

        var temp: IntArray = nums1.copyOf()

        var index1 = 0
        var index2 = 0

        if (n == 0) {


        } else if (m == 0) {
            repeat(n) {
                nums1[it] = nums2[it]
            }
        } else {
            repeat(m + n) {
                val num1 = temp[index1]
                if(index2 >= n) {
                    nums1[index1 + index2] = num1
                    index1++
                    return@repeat
                }
                val num2 = nums2[index2]

                if (index1 >= m || num2 < num1) {
                    nums1[index1 + index2] = num2
                    index2++
                } else {
                    nums1[index1 + index2] = num1
                    index1++
                }
            }
        }

    }
}