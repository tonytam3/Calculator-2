#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Functions are declared//
void addition(long double &result);
void subtraction(long double &result);
void multiplication(long double &result);
void division(long double &result);
void powerFunc(long double &result);
void squareRoot(long double &result);
void factorial(long double &result);
void absoluteV(long double &result);
int showmenu();
void welcome();
void middleman(int x);
void printOut();
void resultNextOp();
void request(int &n, double &x, double &y);

double x = 0.00, y = 0.00;
int n;
long double result = 0.00;

int Response;
bool nextOP = false;
bool progExit = false;
string Response2("empty");
//int abs = 0;

int main() {
	welcome();
	do {
		int decision = showmenu();
		middleman(decision);
		printOut();
		resultNextOp();
	} while (progExit == false);
	cout << "program ended" << endl;
	return 0;
}


void welcome() {
	cout << "Hello, what function would you like to perform today?"<<endl;
}

int showmenu() {
	cout << " 1)addidtion\n 2)substraction\n 3)multiplication\n 4)division\n 5)power function\n 6)squareroot\n 7)factorial\n 8)absolute value\n 9)exit" << endl;
	cin >> x;
	return x;
}

void middleman(int x) {
	do {
		switch (x) {
		case 1: addition(result); break;
		case 2: subtraction(result); break;
		case 3: multiplication(result); break;
		case 4: division(result); break;
		case 5: powerFunc(result); break;
		case 6: squareRoot(result); break;
		case 7: factorial(result); break;
		case 8: absoluteV(result); break;
		case 9: progExit = true;
		}
	} while (x < 1 || x>9);
}

void printOut() {
	cout << "This is your result: " << result << endl<<endl;
}

void resultNextOp() {
	do{
		cout << "Do you want to perform another operation on the result?\n 1)yes\n 2)no\n 3)exit" << endl;
		cin >> Response;
		switch (Response) {
		case 1: nextOP = true; break;
		case 2: result = 0; nextOP = false; break;
		case 3: progExit = true; break;
		}
	} while (Response < 1 || Response>3);
	Response = 0;
}

void request(int &n, double &x, double &y) {
	switch (n) {
	case 1: // functions that use this case is Absolute Value and Squareroot 
		if (nextOP == false) {
			cout << "What is the x Variable?" << endl;
			cin >> x; break;
		}
		else {x = result;}
	case 2: // functions that use this case is Addition, Subtraction, and Multiplication
		if (nextOP == false) {
			cout << "What is the X variable?" << endl;
			cin >> x;
		}
		else {x = result;}
		cout << "What is the Y Variable" << endl;
		cin >> y;break;
	case 3:
		x = result;
		cout << "What is the Y variable?" << endl;
		cin >> y;break;
	case 4: // Only Division uses this case
		if (nextOP == false) {
			cout << "What is the X variable?" << endl;
			cin >> x;
		}
		else { x = result;}
		do {
			cout << "What is the Y Variable" << endl;
			cin >> y;
			if (y == 0) cout << "Can't divide by zero." << endl;
		} while (y == 0);
		break;
	case 5: // Only Factorial function uses this case
		do {
			if (nextOP == false) {
				cout << "What is the X Variable" << endl;
				cin >> x;
			}
			else {x = result;}
			if (x < 0) cout << "Can't do factorial of negative number." << endl;
		} while (x < 0);
		break;
	}
}

void addition(long double &result) {
	n = 2;
	request(n,x,y);
	result = x + y;
}
void subtraction(long double &result) {
	n = 2;
	request(n, x, y);
	result = x - y;
}
void multiplication(long double &result) {
	n = 2;
	request(n, x, y);
	result = x * y;
}
void division (long double &result) {
	n = 4;
	request(n, x, y);
	result = x / y;
}
void powerFunc(long double &result) {
	n = 2;
	request(n, x, y);
	result = pow(x, y);
}
void squareRoot(long double &result){
	n = 1;
	request(n, x, y);
	result = sqrt(x);
}
void factorial(long double &result) {
	n = 5;
	request(n, x, y);

	double n1 = x;
	double n2 = n1 - 1;

	if (x > 0) {
		while (n2 > 0) {
			n1 = n1 * n2;
			n2--;
		}
		result = n1;
	}
	else if (x == 0) {
		result = 1;
	}
	else {
		cout << "invalid input" << endl;
	}
}
void absoluteV(long double &result) {
	n = 1;
	request(n, x, y);
	result = abs(x);
}
