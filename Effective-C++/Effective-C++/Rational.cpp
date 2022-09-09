#include"Rational.h"

int main() {
	Rational<int> onehalf(1, 2);

	Rational<int> result = 2 * onehalf;
	cout << result << endl;

	system("pause");
	return 0;
}