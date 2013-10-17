//coin change problem
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 50000
using namespace std;

vector<int> den;
int dp[MAX];
int solve(int cost)
{
	if(cost == 0)
		return 0;
	else if(dp[cost] != -1) return dp[cost];
	else
	{
		int m = MAX, co;
		for(int i = 0; i < den.size(); i++)
		{
			if(cost - den[i] >= 0)
				co = 1 + solve(cost - den[i]);
			m = min(co, m);
		}
		return dp[cost] = m;
	}
}

main()
{
//	vector<int> den;
	den.clear();
	den.push_back(1);
	int n;
	cin >> n;
	while(n--)
	{
		int d; cin >> d;
		den.push_back(d);
	}
	memset(dp, -1, sizeof dp);
	cout << endl << solve(100);
}

