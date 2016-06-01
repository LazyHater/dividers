#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int getSmallestDivider(long int n);
vector<long int> findPrimeDividers(long int n);
vector<long int> findAllDividers(long int n);
void printVector(ostream &os, const vector<long int> vec);

int main()
{
	while (1) {
		long int input_number = 0;
		cout << "pls enter number : ";
		cin >> input_number;
		input_number = abs(input_number); // deal with sign
		cout << "	factorized: ";

		vector<long int> vec = findPrimeDividers(input_number);
		printVector(cout, vec);

		cout <<endl<< "all dividers";
		vec = findAllDividers(input_number);
		cout << "(size: " << vec.size() << "): ";
		printVector(cout, vec);

		cout << endl;
	}
	return 0;
}

int getSmallestDivider(long int n) {
	for (int i = 2; i <= n; i++)
		if (!(n%i))
			return i;
	return -1; //something gone wery wrong ;-; or n <= 1
}

vector<long int> findPrimeDividers(long int n) {
	vector<long int> prime_dividers;
	prime_dividers.push_back(1);
	while (n != 1) {
		int smallest_divader = getSmallestDivider(n);
		prime_dividers.push_back(smallest_divader);
		n /= smallest_divader;
	}
	return prime_dividers;
}

vector<long int> findAllDividers(long int n) {
	vector<long int> dividers;
	//float n_sqrt = sqrt(n);

	for (long int i = 1; i <= n; i++)
		if (!(n%i))
			dividers.push_back(i);

	return dividers;
}

void printVector(ostream &os, const vector<long int> vec) {
	if (vec.empty()) {
		os << "[]";
		return;
	}

	size_t n = vec.size();
	os << "[";
	for (size_t i = 0; i < n - 1; i++)
		os << vec[i] << ", ";
	os << vec[n - 1] << "]";
}