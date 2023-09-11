#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int C = 1'000'000'000;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1);

	int N = atoi(argv[1]);

	cout << N << '\n';
	vector<int> v;
	for (int i = 1; i <= N; i++)
		v.emplace_back(rnd.next(1, C / 2) * 2);
	for (int i = 1; i <= N / 2; i++)
		v[i]++;
	shuffle(v.begin(), v.end());
	for (int i = 1; i <= N; i++)
		cout << v[i - 1] << " \n"[i == N];
}
