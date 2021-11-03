#include <iostream>
#include <string>

using namespace std;

class cuentaBancaria {
	private:
		string numeroCuenta;
		string nombreTitular;
		double saldo;
	
	public:
		cuentaBancaria(string num, string titular, double saldo);
		double getSaldo();
		string getNumeroCuenta();
		string getNombreTitular();
		void depositar(double importeDeposito);
		void retirar(double importeRetiro);
};

cuentaBancaria::cuentaBancaria(string num, string titular, double saldo){
	if(saldo<0){
		this->saldo=0.00;
	} else {
		this->saldo=saldo;
	}
	this->numeroCuenta=num;
	this->nombreTitular=titular;
}

double cuentaBancaria::getSaldo(){
	return this->saldo;
}

string cuentaBancaria::getNumeroCuenta(){
	return this->numeroCuenta;
}

string cuentaBancaria::getNombreTitular(){
	return this->nombreTitular;
}

void cuentaBancaria::depositar(double importeDeposito){
	if(importeDeposito>0){
		this->saldo+=importeDeposito;
	} else {
		cout<<"!X- IMPORTE NO VALIDO -X¡\n";
	}
}

void cuentaBancaria::retirar(double importeRetiro){
	if(importeRetiro>0 && importeRetiro<= this->saldo){
		this->saldo-=importeRetiro;
	} else {
		cout<<"!X- IMPORTE NO VALIDO -X¡\n";
	}
}

int main(){
	cuentaBancaria micuenta("C-480920", "Maria Reyes", 2500.00);
	cout<<"\n TITULAR: "<< micuenta.getNombreTitular() <<endl;
	cout<<"N° CUENTA: "<< micuenta.getNumeroCuenta() <<endl,
	cout<<"SALDO:  $"<< micuenta.getSaldo() <<endl;
	
	cuentaBancaria miamistad("A-480920", "Odir Guerra", 200.75);
	cout<<"\n TITULAR: "<< miamistad.getNombreTitular() <<endl;
	cout<<"N° CUENTA: "<< miamistad.getNumeroCuenta() <<endl,
	cout<<"SALDO:  $"<< miamistad.getSaldo() <<endl;


	cout<<"\n QUIERO RETIRAR $500 DE LA CUENTA "<< micuenta.getNumeroCuenta() <<endl;
	cout<<"SALDO INICIAL: $"<< micuenta.getSaldo() <<endl;
	micuenta.retirar(500);
	cout<<"SALDO FINAL:  $"<< micuenta.getSaldo() <<endl;	
}
