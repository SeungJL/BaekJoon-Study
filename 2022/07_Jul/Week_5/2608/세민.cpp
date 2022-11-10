#include <iostream>

using namespace std;

constexpr const char* symbol = "IVXLCDM";
constexpr int values[] = { 1, 5, 10, 50, 100, 500, 1000 };
constexpr const char* complexSymbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
constexpr int complexValues[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

char str[100];
int arab;

inline int getMatchedValue(const char ch)
{
	for (int i = 0; i < 7; i++)
	{
		if (symbol[i] == ch)
			return values[i];
	}

	return -1;
}

int main()
{
	for (int i = 0; i < 2; i++)
	{
		cin >> str;
		for (int j = 0; str[j]; j++)
			arab += getMatchedValue(str[j]) * (getMatchedValue(str[j]) < getMatchedValue(str[j + 1]) ? -1 : 1);
	}
	cout << arab << endl;

	while (arab)
	{
		for (int i = 0; i < 13; i++)
		{
			if (complexValues[i] <= arab)
			{
				arab -= complexValues[i];
				cout << complexSymbol[i];
				break;
			}
		}
	}
}