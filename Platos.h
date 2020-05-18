#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED

void Dar_Baja()
{
    cls();
    int ID,pos;
    char a;
    Platos vec;
    cout<<"Ingrese ID a dar de baja: "<<endl;
    cin>>ID;
    pos=Buscar_Platos(ID);
    if(pos>=0)
    {
        cout<<""<<endl;
        vec=Leer_Platos(pos);
        if(vec.Estado==false)
        {
            cout<<"ID ingresado no se encuentra";
            getch();
            return;
        }
        listar_Platos(vec);
        cout<<""<<endl<<endl;
        cout<<"Desea Eliminar plato Y/N?: ";
        cin.ignore();
        cin>>a;
        cout<<""<<endl;
        switch(a)
        {
        case 'Y':
        case 'y':
        {
            vec.Estado=false;
            if(Sobreescribir_Platos(vec,pos))
            {
                cout<<""<<endl;
                cls();
                cout<<"Se elimino el plato correctamente"<<endl;
                getch();
                return;
            }
        }
        break;
        case 'N':
        case 'n':
        {
            cout<<"No se elimino el plato."<<endl;
            getch();
            return;
        }
        break;
        }

    }
    getch();


}

void Listar_Todos()
{
    int cant;
    cant=Cant_Platos();
    Platos *vec;
    vec=(Platos *) malloc(cant * sizeof(Platos));
    if(vec==NULL)
    {
        cout<<"No hay memoria suficiente";
        getch();
        return;
    }

    FILE *p;
    p=fopen(PATH_Platos,"rb");
    if(p==NULL)
    {
        cout<<"No se encuentra el Archivo";
        getch();
        free(vec);
        return;
    }

    fread(vec,sizeof(Platos),cant,p);
    fclose(p);
    cls();
    for(int x=0; x<cant; x++)
    {
        if(vec[x].Estado==true)
        {
            listar_Platos(vec[x]);
            cout<<endl;
        }
    }
    getch();
    free(vec);
}

