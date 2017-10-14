class Solution {
public:
    string reverseVowels(string s) {
        int size = s.size();
        set<char> ss{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = size - 1;
        while (true) {
            while (ss.find(s[i]) == ss.end()) ++i;
            while (ss.find(s[j]) == ss.end()) --j;
            if (i>=j) break;
            cout << s[i] << " " << s[j] << endl;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};


class Solution {
public:
    string reverseVowels(string s) {
        int size = s.size();
        int i = 0, j = size - 1;
        while (true) {
            while (!isVowel(s[i])) ++i;
            while (!isVowel(s[j])) --j;
            if (i>=j) break;
            cout << s[i] << " " << s[j] << endl;
            swap(s[i++], s[j--]);
        }
        return s;
    }
    
    bool isVowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
    }
};


// -%2...