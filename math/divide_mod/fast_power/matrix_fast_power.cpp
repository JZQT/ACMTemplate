// 矩阵快速幂模板
// 
// 题意：
// 斐波那契数列为f(0) = 0, f(1) = 1, ..., f(n) = f(n-1) + f(n-2)
// 给一个整数n，求f(n)的值对MOD求模的结果
// 
// 数据：
// n 大小在64位整型范围内
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long Long;

const Long MATN = 2;
const Long MOD = 10000;

struct matrix       //矩阵结构体
{
    Long n, m;               //矩阵大小
    Long mat[MATN][MATN];
    matrix(void): n(0), m(0) {}
    matrix(Long _n, Long _m): n(_n), m(_m)
    {
        memset(mat, 0, sizeof(mat));
    }
    void Unit(Long unit)         //将矩阵转换为单位矩阵
    {
        n = m = unit;
        for (Long i=0; i<n; ++i)
            for (Long j=0; j<m; ++j)
                mat[i][j] = i == j ? 1 : 0;
    }
};

matrix init, coef;  //定义初值矩阵和系数矩阵
Long n;

void InitRead();

void DataProcess();

matrix MulMod(matrix a, matrix b, Long mod);            //矩阵乘法

matrix MatrixFastPow(matrix base, Long n, Long mod);    //矩阵快速幂

int main()
{
    while (~scanf("%lld", &n))
    {
        if (n == -1) break;
        InitRead();
        DataProcess();
    }
    return 0;
}

void InitRead()
{
    init.n = 1;
    init.m = 2;
    init.mat[0][0] = 0;
    init.mat[0][1] = 1;
    coef.n = coef.m = 2;
    coef.mat[0][0] = 0;
    coef.mat[0][1] = coef.mat[1][0] = coef.mat[1][1] = 1;
    return;
}

void DataProcess()
{
    matrix ans = MulMod(init, MatrixFastPow(coef, n, MOD), MOD);
    printf("%lld\n", ans.mat[0][0]);
    return;
}

matrix MulMod(matrix a, matrix b, Long mod)
{
    matrix ans(a.n, b.m);
    for (int i=0; i<ans.n; ++i)
    {
        for (int j=0; j<ans.m; ++j)
        {
            ans.mat[i][j] = 0;
            for (int k=0; k<a.m; ++k)
            {
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
            ans.mat[i][j] %= mod;
        }
    }
    return ans;
}

matrix MatrixFastPow(matrix base, Long n, Long mod)
{
    matrix ans;
    ans.Unit(base.n);
    while (n != 0)
    {
        if (n & 1) ans = MulMod(ans, base, mod);
        n >>= 1;
        base = MulMod(base, base, mod);
    }
    return ans;
}

