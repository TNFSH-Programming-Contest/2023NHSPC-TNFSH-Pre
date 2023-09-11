#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxNQ = 1'500'000, maxC = 1'000'000'000;
int main()
{
	registerValidation();

	int N = inf.readInt(1, maxNQ);
	inf.readSpace();
	int Q = inf.readInt(1, maxNQ);
	inf.readEoln();
	for (int i = 1; i <= Q; i++)
	{
		inf.readInt(1, N);
		inf.readSpace();
		inf.readInt(1, 1000'000'000);
		inf.readEoln();
	}
	inf.readEof();

	return 0;
}
