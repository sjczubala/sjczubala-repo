#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

constexpr auto MAX_N = 100000;

double input[MAX_N];
int iInput[MAX_N];

void getArray(int n) {
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
}

void getIntArray(int n) {
	for (int i = 0; i < n; i++) {
		cin >> iInput[i];
	}
}

int f0(int n) {
	getArray(n);
	int min = round(input[0]);
	for (int i = 0; i < n; i++) {
		if (min > round(input[i])) {
			min = round(input[i]);
		}
	}
	cout << min << " ";
	return min;
}

int f1(int n) {
	getArray(n);
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (input[j] > input[i])
			{
				temp = input[j];
				input[j] = input[i];
				input[i] = temp;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		cout << input[k] << " ";
	}
	return 0;
}

double f2(int n) {
	getArray(n);
	double sum = 0, sqSum;

	for (int i = 0; i < n; i++) {
		sum += pow(input[i], 2);
	}

	sqSum = sqrt(sum);
	cout << (int)sqSum << " ";
	return (int)sqSum;
}

double f3(int n) {
	getArray(n);
	long double avg, sum = 0, aSum = 0, pSum = 0, dSum, sqSum;
	//double *p = new double[n];
	long double p;
	for (long int j = 0; j < n; j++) {
		sum += input[j];
	}
	avg = (long double)sum / (long double)n;
	//sumuje wszystkie inputy i znajduje ich wartosc srednia
	for (long int i = 0; i < n; i++) {
		p = pow(input[i] - avg, 2);
		pSum += p;
	}
	dSum = pSum / n;
	sqSum = sqrt(dSum);


	//wylicza kwadraty odchylen kazdego inputu od wartosci sredniej
	//for (int j=0;j<n;j++) {
	//	p[j]=pow(input[j]-avg,2);
	//}

	//sumuje wszystkie kwadraty odchylen kazdego inputu od wartosci sredniej
	//for (int k=0;k<n;k++) {
	//	aSum+=p[k];
	//}

	//dzieli sume kwadratow odchylen przez liczbe inputow
	//dSum=aSum/n;

	//wylicza odchylenie standardowe
	//sqSum=sqrt(dSum);
	//delete(p);
	cout << (int)sqSum << " ";
	return (int)sqSum;
}

int f4(int n) {
	getArray(n);
	int temp;

	for (int i = 0; i < n / 2; i++) {
		temp = input[n - i - 1];
		input[n - i - 1] = input[i];
		input[i] = temp;
	}
	for (int j = 0; j < n; j++) {
		cout << (int)input[j] << " ";
	}
	return *input;
}

int f5(int n) {
	getArray(n);
	//int *d = new int[n];
	int d = 0;
	//petla wczytujaca liczby z tablicy
	for (int j = 0; j < n; j++) {

		//petla sprawdzajaca ile liczba ma licznikow
		for (int i = 1; i <= input[j]; i++) {
			if ((int)input[j] % i == 0 && input[j] > 2)d += 1;
			else continue;
		}
	}

	if (d == 2)return 0;
	else return 1;
}

float f7(int n) {
	getArray(n);
	float delta, x1, x2, x0, xl;

	//sprawdzenie czy fcja jest kwadratowa czy szescienna
	if (input[0] == 0) {
		delta = pow(input[2], 2) - (4 * input[1] * input[3]);
	}
	//brak rozwiazan rzeczywistych dla delty<0, liczymy rozwiazania zespolone
	if (delta < 0) {
		delta = fabs(delta);

		x1 = ((-input[2]) - sqrt(delta)) / (2 * input[1]);
		x2 = ((-input[2]) + sqrt(delta)) / (2 * input[1]);

		if (x1 > x2)cout << floor(x2) << "i" << " " << floor(x1) << "i" << endl;

		else cout << floor(x1) << "i" << " " << floor(x2) << "i" << endl;

		return floor(x1), floor(x2);
	}

	//1 rozwiazanie dla delty=0
	else if (delta == 0) {
		x0 = (-input[2]) / (2 * input[1]);

		cout << floor(x0) << endl;

		return floor(x0);
	}

	//2 rozwiazania dla delty>0
	else {
		x1 = ((-input[2]) - sqrt(delta)) / (2 * input[1]);
		x2 = ((-input[2]) + sqrt(delta)) / (2 * input[1]);

		if (x1 > x2)cout << floor(x2) << " " << floor(x1) << endl;

		else cout << floor(x1) << " " << floor(x2) << endl;

		return floor(x1), floor(x2);
	}
}


int f8(int n) {
	getIntArray(n);
	long long int r = 0;
	for (int i = 1; i <= iInput[n - 1]; i++) {
		r += i * (pow((i + 1), 2));
	}

	cout << r << " ";
	return r;
}

unsigned int f9(int n) {
	getIntArray(n);
	unsigned int *count = new unsigned int[n];

	for (int k = 0; k < n; k++) {
		count[k] = 0;
	}

	for (int i = 0; i < n; i++) {
		(unsigned int)iInput[i];
		while (iInput[i]) {
			count[i] += iInput[i] & 1;
			iInput[i] >>= 1;
		}
	}
	for (int j = 0; j < n; j++) {

		cout << count[j] << " ";

	}
	delete count;
	return 0;
}
int main()
{
	int n, subprogram;

	while (cin >> subprogram >> n) {
		switch (subprogram) {
		case 0:
			f0(n);
			break;
		case 1:
			f1(n);
			break;
		case 2:
			f2(n);
			break;
		case 3:
			f3(n);
			break;
		case 4:
			f4(n);
			break;
		case 5:
			f5(n);
			break;
		case 6:
			break;
		case 7:
			f7(n);
			break;
		case 8:
			f8(n);
			break;
		case 9:
			f9(n);
			break;
		default:
			break;
		}
	};
	return 0;
}
