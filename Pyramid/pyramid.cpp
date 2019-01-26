#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<setfill('*');
	for(int i = 1; i<=n; i++)
	{
		cout<<setw(n-i+1);
		for(int j = 1, k = 0; j<=(2*i-1); j++)
		{
			if(j==(2*i-1) && i!=1)
				cout<<left<<setw(n-i+1)<<--k;
			else if(j==(2*i-1) && i==1)
				cout<<right<<setw(n-i+1)<<1<<setw(n-i)<<'*';
			else if (j<=i)
				cout<<right<<++k;
			else
				cout<<right<<--k;
		}
		cout<<endl;
	}
	for(int i = (n-1); i>=1; i--)
	{
		cout<<setw(n-i+1);
		for(int j = 1, k = 0; j<=(2*i-1); j++)
		{
			if(j==(2*i-1) && i!=1)
				cout<<left<<setw(n-i+1)<<--k;
			else if(j==(2*i-1) && i==1)
				cout<<right<<setw(n-i+1)<<1<<setw(n-i)<<'*';
			else if (j<=i)
				cout<<right<<++k;
			else
				cout<<right<<--k;
		}
		cout<<endl;
	}
	return 0;
}
