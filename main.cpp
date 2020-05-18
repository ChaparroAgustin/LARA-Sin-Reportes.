#include <iostream>
using namespace std;
#include <ctime>
#include <cstring>
#include <clocale>
#include "rlutil.h"
using namespace rlutil;

#include "Datos.h"
#include "Prototipos.h"
#include "Mains.h"
#include "Platos.h"
#include "Clientes.h"
#include "Pedidos.h"
#include "Configuracion.h"


int main()
{
    setlocale(LC_ALL, "spanish");
    setColor(WHITENESS);
    setBackgroundColor(BLACK);
    int opc;
    bool salir = true;
    while(salir)
    {
        cls();
        cout<<"|----------------------------|"<<endl;
        cout<<"|       MENÚ PRINCIPAL       |"<<endl;
        cout<<"|----------------------------|"<<endl;
        cout<<"| 1) PLATOS                  |"<<endl;
        cout<<"| 2) CLIENTES                |"<<endl;
        cout<<"| 3) PEDIDOS                 |"<<endl;
        cout<<"| 4) REPORTES                |"<<endl;
        cout<<"| 5) CONFIGURAIÓN            |"<<endl;
        cout<<"|----------------------------|"<<endl;
        cout<<"| 0) SALIR DEL PROGRAMA      |"<<endl;
        cout<<"|----------------------------|"<<endl<<endl;
        cout<<"Ingrese una Opción: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
        {
            Menu_Platos();
        }
        break;
        case 2:
        {
            Menu_Clientes();
        }
        break;
        case 3:
        {
            Menu_Pedidos();
        }
        break;
        case 4:
        {
            //Menu_Reportes();
        } break;
        case 5:
        {
            Menu_Configuracion();
        }
        break;
        case 0:
        {
            salir = false;
        }
        break;
        default:
        {
            cout<<"Opción Incorrecta"<<endl;
            getch();
        }
        break;
        }
    }

    return 0;
}
