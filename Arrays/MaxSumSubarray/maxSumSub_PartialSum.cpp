/*
 * AUTHOR : Sayanatan Pal
 * DATE : 05.01.2020
 * Given an array, find the max sum of subarray and also the start and end index of the subarray  --> O(n)
 * Partial Sum Method
 */

#include <bits/stdc++.h>
using namespace std;

const int Nmax = 10001;

long long maxSumSubarray(int a[], int n) {
        if(n == 0)
                return 0;
        long long s[Nmax], ans = a[1], minS = 0;
        s[1] = a[1];

        //make the partial sum array
        for(int i = 2; i <= n; i++)
                s[i] = s[i - 1] + a[i];

        for(int i = 1; i <= n; i++) {
                if(s[i] - minS > ans)
                        ans = s[i] - minS;
                if(s[i] < minS)
                        minS = s[i];
        }
        return ans;
}


int main()
{
        int n, a[Nmax];
        cout << "Array Size : ";
        cin >> n;
        cout << "Enter elements : ";
        for(int i = 1; i <= n; i++)
                cin >> a[i];
        cout << maxSumSubarray(a, n) << endl;
        return 0;
}
