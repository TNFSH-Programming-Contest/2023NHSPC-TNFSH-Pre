#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, c[2005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> c[i];
	for (int i = 1; i <= N; i++)
	{
		bool found = 0;
        for (int j = i + 1; j <= N; j++)
            if(2 * c[i] <= c[j] && c[j] <= 3 * c[i])
                found = 1;
		cout << (found ? "Yes" : "No") << " \n"[i == N];
	}
}
