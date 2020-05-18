#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED


void Baja_Cliente(){
    cls();
    int id,pos;
    cout<<"ingrese ID:"<<endl;
    cin>>id;
    char a;
    Clientes vec;
    pos=buscar_cliente(id);
    if(pos>0)
    {
        cout<<""<<endl;
        vec=Leer_Clientes(pos);
        Mostrar_cliente(vec);
        cout<<""<<endl<<endl;
        cout<<"Desea Eliminar el cliente Y/N?: ";
        cin.ignore();
        cin>>a;
        cout<<""<<endl;
        switch(a)
        {
        case 'Y':
        case 'y':
        {
            vec.Estado=false;
            if(sobreescribir_cliente(vec,pos))
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

void ordenar_x_apellido(Clientes* reg, int cant)
{
    int i,j,pos;
    Clientes aux;
    for(i=0; i<cant-1; i++)
    {
        pos=i;
        for(j=i+1; j<cant; j++)
        {
            if(strcmpi(reg[j].Apellidos,reg[pos].Apellidos)<0)
            {
                pos=j;
            }
        }
        aux=reg[i];
        reg[i]=reg[pos];
        reg[pos]=aux;

    }
}

void listar_clientes()
{
    cls();
    Clientes *reg;
    int cant;
    cant = Cant_Clientes();
    reg = (Clientes*) malloc(cant* sizeof(Clientes));
    if(reg==NULL)
    {
        cout<<"No hay memoria suficiente";
        getch();
        return;
    }
    FILE *p;
    p = fopen(PATH_Clientes, "rb");
    if(p==NULL)
    {
        cout<<"no se pudo abrir el archivo";
        getch();
        free(reg);
    }
    fread(reg,sizeof (Clientes),cant,p);
    fclose(p);

    ordenar_x_apellido(reg,cant);
    for(int x=0; x<cant; x++)
    {
        Mostrar_cliente(reg[x]);
        cout<<endl;
    }
    getch();


}

void Listar_Cliente_x_ID()
{
    cls();
    Clientes vec;
    int pos,ID;
    cout<<"Ingrese ID: "<<endl;
    cin>>ID;
    pos =  buscar_cliente(ID);
    if(pos>0)
    {
        cls();
        vec=Leer_Clientes(pos);
        Mostrar_cliente(vec);
        getch();
    }
    else
    {
        cout<<"el ID ingresado no existe";
        getch();
    }

}

Clientes Leer_Clientes(int pos)
{
    Clientes vec;
    FILE *p;
    p = fopen(PATH_Clientes,"rb");
    if(p==NULL)
    {
        vec.ID=-1;
        return vec;
    }
    fseek( p, pos* sizeof(Clientes),SEEK_SET);
    fread(&vec,sizeof(Clientes),1, p);
    fclose(p);
    return vec;
}

void Mostrar_cliente(Clientes vec)
{
    if(vec.Estado==true && vec.ID>=0)
    {
        cout<<"ID: "<<vec.ID<<endl;
        cout<<"Apellido: "<<vec.Apellidos<<endl;
        cout<<"Nombre: "<<vec.Nombres<<endl;
        cout<<"Mail: "<<vec.Mail<<endl;
        cout<<"Domicilio: "<<vec.Domicilio<<endl;
        cout<<"Codigo Postal: "<<vec.CP<<endl;
        cout<<"Fecha de Nacimiento: "<<vec.fechanac.dia<<"/"<<vec.fechanac.mes<<"/"<<vec.fechanac.anio<<endl;
    }
    else
    {
        cout<<"El ID ingresado no Existe";
        getch();
    }

}

bool sobreescribir_cliente(Clientes vec, int pos)
{
    FILE *p;
    p = fopen(PATH_Clientes,"rb+");
    if(p==NULL)
        return false;
    fseek(p,pos * sizeof (Clientes),SEEK_SET);

    fwrite(&vec,sizeof (Clientes), 1, p );
    fclose(p);
    return true;
}

int buscar_cliente(int ID)
{
    FILE *p;
    Clientes v;
    p = fopen(PATH_Clientes,"rb");
    if(p==NULL)
        return -2;
    while(fread(&v,sizeof(Clientes),1,p))
    {
        if(ID==v.ID)
        {
            fclose(p);
            return ID-1;
        }
    }
    fclose(p);
    return -1;
}

void Modificar_Cliente()
{
    cls();
    int ID,pos;
    Clientes vec;
    cout<<"ingrese ID del usuario a modificar: ";
    cin>>ID;
    pos = buscar_cliente(ID);
    if(pos>=0)
    {
        vec = Leer_Clientes(pos);
        cout<<""<<endl;
        Mostrar_cliente(vec);
        cout<<""<<endl;
        cout<<"Ingrese nuevo Domicilio: ";
        cin.ignore();
        cin.getline(vec.Domicilio,100);
        if(sobreescribir_cliente(vec,pos))
        {
            cout<<"Se guardo el nuevo domicilio";
            getch();
            return;
        }
        else
        {
            cout<<"No se pudo guardar el domicilio";
            getch();
        }
    }
    else
    {
        cout<<"ID ingresado no existe";
        getch();
        return;
    }
}

bool guardar_cliente(Clientes v)
{
    bool escribio;
    FILE *p;
    p=fopen(PATH_Clientes,"ab");
    if(p==NULL)
        return false;
    fseek(p,0,SEEK_END);
    escribio=fwrite(&v,sizeof (Clientes),1,p);
    fclose(p);
    return escribio;
}

bool chequeo_mail(char *Mail)
{
    int a=0,b=0,cad = strlen(Mail);
    if(!strchr(Mail, '@'))
    {
        cout<<"Mail ingresado es incorrecto"<<endl;
        getch();
        return false;
    }
    for(int x=0; x<cad; x++)
    {
        if(Mail[x]=='.' && Mail[x+1]=='.')
        {
            cout<<"Mail ingresado es incorrecto"<<endl;
            getch();
            return false;
        }
        if(Mail[x]=='@')
        {
            a++;
        }
        if(Mail[x]=='.')
        {
            b++;
        }
        if(Mail[0]=='@' || Mail[0]=='.')
        {
            cout<<"Mail ingresado es incorrecto"<<endl;
            getch();
            return false;
        }
        if(Mail[cad-1]=='.' || Mail[cad-1]=='@')
        {
            cout<<"Mail ingresado es incorrecto"<<endl;
            getch();
            return false;
        }
    }
    if(a>1)
    {
        cout<<"Mail ingresado es incorrecto"<<endl;
        getch();
        return false;
    }
    if(b==0)
    {
        cout<<"Mail ingresado es incorrecto"<<endl;
        getch();
        return false;
    }
    return true;
}

bool chequedo_Fechanac(Clientes v)
{
    Fecha aux;
    aux = hoy();
    if(v.fechanac.anio<aux.anio)
    {
        return true;
    }
    else if(v.fechanac.anio==aux.anio)
    {
        if(v.fechanac.mes<aux.mes)
        {
            return true;
        }
        else if(v.fechanac.mes==aux.mes)
        {
            if(v.fechanac.dia<aux.dia)
            {
                return true;
            }
        }
    }
    return false;
}

int Cant_Clientes()
{
    int bytes,cr;
    FILE *p;
    p=fopen(PATH_Clientes,"rb");
    if(p==NULL)
        return -2;

    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    cr=bytes/sizeof (Clientes);
    return cr;
}

void Nuevo_Cliente()
{
    cls();
    Clientes vec;
    int Cant;
    Cant=Cant_Clientes();
    if(Cant<0)
    {
        vec.ID=1;
    }
    else
    {
        vec.ID=Cant+1;
    }
    cout<<"Ingrese el Nombre del Cliente:  ";
    cin.ignore();
    cin.getline(vec.Nombres,50);
    if(strlen(vec.Nombres)==0){
        cout<<"Este campo no puede estar vacio.";
        getch();
        return;
    }
    cout<<"Ingrese Apellidos:  ";
    cin.getline(vec.Apellidos,50);
    if(strlen(vec.Apellidos)==0){
        cout<<"Este campo no puede estar vacio.";
        getch();
        return;
    }
    cout<<"Ingrese el Mail:  ";
    cin>>vec.Mail;
    if(!chequeo_mail(vec.Mail))
        return;
    cout<<"Ingrese Domicilio: ";
    cin.ignore();
    cin.getline(vec.Domicilio, 100);
    if(strlen(vec.Domicilio)==0){
        cout<<"Este campo no puede estar vacio.";
        getch();
        return;
    }
    cout<<"Ingrese Codigo Postal: ";
    cin>>vec.CP;
    if(vec.CP<1000 || vec.CP>10000)
    {
        cout<<"Codigo postal incorrecto";
        getch();
        return;
    }
    cout<<"Ingrese fecha de nacimiento: "<<endl;
    cout<<"Dia: ";
    cin>>vec.fechanac.dia;
    cout<<"Mes: ";
    cin>>vec.fechanac.mes;
    cout<<"Año: ";
    cin>>vec.fechanac.anio;
    if(!chequedo_Fechanac(vec))
    {
        cout<<"Fecha ingresada es incorrecta"<<endl;
        getch();
        return;
    }
    vec.Estado=true;

    if(guardar_cliente(vec))
    {
        cout<<"Se guardo correctamente el cliente";
        getch();
    }
    else
    {
        cout<<"No se pudo guardar el cliente";
        getch();
    }
}




#endif // CLIENTES_H_INCLUDED
