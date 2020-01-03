/*
 * AUTHOR : Sayanatan Pal
 * DATE : 03.01.2020
 * Prime factorization  --> O(n*log(n))
 * Seive of Eratosthenes Method
 * Classical way - https://www.geeksforgeeks.org/sieve-of-eratosthenes/
 * Efficient Way - geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/
 */

 #include <bits/stdc++.h>
using namespace std;

const int Nmax = 100001;

bool isPrime[Nmax];

void sieveOfEratosthenes(int n) {

        //make an array which has all numbers marked as prime(true)
        for(int i = 2; i <= n; i++)
                isPrime[i] = true;

        for(int i = 2; i <= n/2; i++)
                if(isPrime[i] == true)
                        for(int j = i * 2; j <= n; j += i)
                                isPrime[j] = false;
}

int main()
{
        sieveOfEratosthenes(2);
        for(int i = 2; i <= 100; i++)
                if(isPrime[i] == true)
                        cout << i << " ";
        return 0;
}
