#include<iostream>
#include<cstdlib>
using namespace std;
//prototipo de la funcion
void INV(int N);
//main
int main(void){
	int num;
	//validacion
	do{
		cout<<"Ingrese numero:";
		cin>>num;
		if(num<0){
		cout<<"\nINGRESE UN NUMERO ENTERO POSITIVO, POR FAVOR\n";
	    }
    }
while(num<0);
cout<<"\n El numero invertido es = ";
INV(num);
return 0;
}
//Funcion recursiva
void INV(int N){
	cout<<N%10;
	if(N>10) //Caso base
	INV(N/10); //Caso recursivo
	
}
	
