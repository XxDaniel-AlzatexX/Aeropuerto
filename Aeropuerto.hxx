#include "Aeropuerto.h"

//ENTREGA #1
std::list<Avion> inicializarAviones()
{
    char linea[80];
    char *token;
    std::list<Avion>aviones;
    Avion aux;

    std::ifstream entrada;
    entrada.open("aviones.txt", std::ios::in);
    if(entrada.is_open())
    {
        entrada.getline(linea,80,'\n');
        while(!entrada.eof())
        {
            entrada.getline(linea,80,'\n');
            token=strtok(linea,",");
            while(token!=NULL)
            {
                strcpy(aux.identificador,token);
                token=strtok(NULL,",");
                while(token!=NULL)
                {
                    strcpy(aux.fabricante,token);
                    token=strtok(NULL,",");
                    while(token!=NULL)
                    {
                        strcpy(aux.modelo,token);
                        token=strtok(NULL,",");
                        while(token!=NULL)
                        {
                            aux.anio=atoi(token);
                            token=strtok(NULL,",");
                            while(token!=NULL)
                            {
                                aux.capacidadPasajeros=atoi(token);
                                token=strtok(NULL,",");
                                while(token!=NULL)
                                {
                                    aux.capacidadCarga=atoi(token);
                                    token=strtok(NULL,"\n");
                                    while(token!=NULL)
                                    {
                                        aux.distanciaRecorrida=atoi(token);
                                        aux.disponible=1;
                                        aviones.push_front(aux);
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
        }
        std::cout<<"Los aviones han sido inicializados correctamente :)"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }

    return aviones;
}

std::list<Piloto> inicializarPilotos()
{
    char linea[80];
    char *token;
    std::list<Piloto>pilotos;
    Piloto aux;
    std::ifstream entrada;
    entrada.open("pilotos.txt", std::ios::in);
    if(entrada.is_open())
    {
        entrada.getline(linea,80,'\n');
        while(!entrada.eof())
        {
            entrada.getline(linea,80,'\n');
            token=strtok(linea,",");
            while(token!=NULL)
            {
                aux.identificador=atoi(token);
                token=strtok(NULL,",");
                while(token!=NULL)
                {
                    strcpy(aux.nombres,token);
                    token=strtok(NULL,",");
                    while(token!=NULL)
                    {
                        aux.numeroVuelosRealizados=atoi(token);
                        pilotos.push_front(aux);
                        break;
                    }
                    break;
                }
                break;
            }
        }
        std::cout<<"Los pilotos han sido inicializados correctamente :)"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }

    return pilotos;
}

std::list<Vuelo> inicializarVuelos()
{
    char linea[80];
    char *token;
    std::list<Vuelo>vuelos;
    Vuelo aux;

    std::ifstream entrada;
    entrada.open("vuelos.txt", std::ios::in);
    if(entrada.is_open())
    {
        entrada.getline(linea,80,'\n');
        while(!entrada.eof())
        {
            entrada.getline(linea,80,'\n');
            token=strtok(linea,",");
            while(token!=NULL)
            {
                strcpy(aux.avionAsignado.identificador,token);
                token=strtok(NULL,",");
                while(token!=NULL)
                {
                    aux.piloto.identificador=atoi(token);
                    token=strtok(NULL,",");
                    while(token!=NULL)
                    {
                        aux.coPiloto.identificador=atoi(token);
                        token=strtok(NULL,",");
                        while(token!=NULL)
                        {
                            strcpy(aux.ciudadOrigen,token);
                            token=strtok(NULL,",");
                            while(token!=NULL)
                            {
                                strcpy(aux.ciudadDestino,token);
                                token=strtok(NULL,",");
                                while(token!=NULL)
                                {
                                    aux.cantidadPasajeros=atoi(token);

                                    token=strtok(NULL,"\n");
                                    while(token!=NULL)
                                    {
                                        aux.distanciaTrayecto=atoi(token);
                                        vuelos.push_front(aux);
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }

        }
        std::cout<<"Los vuelos han sido inicializados correctamente :)"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }

    return vuelos;
}

void imprimirAviones(std::list<Avion>aviones)
{
    std::list<Avion>::iterator it = aviones.begin();
    for(auto it = aviones.begin(); it != aviones.end(); it++)
    {
        std::cout<<std::endl<<"IDENTIFICADOR     FABRICANTE           MODELO      ANIO      CAPACIDAD_DE_PASAJEROS     CAPACIDAD_DE_CARGA     DISTANCIA_RECORRIDA     DISPONIBLE (0=NO, 1=SI)"<<std::endl;
        std::cout<<"     "<<it->identificador<<"       "<<it->fabricante<<"           "<<it->modelo<<"     "<<it->anio<<"               "<<it->capacidadPasajeros<<"                     "<<it->capacidadCarga<<"                          "<<it->distanciaRecorrida<<"                        "<<it->disponible<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

void imprimirPilotos(std::list<Piloto>pilotos)
{
    std::list<Piloto>::iterator it = pilotos.begin();
    for(auto it = pilotos.begin(); it != pilotos.end(); it++)
    {
        std::cout<<std::endl<<"IDENTIFICADOR     NOMBRES     NUMERO_DE_VUELOS_REALIZADOS     DISPONIBLE (0=NO, 1=SI)"<<std::endl;
        std::cout<<"  "<<it->identificador<<"    "<<it->nombres<<"             "<<it->numeroVuelosRealizados<<"                         "<<it->disponible<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

void imprimirVuelos(std::list<Vuelo>vuelos)
{
    std::list<Vuelo>::iterator it = vuelos.begin();
    for(auto it = vuelos.begin(); it != vuelos.end(); it++)
    {
        std::cout<<std::endl<<"AVION_ASIGNADO     PILOTO     COPILOTO      CIUDAD_ORIGEN     CIUDAD_DESTINO     CANTIDAD_DE_PASAJEROS     DISTANCIA_TRAYECTO"<<std::endl;
        std::cout<<"     "<<it->avionAsignado.identificador<<"          "<<it->piloto.identificador<<"    "<<it->coPiloto.identificador<<"           "<<it->ciudadOrigen<<"               "<<it->ciudadDestino<<"                    "<<it->cantidadPasajeros<<"                      "<<it->distanciaTrayecto<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

std::list<Vuelo> RealizarVuelo(std::list<Vuelo>vuelos,char avionAsig[])
{
    int cont = 0, aux = 0;
    std::list<Vuelo> auxi;
    std::list<Vuelo>::iterator it = vuelos.begin();
    std::ifstream entrada;
    entrada.open("vuelos.txt", std::ios::in);
    std::ofstream salida;
    salida.open("auxiliar.txt", std::ios::out);

    for(auto it = vuelos.begin(); it != vuelos.end(); it++)
    {
        cont++;
    }

    if(entrada.is_open())
    {
        if(salida.is_open())
        {
            salida<<cont-1<<std::endl;
            for(auto it = vuelos.begin(); it != vuelos.end(); it++)
            {
                if(strcmp(avionAsig,it->avionAsignado.identificador)==0)
                {
                    std::cout<<std::endl<<"Este es el vuelo que realizaste:"<<std::endl;
                    std::cout<<std::endl<<"AVION_ASIGNADO     PILOTO     COPILOTO      CIUDAD_ORIGEN     CIUDAD_DESTINO     CANTIDAD_DE_PASAJEROS     DISTANCIA_TRAYECTO"<<std::endl;
                    std::cout<<"     "<<it->avionAsignado.identificador<<"          "<<it->piloto.identificador<<"    "<<it->coPiloto.identificador<<"           "<<it->ciudadOrigen<<"               "<<it->ciudadDestino<<"                    "<<it->cantidadPasajeros<<"                      "<<it->distanciaTrayecto<<std::endl<<std::endl;
                    it->piloto.disponible = 0;
                    it->avionAsignado.disponible = 0;
                    aux++;
                }
                else
                {
                    salida<<it->avionAsignado.identificador<<","<<it->piloto.identificador<<","<<it->coPiloto.identificador<<","<<it->ciudadOrigen<<","<<it->ciudadDestino<<","<<it->cantidadPasajeros<<","<<it->distanciaTrayecto<<std::endl;
                }
            }
        }
    }
    entrada.close();
    salida.close();
    if(aux>0)
    {
        remove("vuelos.txt");
        rename("auxiliar.txt", "vuelos.txt");
    }
    else
    {
        remove("auxiliar.txt");
        std::cout<<"Ingresaste un avion que no existe, intentalo de nuevo :)"<<std::endl<<std::endl;
    }
    auxi = inicializarVuelos();
    return auxi;
}

//ENTREGA #2
void inicializarCiudades(NodoCiudad *&ciudad)
{
    char linea[200];
    char *token;
    Ciudad aux;

    std::ifstream entrada;
    entrada.open("ciudades.txt", std::ios::in);
    if(entrada.is_open())
    {
        entrada.getline(linea,200,'\n');
        while(!entrada.eof())
        {
            entrada.getline(linea,200,'\n');
            token=strtok(linea,",");
            while(token!=NULL)
            {
                strcpy(aux.codigoIATA,token);
                token=strtok(NULL,",");
                while(token!=NULL)
                {
                    strcpy(aux.nombreAeropuerto,token);
                    token=strtok(NULL,",");
                    while(token!=NULL)
                    {
                        strcpy(aux.nombreCiudad,token);
                        token=strtok(NULL,",");
                        while(token!=NULL)
                        {
                            strcpy(aux.pais,token);
                            //aux.bandera = true;
                            insertarNodoCiudad(ciudad, aux);
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
        }
        std::cout<<"Las ciudades han sido inicializadas correctamente :)"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }
}

void inicializarDestinos(NodoDestino *&destino, NodoCiudad *&ciudad)
{
    char linea[80];
    char *token;
    char auxi[100];
    Destino aux;
    Ciudad *ciudadAux;
    std::ifstream entrada;
    entrada.open("destinos.txt", std::ios::in);
    if(entrada.is_open())
    {
        entrada.getline(linea,80,'\n');
        while(!entrada.eof())
        {
            entrada.getline(linea,80,'\n');
            token=strtok(linea,",");
            while(token!=NULL)
            {
                /*
                      strcpy(auxi,token);
                      ciudadAux = buscarCiudad(ciudad, auxi);
                      std::cout<<ciudadAux->codigoIATA<<std::endl;
                      if(ciudadAux->bandera==true){
                          aux.origen=ciudadAux;
                          sincronizarVuelos(ciudad, destino destino);
                      }else{
                          std::cout<<"La ciudad que ingresaste no existe :("<<std::endl;
                      }*/
                token=strtok(NULL,",");
                while(token!=NULL)
                {
                    /*
                          strcpy(auxi,token);
                          ciudadAux = buscarCiudad(ciudad, auxi);
                          std::cout<<ciudadAux->codigoIATA<<std::endl;
                          if(ciudadAux->bandera==true){
                              aux.destino=ciudadAux;
                              sincronizarVuelos(ciudad, destino destino);
                          }else{
                              std::cout<<"La ciudad que ingresaste no existe :("<<std::endl;
                          }*/
                    token=strtok(NULL,",");
                    while(token!=NULL)
                    {
                        aux.distancia=atoi(token);
                        token=strtok(NULL,",");
                        while(token!=NULL)
                        {
                            aux.tiempo=atoi(token);
                            insertarNodoDestino(destino, aux);
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
        }
        std::cout<<"Los destinos han sido inicializados correctamente :)"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }
}

void insertarNodoCiudad(NodoCiudad *&city, Ciudad n)
{
    if(city == NULL)
    {
        NodoCiudad *aux = crearNodoCiudad(n);
        city = aux;
    }
    else if(strcmp(n.codigoIATA,city->ciudad->codigoIATA) > 0)
    {
        if(city->der == NULL)
        {
            city->der = crearNodoCiudad(n);
        }
        else
        {
            insertarNodoCiudad(city->der, n);
        }
    }
    else
    {
        if(city->izq == NULL)
        {

            city->izq = crearNodoCiudad(n);
        }
        else
        {
            insertarNodoCiudad(city->izq, n);
        }
    }
}

NodoCiudad *crearNodoCiudad(Ciudad n)
{
    NodoCiudad *aux = new NodoCiudad();

    aux->ciudad = &n;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

void preorden(NodoCiudad *nodo)
{
    if (nodo != NULL)
    {
        std::cout<<nodo->ciudad->codigoIATA<<std::endl;
        preorden(nodo->izq);
        preorden(nodo->der);
    }
}

void insertarNodoDestino(NodoDestino *&destiny, Destino n)
{
    if(destiny == NULL)
    {
        NodoDestino *aux = crearNodoDestino(n);
        destiny=aux;
    }
    else
    {
        int valorRaiz = destiny->destino->distancia;
        if(n.distancia<valorRaiz)
        {
            insertarNodoDestino(destiny->izq, n);
        }
        else
        {
            insertarNodoDestino(destiny->der, n);
        }
    }
}

NodoDestino *crearNodoDestino(Destino n)
{
    NodoDestino *aux = new NodoDestino();

    aux->destino = &n;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

Ciudad *buscarCiudad(NodoCiudad *&city, char IATA[3])
{
    if(city==NULL)
    {
        return NULL;
    }
    else if(strcmp(IATA, city->ciudad->codigoIATA)==0)
    {
        //city->ciudad->bandera=true;
        return city->ciudad;
    }
    else if(strcmp(IATA, city->ciudad->codigoIATA)>0)
    {
        return buscarCiudad(city->der,IATA);
    }
    else
    {
        return buscarCiudad(city->izq,IATA);
    }
}

Destino *buscarDestino(NodoDestino *&destiny, int distance)
{
    Destino *aux;
    if(destiny==NULL)
    {
        return aux;
    }
    else if((destiny->destino->distancia)==distance)
    {
        aux = destiny->destino;
        return aux;
    }
    else if(distance<(destiny->destino->distancia))
    {
        return buscarDestino(destiny->izq,distance);
    }
    else
    {
        return buscarDestino(destiny->der,distance);
    }
}

void sincronizarVuelos(NodoCiudad *&city, NodoDestino *&destiny,NodoDestino *&aux)
{
    if (city != NULL)
    {
        if(destiny != NULL)
        {
            if((city->ciudad->codigoIATA)==(destiny->destino->origen->codigoIATA))
            {
                //city->ciudad->vuelosDesde.push_back(destiny->destino);
            }
            if((city->ciudad->codigoIATA)==(destiny->destino->destino->codigoIATA))
            {
                //city->ciudad->vuelosHacia.push_back(destiny->destino);
            }
            sincronizarVuelos(city, destiny->izq, aux);
            sincronizarVuelos(city, destiny->der, aux);
        }
        destiny=aux;
        sincronizarVuelos(city->izq, destiny, aux);
        sincronizarVuelos(city->der, destiny, aux);
    }
}

//ENTREGA #3
void inicializarCiudadesGrafo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad)
{
    char linea[200];
    char *token;
    Ciudad aux;

    std::ifstream entrada;
    entrada.open("ciudades.txt", std::ios::in);
    if(entrada.is_open())
    {
        entrada.getline(linea,200,'\n');
        while(!entrada.eof())
        {
            entrada.getline(linea,200,'\n');
            token=strtok(linea,",");
            while(token!=NULL)
            {
                strcpy(aux.codigoIATA,token);
                token=strtok(NULL,",");
                while(token!=NULL)
                {
                    strcpy(aux.nombreAeropuerto,token);
                    token=strtok(NULL,",");
                    while(token!=NULL)
                    {
                        strcpy(aux.nombreCiudad,token);
                        token=strtok(NULL,",");
                        while(token!=NULL)
                        {
                            strcpy(aux.pais,token);
                            verticesCiudad.push_back(aux);
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
        }
        std::cout<<"Las ciudades han sido inicializadas correctamente :)"<<std::endl<<std::endl;
        Destino aux1;
        aux1.distancia=0;
        for(int i=0; i<verticesCiudad.size(); i++)
        {
            aristasCiudad.push_back(std::vector<Destino>());
            for(int j=0; j<verticesCiudad.size(); j++)
            {
                aristasCiudad[i].push_back(aux1);
            }
        }
    }
    else
    {
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }
}

void inicializarDestinosGrafo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad)
{
    char linea[200];
    char *token;
    char coconut[100];
    char auxIATA[100];
    Destino aux;
    Ciudad *ciudadAux;
    int posOri=0, posDes=0;
    std::ifstream entrada;
    entrada.open("destinos.txt", std::ios::in);
    if(entrada.is_open())
    {
        entrada.getline(linea,200,'\n');
        while(!entrada.eof())
        {
            entrada.getline(linea,200,'\n');
            token=strtok(linea,",");
            while(token!=NULL)
            {
                strcpy(auxIATA,token);
                std::cout<<"guardado iata " <<auxIATA<<" Origen"<<std::endl;
                posOri=buscarPosicionGrafo(verticesCiudad,auxIATA);
                ciudadAux=buscarCiudadVertice(verticesCiudad,auxIATA);
                aux.origen=ciudadAux;
                if(posOri==-1)
                {
                    std::cout<<"La ciudad de origen " <<auxIATA<<" no existe"<<std::endl;
                }
                else
                {
                    token=strtok(NULL,",");
                    while(token!=NULL)
                    {
                        strcpy(auxIATA,token);
                        std::cout<<"guardado iata " <<auxIATA<<" Destino"<<std::endl;
                        posDes = buscarPosicionGrafo(verticesCiudad, auxIATA);
                        ciudadAux=buscarCiudadVertice(verticesCiudad,auxIATA);
                        aux.origen=ciudadAux;
                        if(posDes==-1)
                        {
                            std::cout<<"La ciudad de destino " <<auxIATA<<" no existe"<<std::endl;
                        }
                        else
                        {
                            token=strtok(NULL,",");
                            while(token!=NULL)
                            {
                                aux.distancia=atoi(token);
                                token=strtok(NULL,",");
                                while(token!=NULL)
                                {
                                    aux.tiempo=atoi(token);
                                    aristasCiudad[posOri][posDes]=aux;
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                }
                break;
            }
        }
        std::cout<<"Los destinos han sido inicializados correctamente :)"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }
}

Ciudad *buscarCiudadVertice(std::vector<Ciudad> &verticesCiudad, char auxIATA[])
{
    Ciudad *aux;
    for(int i=0; i<verticesCiudad.size(); i++)
    {
        if(strcmp(verticesCiudad[i].codigoIATA,auxIATA)==0)
        {
            strcpy(aux->codigoIATA,verticesCiudad[i].codigoIATA);
            strcpy(aux->nombreAeropuerto,verticesCiudad[i].nombreAeropuerto);
            strcpy(aux->nombreCiudad,verticesCiudad[i].nombreCiudad);
            strcpy(aux->pais,verticesCiudad[i].pais);
        }
    }
    return aux;
}

int buscarPosicionGrafo(std::vector<Ciudad> &verticesCiudad, char auxIATA[])
{
    for(int i=0; i<verticesCiudad.size(); i++)
    {
        if(strcmp(verticesCiudad[i].codigoIATA, auxIATA)==0)
        {
            return i;
        }
    }
    return -1;
}

void guardarCiudadGrafo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad)
{
    Ciudad aux;
    int verificar;
    std::cout<<"Ingrese el codigo IATA de la ciudad "<<std::endl;
    std::cin>>aux.codigoIATA;
    verificar=buscarPosicionGrafo(verticesCiudad,aux.codigoIATA);
    if(verificar==-1)
    {
        std::cout<<"Ingrese el nombre del aeropuerto "<<std::endl;
        std::cin>>aux.nombreAeropuerto;
        std::cout<<"Ingrese el nombre de la ciudad "<<std::endl;
        std::cin>>aux.nombreCiudad;
        std::cout<<"Ingrese el nombre del pais "<<std::endl;
        std::cin>>aux.pais;
        verticesCiudad.push_back(aux);
        Destino aux1;
        aux1.distancia=0;
        for(int i=verticesCiudad.size(); i<verticesCiudad.size()+1; i++)
        {
            aristasCiudad.push_back(std::vector<Destino>());
            for(int j=0; j<verticesCiudad.size(); j++)
            {
                aristasCiudad[i].push_back(aux1);
            }
        }
    }
    else
    {
        std::cout<<"la ciudad que ingreso ya existe"<<std::endl;
    }
    //std::cout<<buscarPosicionGrafo(verticesCiudad, aux.codigoIATA); //MOSTRAR UBICACION EN EL GRAFO DE LA NUEVA CIUDAD
}

void guardarDestinoGrafo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad)
{
    Destino aux;
    Ciudad *ciudadAuxiliar;
    int posOri=0, posDes=0;
    char auxIATA[100];
    char auxIATAdes[100];
    std::cout<<"ingrese el codigo IATA del origen"<<std::endl;
    std::cin>>auxIATA;
    posOri=buscarPosicionGrafo(verticesCiudad,auxIATA);
    if(posOri>=0)
    {
        //ciudadAuxiliar=buscarCiudadVertice(verticesCiudad,auxIATA);
        aux.origen=ciudadAuxiliar;
        std::cout<<"ingrese el codigo IATA del destino"<<std::endl;
        std::cin>>auxIATAdes;
        posDes=buscarPosicionGrafo(verticesCiudad,auxIATAdes);
        //ciudadAuxiliar=buscarCiudadVertice(verticesCiudad,auxIATAdes);
        aux.destino=ciudadAuxiliar;
        if(posDes>=0)
        {
            std::cout<<"ingrese el tiempo del trayecto"<<std::endl;
            std::cin>>aux.tiempo;
            std::cout<<"ingrese la distancia del trayecto"<<std::endl;
            std::cin>>aux.distancia;
            aristasCiudad[posOri][posDes]=aux;
        }
        else
        {
            std::cout<<"La ciudad destino no existe :("<<std::endl;
        }
    }
    else
    {
        std::cout<<"la ciudad origen no existe :("<<std::endl;
    }
    std::cout<<posDes<<"  "<<posOri<<std::endl;
    //aristasCiudad[posOri][posDes].origen=buscarCiudadVertice(verticesCiudad,auxIATA);
    //aristasCiudad[posOri][posDes].destino=buscarCiudadVertice(verticesCiudad,auxIATAdes);
    std::cout<<aristasCiudad[posOri][posDes].origen->codigoIATA<<std::endl;
    std::cout<<aristasCiudad[posOri][posDes].destino->codigoIATA<<std::endl;
}

void buscarRuta(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad)
{
    int posOri=0, posDes=0, auxDis=0, auxTie=0;
    char auxIATAori[100], auxIATAdes[100];

    std::cout<<"ingrese la ciudad origen"<<std::endl;
    std::cin>>auxIATAori;
    posOri=buscarPosicionGrafo(verticesCiudad,auxIATAori);

    if(posOri!=-1)
    {
        std::cout<<"ingrese la ciudad destino"<<std::endl;
        std::cin>>auxIATAdes;
        posDes=buscarPosicionGrafo(verticesCiudad,auxIATAdes);
        if(posDes!=-1)
        {
            if(aristasCiudad[posOri][posDes].distancia!=0)
            {
                std::cout<<"Hay un vuelo con ruta directa de "<<auxIATAori<<" a "<<auxIATAdes<<std::endl;
                std::cout<<"con una distancia de "<<aristasCiudad[posOri][posDes].distancia<<" y un tiempo de "<<aristasCiudad[posOri][posDes].tiempo<<std::endl;
            }
            for(int i=0; i<aristasCiudad.size(); i++)
            {
                if(aristasCiudad[posOri][i].distancia!=0)
                {
                    if(aristasCiudad[i][posDes].distancia!=0)
                    {
                        std::cout<<"Hay un vuelo con escala de "<<auxIATAori<<" a "<<verticesCiudad[i].codigoIATA<<" y de "<<verticesCiudad[i].codigoIATA<<" a "<<auxIATAdes<<std::endl;
                        auxDis=aristasCiudad[posOri][i].distancia + aristasCiudad[i][posDes].distancia;
                        auxTie=aristasCiudad[posOri][i].tiempo + aristasCiudad[i][posDes].tiempo;
                        std::cout<<"con una distancia de "<<auxDis<<" y un tiempo de "<<auxTie<<std::endl;
                    }
                }
            }
            for(int i=0; i<aristasCiudad.size(); i++)
            {
                if(aristasCiudad[posOri][i].distancia!=0)
                {
                    for(int j=0; j<aristasCiudad.size(); j++)
                    {
                        if(aristasCiudad[i][j].distancia!=0)
                        {
                            if(aristasCiudad[j][posDes].distancia!=0)
                            {
                                std::cout<<"Hay un vuelo con escala de "<<auxIATAori<<" a "<<verticesCiudad[i].codigoIATA<<", de "<<verticesCiudad[i].codigoIATA<<" a "<<verticesCiudad[j].codigoIATA<<" y de "<<verticesCiudad[j].codigoIATA<< " a "<<auxIATAdes<<std::endl;
                                auxDis=aristasCiudad[posOri][i].distancia + aristasCiudad[i][posDes].distancia + aristasCiudad[i][j].distancia;
                                auxTie=aristasCiudad[posOri][i].tiempo + aristasCiudad[i][posDes].tiempo + aristasCiudad[i][j].tiempo;
                                std::cout<<"con una distancia de "<<auxDis<<" y un tiempo de "<<auxTie<<std::endl;
                            }
                        }
                    }
                }
            }

        }
        else
        {
            std::cout<<"ingresaste una ciudad que no esta registrada"<<std::endl;
        }
    }
    else
    {
        std::cout<<"ingresaste una ciudad que no esta registrada"<<std::endl;
    }
}

void buscarMejorRutaDistancia(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad)
{
    int posOri=0, posDes=0,auxDis=0, auxTie=0;
    int menor=999999990, auxI, auxJ, escalas, i, j, auxiTiempo;
    char auxIATAori[100], auxIATAdes[100];

    std::cout<<"ingrese la ciudad origen"<<std::endl;
    std::cin>>auxIATAori;
    posOri=buscarPosicionGrafo(verticesCiudad,auxIATAori);

    if(posOri!=-1)
    {
        std::cout<<"ingrese la ciudad destino"<<std::endl;
        std::cin>>auxIATAdes;
        posDes=buscarPosicionGrafo(verticesCiudad,auxIATAdes);
        if(posDes!=-1)
        {
            if(aristasCiudad[posOri][posDes].distancia!=0)
            {
                menor=aristasCiudad[posOri][posDes].distancia;
                escalas=0;
            }
            for(i=0; i<aristasCiudad.size(); i++)
            {
                if(aristasCiudad[posOri][i].distancia!=0)
                {
                    if(aristasCiudad[i][posDes].distancia!=0)
                    {
                        auxDis=aristasCiudad[posOri][i].distancia + aristasCiudad[i][posDes].distancia;
                        auxTie=aristasCiudad[posOri][i].tiempo + aristasCiudad[i][posDes].tiempo;
                        if(menor>auxDis)
                        {
                            menor=auxDis;
                            escalas=1;
                            auxI=i;
                            auxiTiempo=auxTie;
                        }
                    }
                }
            }
            for(i=0; i<aristasCiudad.size(); i++)
            {
                if(aristasCiudad[posOri][i].distancia!=0)
                {
                    for(j=0; j<aristasCiudad.size(); j++)
                    {
                        if(aristasCiudad[i][j].distancia!=0)
                        {
                            if(aristasCiudad[j][posDes].distancia!=0)
                            {
                                auxDis=aristasCiudad[posOri][i].distancia + aristasCiudad[i][posDes].distancia + aristasCiudad[i][j].distancia;
                                auxTie=aristasCiudad[posOri][i].tiempo + aristasCiudad[i][posDes].tiempo + aristasCiudad[i][j].tiempo;

                                if(menor>auxDis)
                                {
                                    menor=auxDis;
                                    escalas=2;
                                    auxI=i;
                                    auxJ=j;
                                    auxiTiempo=auxTie;
                                }
                            }
                        }
                    }
                }
            }
            if(escalas==0)
            {
                std::cout<<"Hay un vuelo con ruta directa de "<<auxIATAori<<" a "<<auxIATAdes<<std::endl;
                std::cout<<"con una distancia de "<<aristasCiudad[posOri][posDes].distancia<<" y un tiempo de "<<aristasCiudad[posOri][posDes].tiempo<<std::endl;
            }
            else if(escalas==1)
            {
                std::cout<<"Hay un vuelo con escala de "<<auxIATAori<<" a "<<verticesCiudad[auxI].codigoIATA<<" y de "<<verticesCiudad[auxI].codigoIATA<<" a "<<auxIATAdes<<std::endl;
                std::cout<<"con una distancia de "<<menor<<" y un tiempo de "<<auxiTiempo<<std::endl;
            }
            else if(escalas==2)
            {
                std::cout<<"Hay un vuelo con escala de "<<auxIATAori<<" a "<<verticesCiudad[auxI].codigoIATA<<", de "<<verticesCiudad[auxI].codigoIATA<<" a "<<verticesCiudad[auxJ].codigoIATA<<" y de "<<verticesCiudad[auxJ].codigoIATA<< " a "<<auxIATAdes<<std::endl;
                std::cout<<"con una distancia de "<<menor<<" y un tiempo de "<<auxiTiempo<<std::endl;
            }
        }
        else
        {
            std::cout<<"ingresaste una ciudad que no esta registrada"<<std::endl;
        }
    }
    else
    {
        std::cout<<"ingresaste una ciudad que no esta registrada"<<std::endl;
    }
}

void buscarMejorRutaTiempo(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad)
{
    int posOri=0, posDes=0, auxDis=0, auxTie=0;
    int menor=999999990, auxI, auxJ, escalas, i, j, auxiDistancia;
    char auxIATAori[100], auxIATAdes[100];

    std::cout<<"ingrese la ciudad origen"<<std::endl;
    std::cin>>auxIATAori;
    posOri=buscarPosicionGrafo(verticesCiudad,auxIATAori);

    if(posOri!=-1)
    {
        std::cout<<"ingrese la ciudad destino"<<std::endl;
        std::cin>>auxIATAdes;
        posDes=buscarPosicionGrafo(verticesCiudad,auxIATAdes);
        if(posDes!=-1)
        {
            if(aristasCiudad[posOri][posDes].tiempo!=0)
            {
                menor=aristasCiudad[posOri][posDes].tiempo;
                escalas=0;
            }
            for(i=0; i<aristasCiudad.size(); i++)
            {
                if(aristasCiudad[posOri][i].tiempo!=0)
                {
                    if(aristasCiudad[i][posDes].tiempo!=0)
                    {
                        auxDis=aristasCiudad[posOri][i].distancia + aristasCiudad[i][posDes].distancia;
                        auxTie=aristasCiudad[posOri][i].tiempo + aristasCiudad[i][posDes].tiempo;
                        if(menor>auxTie)
                        {
                            menor=auxTie;
                            escalas=1;
                            auxI=i;
                            auxiDistancia=auxDis;
                        }
                    }
                }
            }
            for(i=0; i<aristasCiudad.size(); i++)
            {
                if(aristasCiudad[posOri][i].tiempo!=0)
                {
                    for(j=0; j<aristasCiudad.size(); j++)
                    {
                        if(aristasCiudad[i][j].tiempo!=0)
                        {
                            if(aristasCiudad[j][posDes].tiempo!=0)
                            {
                                auxDis=aristasCiudad[posOri][i].distancia + aristasCiudad[i][posDes].distancia + aristasCiudad[i][j].distancia;
                                auxTie=aristasCiudad[posOri][i].tiempo + aristasCiudad[i][posDes].tiempo + aristasCiudad[i][j].tiempo;

                                if(menor>auxTie)
                                {
                                    menor=auxTie;
                                    escalas=2;
                                    auxI=i;
                                    auxJ=j;
                                    auxiDistancia=auxDis;
                                }
                            }
                        }
                    }
                }
            }
            if(escalas==0)
            {
                std::cout<<"Hay un vuelo con ruta directa de "<<auxIATAori<<" a "<<auxIATAdes<<std::endl;
                std::cout<<"con una distancia de "<<aristasCiudad[posOri][posDes].distancia<<" y un tiempo de "<<aristasCiudad[posOri][posDes].tiempo<<std::endl;
            }
            else if(escalas==1)
            {
                std::cout<<"Hay un vuelo con escala de "<<auxIATAori<<" a "<<verticesCiudad[auxI].codigoIATA<<" y de "<<verticesCiudad[auxI].codigoIATA<<" a "<<auxIATAdes<<std::endl;
                std::cout<<"con una distancia de "<<auxiDistancia<<" y un tiempo de "<<menor<<std::endl;
            }
            else if(escalas==2)
            {
                std::cout<<"Hay un vuelo con escala de "<<auxIATAori<<" a "<<verticesCiudad[auxI].codigoIATA<<", de "<<verticesCiudad[auxI].codigoIATA<<" a "<<verticesCiudad[auxJ].codigoIATA<<" y de "<<verticesCiudad[auxJ].codigoIATA<< " a "<<auxIATAdes<<std::endl;
                std::cout<<"con una distancia de "<<auxiDistancia<<" y un tiempo de "<<menor<<std::endl;
            }
        }
        else
        {
            std::cout<<"ingresaste una ciudad que no esta registrada"<<std::endl;
        }
    }
    else
    {
        std::cout<<"ingresaste una ciudad que no esta registrada"<<std::endl;
    }
}

void imprimirVertices(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad)
{
    for(int i=0; i<verticesCiudad.size(); i++)
    {
        std::cout<<verticesCiudad[i].codigoIATA<<std::endl;
    }
}

void imprimirAristas(std::vector<Ciudad> &verticesCiudad, std::vector<std::vector<Destino>> &aristasCiudad)
{
    for(int i=0; i<aristasCiudad.size(); i++)
    {
        for(int j=0; j<aristasCiudad.size(); j++)
        {
            std::cout<<aristasCiudad[i][j].distancia<<"  ";
        }
        std::cout<<std::endl;
    }
}