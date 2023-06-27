#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include "musica.cpp"
using namespace std;
//VARIABLES GLOBALES
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
const int trampa=30;//la probabilidad de encontrar una trampa

//DECLARACION DE FUNCIONES

//Funcion de probabilidad de 2 numeros
int probabilidad(int, int, int, int);

//Funcion para establecer limite de movimiento
void limites(int&, int ,int );

//Borrar pantallas
void clrscr();

//funcion para imprimir barra de salud
string salud(int);

//yan ken po
bool piedrapapel();

//evaluar yankenpo
int evaluaryankenpo(int , int );


//escogido por sistema
string yankenescogido(int);



//JUEGO PRINCIPAL
int main(){
    CMelody RoomOnFire1;
    CMelody RoomOnFire2;
    CMelody RoomOnFire3;
    CMelody RoomOnFire4;
    Melodia1(RoomOnFire1);
    Melodia2(RoomOnFire2);
    Melodia3(RoomOnFire3);
    Melodia4(RoomOnFire4);
    srand(time(NULL));
    clrscr();
    //preguntar al usuario por el numero de filas y columnas de la matriz cuadrada
    std::cout<<"BIENVENIDO AL LABERINTO DE LA FC-UNI"<<endl;
    RoomOnFire1.Play();
    RoomOnFire1.Play();
    system("pause");
    
    std::cout<<"Para comenzar ingresa tu nombre:"<<endl;
    RoomOnFire2.Play();
    RoomOnFire2.Play();
    string nombre;
    std::cin>>nombre;
    
    std::cout<<"Bienvenido, "<<nombre<<endl;
    std::cout<<"Escoge la cantidad de filas de tu laberinto, recuerda que el mínimo posible es 4"<<endl;
    RoomOnFire1.Play();
    RoomOnFire1.Play();
    int filas;
    std::cin>>filas;
    while (filas<4)
    {
        std::cout<<"tu laberinto debe tener al menos 4 filas"<<endl;
        std::cin>>filas;
    }
    
    std::cout<<"Escoge la cantidad de columnas de tu laberinto, recuerda que el mínimo posible es 4"<<endl;
    RoomOnFire2.Play();
    RoomOnFire2.Play();
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
            }else if(laberinto[i][j-1]==1){
                laberinto[i][j]=probabilidad(0,1,80,20);
            }else{
                laberinto[i][j]=probabilidad(0,1,50,50);
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
    int puntos_perdidos=100/((filas+columnas-1)*trampa/100);
    std::cout<<"Suerte en el desafio, valiente "<<nombre<<endl;
    std::cout<<"Usa las flechas para moverte"<<endl;
    std::cout<<"Cuidado por donde pisas, puedes encontrar trampas en el camino"<<endl;
    RoomOnFire1.Play();
    RoomOnFire1.Play();
    RoomOnFire2.Play();
    
    system("pause");
    clrscr();
    
    //Inicia el juego
    char muro = (char)254u;
    x=0;
    y=0;
    int encuentra_trampa=0;
    int estadosalud=100;
    int pasos=0;
    int contrapasos=0;
    bool exito=false;
    bool juego=false;
    while (!exito)
    {
        std::cout<<"Cuidado por donde pisas, "<<nombre<<". Puedes encontrar trampas en el camino"<<endl;
        std::cout<<"Salud:"<<salud(estadosalud);
        std::cout<<endl;
        string inicial=nombre.substr(0,1);
        //imprime laberinto:
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
                    std::cout<<muro<<" ";
                }else{
                    std::cout<<" "<<" ";
                }
            }
            std::cout<<endl;
        }
        
        if(contrapasos%2==0){
            RoomOnFire1.Play();
        }else{
            RoomOnFire2.Play();
        }
        //selecciona una direccion para moverte
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
        
        //evaluar la probabilidad de encontrarte con una trampa
        encuentra_trampa=probabilidad(0,1,trampa,100-trampa);
        if (encuentra_trampa==0)
        {
           std::cout<<endl;
           std::cout<<"Trampa salvaje aparece"<<endl;
           RoomOnFire3.Play();
           RoomOnFire4.Play();
           system("pause");
           juego=piedrapapel();
           
           if (juego)
           {
            std::cout<<"Felicidades, puedes continuar tu viaje"<<endl;
            
            system("pause");
           }else{
            std::cout<<"has perdido "<<puntos_perdidos<<" puntos de vida"<<endl;
            system("pause");
            estadosalud-=puntos_perdidos;
                if (estadosalud<0)
                {
                    std::cout<<"Has perdido todos tus puntos de vida"<<endl;
                    system("pause");
                    std::cout<<"Game Over"<<endl;
                    break;
                }
                
           }
           
        }
        

        clrscr();
        if (x==filas-1&&y==columnas-1)
        {
            exito=true;
            std::cout<<"¡¡Felicidades, "<<nombre<<". Lograste salir del laberinto!!"<<endl;
            system("pause");
        }
        pasos++;
        if (pasos%2==0)
        {
            contrapasos=pasos/2;
        }else{
            contrapasos=(pasos+1)/2;
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
    return 0;
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

//Devuelve barra de salud
string salud(int valor){
    char vida = (char)254u;
    int cantidad=20*valor/100;
    string salida="[";
    for (int i = 0; i < 20; i++)
    {
        if (i<cantidad)
        {
            salida+=vida;
        }else{
            salida+=" ";
        }
    }
    salida+="] "+to_string(valor)+"%";
    return salida;
}
//Borrar informacion de pantalla
void clrscr()
{
  system("cls");
}

//trampa piedra papel o tijera
bool piedrapapel(){
    int jugadas=0;
    int victorias=0;
    int derrotas=0;
    int yankenpo=0;
    int n=0;
    CMelody RoomOnFire5;
    Melodia5(RoomOnFire5);

    clrscr();
    std::cout<<"Viajero salvaje: Vamos a Jugar al Yan Ken Po"<<endl;
    std::cout<<"Si ganas dos de tres, te dejare seguir tu camino"<<endl;
    system("pause");

    while (derrotas<2&&victorias<2)
    {
        clrscr();
        yankenpo=0;
        std::cout<<"Jugadas: "<<jugadas<<endl;
        std::cout<<"Victorias: "<<victorias<<endl;
        std::cout<<"Derrotas: "<<derrotas<<endl;
        std::cout<<"escoge:"<<endl;
        std::cout<<"1. Piedra"<<endl;
        std::cout<<"2. Papel"<<endl;
        std::cout<<"3. Tijera"<<endl;
        while (yankenpo<1||yankenpo>3)
        {
            std::cin>>yankenpo;
        }
        n =1+(rand()%3);

        std::cout<<"Tu escogiste: "<<yankenescogido(yankenpo)<<endl;
        std::cout<<"Yo escogi: "<<yankenescogido(n)<<endl;
        RoomOnFire5.Play();
        system("pause");
        if (evaluaryankenpo(yankenpo,n)==1)
        {
            std::cout<<"Ganaste esta vez"<<endl;
            victorias++;
        }else if(evaluaryankenpo(yankenpo,n)==2){
            std::cout<<"Jaja eres muy malo para esto"<<endl;
            derrotas++;
        }else{
            std::cout<<"Esta jugada no cuenta"<<endl;
        }
        jugadas++;
        system("pause");
    }
    
    if (victorias==2)
    {
        return true;
    }
    
    return false;
}

int evaluaryankenpo(int a, int b){
//1 piedra
//2 papel
//3 tijera
//devuelve 1 gana jugador
//devuelve 2 gana maquina
//devuelve 3 empate
    if ((a==1&&b==3)||(a==2&&b==1)||(a==3&&b==2))
    {
        return 1;
    }else if(a==b){
        return 3;
    }
    return 2;
}

string yankenescogido(int a){
    switch (a)
    {
    case 1:
        return "Piedra";
        break;
    case 2:
        return "Papel";
        break;
    case 3:
        return "Tijera";
        break;
    default:
        break;
    }
}