/*
    Levenshtein distance

    # Examples

        $ ./levenshtein ABCDEFG ACEG
        Levenshtein Distance: 3

        $ ./levenshtein ABCDEFG AZCPEGM
        Levenshtein Distance: 4
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



size_t levenshtein(const string& x, const string& y) {
    auto m{ x.size() };
    auto n{ y.size() };
    vector<size_t> dp(n + 1, 0);
    for (size_t i = 1; i < n; i++)
    {
        dp[i] = i;
    }

    size_t s, e;
    char p, q;

    for (size_t i = 1; i <= m; i++)
    {
        s = i - 1;
        e = i;
        p = x[i - 1];
        for (size_t j = 1; j <= n; j++)
        {
            q = y[j - 1];
            e = min({ e + 1, dp[j] + 1, s + (p == q ? size_t{0} : size_t{1}) });
            s = dp[j];
            dp[j] = e;
        }

    }

    return dp[n];
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Please provide two strings!" << endl;
        return 1;
    }
    string x = argv[1];
    string y = argv[2];
    auto res = levenshtein(x, y);
    cout << "Levenshtein Distance: " << res << endl;
}