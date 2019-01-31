/*NAME : AVINASH AGARWAL
  ROLL NO : 17CS8065
  DATE OF ASSIGNMENT : 25/01/2019
  ASSIGNMENT NAME : GRAPH PLOTTER*/

#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
	cout<<"Enter the Lower and Upper bound for the Sine Curve(in radians) :\n";
	double low,upp;
	cout<<"Lower Bound : ";
	cin>>low;
	cout<<"Upper Bound : ";
	cin>>upp;


	double a=3.14159/70;
	int x=floor(low/a),y=ceil(upp/a);
	for(int i=x;i<=y;i++)
	{
		int z=floor(sin(i*a)*70);
		if(z>=0)
		{
			cout<<setw(71)<<setfill(' ')<<"|";
			cout<<setw(z+1)<<setfill('*')<<"*\n";
		}
		else
		{
			z*=-1;
			cout<<setw(70-z+1)<<setfill(' ')<<"*";
			cout<<setw(z+1)<<setfill('*')<<"|\n";
		}
	}
	return 0;
}