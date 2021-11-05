#include <iostream>

class ListaEnteros {
	private:
		int cuenta;
		int capacidad;
		int *items;
		void agrandar();

	public:
		ListaEnteros(int capacidad); // Constructores
		ListaEnteros();
		ListaEnteros (const ListaEnteros &otralista); 
		~ListaEnteros(); // Destructor
		bool estaVacia(); int tamanio();
		void insertar(int indice, int item);
		void adjuntar(int item); 
		int obtener(int indice);
		bool contiene(int item); int remover(int indice);
		void imprimirlista();
};

ListaEnteros::ListaEnteros(int capacidad){
	this->cuenta = 0; this->capacidad = capacidad;
	this->items= new int[capacidad];
}

ListaEnteros::~ListaEnteros(){
	delete[] items;
}

bool ListaEnteros::estaVacia(){ 
	return this->cuenta==0;
}

int ListaEnteros::tamanio(){
	return this->cuenta;
}

int ListaEnteros::obtener(int indice){
	if(indice<0 || indice >= this->cuenta) throw "INDICE FUERA DE RANGO";
	if(this->estaVacia()) throw "NO SE PUEDEN RECUPERAR ELEMENTOS DE UNA LISTA VACIA";
	return this->items[indice];
}

void ListaEnteros::insertar(int indice, int item){
	if(indice < 0 || indice >this->cuenta) throw "Indice fuera de rango";
	if(this->cuenta >= this->capacidad) this->agrandar();

	for(int i =cuenta-1; i >= indice; i--){ 
		this->items[i+1]= this->items [i];
	}
	this->items[indice] = item; 
	this->cuenta++;
}

void ListaEnteros::agrandar(){ 
	int *temp = this->items; 
	this->capacidad *=2; 
	this->items = new int[capacidad]; 
	
	for(int i=0; i < this->cuenta; i++){ 
		this->items[i] = temp[i];
	}
	delete[] temp;

}

void ListaEnteros::adjuntar(int item){ 
	this->insertar(this->cuenta, item);
}

bool ListaEnteros::contiene(int item) { 
	for(int i = 0; i < this->cuenta; i++){ 
		if(this->items[i]== item) 
		return true;
	}
	return false;
}

int ListaEnteros::remover(int indice){ 
	if(this->estaVacia()) throw "No se puede recuperar elementos de una lista vacia";
	if(indice <0 || indice > this->cuenta) throw "Indice fuera de rango";

	int valor = this->items[indice]; 
	for(int i= indice; i < cuenta -1;i++){ 
		this->items[i] = this->items[i+1];
	}
	this->cuenta--; 
	return valor;
}

void ListaEnteros:: imprimirlista(){
	std::cout << "| ";

	for (int i = 0; i < this->cuenta; i++){ 
		std::cout << this->obtener(i) << " ";
		std::cout << std::endl;
	}
}

int main(){
	ListaEnteros lint1(10);
	
	lint1.adjuntar (12); 
	lint1.adjuntar (7);
	lint1.adjuntar (19);
	lint1.imprimirlista();
	
	lint1.adjuntar (30); 
	lint1.imprimirlista();
	
	lint1.insertar (1,41); 
	lint1.imprimirlista();
	
	lint1.remover(2); 
	lint1.imprimirlista();
	
	return 0;
}
