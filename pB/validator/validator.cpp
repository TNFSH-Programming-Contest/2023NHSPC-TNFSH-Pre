#include "testlib.h"
using namespace std;

const int maxN = 300'000, maxC = 2'000'000'000;

int main()
{
	registerValidation();
	// about testlib, see https://codeforces.com/blog/entry/18291

	int N = inf.readInt(1, maxN, "N");
	inf.readEoln();

	for (int i = 1; i <= N; i++)
	{
		inf.readInt(0, maxC, "c_i");
		if (i == N)
			inf.readEoln();
		else
			inf.readSpace();
	}
	inf.readEof();

	return 0;
}
