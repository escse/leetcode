class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0, right = rotateArray.size() - 1, mid;
        while (true) {
            if (right - left == 1) return rotateArray[right];
            mid = (left + right) >> 1;
            if (rotateArray[mid] >= rotateArray[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
    }
};