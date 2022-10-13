#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct DLX_Excat
{
    // number of row & col, and current idx = vector.size() - 1
    int n, m, idx;
    vector<int> first, sz, stk;
    vector<int> L, R, U, D; // 4 direction
    vector<int> col, row;
    // other information please add here.
    int solution_count;
    // answer area, please add here.
    vector<int> ans;
    // normal area.
    void init(const int &r, const int &c)
    {
        n = r, m = c;
        first.clear(), sz.clear(), stk.clear();
        L.clear(), R.clear(), U.clear(), D.clear();
        col.clear(), row.clear();

        solution_count = 0, ans.clear();

        first.resize(n + 1), sz.resize(m + 1);
        L.resize(m + 1), R.resize(m + 1), U.resize(m + 1), D.resize(m + 1);
        col.resize(m + 1), row.resize(m + 1);
        for (int i = 0; i <= m; ++i)
        {
            L[i] = i - 1, R[i] = i + 1;
            U[i] = D[i] = i;
        }

        L[0] = m, R[m] = 0;
        idx = m + 1;
    }
    // insert complexity : O(1)
    // other information is preserved.
    void insert(const int &r, const int &c)
    {
        col.push_back(c), row.push_back(r);
        // add other information like : w.push_back(W);

        ++sz[c];
        U.push_back(c), D.push_back(D[c]);
        U[D[c]] = idx, D[c] = idx;

        if (!first[r])
        {
            first[r] = idx;
            L.push_back(idx), R.push_back(idx);
        }
        else
        {
            R.push_back(R[first[r]]);
            L[R[first[r]]] = idx;
            L.push_back(first[r]);
            R[first[r]] = idx;
        }
        ++idx;
    }
    // remove complexity : O(m)
    void remove(const int &c)
    {
        L[R[c]] = L[c], R[L[c]] = R[c];
        for (int i = D[c]; i != c; i = D[i])
            for (int j = R[i]; j != i; j = R[j])
                U[D[j]] = U[j], D[U[j]] = D[j], --sz[col[j]];
    }
    // recover complexity : O(m)
    void recover(const int &c)
    {
        for (int i = U[c]; i != c; i = U[i])
            for (int j = L[i]; j != i; j = L[j])
                U[D[j]] = D[U[j]] = j, ++sz[col[j]];
        L[R[c]] = R[L[c]] = c;
    }
    // other information can be added to parameter or function
    bool dance()
    {
        if (!R[0])
        {
            // output/update answer here if necessary.
            // for (size_t i = 0; i < stk.size(); ++i)
                // printf("%d ", stk[i]);
            // if (!solution_count)
                // ans = stk;
            ++solution_count;
            return 1;
        }
        int c = R[0];
        for (int i = R[0]; i; i = R[i])
            if (sz[i] < sz[c])
                c = i;
        remove(c);
        for (int i = D[c]; i != c; i = D[i])
        {
            stk.push_back(row[i]); // currently searching row[i]
            for (int j = R[i]; j != i; j = R[j])
                remove(col[j]);

            // use if(dance(...)) return 1; when only one solution is needed.
            dance();

            for (int j = L[i]; j != i; j = L[j])
                recover(col[j]);
            stk.pop_back();
        }
        recover(c);
        return 0;
    }
    // sudoku area
    int g_length, whole_length, area;
    void init_sudoku(int g) 
    { 
        g_length = g, whole_length = g * g;
        int k = whole_length;
        area = k * k;
        init(k * k * k, k * k * 4);
    }
    void _insert_sudoku(int r, int c, int _n)
    {
        int g = ((r - 1) / g_length) * g_length + ((c - 1) / g_length) + 1;
        int row = (r - 1) * area + (c - 1) * whole_length + _n;
        insert(row, (r - 1) * whole_length + c);
        insert(row, area + (r - 1) * whole_length + _n);
        insert(row, area * 2 + (c - 1) * whole_length + _n);
        insert(row, area * 3 + (g - 1) * whole_length + _n);
    }
    // still need to insert even if n == 0
    void insert_sudoku(int r, int c, int _n)
    {
        for (int v = 1; v <= whole_length; ++v)
            if ((_n == 0) || (_n == v))
                _insert_sudoku(r, c, v);
    }
    // use after dance
    void output_ans()
    {
        printf("%d\n", solution_count);
        /*
        vector<int> sudoku_ans;
        sudoku_ans.resize(area);
        int idx = 0;
        for (int i = 0; i < ans.size(); ++i)
            sudoku_ans[(ans[i] - 1) / whole_length] = (ans[i] - 1) % whole_length + 1;
            
        for (int i = 1; i <= whole_length; ++i, putchar('\n'))
            for (int j = 1; j <= whole_length; ++j, putchar(' '))
                printf("%d", sudoku_ans[idx++]);
        */
    }
}dlx;
int x;
int main()
{
    dlx.init_sudoku(3);
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
            scanf("%d", &x), dlx.insert_sudoku(i, j, x);
    dlx.dance();
    dlx.output_ans();
}