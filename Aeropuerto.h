#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <stack>

//ENTREGA #1
struct Avion
{
    char identificador[40];
    char fabricante[40];
    char modelo[40];
    int anio;
    int capacidadPasajeros;
    int capacidadCarga;
    int distanciaRecorrida;
    int disponible;
};

struct Piloto
{
    int identificador;
    char nombres[40];
    int numeroVuelosRealizados;
    int disponible=1;
};

struct Vuelo
{
    Avion avionAsignado;
    Piloto piloto;
    Piloto coPiloto;
    char ciudadOrigen[40];
    char ciudadDestino[40];
    int cantidadPasajeros;
    int distanciaTrayecto;
};

//ENTREGA #2
struct Ciudad
{
    //std::list<Destino> vuelosDesde;
    //std::list<Destino> vuelosHacia;
    char codigoIATA[100];
    char nombreAeropuerto[100];
    char nombreCiudad[100];
    char pais[100];
    //bool bandera=true;
};

struct NodoCiudad
{
    Ciudad *ciudad;
    NodoCiudad *der;
    NodoCiudad *izq;
};

struct Destino
{
    Ciudad *origen;
    Ciudad *destino;
    int distancia;
    int tiempo;
};

struct NodoDestino
{
    Destino *destino;
    NodoDestino *der;
    NodoDestino *izq;
};

//ENTREGA #3
//IMPLEMENTACION CON MATRIZ DE ADYACENCIA
std::vector<Ciudad> verticesCiudad;
std::vector<std::vector<Destino>> aristasCiudad;

//ENTREGA #1
std::list<Avion> inicializarAviones();
std::list<Piloto> inicializarPilotos();
std::list<Vuelo> inicializarVuelos();
void imprimirAviones(std::list<Avion>aviones);
void imprimirPilotos(std::list<Piloto>pilotos);
void imprimirVuelos(std::list<Vuelo>vuelos);
std::list<Vuelo> RealizarVuelo(std::list<Vuelo>vuelos,char avionAsig[]);

//ENTREGA #2
void inicializarCiudades(NodoCiudad *&ciudad);
void inicializarDestinos(NodoDestino *&destino, NodoCiudad *&ciudad);
void insertarNodoCiudad(NodoCiudad *&city, Ciudad n);
NodoCiudad *crearNodoCiudad(Ciudad n);
void insertarNodoDestino(NodoDestino *&destiny, Destino n);
NodoDestino *crearNodoDestino(Destino n);
Ciudad *buscarCiudad(NodoCiudad *&city, char IATA[3]);
Destino *buscarDestino(NodoDestino *&destiny, int distance);
void preorden(NodoDestino *nodo);
void sincronizarVuelos(NodoCiudad *&city, NodoDestino *&destiny, NodoDestino *&aux);

//ENTREGA #3
void inicializarCiudadesGrafo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad);
void inicializarDestinosGrafo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad);
void guardarCiudadGrafo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad);
void guardarDestinoGrafo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad);
void buscarRuta(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad);
void buscarMejorRutaTiempo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad);
void buscarMejorRutaDistancia(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad);
Ciudad *buscarCiudadVertice(std::vector<Ciudad> &verticesCiudad, char auxIATA[]);
int buscarPosicionGrafo(std::vector<Ciudad> &verticesCiudad, char auxIATA[]);
void imprimirVertices(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad);
void imprimirAristas(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad);

#include "Aeropuerto.hxx"
#endif