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
#include"admin.h"


using namespace std;
using namespace xeta;
using namespace ingredient;
using namespace stock;
using namespace dish;
using namespace user;
using namespace database;
using namespace admin;

Stock stc;
Database datab;
Admin admin1("admin", "admin");
string iname;
double ifats;
double iprotein;
double icarbohydrates;
double ikcal;
double iamount;
int icount;
Dishstc dshstc;

void Start() {
	int chs1,chs2;
	int chs3,chs4,chs5,chs6;
	int id;
	double tdey=0;
	bool reg=false;
	string username;
	string password;
	string guest;
	while (true) {
		system("cls");
		cout << "Xosh gelmishsiniz" << endl;
		cout << "Statusunuzu secin" << endl;
		cout << "1.Admin: " << endl;
		cout << "2.Mushteri: " << endl;
		cout << "Secim: ";
		cin >> chs1;
		if (chs1 == 1) {
			while (true)
			{
				system("cls");
				cout << "Adinizi daxil edin: ";
				cin >> username;
				cout << "Parolu daxil edin: ";
				cin >> password;
				if (username == admin1.username && password == admin1.password) {
					while (true)
					{
						system("cls");
						cout << "1.Ingredient elave edin" << endl;
						cout << "2.Yeni yemek elave edin" << endl;
						cout << "0.Geri" << endl;
						cout << "Secim:";
						cin >> chs2;
						if (chs2 == 1) {
							stc.Addingre();
						}
						else if (chs2 == 2) {
							dshstc.adddish(stc);
						}
						else {
							break;
						}
					}
				}
				else {
					cout << "Login ve ya parol sefdir" << endl;
					break;
				}
			}
		}
		else if (chs1 == 2) {
			while (true)
			{
				system("cls");
				cout << "1.Yeni musteri" << endl;
				cout << "2.Daimi musteri" << endl;
				cin >> chs3;
				if (chs3 == 1) {
					while (true)
					{
						cout << "Adinizi daxil edin: ";
						cin >> guest;
						cout << "ID nizi daxil edin: ";
						cin >> id;
						for (int i = 0; i < datab.users.size(); i++)
						{
							if (id == datab.users[i].id) {
								cout << "Bu id de istifadeci artiq var!";
								reg = false;
								break;
							}
							reg = true;
						}
						if (reg == false)break;
						else {
							datab.users.push_back(*new User(guest, id));
							break;
						}
					}
					break;
				}
				else if (chs3 == 2) {
					system("cls");
					cout << "Adinizi daxil edin: ";
					cin >> guest;
					cout << "Id nizi daxi edin: ";
					cin >> id;
					for (int i = 0; i < datab.users.size(); i++)
					{
						if (guest == datab.users[i].name && id == datab.users[i].id) {
							cout << "Xos Gelmishsiniz";
							cout << "1.Yeni sifaris" << endl;
							cout << "2.Sifarislere bax" << endl;
							cout << "0.Geri" << endl;
							cin >> chs5;
							if (chs5 == 1) {
								while (true)
								{
									system("cls");
									for (int j = 0; j < dshstc.dishs.size(); j++)
									{
										cout << j + 1 << dshstc.dishs[j].name << endl;
									}
									cout << "0.Geri";
									cout << "Sifarisinizi secin: ";
									cin >> chs4;
									if (chs4 == 0) {
										break;
									}
									datab.users[i].order.dish.push_back(dshstc.dishs[chs4 - 1]);
									for (int k = 0; k < dshstc.dishs.size(); k++)
									{
										for (int c = 0; c < dshstc.dishs[k].ingredients.size(); c++)
										{
											for (int f = 0; f < stc.ingredients.size(); f++)
											{
												if (dshstc.dishs[k].ingredients[c].name == stc.ingredients[f].name) {
													stc.ingredients.erase((stc.ingredients.begin() + f));
													break;
												}
											}
										}
									}
								}
							}
							else if (chs5 == 2) {
								cout << "Sebetiniz\n";
								for (int j = 0; j <datab.users[i].order.dish.size(); j++)
								{
									cout << "Yemeyin adi: " << datab.users[i].order.dish[j].name << endl;
									cout << "Yemeyin deyeri: " << datab.users[i].order.dish[j].amount << endl;
									tdey += datab.users[i].order.dish[j].amount;
								}
								cout << "Umumi mebleg: " << tdey <<endl;
								cout << "1.Sifarisi tesdiqle" << endl;
								cout << "0.Geri" << endl;
								cin >> chs6;
								if (chs6 == 1) {
									datab.users[i].order.dish.clear();
								}
								else { break; }
							}
							else { break; }
						}
						else {
							cout << "Bele bir mushteri yoxdur." << endl;
							break;
						}
					}
				}
				break;
			}
		}
	}
}