/*NAME : AVINASH AGARWAL
  ROLL NO : 17CS8065
  DATE OF ASSIGNMENT : 25/01/2019
  ASSIGNMENT NAME : ADDITION/SUBTRACTION/MULTIPLICATION USING FILES*/

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

string subtract(string first_num, string second_num, int reverse)
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
	while(j>=0)
	{
		ll int num = (second_num[j] - '0') - borrow;
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
		if(j==0)
			ans = '-' + ans;
		j--;
	}
	if(borrow == 1 || ans[0] == '-')
		return subtract(second_num, first_num, 1);
	else
	{
		if(reverse == 1)
			ans = '-' + ans;
		return ans;
	}
}

string compare(string first_num, string second_num)
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
	while(j>=0)
	{
		ll int num = (second_num[j] - '0') - borrow;
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
		if(j==0)
			ans = '-' + ans;
		j--;
	}
	if(borrow == 1)
		ans = '-' + ans;
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
	
	fstream f;
	f.open("input.txt", ios::in);
	string first_num;
	string second_num;
	f>>first_num;
	f>>second_num;
	f.close();
	ll int choice;
	cout<<"Enter 1 to Add.\nEnter 2 to Subtract.\nEnter 3 to Multiply.\nEnter 4 to Divide.\n";
	cin>>choice;
	string ans = "Try Again!";
	switch(choice)
	{
		case 1: ans = add(first_num, second_num);
				break;
		case 2: ans = subtract(first_num, second_num, 0);
				break;
		case 3: ans = multiply(first_num, second_num);
				break;
		// case 4: ans = divide(first_num, second_num);
		// 		break;
		default: cout<<"Invalid Option! Select a correct option.\n";
	}
	cout<<endl<<"Answer: "<<ans<<endl;
	return 0;
}
