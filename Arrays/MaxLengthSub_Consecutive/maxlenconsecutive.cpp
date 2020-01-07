/*
 * AUTHOR : Sayanatan Pal
 * DATE : 05.01.2020
 * Given an array, find the max length of subarray consisting of consecutive elements --> O(n^2)
 * Example : I/P = 4 1 2 3 6 7 , O/P = 4
 */

#include <bits/stdc++.h>
using namespace std;

const int Nmax = 100001;

//Global
int a[Nmax], n;
bool fr[Nmax];

int longestConsecNumsSubarray() {
        int ans = 0;
        for(int Left = 1; Left <= n; Left++) {

                //Frequency Array update to false
                for(int i = 1; i <= n; i++)
                        fr[i] = false;

                int Min = a[Left], Max = a[Left];

                for(int Right = Left; Right <= n; Right++) {
                        if(fr[a[Right]] == true)
                                break;
                        fr[a[Right]] = true;
                        Min = min(Min, a[Right]);
                        Max = max(Max, a[Right]);
                        if(Right - Left == Max - Min)
                                ans = max(ans, Right - Left + 1);
                }
        }
        return ans;
}

int main()
{
        cout << "Array Size : ";
        cin >> n;
        cout << "Enter elements : ";
        for(int i = 1; i <= n; i++)
                cin >> a[i];
        cout << "Result: " << longestConsecNumsSubarray() << endl;
        return 0;
}
