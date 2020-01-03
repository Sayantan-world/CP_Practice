/*
 * AUTHOR : Sayanatan Pal
 * DATE : 03.01.2020
 * Prime number check (Primality Test Method [sqrt(n)]) --> O(sqrt(n))
 * Link : https://www.geeksforgeeks.org/primality-test-set-1-introduction-and-school-method/
 */

 #include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
        // Corner cases
        if (n <= 1) return false;
        if (n <= 3) return true;

        // This is checked so that we can skip
        // middle five numbers in below loop
        if (n%2 == 0 || n%3 == 0) return false;

        for (int i=5; i<sqrt(n); i=i+6)
                if (n%i == 0 || n%(i+2) == 0)
                        return false;

        return true;
}


// Driver Program
int main()
{
        int input;
        cin >> input;
        isPrime(input) ? cout << "true\n" : cout << "false\n";
        return 0;
}
