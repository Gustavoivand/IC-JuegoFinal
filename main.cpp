#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
using namespace std;
//VARIABLES GLOBALES
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//DECLARACION DE FUNCIONES

//Funcion de probabilidad de 2 numeros
int probabilidad(int, int, int, int);

//Funcion para establecer limite de movimiento
void limites(int&, int ,int );

//Borrar pantallas
void clrscr();


//JUEGO PRINCIPAL
int main(){
    srand(time(NULL));
    clrscr();
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
    
    //crea una matriz binaria 
    //se puede transitar por los 1
    //los 0 son los muros del laberinto
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (((i==0)&&(j==0))||((i==filas-1)&&(j==columnas-1)))
            {
                laberinto[i][j]=1;
            }else{
                laberinto[i][j]=probabilidad(0,1,55,45);
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


    std::cout<<"Suerte en el desafio, "<<nombre<<endl;
    std::cout<<"Usa las flechas para moverte"<<endl;
    std::cout<<"Cuidado por donde pisas, puedes encontrar trampas en el camino"<<endl;
    system("pause");


    clrscr();
    //imprimir laberinto
    x=0;
    y=0;
    bool exito=false;
    while (!exito)
    {
        std::cout<<"Cuidado por donde pisas, "<<nombre<<". Puedes encontrar trampas en el camino"<<endl;
        std::cout<<endl;
        string inicial=nombre.substr(0,1);
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                if (i==x && j==y)
                {
                    std::cout<<inicial<<" ";
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
        
        
        int c = 0;
        while(c==0)
        {
            switch((c=getch())) {
            case KEY_UP:
                limites(x,1,filas-1);
                if (laberinto[x-1][y]!=0)
                {
                   x--;
                }
                break;
            case KEY_DOWN:
                limites(x,0,filas-2);
                if (laberinto[x+1][y]!=0)
                {
                   x++;
                }
                break;
            case KEY_LEFT:
                limites(y,1,columnas-1);
                if (laberinto[x][y-1]!=0)
                {
                   y--;
                }
                break;
            case KEY_RIGHT:
                limites(y,0,columnas-2);
                if (laberinto[x][y+1]!=0)
                {
                   y++;
                }
                break;
            default:
                
                break;
            }
        }
        
        clrscr();
        if (x==filas-1&&y==columnas-1)
        {
            exito=true;
            std::cout<<"Felicidades, "<<nombre<<". Lograste salir del laberinto."<<endl;
        }
        
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

//primer parametro, variable a ingresar,
//segundo y tercero, límite inferior y superior respectivamente
void limites(int& variable, int inferior,int superior){
    if (variable<inferior)
    {
        variable++;
    }else if (variable>superior)
    {
        variable--;
    }
}

//Borrar informacion de pantalla
void clrscr()
{
  system("cls");
}