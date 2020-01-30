#include <iostream>
using namespace std;
//Main
int main(){
 int I = 0;
 cout<<"Ingrese una palabra: "<<endl;
 string palabra;
 cin>>palabra;
 int J = palabra.length() - 1;
 int mitad = J / 2;
 while(palabra[I] == palabra[J]){
 if(mitad == I){
 cout << "Es palindromo";
 break;
 }
 J--;
 I++;
 }
 if(mitad != I)
 cout << "No es palindromo";
 return 0;
 }
