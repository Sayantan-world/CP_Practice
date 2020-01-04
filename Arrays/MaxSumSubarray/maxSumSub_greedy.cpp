/*
 * AUTHOR : Sayanatan Pal
 * DATE : 04.01.2020
 * Given an array, find the max sum of subarray and also the start and end index of the subarray  --> O(n)
 * Greedy Method
 */

#include <bits/stdc++.h>
using namespace std;

const int Nmax = 10001;
int first=0,last=0;//start and end

long long maxSumSubarray(int a[], int n) {
        long long sum = 0, ans = a[0];
        for(int i = 0; i < n; i++) {
                sum += a[i];
                if(sum > ans) {
                        if(!first) { first=i;}
                        ans = sum;
                        last=i;
                }

                //is sum is less than zero start afresh
                if(sum < 0) {
                        sum = 0;
                        first=0;
                }
        }
        return ans;
}

int main()
{
        int n, a[Nmax];
        cout << "Array Size : ";
        cin >> n;
        cout << "Enter elements : ";
        for(int i = 0; i < n; i++)
                cin >> a[i];
        cout << maxSumSubarray(a, n) << endl;
        cout << "Range is (" << first << "," << last << ")" << endl;
        return 0;
}
