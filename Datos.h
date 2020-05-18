#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

struct Platos
{
    int ID;
    char Nombre[50]="\0";
    float Costo_Preparacion;
    float Valor_Venta;
    int Tiempo_Preparacion;
    int IDRestaurante;
    int Comision;
    int IDCategoria;
    bool Estado;
};

struct Fecha
{
    int dia, mes, anio;
};

struct Clientes
{
    int ID;
    char Apellidos[50]="\0";
    char Nombres[50]="\0";
    char Mail[50]="\0";
    char Domicilio[100]="\0";
    int CP;
    struct Fecha fechanac;
    bool Estado;
};

struct Pedidos{
int ID, IDCliente, IDPlato, Cantidad, Estado;
float PrecioUnitario, Valoracion;
Fecha FechaPedido;
};


Fecha hoy()
{
    time_t t;
    t = time(NULL);
    struct tm *f;
    f = localtime(&t);
    Fecha aux;
    aux.dia = f->tm_mday;
    aux.mes = f->tm_mon+1;
    aux.anio = f->tm_year+1900;
    return aux;
}

const char *PATH_Clientes = "Clientes.dat";

const char *PATH_Platos = "Platos.dat";

const char *PATH_Pedidos = "Pedidos.dat";

const char *PATH_Clientes_BKP = "Clientes.bkp";

const char *PATH_Platos_BKP = "Platos.bkp";

const char *PATH_Pedidos_BKP = "Pedidos.bkp";

#endif // DATOS_H_INCLUDED
