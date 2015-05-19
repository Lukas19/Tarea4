/*
list: Lista todos los tags contenidos en el tag actual
change x: donde x es un numero mayor o igual a 1, indicando el tag al cual queremos navegar
back: ir al tag anterior en la jerarquia
position: indica el tag en el cual estamos situados actualmente
exit: salir del programa
*/

#include <iostream>
#include <string>
#include <fstream>
#include "arbol.h"
using namespace std;

//Prototipo
void back(ptrNodo &n);

void cargar_archivo(string filename, ptrNodo &n){ //recibe puntero al nodo raiz
	fstream myfile;
	myfile.open(filename.c_str());
	string line;
	int nivel = 0;
	int fin = 0;
	cout << "Cargando archivo." << endl;
	ptrNodo r = n; // r es un puntero fijo a raiz

	while(getline(myfile, line)){	
		for (unsigned int i = 0; i < line.size(); i++){

			if(line[nivel] == '/'){
				nivel-=2;
				fin++;
				if(fin==3) //fin del documento
					break;
				back(n);
				if(fin == 2){ // si hay 2 cierres seguidos vuelve solo 1 nivel
					nivel++;
					break;
				}
				back(n);
				break;
			}

			if (line[i]==' '){ //cuenta los espacios si los hay
				if(i>nivel){
					insertar_nodo(n); //n cambia al nodo creado
					nivel++;
				}
			}
			else{
				if (nivel)  //borra los espacios si los hay
					line.erase(line.begin(),line.begin()+i-1);					
				n->dato = line;
				break;
			}

			fin = 0;
		}
	}
	cout << "Archivo cargado." << endl;
	n = r;
}

void list(ptrNodo &n){
	for (auto it = n->hijos.begin(); it != n->hijos.end(); ++it)
		cout << *it->dato <<endl;
}

void change(int x, ptrNodo &n){
	n = n->hijos[x-1];
}

void back(ptrNodo &n){
	n = n->padre; 
}
/*
otra forma es tener un puntero fijo a la raiz
y recorrer el arbol hasta que un puntero del vector
sea igual al nodo en el que estamos
*/

void position(ptrNodo &n){
	cout << n->dato << endl;
}

//void exit() hacer esta funcion en el main y ponerle un break al while(true)
