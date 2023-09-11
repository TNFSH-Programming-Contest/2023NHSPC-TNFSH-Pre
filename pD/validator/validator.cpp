#include "testlib.h"
using namespace std;

const int maxNQ = 200'000, maxC = 1'000'000'000;

int main()
{
	registerValidation();

	int N = inf.readInt(1, maxNQ, "N");
	inf.readSpace();
	int Q = inf.readInt(1, maxNQ, "Q");
	inf.readEoln();

	for (int i = 1; i <= N; i++)
	{
		inf.readDouble(1, maxC, "c_i");
		if (i == N)
			inf.readEoln();
		else
			inf.readSpace();
	}

	for (int i = 1; i <= Q; i++)
	{
		int t = inf.readInt(1, 2, "type");
		inf.readSpace();
		if (t == 1)
			inf.readInt(1, maxC, "d");
		else
		{
			inf.readInt(0, N - 1, "p");
			inf.readSpace();
			inf.readInt(1, maxC, "c");
		}
		inf.readEoln();
	}
	inf.readEof();

	return 0;
}
