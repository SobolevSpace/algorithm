#include <string>
#include <vector>

using namespace std;

class string_algo {
public:
    int KMP(const string& str, const string& pattern) {
        int m = str.length(), n = pattern.length();
        vector<int> next(n + 1, 0);
        // fill next;
        if (n == 0) return 0;
        next[0] = -1;
        int i = 0, j = -1;
        while (i < n) {
            if (j == -1 || str[i] == pattern[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else j = next[j];
        }
        i = 0, j = 0;
        while (i < m && j < n) {
            if (j == -1 || str[i] == pattern[j]) {
                i++;
                j++;
            }
            else j = next[j];
        }

        if (j < n) return -1;
        else return i - j;
    }

    void manacher(const string& str) {
        string newstr;
        int L = str.length();
        for (int i = 0; i < L; i++) {
            newstr += str[i];
            newstr += '#';//maybe not
        }
        int n = newstr.length(), l = 0, r = -1;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > r) dp[i] = 1;
            else dp[i] = max(dp[l + r - i], r - i);

            while (i + dp[i] < n && i - dp[i] >= 0 && newstr[i + dp[i]] == newstr[i - dp[i]]) {
                dp[i]++;
            }

            if (i + dp[i] - 1 > r) {
                r = i + dp[i] - 1;
                l = i - dp[i] + 1;
            }
        }
        //ans in dp
        //need post process
    }


};

class Trie {
public:
    static const int SIGMA = 26;
    bool isEnd;
    vector<Trie*> child;

    Trie() :isEnd(false), child(SIGMA, nullptr) {}

    void insert(const string& str) {
        Trie* p = this;
        for (int i = 0; i < str.length(); i++) {
            if (p->child[str[i] - 'a'] == nullptr) { //maybe not
                p->child[str[i] - 'a'] = new Trie();
            }
            p = p->child[str[i] - 'a'];
        }
        p->isEnd = true;
    }

    bool find(const string& str) {
        Trie* p = this;
        for (int i = 0; i < str.length() && p; i++) {
            p = p->child[str[i] - 'a'];//maybe not
        }
        return p && p->isEnd;
    }

    bool findPrefix(const string& prefix) {
        Trie* p = this;
        for (int i = 0; i < prefix.length() && p; i++) {
            p = p->child[str[i] - 'a']; //maybe not
        }
        return p != nullptr;
    }
 };