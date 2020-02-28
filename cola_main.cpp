#include "cola_prioridad.h"
#include <iostream>

using namespace std;

int main() {
	cola_prio<char> cola;
	
	cout<<"COLA DE PRIORIDAD:\n";
	
	cola.insertar('A',100);
	cola.insertar('B',90);
	cola.insertar('C',50);
	cola.insertar('D',70);
	cola.insertar('E',140);
	cola.insertar('F',10);
	cola.insertar('G',200);
	cola.insertar('H',12);
	cola.insertar('I',80);
	cola.insertar('J',0);
	
	while(!cola.cola_vacia()) {
		cout<<cola.atender()<<"-";
	}
	return 0;
}
