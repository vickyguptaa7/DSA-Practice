#include <iostream>
#include<algorithm>
using namespace std;

struct interval
{
	long long int s,e;
};

bool myComp(interval a,interval b)
{
	return a.s<b.s;
}

int Merge(interval arr[],int n)
{
	if(n<2)return n;
	sort(arr,arr+n,myComp);

	int res=0;
	
    for(int i=1;i<n;i++)
	{
		if(arr[res].e>=arr[i].s)
		{
			arr[res].s=min(arr[i].s,arr[res].s);
			arr[res].e=max(arr[i].e,arr[res].e);
		}
		else
		{
			res++;
			arr[res]=arr[i];
		}
	}
	return (res+1);
}

void Kth_Smallest(long long int arr2[],int m,interval arr1[],int n)
{
	for(int i=0;i<m;i++)
	{
		long long int k=arr2[i];
		bool chk=true;
		for(int j=0;j<n;j++)
		{
			if(k<=arr1[j].e-arr1[j].s+1)
			{
				cout<<arr1[j].s+k-1<<endl;
			}
            k-=arr1[j].e-arr1[j].s+1;
		}
		if(chk)cout<<-1<<endl;
	}
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		interval arr1[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr1[i].s>>arr1[i].e;
		}

        long long int arr2[q];
		for(int i=0;i<q;i++)
		{
			cin>>arr2[i];
		}

		n=Merge(arr1,n);

		Kth_Smallest(arr2,q,arr1,n);
	}				
}


