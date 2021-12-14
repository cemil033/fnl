#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"xetalar.h"
#include"ingredient.h"
#include"stock.h"
#include"yemek.h"

using namespace std;
using namespace xeta;
using namespace ingredient;
using namespace stock;
using namespace dish;

namespace user {
	class Order {
	public:
		vector<Dish> dish;
		Order() :dish() {}
		Order(vector<Dish> t) :dish(t) {}
		void adddish(Dish t) {
			dish.push_back(t);
		}
	};

	class User {
	public:
		string name;
		int id;
		Order order;
		User():name(),id(){}
		User(string name,int id):name(name),id(id){}
		void Showorder() {
			for (auto i:order.dish)
			{
				cout << i.name << endl;
			}
		}
	};
}