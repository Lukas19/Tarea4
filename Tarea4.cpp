#include <iostream>
#include <string>
#include <list>
using namespace std;

struct nodo{
	string dato;
	list<nodo> hijos;
	nodo *padre;
};

typedef nodo *ptrNodo;

nodo insertar_nodo(ptrNodo &n){
	ptrNodo nuevo = new nodo;
	nuevo->padre = n;
	n->hijos.push_back(*nuevo);
	n = nuevo;
	return n;
}
