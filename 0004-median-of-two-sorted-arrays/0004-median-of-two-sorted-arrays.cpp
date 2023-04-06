class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        //전체의 중간지점을 구하자.
        int middlePoint = (len1 + len2 + 1) / 2;


        int median1 = findMedian(nums1, nums2, 0, len1 - 1, 0, len2 - 1, middlePoint);
        if ((len1 + len2) % 2 == 1)return median1;

        //짝수인 경우 한번 더 계산.
        int median2 = findMedian(nums1, nums2, 0, len1 - 1, 0, len2 - 1, middlePoint + 1);
        return (median1 + median2) / 2.0;
    }

    //이게 핵심임.
    int findMedian(vector<int> &nums1, vector<int> &nums2, int l1, int r1, int l2, int r2, int mp) {
        //base case(Conquer)
        if (l1 > r1) {
            return nums2[l2 + mp - 1];
        }
        if (l2 > r2) {
            return nums1[l1 + mp - 1];
        }
        int mid1 = (l1 + r1) / 2, mid2 = (l2 + r2) / 2;

        // Divide
        if (nums1[mid1] <= nums2[mid2]) {
            //중간지점의 크기가 2번째 배열이 크거나 같은 경우.


            if (mp <= (mid1 - l1) + (mid2 - l2) + 1) return findMedian(nums1, nums2, l1, r1, l2, mid2 - 1, mp);
            else return findMedian(nums1, nums2, mid1 + 1, r1, l2, r2, mp - (mid1 - l1) - 1);
        } else {//1번째 배열이 더 큰 경우
            if (mp <= (mid1 - l1) + (mid2 - l2) + 1) return findMedian(nums1, nums2, l1, mid1 - 1, l2, r2, mp);
            else return findMedian(nums1, nums2, l1, r1, mid2 + 1, r2, mp - (mid2 - l2) - 1);
        }
    }
};