#include <stdio.h>
#include <assert.h>
#include <vector>
using namespace std;
struct DLX_Excat_Partial
{
    // number of row & col, and current idx = vector.size() - 1
    // only cover k columns exactly
    int n, m, k, idx;
    vector<int> first, sz, stk;
    vector<int> L, R, U, D; // 4 direction
    vector<int> col, row;
    // other information please add here.
    
    // answer area, please add here.
    int solution_count;
    vector<bool> status;

    // normal area.
    void init(const int &r, const int &c, const int &_k)
    {
        assert(_k < c);
        n = r, m = c, k = _k;
        first.clear(), sz.clear(), stk.clear();
        L.clear(), R.clear(), U.clear(), D.clear();
        col.clear(), row.clear();
        first.resize(n + 1), sz.resize(m + 1);
        L.resize(m + 1), R.resize(m + 1), U.resize(m + 1), D.resize(m + 1);
        col.resize(m + 1), row.resize(m + 1);

        solution_count = 0, status.resize(n + 1);

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
        // use R[0] > k || R[0] == 0 if we only need first k columns repeatly covered.
        if (R[0] > k || R[0] == 0) 
        {
            // output/update answer here if necessary.
            ++solution_count;
            return 1;
        }
        int c = R[0];
        // use (i != 0 && i <= k) at for looping
        // if we only need first k columns repeatly covered.
        for (int i = R[0]; i && i <= k; i = R[i])
            if (sz[i] < sz[c])
                c = i;
        remove(c);
        for (int i = D[c]; i != c; i = D[i])
        {
            stk.push_back(row[i]); // currently searching row[i]
            for (int j = R[i]; j != i; j = R[j])
                remove(col[j]);

            // use if(dance(...)) return 1; when only one solution is needed.
            // if (dance())
                // return 1;
            dance();
            for (int j = L[i]; j != i; j = L[j])
                recover(col[j]);
            stk.pop_back();
        }
        recover(c);
        return 0;
    }
    int grid_length;

    void init_queen(const int& _n) 
    { 
        grid_length = _n;
        init(_n * _n, 6 * _n - 2, _n); 
    }
    void insert_queen(const int& r, const int& c)
    {
        int row = (r - 1) * grid_length + c;
        insert(row, r), insert(row, grid_length + c);
        insert(row, 2 * grid_length + (r + c - 1));
        insert(row, (4 * grid_length - 1) + (r - c + grid_length));
    }

};
DLX_Excat_Partial dlx;
int n;
int main()
{
    scanf("%d", &n);
    dlx.init_queen(n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dlx.insert_queen(i, j);
    dlx.dance();
    printf("%d", dlx.solution_count);
}