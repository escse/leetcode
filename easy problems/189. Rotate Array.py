// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         ::rotate(nums.begin(), nums.begin()+k, nums.end());   
//     }
// };



class Solution:
    # @param nums, a list of integer
    # @param k, num of steps
    # @return nothing, please modify the nums list in-place.
    def rotate(self, nums, k):
        n = len(nums)
        k = k % n
        nums[:] = nums[n-k:] + nums[:n-k]