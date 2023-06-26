#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//DECLARACION DE FUNCIONES

//Funcion de probabilidad de 2 numeros
int probabilidad(int, int, int, int);


//JUEGO PRINCIPAL
int main(){
    //preguntar al usuario por el numero de filas y columnas de la matriz cuadrada
    std::cout<<"BIENVENIDO AL LABERINTO DE LA FC-UNI"<<endl;
    system("pause");
    std::cout<<"Para comenzar ingresa tu nombre:"<<endl;
    string nombre;
    std::cin>>nombre;
    std::cout<<"Bienvenido, "<<nombre<<endl;
    std::cout<<"Escoge la cantidad de filas de tu laberinto, recuerda que el mínimo posible es 4"<<endl;
    int filas;
    std::cin>>filas;
    while (filas<4)
    {
        std::cout<<"tu laberinto debe tener al menos 4 filas"<<endl;
        std::cin>>filas;
    }
    
    std::cout<<"Escoge la cantidad de columnas de tu laberinto, recuerda que el mínimo posible es 4"<<endl;
    int columnas;
    std::cin>>columnas;
     while (columnas<4)
    {
        std::cout<<"tu laberinto debe tener al menos 4 columnas"<<endl;
        std::cin>>columnas;
    }


    //crear laberinto
   
    








    int numero=probabilidad(0,1,20,80);
    std::cout<<"Numero: "<<numero;
    return 0;
}

//DEFINICION DE FUNCIONES

//Funcion de probabilidad de 2 numeros
/// <param name="a">Used to indicate status.</param>
int probabilidad(int a, int b, int pa, int pb){
    srand(time(NULL));
    int n =1+(rand()%100);
    if(n<=pa)
        return a;
    if(n<=(pa+pb))
        return b;
}