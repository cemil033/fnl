#pragma once
#include<iostream>
#include<fstream>
#include"xetalar.h"

using namespace std;
using namespace xeta;

namespace ingredient {
	class Ingredient {
	public:
		string name;
		double fats;
		double protein;
		double carbohydrates;
		double kcal;
		double amount;
		Ingredient() : name(), fats(), protein(), carbohydrates(), kcal(), amount() {};
		Ingredient(const string name, double fat, double protein, double carbohydrates, double kcal, double amount) {
			if (name == "")throw SehvArgumentXeta("Gonderilen deyer duz deyil", __LINE__, "source.cpp", time(NULL));
			this->name = name;
			this->fats = fat;
			this->protein = protein;
			this->carbohydrates = carbohydrates;
			this->kcal = kcal;
			this->amount = amount;
		}
		void Show() {
			cout << "unknown" << endl;
		}
		void Writetofile() {
			fstream file("ingredient.txt", ios::end);
			file.setf(ios::left);
			file << name << " "
				<< fats << " "
				<< protein << " "
				<< carbohydrates << " "
				<< kcal << " "
				<< amount << endl;
		}
		~Ingredient() {};
	};
}