#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

struct Matrix {
    int rows, cols;
    vector<vector<int>> m;

    Matrix(int r, int c, bool identity = false) : rows(r), cols(c) {
        m.assign(r, vector<int>(c, 0));
        if (identity) {
            for (int i = 0; i < min(r, c); i++) {
                m[i][i] = 1;
            }
        }
    }

    Matrix operator+(const Matrix &other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.m[i][j] = (m[i][j] + other.m[i][j]) % MOD;
            }
        }
        return result;
    }

    Matrix operator-(const Matrix &other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.m[i][j] = (m[i][j] - other.m[i][j] + MOD) % MOD;
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.m[i][j] = (result.m[i][j] + m[i][k] * other.m[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    Matrix operator^(long long exp) const {
        Matrix base = *this;
        Matrix result(rows, cols, true); // identidade
        while (exp > 0) {
            if (exp & 1) {
                result = result * base;
            }
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};

bool check(array<int, 3> a, array<int, 3> b){
    for(int i = 0; i < 3; i++){
        if(a[i] == b[i]){
            return false;
        }
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    vector<array<int, 3>> t;

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            for(int k = 1; k <= 3; k++){
                if(i != j && j != k){
                    t.push_back({i, j, k});
                }
            }
        }
    }

    Matrix init(12, 12);

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            init.m[i][j] = check(t[i], t[j]);
        }
    }

    int n;
    cin >> n;

    if(n == 1){
        cout << "12\n";
        return 0;
    }

    init = init ^ (n - 1);

    int sum = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            sum += init.m[i][j];
            if(sum >= MOD){
                sum -= MOD;
            }
        }
    }
    
    cout << sum << '\n';

}
