#include <bits/stdc++.h>
using namespace std;

#define ss second
#define ff first

int main(){
int T;
	cin>>T;
	while(T--)
	{
		int n, m, k;
		cin>>n>>m>>k;
		vector<int>sub(n);
		for(int i = 0; i<=n-1; i++)
		{
			cin>>sub[i];
		}
		int t[n];
		for(int i = 0; i<=n-1; i++)
		{
			cin>>t[i];
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		for(int i = 0; i<=n-1; i++)
		{
			pair<int, int> p = {t[i], sub[i]};
			pq.push(p);
		}
		pair<int, int> a[m+1] {{0, 0}};
		while(k>0 && !pq.empty())
		{
			pair<int, int> v = pq.top();
			pq.pop();
			if(a[v.ss].ff %2 == 0)
			{
				if((k-v.ff-a[v.ss].ss) >=0)
				{
					k-=(v.ff+a[v.ss].ss);
					a[v.ss].ff++;
					a[v.ss].ss = 0;
				}
			}
			else
			{
				a[v.ss].ff++;
				a[v.ss].ss = v.ff;
			}
		}
		int count = 0;
		for(int i = 1; i<=m; i++)
		{
			if(a[i].ff%2 == 0)
			{
				count+=(a[i].ff/2);
			}
			else
			{
				count+=(a[i].ff/2+1);
			}
		}
		cout<<count<<endl;
	}
    return 0;
}