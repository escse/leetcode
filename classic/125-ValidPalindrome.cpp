// 3.1 Valid Palindrome
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), tolower);
        auto left = s.begin();
        auto right = prev(s.end());
        while (left < right) {
            while (!isalnum(*left)) ++left;
            while (!isalnum(*right)) --right;
            if (*left != *right) return false;
            ++left;
            --right;
        }
        return true;
    }
};


int main(int argc, char const *argv[]) {
    std::cout << Solution().isPalindrome("asdsa");
    return 0;
}
