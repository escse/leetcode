class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        copy(nums1.begin(), nums1.begin() + m, nums1.begin() + n);
        auto it = nums1.begin();
        auto it1 = nums1.begin() + n;
        auto it2 = nums2.begin();
        while (it != nums1.begin() + m + n) {
            if (it1 == nums1.end()) {
                copy(it2, nums2.end(), it);
                break;
            }
            if (it2 == nums2.end()) {
                break;
            }
            if (*it1 < *it2) {
                swap(*it++, *it1++);
            } else {
                swap(*it++, *it2++);
            }
        }
        
    }
};