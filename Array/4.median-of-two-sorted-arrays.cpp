/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
            vector<int> nums;
            //nums.insert(nums.end(), nums1.begin(), nums1.end());
            //nums.insert(nums.end(), nums2.begin(), nums2.end());
            int i=0,j=0;
            while(i<nums1.size()&&j<nums2.size()){
                if(nums1[i]<=nums2[j]){
                    nums.push_back(nums1[i]);
                    i++;
                }
                else{
                    nums.push_back(nums2[j]);
                    j++;
                }
            }
            if(i>=nums1.size()){
                nums.insert(nums.end(), nums2.begin()+j, nums2.end());
            }
            else{
                nums.insert(nums.end(), nums1.begin()+i, nums1.end());
            }

            int total = nums.size();
            if(total%2 == 1){
                return nums[total/2];
            }
            else{
                return (nums[total/2-1]+nums[total/2])/2.0;
            }
    }
};
// @lc code=end
