#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

enum Operation {
    Match = 1,
    Mismatch = 2,
    Insert = 3,
    Delete = 4,
};

struct AlignmentResult {
    vector<Operation> operations;
    int score;
};

class Matrix {
    vector<int> inner;
    size_t m, n;
public:
    Matrix(size_t m, size_t n) : inner{ vector<int>(m * n, 0) }, m{ m }, n{ n } {};
    int get(size_t i, size_t j) {
        return inner[i * n + j];
    }
    void set(size_t i, size_t j, int val) {
        inner[i * n + j] = val;
    }
};

AlignmentResult align(const string& x, const string& y, int match, int mismatch, int gap) {
    auto m = x.size();
    auto n = y.size();
    Matrix score(m + 1, n + 1);
    Matrix traceback(m + 1, n + 1);

    int t = 0;
    for (int j = 1; j <= n; j++)
    {
        t += gap;
        score.set(0, j, t);
        traceback.set(0, j, Insert);
    }
    t = 0;
    for (int i = 1; i <= m; i++)
    {
        t += gap;
        score.set(i, 0, t);
        traceback.set(i, 0, Delete);
    }
    char p, q;
    int s, tmp;
    Operation op;
    for (int i = 1; i <= m; i++)
    {
        p = x[i - 1];
        for (int j = 1; j <= n; j++)
        {
            q = y[j - 1];
            s = score.get(i - 1, j - 1) + (p == q ? match : mismatch);
            op = p == q ? Match : Mismatch;
            tmp = score.get(i - 1, j) + gap;
            if (tmp > s) {
                s = tmp;
                op = Delete;
            }
            tmp = score.get(i, j - 1) + gap;
            if (tmp > s) {
                s = tmp;
                op = Insert;
            }
            score.set(i, j, s);
            traceback.set(i, j, op);
        }

    }
    vector<Operation> operations;
    int i = m;
    int j = n;
    while (true)
    {
        auto op = (Operation)traceback.get(i, j);
        if (op == 0) {
            break;
        }
        operations.push_back(op);
        switch (op)
        {
        case Match:
        case Mismatch:
            i--;
            j--;
            break;
        case Insert:
            j--;
            break;
        case Delete:
            i--;
            break;
        default:
            break;
        }
    }
    reverse(operations.begin(), operations.end());


    AlignmentResult res{ operations, score.get(m, n) };
    return res;
}

void print_result(AlignmentResult& res, string& x, string& y) {
    string xf{ "" };
    string yf{ "" };
    int i = 0;
    int j = 0;
    for (auto& op : res.operations)
    {
        switch (op)
        {
        case Operation::Match:
        case Operation::Mismatch:
            xf.push_back(x[i]);
            yf.push_back(y[j]);
            i++;
            j++;
            break;
        case Operation::Insert:
            xf.push_back('-');
            yf.push_back(y[j]);
            j++;
        case Operation::Delete:
            xf.push_back(x[i]);
            yf.push_back('-');
            i++;
        default:
            break;
        }
    }
    cout << xf << endl;
    cout << yf << endl;
    cout << "Score: " << res.score << endl;
}

int main(int argc, char* argv[]) {
    // if (argc < 3) {
    //     cout << "Please provide two strings!" << endl;
    //     return 1;
    // }
    string x, y;
    int match, mismatch, gap;
    cout << "First sequence: " << endl;
    cin >> x;
    cout << "Second sequence: " << endl;
    cin >> y;
    cout << "Match score" << endl;
    cin >> match;
    cout << "Mismatch score" << endl;
    cin >> mismatch;
    cout << "Gap penalty" << endl;
    cin >> gap;
    if (gap > 0) {
        gap = -gap;
    }


    auto res = align(x, y, match, mismatch, gap);
    print_result(res, x, y);
}