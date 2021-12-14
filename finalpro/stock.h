#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"xetalar.h"
#include"ingredient.h"

using namespace std;
using namespace xeta;
using namespace ingredient;

namespace stock {
	class Stock {

	public:

		vector<Ingredient> ingredients;

		void Addingre() {

			int chs1, count;

			cout << "Elave etmek istediyiniz ingridient secin" << endl;
			cout << "1.Sarimsaq\n"
				<< "2.Et\n"
				<< "3.Edviyyat\n"
				<< "4.Pendir\n"
				<< "5.Pomidor\n"
				<< "6.Xiyar\n"
				<< "7.Un\n"
				<< "8.Zeytun\n"
				<< "9.yeni ingrediyent\n"
				<< "0.Geri\n";
			cout << "Secim:";
			cin >> chs1;

			if (chs1 == 1) {
				cout << "Say daxil edin:";
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					ingredients.push_back(Ingredient("Sarimsaq", 0.1, 0.1, 0.1, 10, 0.5));
				}
			}

			else if (chs1 == 2) {
				cout << "Say daxil edin:";
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					ingredients.push_back(Ingredient("Et", 20, 15, 5, 150, 1.2));
				}
			}

			else if (chs1 == 3) {
				cout << "Say daxil edin:";
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					ingredients.push_back(Ingredient("Edviyyat",0.01, 0.01,0.01, 0.01, 0.2));
				}
			}

			else if (chs1 == 4) {
				cout << "Say daxil edin:";
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					ingredients.push_back(Ingredient("Pendir", 0.2, 0.2, 0.2, 200, 0.4));
				}
			}

			else if (chs1 == 5) {
				cout << "Say daxil edin:";
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					ingredients.push_back(Ingredient("Pomidor", 0.05, 0, 0.01, 0.1, 0.1));
				}
			}

			else if (chs1 == 6) {
				cout << "Say daxil edin:";
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					ingredients.push_back(Ingredient("Xiyar", 0.05, 0, 0.01, 0.1, 0.1));
				}
			}

			else if (chs1 == 7) {
				cout << "Say daxil edin:";
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					ingredients.push_back(Ingredient("Un", 0, 0, 0.1, 0.1, 0.2));
				}
			}

			else if (chs1 == 8) {
				cout << "Say daxil edin:";
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					ingredients.push_back(Ingredient("Zeythun", 0.1, 0.1, 0.01, 0.2, 0.2));
				}
			}

			else if (chs1 == 9) {
				string name;
				double fats;
				double protein;
				double carbohydrates;
				double kcal;
				double amount;
				cout << "Ingredientin adini daxil edin:";
				cin >> name;
				cout << "Ingredientin yagliligini daxil edin: ";
				cin >> fats;
				cout << "Ingredientin protein deyerini daxil edin: ";
				cin >> protein;
				cout << "Ingredientin carbohidrat deyerini daxil edin: ";
				cin >> carbohydrates;
				cout << "Ingredientin kalori deyerini daxil edin(kcal): ";
				cin >> kcal;
				cout << "Ingredientin qiymetini daxil edin: ";
				cin >> amount;
				cout << "Say daxil edin:";
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					ingredients.push_back(*new Ingredient(name, fats, protein, carbohydrates, kcal, amount));
				}
			}

			else {
				return;
			}
		}

		void Writefofile() {
			fstream file("stock.txt", ios::end);
			for (int i = 0; i <ingredients.size(); i++)
			{
				file << ingredients[i].name 
					<< ingredients[i].fats 
					<< ingredients[i].protein 
					<< ingredients[i].carbohydrates 
					<< ingredients[i].kcal 
					<< ingredients[i].amount;
			}
		}

	};
}