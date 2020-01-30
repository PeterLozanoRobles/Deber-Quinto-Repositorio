//Nombre: PETER LOZANO ROBLES
//Curso: SOFTWARE 3-2
//Fecha: 2 de Noviembre del 2019
#include<iostream>
#include<conio.h>
using namespace std;
void TamanioVector();
void IngresarDatos();
void OrdenarporburbujaE(int arreglo[], int n);
void OrdenarporburbujaM (int arreglo[], int n);
void intercambiar (int& x, int& y);
void ordIntercambio (int arreglo[], int n);
void Ordenarporseleccion (int arreglo[], int n);
void mostrarDatos(int arreglo[], int n);
int arreglo[100],n;
int main(){
    int opc1,opc2;
    do{
    system ("cls");
    printf("\t\t|----------------Menu---------------------|\n");
    printf("\t\t|       1. Leer tamaño del vector         |\n");
    printf("\t\t|   	2. Ingresar datos                 |\n");
    printf("\t\t|    	3. Ordenar datos                  |\n");
    printf("\t\t|   	4. Mostrar datos                  |\n");
    printf("\t\t|   	5. Salir                          |\n");
    printf("\t\t|-----------------------------------------|\n");
    printf("\t\t\tEliga una opcion: ");		
	scanf("%d",&opc1);
    
    switch(opc1){
    	case 1: system ("cls");
				printf("\n\tLeer tamaño de vector. \n\n");
    			TamanioVector();
    			system ("pause");
    			break;
    	case 2: system ("cls");
				printf("\n\tIngresar elementos. \n\n");
    			IngresarDatos();
    			system ("pause");
    			break;
        case 3:	system ("cls");
        		printf("-----------Metodos para ordenar-----------\n");
        		printf("\t1. Metodo de Burbuja Estandar\n");
            	printf("\t2. Metodo de Burbuja Mejorada\n");
            	printf("\t3. Metodo de Intercambio\n");
            	printf("\t4. Metodo de Seleccion\n");
            	printf("\n\tElija una opcion: ");   scanf("%d",&opc2);

            	switch(opc2){
               		case 1:	OrdenarporburbujaE(arreglo, n);
               				printf("\n\n");
							system ("pause");        
                			break;          
      				case 2:	OrdenarporburbujaM (arreglo, n);
      						printf("\n\n");
							system ("pause");        
                			break;          
                	case 3:	ordIntercambio(arreglo,n);
                			printf("\n\n");
							system ("pause");        
                			break;          
    	        	case 4:	Ordenarporseleccion (arreglo, n);
    	        			printf("\n\n");
							system ("pause");       
                			break;          
                	default:printf("Opcion no valida. \n");
                			system ("pause"); 
							break;
					}break;
        case 4: printf("\n\tMostrar datos. \n\n");
        		mostrarDatos(arreglo, n);
        		system ("pause");
        		break;
        case 5: printf("\n Saliendo....\n");
        		break;
		default:printf("\n Opcion no valida\n\n");
				system ("pause");
				break;
		}
	}while (opc1!=5);
	getch();
	return 0;
}
void TamanioVector(){
	cout<<" Ingrese el tamaño del vector: ";
    cin>>n;
    printf("\n\n Se ha ingresado el tamaño del vector. \n\n");
}

void IngresarDatos(){
    for(int i=0 ; i<n ; i++){
	cout<<" Ingrese los valores: \t";
    cin>>arreglo[i];
    }
	printf("\n\n Se han ingresado los valores. \n\n");
}

void OrdenarporburbujaE(int arreglo[], int n){
	int i=0 , j=0 , aux=0;
	for(i=0 ; i<n-1 ; i++){
		for(j=0 ; j<n-1 ; j++){
			if(arreglo[j] > arreglo[j+1]){
				aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
			}
		}
	}
	cout<<"\n Lista ordenada por el metodo de burbuja estandar. \n\n";
}

void OrdenarporburbujaM (int arreglo[], int n){
	int j=0,aux=0,desorden=0;
	do{
		for(j=0 ;j<n-1 ; j++){
			if(arreglo[j] > arreglo[j+1]){
				aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
				desorden = 1;
			}
		}
	}while(desorden != 0);
	cout<<"\n Lista ordenada por el metodo de burbuja mejorada. \n\n";
}

void intercambiar (int& x, int& y){
	int aux = x;
	x = y;
	y = aux;
}

void ordIntercambio (int arreglo[], int n){
	int i, j;
	for (i=0; i<n-1; i++)		
		for (j=i+1 ; j<n ; j++)	
			if (arreglo[i] > arreglo[j]){		
				intercambiar(arreglo[i] , arreglo[j]);
			}
	cout<<"\n Lista ordenada por metodo de intercambio. \n\n";
}

void Ordenarporseleccion (int arreglo[], int n){
	int i=0, j=0, aux=0, min=0;
	for(i=0 ; i<n-1 ; i++){
		min=i;
		for(j=i+1 ; j<n ; j++){
			if(arreglo[j] < arreglo[min]){
				min=j;
			}
		}
	}
	cout<<"\n Lista ordenada por metodo de seleccion. \n\n";
}

void mostrarDatos(int arreglo[], int n){
	cout<<"\n\t\tMostrar datos\n";
	cout<<"\n Sus numeros ordenados son: ";
    for(int i=0 ; i<n ; i++){
    	cout<<arreglo[i]<<" ";	
	}
	cout<<"\n\n Elemento menor: "<<arreglo[0];
	cout<<"\n\n Elemento mayor: "<<arreglo[n-1];
	cout<<"\n\n";
}
