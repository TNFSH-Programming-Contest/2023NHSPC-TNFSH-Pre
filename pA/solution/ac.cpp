#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int a, c[2] = {0, 0};
	while (N--)
	{
		cin >> a;
		c[a & 1]++;
	}
	cout << (c[1] > c[0] ? "Alice\n" : "Bob\n");
}
