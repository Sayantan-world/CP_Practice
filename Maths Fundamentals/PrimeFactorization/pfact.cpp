/*
 * AUTHOR : Sayanatan Pal
 * DATE : 03.01.2020
 * Prime factorization (Primality Test Method [sqrt(n)]) --> O(n*sqrt(n))
 * Link : https://www.geeksforgeeks.org/primality-test-set-1-introduction-and-school-method/
 * NOTE: If you multiply two 32 bit integers, it might be possible that result exceeds the limit of 32 bit and leads to an overflow.
 * Now even if you store it in a long long(64 bit) variable, it has already overflowed and result might be negative.
 * If 1LL is multiplied along with two integer variables, result is converted to long long during calculation of product itself.
 * Thus, avoiding any overflow.
 */

 #include <bits/stdc++.h>
using namespace std;

int f[100], expo[100], len;

void primeFact(int n) {
        if(n == 1) {
                len++;
                f[len] = 2;
                expo[len] = 0;
                return;
        }
        int d = 2;
        while(1LL * d * d <= n && n > 1) {
                int k = 0;
                while(n % d == 0) {
                        k++;
                        n /= d;
                }
                if(k > 0) {
                        len++;
                        f[len] = d;
                        expo[len] = k;
                }
                d++;
        }
        if(n > 1) {
                len++;
                f[len] = n;
                expo[len] = 1;
        }
}

int main()
{
        int input;
        cin >> input;
        primeFact(input);
        for(int i = 1; i <= len; i++) {
                cout << f[i] << " x " << expo[i] << "\n";
        }
        return 0;
}
