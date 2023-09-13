#include <bits/stdc++.h>
using namespace std;

int N, c[300005], ans[300005];
set<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> c[i];
	for (int i = N; i >= 1; i--)
	{
		auto iter = st.lower_bound(2 * c[i]);
		if(iter != st.end())
			ans[i] = (*iter <= 3 * c[i]);
		st.insert(c[i]);
	}
	for (int i = 1; i <= N; i++)
		cout << (ans[i] ? "Yes" : "No") << " \n"[i == N];
}
