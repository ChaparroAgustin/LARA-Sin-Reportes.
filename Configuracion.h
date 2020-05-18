#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void Realizar_Backups()
{
    cls();
    char a;
    cout<<"--------------------------------"<<endl;
    cout<<"Realizar BACK UP de los Archivos"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<endl<<endl;
    cout<<"Desea realizar back up?  Y/N"<<endl;
    cin>>a;
    switch(a)
    {
    case 'y':
    case 'Y':
    {
        if(Creacion_Backup_Clientes()&&Creacion_Backup_Pedidos()&&Creacion_Backup_Platos())
        {
            cout<<"se procedio con la realizacion de los BackUps";
            getch();
            return;
        }
        else
        {
            cout<<"No se pudo realizar los BackUps";
            getch();
            return;
        }
    }
    break;
    case 'n':
    case 'N':
    {
        cout<<"Se cancelo el proceso"<<endl;
        getch();
        return;
    }
    break;
    }
}

bool Creacion_Backup_Platos()
{
    //backup Platos
    Platos v;
    int x, cant = Cant_Platos();
    FILE *p, *q;
    p = fopen(PATH_Platos,"rb");
    if(p == NULL)
        return false;
    q = fopen(PATH_Platos_BKP,"wb");
    if(q == NULL)
        return false;

    for(x=0; x<cant; x++)
    {
        fread(&v,sizeof (Platos),1,p);
        fwrite(&v,sizeof (Platos),1,q);
    }
    fclose(p);
    fclose(q);
    return true;
}
bool Creacion_Backup_Clientes()
 {
    //backup Clientes
    Clientes vec;
    int y, cant2 = Cant_Clientes();
    FILE *w, *r;
    w = fopen(PATH_Clientes,"rb");
    if(w == NULL)
        return false;
    r = fopen(PATH_Clientes_BKP,"wb");
    if(r == NULL)
        return false;

    for(y=0; y<cant2; y++)
    {
        fread(&vec,sizeof (Clientes),1,w);
        fwrite(&vec,sizeof (Clientes),1,r);
    }
    fclose(w);
    fclose(r);
    return true;
}

bool Creacion_Backup_Pedidos()
 {
    //backup Pedidos
    Pedidos reg;
    int z, cant3 = Cant_Pedidos();
    FILE *m, *b;
    m = fopen(PATH_Pedidos,"rb");
    if(m == NULL)
        return false;
    b = fopen(PATH_Pedidos_BKP,"wb");
    if(b == NULL)
        return false;

    for(z=0; z<cant3; z++)
    {
        fread(&reg,sizeof (Pedidos),1,m);
        fwrite(&reg,sizeof (Pedidos),1,b);
    }
    fclose(m);
    fclose(b);
    return true;
 }
void Restaurar_backups()
{
    cls();
    char a;
    cout<<"--------------------------------"<<endl;
    cout<<"Restaurar BACK UP de los Archivos"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<endl<<endl;
    cout<<"Desea restaurar los back ups?  Y/N"<<endl;
    cin>>a;
    switch(a)
    {
    case 'y':
    case 'Y':
    {
        if(Restauracion_Backup_Clientes()&&Restauracion_Backup_Pedidos()&&Restauracion_Backup_Platos())
        {
            cout<<"se procedio con la restauracion de los BackUps";
            getch();
            return;
        }
        else
        {
            cout<<"No se pudo restaurar los BackUps";
            getch();
            return;
        }
    }
    break;
    case 'n':
    case 'N':
    {
        cout<<"Se cancelo el proceso"<<endl;
        getch();
        return;
    }
    break;
    }

}

bool Restauracion_Backup_Pedidos(){

    //Restaurar Pedidos
    Pedidos v;
    int x, cant = Cant_PedidosBKP();
    FILE *p, *q;
    p = fopen(PATH_Pedidos,"wb");
    if(p == NULL)
        return false;
    q = fopen(PATH_Pedidos_BKP,"rb");
    if(q == NULL)
        return false;

    for(x=0; x<cant; x++)
    {
        fread(&v,sizeof (Pedidos),1,q);
        fwrite(&v,sizeof (Pedidos),1,p);
    }
    fclose(p);
    fclose(q);
    return true;
}


bool Restauracion_Backup_Platos()
{
    //Restauracion Platos
    Platos v;
    int x, cant = Cant_PlatosBKP();
    FILE *p, *q;
    p = fopen(PATH_Platos,"wb");
    if(p == NULL)
        return false;
    q = fopen(PATH_Platos_BKP,"rb");
    if(q == NULL)
        return false;

    for(x=0; x<cant; x++)
    {
        fread(&v,sizeof (Platos),1,q);
        fwrite(&v,sizeof (Platos),1,p);
    }
    fclose(p);
    fclose(q);
    return true;
}

bool Restauracion_Backup_Clientes()
{
    //Restaurar Clientes
    Clientes vec;
    int y, cant2 = Cant_ClientesBKP();
    FILE *w, *r;
    w = fopen(PATH_Clientes,"wb");
    if(w == NULL)
        return false;
    r = fopen(PATH_Clientes_BKP,"rb");
    if(r == NULL)
        return false;

    for(y=0; y<cant2; y++)
    {
        fread(&vec,sizeof (Clientes),1,r);
        fwrite(&vec,sizeof (Clientes),1,w);
    }
    fclose(w);
    fclose(r);
    return true;
}

int Cant_ClientesBKP()
{
    int bytes,cp;
    FILE *p;
    p = fopen(PATH_Clientes_BKP, "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cp = bytes / sizeof(Clientes);
    fclose(p);
    return cp;
}

int Cant_PedidosBKP()
{
    int bytes,cp;
    FILE *p;
    p = fopen(PATH_Pedidos_BKP, "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cp = bytes / sizeof(Pedidos);
    fclose(p);
    return cp;
}

int Cant_PlatosBKP()
{
    int bytes,cp;
    FILE *p;
    p = fopen(PATH_Platos_BKP, "rb");
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

#endif // CONFIGURACION_H_INCLUDED
