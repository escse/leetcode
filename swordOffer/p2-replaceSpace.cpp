class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = count_if(str, str+length, [](char c){return c == ' ';});
        int new_len = length + 2 * count;
        str[new_len] = '\0';
        char *p1 = str + new_len - 1;
        char *p2 = str + length - 1;
        while (p1 != p2) {
            if (*p2 != ' ') {
                *p1 = *p2;
                --p1;
                --p2;
                continue;
            }
            *(p1--) = '0';
            *(p1--) = '2';
            *(p1--) = '%';
            --p2;
        }
	}
};