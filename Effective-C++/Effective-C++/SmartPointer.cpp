#include<iostream>
#include"SmartPointer.h"
using namespace std;

int main() {
	String s1("Hello");
	String s2("C++");

	cout << s1[3] << endl;
	s1[5] = 'm';
	cout << s1[5] << endl;
	system("pause");
	return 0;
}