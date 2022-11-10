#include <bits/stdc++.h>
using namespace std;

int make_num(string s)
{
	int sum = 0;
	s += " "; // 연산을 i+1 인덱스로 해서 끝 추가

	for (int i = 0; i < s.size(); i++)
	{
		//예외 사항 시작
		if (s[i] == 'I')
		{
			if (s[i + 1] == 'V')
			{
				sum += 4;
				i++;
				continue;
			}
			else if (s[i + 1] == 'X')
			{
				sum += 9;
				i++;
				continue;
			}
		}
		else if (s[i] == 'X')
		{
			if (s[i + 1] == 'L')
			{
				sum += 40;
				i++;
				continue;
			}
			else if (s[i + 1] == 'C')
			{
				sum += 90;
				i++;
				continue;
			}
		}
		else if (s[i] == 'C')
		{
			if (s[i + 1] == 'D')
			{
				sum += 400;
				i++;
				continue;
			}
			else if (s[i + 1] == 'M')
			{
				sum += 900;
				i++;
				continue;
			}
		}//예외사항 끝

		if (s[i] == 'I')
			sum += 1;
		else if (s[i] == 'V')
			sum += 5;
		else if (s[i] == 'X')
			sum += 10;
		else if (s[i] == 'L')
			sum += 50;
		else if (s[i] == 'C')
			sum += 100;
		else if (s[i] == 'D')
			sum += 500;
		else if (s[i] == 'M')
			sum += 1000;
	}
	return sum;
}
string make_str(int sum)
{
	string result;
	while (sum > 0)
	{
		if (sum >= 1000)
		{
			result += "M";
			sum -= 1000;
			continue;
		}
		else if (sum >= 900)
		{
			result += "CM";
			sum -= 900;
			continue;
		}
		else if (sum >= 500)
		{
			result += "D";
			sum -= 500;
			continue;
		}
		else if (sum >= 400)
		{
			result += "CD";
			sum -= 400;
			continue;
		}
		else if (sum >= 100)
		{
			result += "C";
			sum -= 100;
			continue;
		}
		else if (sum >= 90)
		{
			result += "XC";
			sum -= 90;
			continue;
		}
		else if (sum >= 50)
		{
			result += "L";
			sum -= 50;
			continue;
		}
		else if (sum >= 40)
		{
			result += "XL";
			sum -= 40;
			continue;
		}
		else if (sum >= 10)
		{
			result += "X";
			sum -= 10;
			continue;
		}
		else if (sum >= 9)
		{
			result += "IX";
			sum -= 9;
			continue;
		}
		else if (sum >= 5)
		{
			result += "V";
			sum -= 5;
			continue;
		}
		else if (sum >= 4)
		{
			result += "IV";
			sum -= 4;
			continue;
		}
		else
		{
			result += "I";
			sum--;
			continue;
		}
	}
	return result;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int sum = make_num(s1) + make_num(s2);
	string result = make_str(sum);
	cout << sum << '\n';
	cout << result;

	return 0;
}
