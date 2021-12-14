#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include"xetalar.h"
#include"ingredient.h"
#include"stock.h"

using namespace std;
using namespace xeta;
using namespace ingredient;
using namespace stock;

namespace dish {
	class Dish {
	public:
		string name;
		vector<Ingredient> ingredients;
		double amount;

		Dish() :name(), ingredients(),amount(){}

		Dish(string name,vector<Ingredient> ingres):name(name),ingredients(ingres){
			for (int i = 0; i < ingres.size(); i++)
			{
				amount += ingres[i].amount;
			}
		}

		void Addingre(Ingredient t) {
			ingredients.push_back(t);
			amount += t.amount;
		}


	};
	class Dishstc {
	public:
		vector<Dish> dishs;
		Dishstc():dishs(){}
		void adddish(Stock& t) {
			string iname;
			int isort;
			int icount;
			int temp;
			vector<Ingredient> ings;
			string dshname;
			cout << "Lazim olan ingredientin movcudlugunu yoxla." << endl;
			cout << "Ceshid sayini daxil edin: ";
			cin >> isort;
			for (int i = 0; i < isort; i++)
			{
				system("cls");
				icount = 0;
				temp = 0;
				cout << "Ingredient adini daxil edin: ";
				cin >> iname;
				for (int i = 0; i < t.ingredients.size(); i++)
				{
					if (t.ingredients[i].name == iname) {
						temp++;
					}
				}
				if (temp < icount) {
					cout << "Lazim olan ingredient movcud deyil" << endl;;
					return;
				}
			}
			cout << "Yemeyin adini daxi edin: ";
			cin >> dshname;
			for (int i = 0; i < isort; i++)
			{
				system("cls");
				cout << "Ingredient adini daxil edin: ";
				cin >> iname;
				for (int i = 0; i < t.ingredients.size(); i++)
				{
					if (t.ingredients[i].name == iname) {
						ings.push_back(t.ingredients[i]);
						t.ingredients.erase((t.ingredients.begin() + i));
					}
				}
			}
			dishs.push_back(*new Dish(dshname, ings));
		}
	};
}