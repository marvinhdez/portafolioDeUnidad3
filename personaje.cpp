#include <iostream>
#include <string>

using namespace std;

class personaje {
	private:
		string nombre;
		int puntosVida;
		
	public: 
		personaje(string nombre, int puntosVida);
		int puntosPerdido;
		int recibirGolpe();
		bool estaVivo();
		int getPuntosVida();
		string getNombre();
		int comer();
};

personaje::personaje(string nombre, int puntosVida){
	this->nombre=nombre;
	this->puntosVida=puntosVida;
	this->puntosPerdido;
}

int personaje::recibirGolpe(){
	if(puntosVida>puntosPerdido){
		puntosVida-=puntosPerdido;
	}else if(puntosVida<puntosPerdido){
		puntosVida=0;
	}	
}

bool personaje::estaVivo(){
	if(puntosVida>0){
		return true;
	}else {
		return false;
	}
}

int personaje::getPuntosVida(){
	return puntosVida;
}

string personaje::getNombre(){
	return this->nombre;
}

int personaje::comer(){
	puntosVida-=puntosPerdido;
}

int main(){
	
	personaje pokacho("Pokacho",1230);
	cout<<"NOMBRE DEL PERSONAJE: " << pokacho.getNombre() << endl;
	cout<<"PUNTO DE VIDA: " << pokacho.getPuntosVida() <<endl <<endl;
	
	personaje tocinauro("tocinauro",1090);
	cout<<"NOMBRE DEL PERSONAJE: " << tocinauro.getNombre() << endl;
	cout<<"PUNTO DE VIDA: " << tocinauro.getPuntosVida() <<endl  <<endl;

	personaje cauchin("cauchin",2015);
	cout<<"NOMBRE DEL PERSONAJE: " << cauchin.getNombre() << endl;
	cout<<"PUNTO DE VIDA: " << cauchin.getPuntosVida() <<endl  <<endl;		
	return 0;
}

