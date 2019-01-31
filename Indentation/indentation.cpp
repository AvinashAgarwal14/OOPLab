/*NAME : AVINASH AGARWAL
  ROLL NO : 17CS8065
  DATE OF ASSIGNMENT : 25/01/2019
  ASSIGNMENT NAME : INDENTATION*/

#include<stdio.h>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

int main()
{

	fstream f;
	f.open("input.txt", ios::in);
	string line;
	int space = 0;
	while(f)
	{
		getline(f, line);
		if(line == "}")
			space--;
		if(space > 0)
			{
				int temp = space;
				while(temp--)
					line = "	" + line;
			}
		ll int i = 0;
		ll int len = line.length()-1;
		while(i<=len)
			{ 
				if(line[i]=='{')
					space++;
				i++;
			}
		cout<<line<<endl;
	}
	f.close();
	return 0;
}
