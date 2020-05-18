#ifndef MAINS_H_INCLUDED
#define MAINS_H_INCLUDED


void Menu_Platos()
{
    setlocale(LC_ALL, "spanish");
    int opcion;
    bool salir=true;
    while(salir)
    {
        cls();
        cout<<"|-----------------------------|"<<endl;
        cout<<"|         MENÚ PLATOS         |"<<endl;
        cout<<"|-----------------------------|"<<endl;
        cout<<"| 1) NUEVO PLATO              |"<<endl;
        cout<<"| 2) MODIFICAR PLATO          |"<<endl;
        cout<<"| 3) LISTAR PLATO POR ID      |"<<endl;
        cout<<"| 4) PLATOS POR RESTAURANTE   |"<<endl;
        cout<<"| 5) LISTAR TODOS LOS PLATOS  |"<<endl;
        cout<<"| 6) ELIMINAR PLATO           |"<<endl;
        cout<<"|-----------------------------|"<<endl;
        cout<<"| 0) VOLVER AL MENÚ PRINCIPAL |"<<endl;
        cout<<"|-----------------------------|"<<endl<<endl;
        cout<<"Opción: "<<endl;
        cin>>opcion;
        switch(opcion)
        {
        case 1:
        {
            Nuevo_Plato();
        }
        break;
        case 2:
        {
            Modificar_Plato();
        }
        break;
        case 3:
        {
            Listar_Platos_x_ID();
        }
        break;
        case 4:
        {
            Platos_X_Restaurante();
        }
        break;
        case 5:
        {
            Listar_Todos();
        }
        break;
        case 6:
        {
            Dar_Baja();
        }
        break;
        case 0:
        {
            salir=false;
        }
        break;
        default:
        {
            cout<<"Opción incorrecta"<<endl;
            getch();
        }
        break;
        }

    }
}

void Menu_Clientes()
{
    setlocale(LC_ALL, "spanish");
    int opcion;
    bool salir=true;
    while(salir)
    {
        cls();
        cout<<"|-----------------------------|"<<endl;
        cout<<"|         MENÚ CLIENTES       |"<<endl;
        cout<<"|-----------------------------|"<<endl;
        cout<<"| 1) NUEVO CLIENTE            |"<<endl;
        cout<<"| 2) MODIFICAR CLIENTE        |"<<endl;
        cout<<"| 3) LISTAR CLIENTE POR ID    |"<<endl;
        cout<<"| 4) LISTAR TODOS LOS CLIENTES|"<<endl;
        cout<<"| 5) ELIMINAR CLIENTE         |"<<endl;
        cout<<"|-----------------------------|"<<endl;
        cout<<"| 0) VOLVER AL MENÚ PRINCIPAL |"<<endl;
        cout<<"|-----------------------------|"<<endl<<endl;
        cout<<"Opción: "<<endl;
        cin>>opcion;
        switch(opcion)
        {
        case 1:
        {
            Nuevo_Cliente();
        }
        break;
        case 2:
        {
            Modificar_Cliente();
        }
        break;
        case 3:
        {
            Listar_Cliente_x_ID();
        }
        break;
        case 4:
        {
            listar_clientes();
        }
        break;
        case 5:
        {
            Baja_Cliente();
        }
        break;
        case 0:
        {
            salir=false;
        }
        break;
        default:
        {
            cout<<"Opción incorrecta"<<endl;
            getch();
        }
        break;
        }

    }
}

void Menu_Pedidos()
{

    int op;
    bool salir = true;
    while(salir)
    {
        cls();
        cout<<"|-------------------------------|"<<endl;
        cout<<"|        MENÚ PEDIDOS           |"<<endl;
        cout<<"|-------------------------------|"<<endl;
        cout<<"|1) NUEVO PEDIDO                |"<<endl;
        cout<<"|2) MODIFICAR PEDIDO            |"<<endl;
        cout<<"|3) LISTAR PEDIDO POR ID        |"<<endl;
        cout<<"|4) LISTAR TODOS LOS PEDIDOS    |"<<endl;
        cout<<"|-------------------------------|"<<endl;
        cout<<"|0) VOLVER AL MENÚ PRINCIPAL    |"<<endl;
        cout<<"|-------------------------------|"<<endl;
        cout<<""<<endl;
        cout<<"Ingrese opcion"<<endl;
        cin>>op;
        switch(op)
        {
        case 1:
        {
            Nuevo_Pedido();
        }
        break;
        case 2:
        {
            Modificar_Pedido();
        }
        break;
        case 3:
        {
            Listar_Pedido_x_ID();
        }
        break;
        case 4:
        {
            Listar_Pedidos();
        }
        break;
        case 0:
        {
            salir = false;
        }
        break;
        }
    }
}

void Menu_Configuracion()
{

    int op;
    bool salir = true;
    while(salir)
    {
        cls();
        cout<<"|----------------------------------|"<<endl;
        cout<<"|      MENÚ CONFIGURACIÓN          |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        cout<<"| 1) REALIZAR COPIA DE SEGURIDAD   |"<<endl;
        cout<<"| 2) RESTAURAR COPIA DE SEGURIDAD  |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        cout<<"| 0) VOLVER AL MENÚ PRINCIPAL      |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        cout<<endl<<endl;
        cout<<"Ingrese Opción: "<<endl;
        cin>>op;
        switch(op)
        {

        case 1:
        {
            Realizar_Backups();
        }
        break;
        case 2:
        {
Restaurar_backups();
        } break;
        case 0:
        {
            salir = false;
        }
        break;
        default:
        {
            cout<<"Opción incorrecta"<<endl;
            getch();
        }
        break;

        }
    }

}
#endif // MAINS_H_INCLUDED
