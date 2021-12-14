#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"xetalar.h"
#include"ingredient.h"
#include"stock.h"
#include"yemek.h"
#include"User.h"
#include"database.h"


using namespace std;
using namespace xeta;
using namespace ingredient;
using namespace stock;
using namespace dish;
using namespace user;
using namespace database;

namespace admin {
	class Admin {
	public:
		string username;
		string password;
		Admin():username(),password() {
			
		}
		Admin(string usname, string pass) {
			if(usname=="")throw SehvArgumentXeta("Gonderilen deyer duz deyil", __LINE__, "source.cpp", time(NULL));
			if(usname.size()<5)throw SehvArgumentXeta("Gonderilen deyer duz deyil", __LINE__, "source.cpp", time(NULL));
			if(pass.size()<5)throw SehvArgumentXeta("Gonderilen deyer duz deyil", __LINE__, "source.cpp", time(NULL));
			username = usname;
			password = pass;
		}

	};
}
