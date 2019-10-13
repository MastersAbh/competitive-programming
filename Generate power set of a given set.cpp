#include <bits/stdc++.h>
using namespace std;

/*

Approach:

For a given set S, the power set can be found by generating all binary numbers between 0 to 2n-1 where n is the size of the given set.

For example, for set S {x, y, z}, we generate binary numbers from 0 to 23-1 and for each number generated, the corresponding set can be found by considering set bits in the number.

0 = 000 = {}
1 = 001 = {z}
2 = 010 = {y}
3 = 011 = {y, z}
4 = 100 = {x}
5 = 101 = {x, z}
6 = 110 = {x, y}
7 = 111 = {x, y, z}

*/

void findPowerSet(vector<int> const &S, int n)
{
    // N stores total number of subsets
    int N = pow(2, n);

    // generate each subset one by one
    for (int i = 0; i < N; i++)
    {
		// check every bit of i
        for (int j = 0; j < n; j++)
        {
            // if j'th bit of i is set, print S[j]
            if (i & (1 << j))
                cout << S[j] << " ";
        }
        cout << endl;
	}
}

int main()
{
    vector<int> S = { 1, 2, 3 };
	int n = S.size();

    findPowerSet(S, n);
}
