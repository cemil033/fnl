#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"xetalar.h"
#include"ingredient.h"
#include"stock.h"
#include"yemek.h"
#include"User.h"

using namespace std;
using namespace xeta;
using namespace ingredient;
using namespace stock;
using namespace dish;
using namespace user;


namespace database {
	class Database {
	public:
		vector<User> users;
		Database():users(){}
		Database(vector<User> t):users(t){}
		void Showordes(int id) {
			for (auto i:users)
			{
				if (id == i.id)i.Showorder();
			}
		}
	};

}