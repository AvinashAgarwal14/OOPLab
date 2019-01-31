#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	

	
	ll int x, y;
	cin>>x>>y;
	float low = (3.14/180)*x;
	float high = (3.14/180)*y;
	float tp = 3.14/20;
	for(int i=0;i<=10;i++)
	{
		float sin_value = sin(tp*i);
		cout<<setfill(' ')<<setw(20)<<" ";
		cout<<setfill('*')<<setw(int(sin_value*20)+1)<<left<<"*";	
		cout<<endl;
	}
	for(int i=9;i>0;i--)
	{
		float sin_value = sin(tp*i);
		cout<<setfill(' ')<<setw(20)<<" ";
		cout<<setfill('*')<<setw(int(sin_value*20)+1)<<left<<"*";	
		cout<<endl;
	}
	for(int i=0;i<=10;i++)
	{
		float sin_value = sin(tp*i);
		cout<<setfill(' ')<<setw(20 - int(sin_value*20))<<" ";
		cout<<setfill('*')<<setw(int(sin_value*20)+1)<<right<<"*";	
		cout<<endl;
	}
	for(int i=9;i>=0;i--)
	{
		float sin_value = sin(tp*i);
		cout<<setfill(' ')<<setw(20 - int(sin_value*20))<<" ";
		cout<<setfill('*')<<setw(int(sin_value*20)+1)<<right<<"*";	
		cout<<endl;
	}
	return 0;
}