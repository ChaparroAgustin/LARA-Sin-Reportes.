#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

void Nuevo_Pedido()
{

    cls();
    Pedidos vec;
    Platos v;
    Clientes reg;
    int cant,cliente,plato;
    cant = Cant_Pedidos();
    if(cant>=0)
    {
        vec.ID=cant+1;
    }
    else
    {
        vec.ID=1;
    }
    cout<<"Ingrese ID del Cliente: "<<endl;
    cin>>vec.IDCliente;
    cliente = buscar_cliente(vec.IDCliente);
    if(cliente>=0)
    {
        cout<<endl;
        reg = Leer_Clientes(cliente);
        Mostrar_cliente(reg);
    }
    else
    {
        cout<<"El ID de Cliente no exixte"<<endl;
        getch();
        return;
    }
    cout<<endl;
    cout<<"Ingrese ID de Plato: "<<endl;
    cin>>vec.IDPlato;
    cls();
    plato = Buscar_Platos(vec.IDPlato);
    if(plato>=0)
    {
        cout<<endl;
        v = Leer_Platos(plato);
        listar_Platos(v);
    }
    else
    {
        cout<<"El ID de Plato no exixte"<<endl;
        getch();
        return;
    }
    cout<<endl;
    cout<<"Ingrese la cantidad: "<<endl;
    cin>>vec.Cantidad;
    cls();
    if(vec.Cantidad<=0)
        return;

    cout<<endl;
    cout<<"Precio unitario: "<< v.Valor_Venta<<endl;
    vec.PrecioUnitario=v.Valor_Venta;
    cout<<endl;
    cout<<"Ingrese fecha del Pedido: "<<endl;
    cout<<"Dia: ";
    cin>>vec.FechaPedido.dia;
    cout<<"Mes: ";
    cin>>vec.FechaPedido.mes;
    cout<<"Año: ";
    cin>>vec.FechaPedido.anio;
    if(!Chequeo_Fecha(vec.FechaPedido))
    {
        cout<<"Fecha incorrecta"<<endl;
        getch();
        return;
    }
    cout<<"Ingrese Valoracion: "<<endl;
    cin>>vec.Valoracion;
    if(vec.Valoracion<0 || vec.Valoracion>10)
    {
        cout<<"Valoracion ingresada es Incorrecta";
        getch();
        return;
    }

    vec.Estado=1;

    if(guardar_Pedido(vec))
    {
        cout<<"El pedido se guardo correctamente";
        getch();
    }
    else
    {
        cout<<"No se guardo el Pedido";
        getch();
    }
    return;
}

bool guardar_Pedido(Pedidos v)
{
    FILE *p;
    p = fopen(PATH_Pedidos,"ab");
    if(p == NULL)
        return false;

    if(fwrite(&v,sizeof (Pedidos),1,p))
    {
        fclose(p);
        return true;
    }

    fclose(p);
    return false;
}

bool Chequeo_Fecha(Fecha f)
{
    Fecha aux;
    aux = hoy();
    if(f.anio>aux.anio)
    {
        return true;
    }
    if(f.anio==aux.anio)
    {
        if(f.mes=aux.mes)
        {
            if(f.dia>=aux.dia)
            {
                return true;
            }
        }
        if(f.mes>aux.mes)
        {
            return true;
        }
    }
    return false;
}

int Cant_Pedidos()
{
    int bytes,cr;
    FILE *p;
    p=fopen(PATH_Pedidos,"rb");
    if(p==NULL)
        return -2;

    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    cr=bytes/sizeof (Pedidos);
    return cr;
}

void Modificar_Pedido()
{

    cls();
    Pedidos vec;
    int ID,pos;
    cout<<"Ingrese ID: ";
    cin>>ID;
    pos = Buscar_Pedido(ID);
    if(pos>=0)
    {
        vec = Leer_Pedido(pos);
        cout<<endl;
        mostrar_Pedido(vec);
        cout<<endl;
        cout<<"Ingrese el Nuevo Estado: ";
        cin>>vec.Estado;
        if(vec.Estado>3 || vec.Estado<1)
        {
            cout<<"Estado Incorrecto";
            getch();
            return;
        }
        if(Sobreescribir_Pedidos(vec, pos))
        {
            cout<<"Se guardo correctamente el nuevo estado";
            getch();
            return;
        }
        else
        {
            cout<<"No se guardo correctamente el pedido";
            getch();
            return;
        }

    }
    else
    {
        cout<<"ID ingresado es incorrecto";
        getch();
        return;
    }


}