int Cant_Platos()
{
    int bytes,cp;
    FILE *p;
    p = fopen(PATH_Platos, "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cp = bytes / sizeof(Platos);
    fclose(p);
    return cp;
}

void Platos_X_Restaurante()
{
    cls();
    int ID,cant;
    cout<<"ingrese ID del Restaurante: ";
    cin>>ID;
    cant=Cant_Platos();
    if(cant==0)
    {
        cout<<"No se encuentran cargados Platos";
        getch();
        return;
    }
    Platos *vec;
    vec=(Platos *) malloc(cant * sizeof(Platos));
    if(vec==NULL)
    {
        cout<<"No hay memoria suficiente";
        getch();
        return;
    }

    FILE *p;
    p=fopen(PATH_Platos,"rb");
    if(p==NULL)
    {
        cout<<"No se encuentra el Archivo";
        getch();
        free(vec);
        return;
    }

    fread(vec,sizeof(Platos),cant,p);
    fclose(p);

    cls();
    for(int x=0; x<cant; x++)
    {
        if(vec[x].IDRestaurante==ID && vec[x].Estado==true)
        {
            listar_Platos(vec[x]);
            cout<<endl;
        }
    }
    getch();

    free(vec);
}

bool Sobreescribir_Platos(Platos vec, int pos)
{
    FILE *p;
    p=fopen(PATH_Platos,"rb+");
    if(p==NULL)
        return false;

    fseek(p,pos*sizeof (Platos),SEEK_SET);
    bool a=fwrite(&vec,sizeof(Platos),1,p);
    fclose(p);
    return a;
}

void listar_Platos(Platos vec)
{
    cout<<"ID: "<<vec.ID<<endl;
    cout<<"Nombre: "<<vec.Nombre<<endl;
    cout<<"Costo de Preparación: $"<<vec.Costo_Preparacion<<endl;
    cout<<"Valor de Venta: $"<<vec.Valor_Venta<<endl;
    cout<<"Tiempo de Preparación: "<<vec.Tiempo_Preparacion<<" min"<<endl;
    cout<<"ID de Restaurante: "<<vec.IDRestaurante<<endl;
    cout<<"Comisión: "<<vec.Comision<<"%"<<endl;
    cout<<"ID de Categoria: "<<vec.IDCategoria<<endl;
}

Platos Leer_Platos(int pos)
{
    Platos vec;
    FILE *p;
    p=fopen(PATH_Platos,"rb");
    if(p==NULL)
    {
        vec.ID=-1;
        return vec;
    }
    fseek( p, pos * sizeof(Platos),SEEK_SET);
    fread(&vec,sizeof (Platos),1,p);
    fclose(p);
    return vec;

}

void Listar_Platos_x_ID()
{
    cls();
    int id, pos;
    cout<<"Ingrese ID: ";
    cin>>id;

    pos=Buscar_Platos(id);
    if(pos>=0)
    {
        Platos vec=Leer_Platos(pos);
        if(vec.Estado==false)
        {
            cout<<"ID ingresado no se encuentra";
            getch();
            return;
        }
        listar_Platos(vec);
        getch();
    }
    else
    {
        cout<<"No existe el ID ingresado";
        getch();
    }
}

void Modificar_Plato()
{
    cls();
    Platos vec;
    int ID,pos;
    cout<<"Ingrese id del plato a modificar: "<<endl;
    cin>>ID;
    pos=Buscar_Platos(ID);
    if(pos>=0)
    {
        vec=Leer_Platos(pos);
        if(vec.Estado==false)
        {
            cout<<"ID ingresado no se encuentra";
            getch();
            return;
        }
        cout<<""<<endl;
        listar_Platos(vec);
        cout<<""<<endl;
        cout<<"Ingrese Valor de Venta: $";
        cin>>vec.Valor_Venta;
        if(vec.Valor_Venta<vec.Costo_Preparacion)
        {
            cout<<"El valor ingresado es menor al costo de preparacion,";
            return;
        }
        cout<<"Ingrese tiempo de preparación: ";
        cin>>vec.Tiempo_Preparacion;
        if(Sobreescribir_Platos(vec,pos))
        {
            cls();
            cout<<"Se modifico correctamente el plato";
            getch();
        }
        else
        {
            cls();
            cout<<"No se pudo modificar el plato";
            getch();
        }
    }
    else
    {
        cls();
        cout<<"El ID no se encuentra";
        getch();
    }

}

void Nuevo_Plato()
{
    Platos vec;
    if(CargarPlatos(&vec))
    {
        if(guardar_Platos(vec))
        {
            cout<<"Se guardo correctamente el Plato"<<endl;
            getch();
        }
        else
        {
            cout<<"No se pudo guardar el plato correctamente"<<endl;
            getch();
        }
    }
    else
    {
        cout<<"No se pudo guardar el Plato"<<endl;
        getch();
    }
}

bool guardar_Platos(Platos reg)
{
    bool escribio;
    FILE *p;
    p = fopen(PATH_Platos, "ab");
    if (p == NULL)
        return false;

    escribio = fwrite(&reg, sizeof(Platos), 1, p);
    fclose(p);
    return escribio;
}

int Buscar_Platos(int id)
{
    Platos v;
    int i=0;
    FILE *p;
    p=fopen(PATH_Platos,"rb");
    if(p == NULL)
        return -2;

    while(fread(&v,sizeof(Platos),1,p))
    {
        if(id==v.ID)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

bool CargarPlatos(Platos *vec)
{
    cls();
    int ID,pos;
    cout<<"Ingrese ID: ";
    cin>>ID;
    if(ID<=0)
        return false;
    pos=Buscar_Platos(ID);
    Platos reg=Leer_Platos(pos);
    if(reg.Estado==false)
    {
        cout<<"ID ingresado ya se encuentra en uso"<<endl;;
        getch();
        return false;
    }
    if(pos>=0)
    {
        cout<<"El ID ya se encuentra cargado"<<endl;
        getch();
        return false;
    }
    vec->ID=ID;
    cout<<"Ingrese Nombre: ";
    cin.ignore();
    cin.getline(vec->Nombre,50);
    if(strlen(vec->Nombre)<=0)
        return false;
    cout<<"Ingrese Costo de Preparación: $";
    cin>>vec->Costo_Preparacion;
    if(vec->Costo_Preparacion<0)
        return false;
    cout<<"Ingrese Valor de Venta: $";
    cin>>vec->Valor_Venta;
    if(vec->Valor_Venta<0 || vec->Valor_Venta<vec->Costo_Preparacion)
        return false;
    cout<<"ingrese Tiempo de Preparación: ";
    cin>>vec->Tiempo_Preparacion;
    if(vec->Tiempo_Preparacion<0)
        return false;
    cout<<"Ingrese ID del Restaurante: ";
    cin>>vec->IDRestaurante;
    if(vec->IDRestaurante<0)
        return false;
    cout<<"Ingrese Comisión del Restaurante: ";
    cin>>vec->Comision;
    if(vec->Comision<0 || vec->Comision>100)
        return false;
    cout<<"Ingrese ID de Categoria: ";
    cin>>vec->IDCategoria;
    if(vec->IDCategoria<0)
        return false;
    vec->Estado=true;
    return true;

}


#endif // PLATOS_H_INCLUDED
