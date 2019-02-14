/*NAME : AVINASH AGARWAL
  ROLL NO : 17CS8065
  DATE OF ASSIGNMENT : 08/02/2019
  ASSIGNMENT NAME : HASHING*/

#include<iostream>
#include<cstdlib>
#define ll long long
using namespace std;

int main()
{
	srand(time(0));
	ll int batch_misses[6];
	for(int num=20;num<=100;num+=20)
	{

		int *hashtable= new int[100];
		for(int i=0;i<100;i++)
			hashtable[i]=-1;
		
		int total_miss=0;
		for(int i=1;i<=num;i++)
		{
			int x=rand();
			int miss=0;
			int index=x%100;
			int indi=index;
			while(*(hashtable+index)!=-1)
			{
				miss++;
				index++;
				if(index==100)
					index=0;
			}
			hashtable[index]=x;
			total_miss+=miss;
		}
		batch_misses[num/20]=total_miss;
		cout<<"Total Number of misses for batch of "<<num<<" elements: "<<total_miss<<"\n";
		cout<<"Hash table for "<<num<<" Elemnets:\n";
		for(int i = 0; i< 100;i++)
			cout<<hashtable[i]<<"  ";
		cout<<"\n\n";
		delete hashtable;
	}
	
	// Calculation of Mean and Variance
	int a=0,b=0;
	for(int i=1;i<=5;i++)
	{
		a+=batch_misses[i];
		b+=batch_misses[i]*batch_misses[i];
	}
	float avg=(float)a/5;
	cout<<"Average Miss: "<<avg<<"\n";
	float var=(float)b/5-(avg*avg);
	cout<<"Variance of Miss: "<<var<<"\n";
	return 0;
}
