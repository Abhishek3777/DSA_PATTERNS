#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    // loop from 2 to sqrt n
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    // print all prime numbers
    cout << "Prime numbers upto " << n << endl;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
            cout << i << " ";
    }
    cout << endl;
}

int main()
{

    int n = 50;
    sieveOfEratosthenes(n);

    return 0;
}