#include "testlib.h"
using namespace std;

const long long maxNM = 2000;

int main()
{
	registerValidation();
	int N = inf.readInt(1, maxNM);
	inf.readSpace();
	int M = inf.readInt(1, maxNM);
	inf.readEoln();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char c = inf.readChar();
			ensure(c == '.' || c == '#');
		}
		inf.readEoln();
	}
	inf.readEof();

	return 0;
}
