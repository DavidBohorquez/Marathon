#ifndef COLAPRIORIDAD_H
#define	COLAPRIORIDAD_H
#include <iostream>

using namespace std;
template<class T>
struct nodo {
	int prioridad;
	T dato;
	nodo<T> *izq, *der;
};

template<class T>
class cola_prio {
	public:
		cola_prio();
		~cola_prio();
		bool insertar(T,int);
		T atender();
		bool cola_vacia();
		bool cola_llena();
	private:
		nodo<T> arr[100];
		int pos_ultima;
};

template<class T>
cola_prio<T>::cola_prio() {
	pos_ultima=0;
}

template<class T>
cola_prio<T>::~cola_prio() {
}

template<class T>
bool cola_prio<T>::cola_llena() {
	if(pos_ultima >= 100) {
		return true;
	}else {
		return false;
	}
}

template<class T>
bool cola_prio<T>::cola_vacia() {
	if(pos_ultima == 0) {
		return true;
	}else {
		return false;
	}
}

template<class T>
bool cola_prio<T>::insertar(T dato, int prio) {
	nodo<T> nuevo;
	nuevo.dato = dato;
	nuevo.prioridad = prio;
	
	int padre=0;
	pos_ultima++;
	
	if(cola_llena()) {
		return false;
	}else {
		int pos_act=pos_ultima;
	
		padre = pos_act/2;
		while(padre!=0 && nuevo.prioridad > arr[padre].prioridad) {
			arr[pos_act] = arr[padre];
			pos_act = padre;
			padre = pos_act/2;
		}
		arr[pos_act] = nuevo;
		
		return true;
	}
}

template<class T>
T cola_prio<T>::atender() {
	if(!cola_vacia()) {
		T dato_raiz = arr[1].dato;
		int pos_act = 1;
		int hijo_izq = 2, hijo_der = 3;
		
		int aux = pos_ultima;
		
		while(aux==pos_ultima) {
				if(hijo_izq < pos_ultima && hijo_der < pos_ultima) {
					if(arr[hijo_izq].prioridad > arr[hijo_der].prioridad) {
						if(arr[hijo_izq].prioridad > arr[pos_ultima].prioridad) {
							arr[pos_act] = arr[hijo_izq];
							pos_act = hijo_izq;
						}else {
							arr[pos_act] = arr[pos_ultima];
							pos_ultima--;
						}
					}else {
						if(arr[hijo_der].prioridad > arr[pos_ultima].prioridad) {
							arr[pos_act] = arr[hijo_der];
							pos_act = hijo_der;
						}else {
							arr[pos_act] = arr[pos_ultima];
							pos_ultima--;
						}
					}	
				}else if(hijo_izq < pos_ultima) {
					if(arr[hijo_izq].prioridad > arr[pos_ultima].prioridad) {
						arr[pos_act] = arr[hijo_izq];
						pos_act = hijo_izq;
					}else {
						arr[pos_act] = arr[pos_ultima];
						pos_ultima--;
					}
				}else if(hijo_der < pos_ultima){
					if(arr[hijo_der].prioridad > arr[pos_ultima].prioridad) {
						arr[pos_act] = arr[hijo_der];
						pos_act = hijo_der;
					}else {
						arr[pos_act] = arr[pos_ultima];
						pos_ultima--;
					}
				}else {
					arr[pos_act] = arr[pos_ultima];
					pos_ultima--;
				}
				hijo_izq = 2*pos_act;
				hijo_der = (2*pos_act) + 1;
		}
		return dato_raiz;
	}else{
		//return NULL;	
	}
}

#endif
