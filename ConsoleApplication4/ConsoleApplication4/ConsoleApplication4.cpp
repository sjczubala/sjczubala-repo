// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

struct item {
	int P;
	int W;
};

int main()
{
	int car_number;
	cin >> car_number;
	for (int l = 0; l < car_number; l++) {

		int car_storage, items_number;
		int incomeP = 0, outcomeP = 20, expensesP = 0, weight_sumP = 0, overw_items = 0;
		int incomeW = 0, outcomeW = 20, expensesW = 0, weight_sumW = 0;
		item itemsP[15];
;

		cin >> items_number;


		for (int i = 0; i < items_number; i++) {
			cin >> itemsP[i].P;

			//cout << "Price[" << i << "]:" << itemsP[i].P << endl;
		}



		for (int j = 0; j < items_number; j++) {

			cin >> itemsP[j].W;
			//cout << "Weight[" << j << "]:" << itemsP[j].W << endl;
		}

		cin >> car_storage;
		//cout << "Car storage:" << car_storage << endl;
		map<int, int, greater <int>> items_mapP;
		for (int f = 0; f < items_number; f++) {
			items_mapP.insert(pair<int, int>(itemsP[f].P, itemsP[f].W));
		}

		for (auto h : items_mapP) {
			if (weight_sumW + h.second < car_storage) {
				incomeW += h.first;
				weight_sumW += h.second;
			}
		}
		int o = 0;
		for (auto x = items_mapP.rbegin(); x != items_mapP.rend(); x++) {


			if (weight_sumP + x->second < car_storage) {
				incomeP += x->first;
				//cout << "IncomeP[" << o << "]:" << incomeP << endl;
				if (itemsP[o].W > 100) {
					overw_items++;
					weight_sumP += x->second;
					//cout << "WeightOverw[" << o << "]:" << itemsP[o].W << endl;
				}
				else weight_sumP += x->second;
				//cout << "Weight SumP[" << o << "]:" << weight_sumP << endl;
				o++;
			}

		}


		/*map<int, int> ::iterator it;
		for (it = items_map.begin(); it != items_map.end(); it++) {
			for (auto& c : items_map) {
				cout << "Pair:" << c.first << ":" << c.second << endl;
			}
		}
		
		for (auto& x : items_map) {
			if (weight_sum + x.second < car_storage) {
				income += x.first;
				weight_sum += x.second;
			}
		}*/
		if (incomeW > incomeP) {
			outcomeW = outcomeW + (overw_items * 5);
			expensesW = incomeW - outcomeW;
			cout << expensesW << endl;
		}
		else {
			outcomeP = outcomeP + (overw_items * 5);
			expensesP = incomeP - outcomeP;

		}

		if (outcomeP > incomeP && outcomeW > incomeW) {
			cout << endl << "0" << endl;
		}
		
		else cout << expensesP << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu