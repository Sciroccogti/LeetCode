/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/comments/36497
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    double ret;
    int l = (nums1Size + nums2Size + 1) / 2, r = (nums1Size + nums2Size + 2) / 2;
    return (findKth(nums1, 0, nums1Size, nums2, 0, nums2Size, l) + findKth(nums1, 0, nums1Size, nums2, 0, nums2Size, r)) / 2.0;
}

int findKth(int *nums1, int i, int s1, int *nums2, int j, int s2, int k)
{
    if (i >= s1)
    {
        return nums2[j + k - 1];
    }
    if (j >= s2)
    {
        return nums1[i + k - 1];
    }
    if (k == 1)
    {
        return nums1[i] > nums2[j] ? nums2[j] : nums1[i]; // min
    }
    int maxVal = nums1[s1 - 1] > nums2[s2 - 1] ? nums1[s1 - 1] : nums2[s2 - 1]; // max
    int midVal1 = (i + k / 2 - 1 < s1) ? nums1[i + k / 2 - 1] : maxVal;
    int midVal2 = (j + k / 2 - 1 < s2) ? nums2[j + k / 2 - 1] : maxVal;
    if (midVal1 < midVal2)
    {
        return findKth(nums1, i + k / 2, s1, nums2, j, s2, k - k / 2);
    }
    else
    {
        return findKth(nums1, i, s1, nums2, j + k / 2, s2, k - k / 2);
    }
}
// @lc code=end
