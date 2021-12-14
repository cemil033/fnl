#pragma once
#include <iostream>
using namespace std;
namespace xeta {
	class Xeta {
	public:
		string text;
		int line;
		string source;
		time_t time;
		Xeta() :text(), line(), source(), time() {}
		Xeta(string txt, int l, string s, time_t t) :text(txt), line(l), source(s), time(t) {}

		void Show() {
			cout << "Xetanin Metini: " << text << endl;
			cout << "Xetanin setri: " << line << endl;
			cout << "Xetanin fayli: " << source << endl;
			cout << "Xetanin zamani: " << time << endl;
		}
	};

	class DatabaseXeta :public Xeta {
	public:
		DatabaseXeta(string txt, int l, string s, time_t t) :Xeta(txt, l, s, t) {
		}
		void Show() {
			cout << "Xetanin Metini: " << text << endl;
			cout << "Xetanin setri: " << line << endl;
			cout << "Xetanin fayli: " << source << endl;
			cout << "Xetanin zamani: " << time << endl;
		}
	};

	class SehvArgumentXeta :public Xeta {
	public:
		SehvArgumentXeta(string txt, int l, string s, time_t t) :Xeta(txt, l, s, t) {
		}
		void Show() {
			cout << "Xetanin Metini: " << text << endl;
			cout << "Xetanin setri: " << line << endl;
			cout << "Xetanin fayli: " << source << endl;
			cout << "Xetanin zamani: " << time << endl;
		}
	};
}