//REALIZADO POR JUAN DAVID ROBLEDO Y DANIEL FELIPE ALZATE
#include <iostream>
#include <list>
#include <fstream>
#include <string.h>
#include <vector>
#include "Aeropuerto.h"

int main()
{
    //ENTREGA #1
    std::list<Vuelo>vuelos;
    std::list<Avion>aviones;
    std::list<Piloto>pilotos;
    //ENTREGA #2
    NodoCiudad *ciudad = NULL;
    NodoDestino *destino = NULL;
    //ENTREGA #3
    std::vector<Ciudad> verticesCiudad;
    std::vector<std::vector<Destino>> aristasCiudad;

    char avionAsig[40];
    char IATA[3];
    int distancia = 0;
    std::string auxi;
    Ciudad auxCi;
    Destino auxDe;
    Ciudad *auxiliar = NULL;
    int opcion = 0;

    do
    {
        //MENU CON LAS OPCIONES SOLICITADAS PARA LA ENTREGA #1.
        std::cout<<"                                                  .:MENU:."<<std::endl;
        std::cout<<"                                            .:PRIMERA ENTREGA:."<<std::endl;
        std::cout<<"                               .:Presiona 1 para inicializar los aviones:."<<std::endl;
        std::cout<<"                               .:Presiona 2 para inicializar los pilotos:."<<std::endl;
        std::cout<<"                               .:Presiona 3 para inicializar los vuelos:."<<std::endl;
        std::cout<<"              .:Presiona 4 para mostrar en pantalla la informacion de todos los aviones:."<<std::endl;
        std::cout<<"              .:Presiona 5 para mostrar en pantalla la informacion de todos los pilotos:."<<std::endl;
        std::cout<<"         .:Presiona 6 para mostrar en pantalla la informacion de todos los vuelos programados:."<<std::endl;
        std::cout<<"                        .:Presiona 7 para realizar un vuelo que se encuentre programado:."<<std::endl;
        //MENU CON LAS OPCIONES SOLICITADAS PARA LA ENTREGA #2.
        std::cout<<"                                            .:SEGUNDA ENTREGA:."<<std::endl;
        std::cout<<"                               .:Presiona 8 para inicializar las ciudades:."<<std::endl;
        std::cout<<"                         .:Presiona 9 para inicializar el diccionario de destino:."<<std::endl;
        std::cout<<"                           .:Presiona 10 para buscar una ciudad por sus siglas:."<<std::endl;
        std::cout<<"                                 .:Presiona 11 para buscar un destino:."<<std::endl;
        std::cout<<"                                .:Presiona 12 para guardar una ciudad:."<<std::endl;
        std::cout<<"                                 .:Presiona 13 para guardar un destino:."<<std::endl;
        //MENU CON LAS FUNCIONES SOLICITADAS PARA LA ENTREGA #3
        std::cout<<"                                            .:TERCERA ENTREGA:."<<std::endl;
        std::cout<<"                               .:Presiona 14 para inicializar el grafo:."<<std::endl;
        std::cout<<"                                .:Presiona 15 para guardar una ciudad:."<<std::endl;
        std::cout<<"                                .:Presiona 16 para guardar un destino:."<<std::endl;
        std::cout<<"                                  .:Presiona 17 para buscar una ruta:."<<std::endl;
        std::cout<<"                            .:Presiona 18 para buscar la mejor ruta/tiempo:."<<std::endl;
        std::cout<<"                          .:Presiona 19 para buscar la mejor ruta/distancia:."<<std::endl;
        std::cout<<"                                 .:Presiona 20 para salir del programa:."<<std::endl<<std::endl;
        std::cout<<"Presiona el numero de la opcion deseada: ";
        std::cin>>opcion;
        std::cout<<std::endl;

        switch(opcion)
        {
        //ENTREGA #1
        case 1:
            aviones = inicializarAviones();
            break;

        case 2:
            pilotos = inicializarPilotos();
            break;

        case 3:
            vuelos = inicializarVuelos();
            break;

        case 4:
            imprimirAviones(aviones);
            break;

        case 5:
            imprimirPilotos(pilotos);
            break;

        case 6:
            imprimirVuelos(vuelos);
            break;

        case 7:
            imprimirVuelos(vuelos);
            std::cout<<"Cual vuelo desea realizar? (Escribe el avion asignado del vuelo)"<<std::endl;
            std::cin>>avionAsig;
            vuelos = RealizarVuelo(vuelos, avionAsig);
            break;

        //ENTREGA #2
        case 8:
            inicializarCiudades(ciudad);
            std::cout<<"Desea ver el preorder del arbol ciudad?";
            std::cin>>auxi;
            if(auxi=="SI"||auxi=="si"||auxi=="Si")
            {
                preorden(ciudad);
            }
            break;

        case 9:
            inicializarDestinos(destino, ciudad);
            break;

        case 10:
            std::cout<<"Ingrese el codigo IATA para buscar la ciudad";
            std::cin>>IATA;
            //auxiliar = buscarCiudad(ciudad, IATA);
            std::cout<<auxiliar->codigoIATA<<std::endl;
            std::cout<<auxiliar->nombreAeropuerto<<std::endl;
            std::cout<<auxiliar->nombreCiudad<<std::endl;
            std::cout<<auxiliar->pais<<std::endl;
            break;

        case 11:
            std::cout<<"Ingrese la distancia para buscar el destino";
            std::cin>>distancia;
            //std::cout<<buscarDestino(destino, distancia)->distancia<<std::endl;
            //std::cout<<buscarDestino(destino, distancia)->tiempo<<std::endl;
            break;

        case 12:
            std::cout<<"Ingrese el codigo IATA de la ciudad que desea agregar"<<std::endl;
            std::cin>>auxCi.codigoIATA;
            //if(buscarCiudad(ciudad, auxCi.codigoIATA)->bandera==false){
            std::cout<<"Ingrese el nombre del aeropuerto de la ciudad que desea agregar"<<std::endl;
            std::cin>>auxCi.nombreAeropuerto;
            std::cout<<"Ingrese el nombre de la ciudad que desea agregar"<<std::endl;
            std::cin>>auxCi.nombreCiudad;
            std::cout<<"Ingrese el pais de la ciudad que desea agregar"<<std::endl;
            std::cin>>auxCi.pais;
            insertarNodoCiudad(ciudad, auxCi);
            std::cout<<"La ciudad se guardo correctamente"<<std::endl;
            //}else{
            //std::cout<<"La ciudad que ingresaste ya existe :("<<std::endl;
            //}
            break;

        case 13:
            std::cout<<"Ingrese el codigo IATA de la ciudad (origen) que desea agregar"<<std::endl;
            std::cin>>IATA;
            //if(buscarCiudad(ciudad, IATA)->bandera!=false){
            //auxDe.origen=buscarCiudad(ciudad, IATA);
            std::cout<<"Ingrese el codigo IATA de la ciudad (destino) que desea agregar"<<std::endl;
            std::cin>>IATA;
            //if(buscarCiudad(ciudad, IATA)->bandera!=false){
            //auxDe.destino=buscarCiudad(ciudad, IATA);
            std::cout<<"Ingrese la distancia del destino que desea agregar"<<std::endl;
            std::cin>>auxDe.distancia;
            std::cout<<"Ingrese el tiempo del destino que desea agregar"<<std::endl;
            std::cin>>auxDe.tiempo;
            insertarNodoDestino(destino, auxDe);
            std::cout<<"El destino se guardo correctamente"<<std::endl;
            //}else{
            //std::cout<<"La ciudad que ingresaste no existe :("<<std::endl;
            //}
            //}else{
            //std::cout<<"La ciudad que ingresaste no existe :("<<std::endl;
            //}
            break;
        
        //ENTREGA #3
        case 14:
            inicializarCiudadesGrafo(verticesCiudad, aristasCiudad);
            inicializarDestinosGrafo(verticesCiudad, aristasCiudad);
            //imprimirVertices(verticesCiudad, aristasCiudad); //VER LOS VERTICES
            //imprimirAristas(verticesCiudad, aristasCiudad); //VER LAS ARISTAS
            break;

        case 15:
            guardarCiudadGrafo(verticesCiudad, aristasCiudad);
            break;

        case 16:
            guardarDestinoGrafo(verticesCiudad, aristasCiudad);
            break;

        case 17:
            buscarRuta(verticesCiudad, aristasCiudad);
            break;

        case 18:
            buscarMejorRutaTiempo(verticesCiudad, aristasCiudad);
            break;

        case 19:
            buscarMejorRutaDistancia(verticesCiudad, aristasCiudad);
            break;

        case 20:
            std::cout<<"Muchas gracias por usar el programa, vuelve pronto :)"<<std::endl;
            opcion=21;
            break;

        default:
            std::cout<<"Opcion inexistente, vuelve a intentarlo :("<<std::endl<<std::endl;
            opcion=20;
        }
    }
    while(opcion<21);
}