#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;
//DECLARACION DE FUNCIONES

//Funcion de probabilidad de 2 numeros
int probabilidad(int, int, int, int);


//JUEGO PRINCIPAL
int main(){
    srand(time(NULL));
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
    int laberinto[filas][columnas];
    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (((i==0)&&(j==0))||((i==filas-1)&&(j==columnas-1)))
            {
                laberinto[i][j]=1;
            }else{
                laberinto[i][j]=probabilidad(0,1,60,40);
            }
            
        }
        
    }
    
    //crear solucion
    bool solucion=false;
    int x,y;
    int prob;
    x=0;
    y=0;
    while (!solucion)
    {
        //abajo o derecha
        if (x <filas-1 && y<columnas-1)
        {
            prob=probabilidad(0,1,50,50);
            if (prob==0)
            {
                y++;
                laberinto[x][y]=1;
            } else
            {
                x++;
                laberinto[x][y]=1;
            }
        }else if (x <filas-1 && y==columnas-1)
        {
            x++;
            laberinto[x][y]=1;
        }else if (x ==filas-1 && y<columnas-1)
        {
            y++;
                laberinto[x][y]=1;
        }else if (x ==filas-1 && y==columnas-1)
        {
            solucion=true;
        }  
    }
    //imprimir laberinto
    std::cout<<endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i==0 && j==0)
            {
                std::cout<<"I"<<" ";
            }else if (i==filas-1 && j==columnas-1)
            {
                std::cout<<"F"<<" ";
            }else if (laberinto[i][j]==0)
            {
                std::cout<<"X"<<" ";
            }else{
                std::cout<<" "<<" ";
            }
        }
        std::cout<<endl;
    }
    

    
   
    


    return 0;
}

//DEFINICION DE FUNCIONES

//Funcion de probabilidad de 2 numeros
/// <param name="a">Used to indicate status.</param>
int probabilidad(int a, int b, int pa, int pb){
    int n =1+(rand()%100);
    if(n<=pa)
        return a;
    if(n<=(pa+pb))
        return b;
}