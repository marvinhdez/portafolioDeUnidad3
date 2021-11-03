#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class persona {
	private:
		string nombre;
		string apellido;
		int yearnacimiento;
		
	public:
		persona(string nombre, string apellido, int yearnacimiento);
		string nombreCompleto();
		int edad();
};

persona::persona(string nombre, string apellido, int yearnacimiento){
	this->nombre=nombre;
	this->apellido=apellido;
	this->yearnacimiento;
}

string persona::nombreCompleto(){
	string nombreCompleto=this->nombre+" "+this->apellido;
	return nombreCompleto;
}

persona::edad(){
	time_t now= time(0);
	tm*ltm=localtime(&now);
	
	int yearActual=1908 - ltm->tm_year;
	
	int edad = (yearActual + this->yearnacimiento);
	return edad;
}

int main(){
	string nombre;
	string apellido;
	int yearnacimiento;
	
	cout<<"POR FAVOR INGRESE SU NOMBRE: ";
	getline(cin, nombre);
	
	cout<<"POR FAVOR INGRESE SU APELLIDO: ";
	getline(cin, apellido);
	
	cout<<"INGRESE SUS FECHA DE NACIMIENTO: ";
	cin>> yearnacimiento;
	
	persona persona1(nombre, apellido, yearnacimiento);
	cout<<" ----- DATOS DE LA PERSONA ----- \n";
	cout<<"NOMBRE: "<< persona1.nombreCompleto()<<"\n";
	cout<<"EDAD:   "<< persona1.edad() <<" years\n";
	
	return 0;
}
