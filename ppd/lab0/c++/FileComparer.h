#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class FileComparer {
public:

	FileComparer() {}

	vector<int> getVecInt(string filename) {
		fstream fin(filename);
		string str;
		vector<int> vec;
		try {
			while (fin >> str) {
				int nr = stoi(str);
				vec.push_back(nr);
			}
		}
		catch (...) {
			return {};
		}

		return vec;
	}

	vector<double> getVecDouble(string filename) {
		ifstream fin(filename);
		string str;
		vector<double> vec;
		try {
			while (fin >> str) {
				double nr = stod(str);
				vec.push_back(nr);
			}
		}
		catch (...) {
			return {};
		}

		return vec;
	}

	bool compareFiles(string fileName1, string fileName2, string wich) {
		if (wich == "int") {
			vector<int> vec1 = getVecInt(fileName1);
			vector<int> vec2 = getVecInt(fileName2);

			if (vec1.size() == 0 || vec2.size() == 0)
				return false;

			if (vec1.size() != vec2.size())
				return false;

			for (int i = 0; i < vec1.size(); ++i) {
				if (vec1[i] != vec2[i])
					return false;
			}
		}
		else {
			vector<double> vec1 = getVecDouble(fileName1);
			vector<double> vec2 = getVecDouble(fileName2);

			if (vec1.size() == 0 || vec2.size() == 0)
				return false;

			if (vec1.size() != vec2.size())
				return false;

			for (int i = 0; i < vec1.size(); ++i) {
				if (vec1[i] != vec2[i])
					return false;
			}
		}

		return true;
	}

};