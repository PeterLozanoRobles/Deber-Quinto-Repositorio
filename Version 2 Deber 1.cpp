#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#define Impuesto 0.15
int nUsuarios;
//Prototipos de las funciones
int ConsumoMes(int actual, int antetior);
void Guardar(struct Factura *co);
void FacturaMostrar(struct Factura *co);
//structs
using namespace std;
struct Fecha{
	int dia,mes,anio;
};
struct cliente{
	char cedula[20],nombre[20],apellido[10],telefono[30],direccion[30];
};
struct Medidor{
	struct Fecha f;
	struct cliente c;
	int mes_anterior,mes_actual,consumo;
}; 
struct Factura{
	struct Fecha f;
	struct Medidor m;
	struct cliente c;
	float subtotal,impuesto,total;
};
//Funciones
//Funcion para guardar datos
void Guardar(struct Factura *co){
	cout<<"INGRESE CANTIDAD DE PERSONAS A REGISTRAR : ";
    cin>>nUsuarios;
    for(int n=1;n<=nUsuarios;n++){
	cout<<"----------------------------------------\n";
	cout<<"Ingrese sus los siguients datos:\n";
	cout<<"----------------------------------------";
	cout<<"\n Ingrese el dia: ";
	scanf("%d",&co->f.dia);
	cout<<"----------------------------------------";
	cout<<"\n Ingrese el mes: ";
	scanf("%d",&co->f.mes);
	cout<<"----------------------------------------";
	cout<<"\n Ingrese el anio: ";
	scanf("%d",&co->f.anio);
	cout<<"----------------------------------------";
	fflush(stdin);
	cout<<"\nIngrese su Cedula: ";
	gets(co->c.cedula);
	cout<<"----------------------------------------";
	cout<<"\nIngrese su Nombre: ";
	gets(co->c.nombre);
	cout<<"----------------------------------------";
	cout<<"\nIngrese su Apellido: ";
	gets(co->c.apellido);
	cout<<"----------------------------------------";
	cout<<"\nIngrese su Telefono: ";
	gets(co->c.telefono);
	cout<<"----------------------------------------";
	cout<<"\nIngrese su Direccion: ";
	gets(co->c.direccion);
	cout<<"----------------------------------------";
	cout<<"\nIngrese la lectura del mes anterior: ";
	scanf("%d",&co->m.mes_anterior);
	cout<<"----------------------------------------";
	cout<<"\nIngrese la lectura del mes actual: ";
	scanf("%d",&co->m.mes_actual);
	cout<<"----------------------------------------";
	co->m.consumo=ConsumoMes(co->m.mes_actual, co->m.mes_anterior);
}
//funcion para calculo de consumo
int ConsumoMes(int actual, int anterior){
	int con=0;
	con=actual - anterior;
	return con;
}
//funcion para calculo subtotal
float CalcularSubtotal(float consumo) {
	if (consumo <= 100) {
		return consumo * 0.30;
	} else if (consumo <= 1000) {
		return consumo * 0.20;
	} else {
		return consumo * 0.10;
	}
}
//Calculo final o total
float CalcularTotal(float subtotal) {
	return subtotal + (subtotal * Impuesto);
}
}
}
//Mostrar factura
void FacturaMostrar(struct Factura *co){
	co->subtotal=CalcularSubtotal(co->m.consumo);
	co->total=CalcularTotal(co->subtotal);
	cout<<"----------------------------------------";
	printf("\nFECHA: %d %d %d\n",co->f.dia, co->f.mes, co->f.anio);
	cout<<"----------------------------------------";
	printf("\nNumero de Cedula: %s\n",co->c.cedula);
	cout<<"----------------------------------------";
	printf("\nNombre: %s\n",co->c.nombre);
	cout<<"----------------------------------------";
	printf("\nApellido: %s\n",co->c.apellido);
	cout<<"----------------------------------------";
	printf("\n Su Consumo es: %d\n",co->m.consumo);
	cout<<"----------------------------------------";
	printf("\n El Subtotal es: %f\n",co->subtotal);
	cout<<"----------------------------------------";
	printf("\n El Total es: %f\n",co->total);
	cout<<"----------------------------------------";
	getch();
}
//Main
int main(){
	int opc;
	struct Factura f;
	//Menú
	do{
	system("cls"); 	
	printf("*----------------------------------------------------*\n");
	printf("*                  MENU DE OPCIONES                  *\n");
    printf("*----------------------------------------------------*");
    printf("\n*   1. Guardar informacion de clientes.              *");
    printf("\n*   2. Ver Factura.                                  *");
    printf("\n*   3. Salir.                                        *\n");
    printf("*----------------------------------------------------*\n");
    printf("\n   Introduzca una opcion (1-3):");
    scanf("%d", &opc );    
        system("cls");
	switch ( opc ){
        case 1: 
            Guardar(&f);
                    break;
        case 2: 
            FacturaMostrar(&f);
                    break;
	}
    }while ( opc!=3);
    return 0;
    getch();
}
