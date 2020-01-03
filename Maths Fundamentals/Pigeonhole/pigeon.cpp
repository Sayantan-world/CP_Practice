/*
 * AUTHOR : Sayanatan Pal
 * DATE : 04.01.2020
 * Given an integer n, find the smallest number consisting of the digits 0 and 1 which is divisible by n  --> O(n)
 * Works on the basis of Pigeonhole Principle
 */

#include <bits/stdc++.h>
using namespace std;

const int Nmax = 100005;
int fr[Nmax];//initialized with zero

void findNumber(int n) {
        int cur_rem = 0;
        for(int i = 1; i <= n; i++) {

                //We are storing mod value as its saving space
                cur_rem = (cur_rem * 10 + 1) % n;

                //If the rem is zero then print 1 i times and quit
                if(cur_rem == 0) {
                        for(int j = 1; j <= i; j++)
                                cout << 1;
                        return;
                }

                //Chk if there is something
                if(fr[cur_rem] != 0) {

                        //print 1 i-rem times
                        for(int j = 1; j <= i - fr[cur_rem]; j++)
                                cout << 1;

                        //print 0 rem times
                        for(int j = 1; j <= fr[cur_rem]; j++)
                                cout << 0;
                        return;
                }
                fr[cur_rem] = i;
        }
}

int main()
{
        int n;
        cin >> n;
        findNumber(n);
        cout << endl;
        return 0;
}
