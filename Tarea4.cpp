#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct nodo{
	string dato;
	vector <ptrNodo> ptrs;
	nodo *padre;
};