bool Sobreescribir_Pedidos(Pedidos vec,int pos)
{
    FILE *p;
    p = fopen(PATH_Pedidos,"rb+");
    if(p == NULL)
        return false;
    fseek(p,pos*sizeof (Pedidos),SEEK_SET);
    if(fwrite(&vec,sizeof (Pedidos),1,p))
    {
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

void mostrar_Pedido(Pedidos vec)
{
    if(vec.ID>0)
    {

        cout<<"ID: ";
        setColor(YELLOW);
        cout<<vec.ID<<endl;
        setColor(GREEN);
        cout<<"ID Cliente: ";
        setColor(YELLOW);
        cout<<vec.IDCliente<<endl;
        setColor(GREEN);
        cout<<"ID Plato: ";
        setColor(YELLOW);
        cout<<vec.IDPlato<<endl;
        setColor(GREEN);
        cout<<"Cantidad: ";
        setColor(YELLOW);
        cout<<vec.Cantidad<<endl;
        setColor(GREEN);
        cout<<"Precio Unitario: ";
        setColor(YELLOW);
        cout<<vec.PrecioUnitario<<endl;
        setColor(GREEN);
        cout<<"Fecha de Pedido: ";
        setColor(YELLOW);
        cout<<vec.FechaPedido.dia<<"/"<<vec.FechaPedido.mes<<"/"<<vec.FechaPedido.anio<<endl;
        setColor(GREEN);
        cout<<"Valoracion: ";
        setColor(YELLOW);
        cout<<vec.Valoracion<<endl;

        switch(vec.Estado)
        {
        case 1:
        {
            setColor(YELLOW);
            cout<<"Estado: Pedido en Curso"<<endl;
        }
        break;
        case 2:
        {
            setColor(GREY);
            cout<<"Estado: Pedido Completado"<<endl;
        }
        break;
        case 3:
        {
            setColor(RED);
            cout<<"Estado: Pedido Cancelado"<<endl;
        }
        break;
        }
    }
    else
    {
        cout<<"ID ingresado es Incorrecto"<<endl;
    }
    setColor(WHITENESS);
    setBackgroundColor(BLACK);
    return;
}

Pedidos Leer_Pedido(int pos)
{
    Pedidos vec;
    FILE *p;
    p = fopen(PATH_Pedidos, "rb");
    if(p == NULL)
    {
        vec.ID=-1;
        return vec;
    }
    fseek(p,pos *sizeof (Pedidos),SEEK_SET);
    fread(&vec,sizeof (Pedidos),1,p);
    fclose(p);
    return vec;
}

int Buscar_Pedido(int ID)
{
    Pedidos v;
    FILE *p;
    p = fopen(PATH_Pedidos,"rb");
    if(p == NULL)
        return -2;
    while(fread(&v,sizeof(Pedidos),1,p))
    {
        if(v.ID==ID)
        {
            fclose(p);
            return ID-1;
        }
    }
    fclose(p);
    return -1;

}

void Listar_Pedido_x_ID()
{
    cls();
    int ID,pos;
    Pedidos vec;
    cout<<"Ingrese ID: ";
    cin>>ID;
    pos = Buscar_Pedido(ID);
    if(pos>=0)
    {
        vec = Leer_Pedido(pos);
        cout<<endl;
        mostrar_Pedido(vec);
        getch();
        return;
    }
    else
    {
        cout<<"ID ingresado es incorrecto";
        getch();
    }
    return;
}

void Listar_Pedidos()
{
    cls();
    int cant,pos;
    Pedidos *v;
    cant = Cant_Pedidos();
    if(cant<0)
    {
        cout<<"No hay pedidos cargados";
        getch();
        return;
    }
    v =(Pedidos *) malloc(cant * sizeof(Pedidos));
    if(v == NULL)
    {
        cout<<"No hay memoria suficiente";
        getch();
    }
    FILE *p;
    p = fopen(PATH_Pedidos,"rb");
    if(p == NULL)
    {
        cout<<"No se pudo abrir el archivo";
        getch();
        free(v);
    }
    fread(v,sizeof (Pedidos),cant,p);
    fclose(p);

    for(int x=0; x<cant; x++)
    {
        mostrar_Pedido(v[x]);
        cout<<endl;
    }
    getch();
    setColor(WHITENESS);
    setBackgroundColor(BLACK);
}


#endif // PEDIDOS_H_INCLUDED
