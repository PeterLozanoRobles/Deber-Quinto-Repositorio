#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
 //prototipo de la funcion 
int palindroma(char PAL[],int ini, int fin);
//main
int main( void ){
    char PAL[50];
    int tam,pal;
    cout<<" INGRESE PALABRA: ";
    cin.getline(PAL,50);
    tam=strlen(PAL);
    pal=palindroma(PAL,0,tam-1);
    if(pal==1)
    cout<<"\nSi es palindroma\n";
    else if(pal==0)
    cout<<"\n\nNO es Palindroma: \n";
    return 0;
}
//Funcion recursiva
int palindroma(char PAL[],int ini, int fin){
     if(ini >= fin)//Caso base
          return 1;
     if(PAL[ini] == PAL[fin])
          palindroma(PAL, ini+1, fin-18); //Caso recursivo
    else return 0;
}
