#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
	string name;
	int day;
	int month;
	int year;

	Person(string name, int day, int month, int year) {
		this->name = name;
		this->day = day;
		this->month = month;
		this->year = year;
	}
};

bool compare(Person& p1, Person& p2) {	//더 오래전에 태어난 사람이 앞에 오도록 정렬(날짜 오름차순)
	if (p1.year < p2.year) 
		return true;
	else if (p1.year > p2.year)
		return false;
	else {
		if (p1.month < p2.month) 
			return true;
		else if (p1.month > p2.month)
			return false;
		else {
			if (p1.day < p2.day) 
				return true;
			else
				return false;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<Person> vec;

	for (int i = 0; i < n; i++) {
		string name;
		int day, month, year;
		cin >> name >> day >> month >> year;
		vec.push_back(Person(name, day, month, year));
	}

	sort(vec.begin(), vec.end(), compare);

	cout << vec[n-1].name << endl;
	cout << vec[0].name << endl;

	return 0;
}