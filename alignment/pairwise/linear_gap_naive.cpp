// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// enum class Operation {
//     Match,
//     Mismatch,
//     Insert,
//     Delete,
// };

// struct AlignmentResult {
//     vector<Operation> operations;
//     int score;
// };

// class Matrix {
//     vector<int> inner;
//     size_t m, n;
// public:
//     Matrix(size_t m, size_t n) : inner{ vector<int>(m * n, 0) }, m{ m }, n{ n } {};
//     int get(size_t i, size_t j) {
//         return inner[i * n + j];
//     }
//     void set(size_t i, size_t j, int val) {
//         inner[i * n + j] = val;
//     }
// };

// size_t align(const string& x, const string& y, int match, int mismatch, int gap) {
//     auto m = x.size();
//     auto n = y.size();
//     Matrix dp(m + 1, n + 1);
//     vector<Operation> res;
//     int t = 0;
//     for (int j = 1; j <= n; j++)
//     {
//         t += gap;
//         dp.set(0, j, t);
//     }
//     t = 0;
//     for (int i = 1; i <= m; i++)
//     {
//         t += gap;
//         dp.set(i, 0, t);
//     }
//     char p, q;

//     for (int i = 1; i <= m; i++)
//     {
//         p = x[i];
//         for (int j = 0; j <= n; j++)
//         {
//             q = y[j];     /* code */
//         }

//     }

// }

// int main() {}