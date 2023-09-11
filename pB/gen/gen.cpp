#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	const int N = atoi(argv[1]), C = atoi(argv[2]);
	cout << N << "\n";
	for (int i = 1; i <= N; i++)
		cout << rnd.next(0, C) << " \n"[i == N];
	return 0;
}
