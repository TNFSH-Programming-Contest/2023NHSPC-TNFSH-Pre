#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main()
{
	registerValidation();

	int N = inf.readInt(1, 1000'000'000);
	inf.readEoln();
	for (int i = 1; i <= N; i++)
	{
		inf.readInt(1, 1000'000'000);
		if (i == N)
			inf.readEoln();
		else
			inf.readSpace();
	}
	inf.readEof();

	return 0;
}
