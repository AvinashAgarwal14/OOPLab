#include<iostream>
#include<string.h>
#include<fstream>
#define ll long long
using namespace std;

string add(string first_num, string second_num)
{
	ll int i = first_num.length()-1;
	ll int j = second_num.length()-1;
	ll int carry = 0;
	string ans = "";
	while(i>=0 && j>=0)
	{
		ll int num = (first_num[i]- '0') + (second_num[j] - '0') + carry;
		if(num >=10)
		{
			carry = 1;
			ans = char(num%10 + '0') + ans;
		}
		else
		{
			carry = 0;
			ans = char(num%10 + '0') + ans;
		}
		i--;
		j--;
	}
	while(i>=0)
	{
		ll int num = (first_num[i]- '0') + carry;
		if(num >=10)
		{
			carry = 1;
			ans = char(num%10 + '0') + ans;
		}
		else
		{
			carry = 0;
			ans = char(num%10 + '0') + ans;
		}
		i--;
	}
	while(j>=0)
	{
		ll int num = (second_num[j]- '0') + carry;
		if(num >=10)
		{
			carry = 1;
			ans = char(num%10 + '0') + ans;
		}
		else
		{
			carry = 0;
			ans = char(num%10 + '0') + ans;
		}
		j--;
	}
	if(carry > 0)
		ans = char(carry + '0') + ans;
	return ans;
}

string subtract(string first_num, string second_num)
{
	ll int i = first_num.length()-1;
	ll int j = second_num.length()-1;
	ll int borrow = 0;
	string ans = "";
	while(i>=0 && j>=0)
	{
		ll int num = (first_num[i] - '0') - (second_num[j] - '0') - borrow;
		if(num < 0)
		{
			borrow = 1;
			ans = char((10+num) + '0') + ans;
		}
		else
		{
			borrow = 0;
			ans = char(num + '0') + ans;
		}
		i--;
		j--;
	}
	while(i>=0)
	{
		ll int num = (first_num[i] - '0') - borrow;
		if(num < 0)
		{
			borrow = 1;
			ans = char((10+num) + '0') + ans;
		}
		else
		{
			borrow = 0;
			ans = char(num + '0') + ans;
		}
		i--;
	}
	return ans;
}

string multiply( string first_num, string second_num) 
{
	ll int i = first_num.length()-1;
	ll int j = second_num.length()-1;
	ll int carry = 0;
	string ans = "0";
	if(i<j)
	{
		string temp = first_num;
		first_num = second_num;
		second_num = temp;
		i = first_num.length()-1;
		j = second_num.length()-1;
	}
	for(int k = j; k>=0 ; k--)
	{
		string temp_mul = "";
		for(int l = i; l>=0 ; l--)
		{
			int elem = (first_num[l]-'0')*(second_num[k] - '0') + carry;
			if(elem >= 10)
			{
				carry = elem / 10;
				temp_mul =  char(elem%10+'0') + temp_mul;
			}
			else
			{
				carry = 0;
				temp_mul =  char(elem%10+'0') + temp_mul;
			}
		}
		if(carry!=0)
			temp_mul =  char(carry+'0') + temp_mul;
		carry = 0;
		ll int zeros = j-k;
		while(zeros--)
			temp_mul = temp_mul + "0";
		ans = add(temp_mul, ans);
	}
	return ans;
}

int main()
{
	string num;
	cin>>num;
	string ans = "1";
	while(num!="0")
	{
		ans = multiply(num, ans);
		num = subtract(num, "1");
		if(num[0]=='0' && num.length()!=1)
		{	
			string num_cp="";
			while(num[0]=='0')
			{
				for (int i = 1; i < num.length(); ++i)
					num_cp += num[i];
				num = num_cp;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
