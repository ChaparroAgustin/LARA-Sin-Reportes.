#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

/*Prototipos/ PLATOS*/

void Menu_Platos();

void Nuevo_Plato();

int Buscar_Platos(int);

bool CargarPlatos(Platos *);

void Menu_Platos(Platos);

bool guardar_Platos(Platos);

void Modificar_Plato();

void Listar_Platos_x_ID();

Platos Leer_Platos(int);

void listar_Platos(Platos);

bool Sobreescribir_Platos(Platos, int);

void Platos_X_Restaurante();

int Cant_Platos();

void Listar_Todos();

void Dar_Baja();

/*Prototipos CLIENTES*/

void Menu_Clientes();

void Nuevo_Cliente();

int Cant_Clientes();//devuelve la cantidad de registro que contiene el archivo

Fecha hoy();//trae al programa la fecha del sistema

bool chequedo_Fechanac(Clientes);

bool chequeo_mail(char);//cheuque que el mail ingresado cumpla las condiciones necesarias

bool guardar_cliente(Clientes);//Guarda en el archivo cada cliente cargado

void Modificar_Cliente();

int buscar_cliente(int);

bool sobreescribir_cliente(Clientes, int);

void Mostrar_cliente(Clientes);

Clientes Leer_Clientes(int);

void Listar_Cliente_x_ID();

void listar_clientes();

void ordenar_x_apellido(Clientes, int);

void Baja_Cliente();

// Prototipos Pedidos

void Menu_Pedidos();

void Nuevo_Pedido();

int Cant_Pedidos();

bool Chequeo_Fecha(Fecha);

bool guardar_Pedido(Pedidos);

void Modificar_Pedido();

int Buscar_Pedido(int);

Pedidos Leer_Pedido(int);

void mostrar_Pedido(Pedidos);

bool Sobreescribir_Pedidos(Pedidos, int);

void Listar_Pedido_x_ID();

void Listar_Pedidos();

//Prototipos Configuracion

void Realizar_Backups();

void Restaurar_backups();

bool Creacion_Backup_Clientes();

bool Creacion_Backup_Pedidos();

bool Creacion_Backup_Platos();

int Cant_ClientesBKP();

int Cant_PedidosBKP();

int Cant_PlatosBKP();

bool Restauracion_Backup_Clientes();

bool Restauracion_Backup_Pedidos();

bool Restauracion_Backup_Platos();


#endif // PROTOTIPOS_H_INCLUDED
