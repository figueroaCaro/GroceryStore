#include <stdio.h>
#include<string.h>
// Ejercicio Práctica 3
//Figueroa Ruiz Carolina

typedef struct
{
	int clave;
	char nombreProducto[20];
	char unidad[20];
	float precio;
} Producto;

typedef struct
{
	char nombreEmpleado[20];
	char apellidoEmpleado[20];
	char rango[20];
} Empleado;

typedef struct
{
	char nombreGerente[20];
	char apellidoGerente[20];
	float salario;
} Gerente;

typedef struct
{
	int codigoSec;
	char categoria[20];
	Empleado encargadoSec[10];
	Producto productos[10];
	int numE;
	int numP;
} Seccion;

typedef struct
{
	char nombreTie[20];
	int codigoTie;
	Gerente encargadoTie;
	Seccion secciones[5];
	int numS;
} Tienda;

Tienda crearTienda();
Seccion crearSeccion();
Producto registrarProducto();
Producto agregarProducto(Tienda *, int);
Empleado crearEmpleado();
void agregarEmpleado(Tienda *, int);
Gerente registrarGerente();
void agregarGerente(Tienda *);
Seccion agregarSeccion(Tienda *);
void imprimTienda(Tienda *);
void imprimSecc(Tienda *);
void imprimProduc(Tienda *);

int count=1;

int main()
{
	printf("-----> ADMINISTRACION PARA UNA CADENA DE ABARROTES <-----\n");
	int opcion=0, i=0, t=0;
	
	Tienda arrTienda[5];
	
	strcpy(arrTienda[0].nombreTie,"Wallmart");
	arrTienda[0].codigoTie=1234;
	strcpy(arrTienda[0].encargadoTie.nombreGerente,"Pablo");
	strcpy(arrTienda[0].encargadoTie.apellidoGerente,"Flores");
	arrTienda[0].encargadoTie.salario=50000;
	arrTienda[0].numS=3;
	
	arrTienda[0].secciones[0].numE=2;
	arrTienda[0].secciones[0].numP=5;
	arrTienda[0].secciones[0].codigoSec=11111;
	strcpy(arrTienda[0].secciones[0].categoria,"Limpieza");
	strcpy(arrTienda[0].secciones[0].encargadoSec[0].nombreEmpleado,"Manuel");
	strcpy(arrTienda[0].secciones[0].encargadoSec[0].apellidoEmpleado,"Fernandez");
	strcpy(arrTienda[0].secciones[0].encargadoSec[0].rango,"Intermedio");
	strcpy(arrTienda[0].secciones[0].encargadoSec[1].nombreEmpleado,"Francisco");
	strcpy(arrTienda[0].secciones[0].encargadoSec[1].apellidoEmpleado,"Lopez");
	strcpy(arrTienda[0].secciones[0].encargadoSec[1].rango,"Alto");
	arrTienda[0].secciones[0].productos[0].clave=000;
	strcpy(arrTienda[0].secciones[0].productos[0].nombreProducto,"Zote");
	strcpy(arrTienda[0].secciones[0].productos[0].unidad,"Piezas");
	arrTienda[0].secciones[0].productos[0].precio=45;
	arrTienda[0].secciones[0].productos[1].clave=111;
	strcpy(arrTienda[0].secciones[0].productos[1].nombreProducto,"Ace");
	strcpy(arrTienda[0].secciones[0].productos[1].unidad,"kilo");
	arrTienda[0].secciones[0].productos[1].precio=80;
	arrTienda[0].secciones[0].productos[2].clave=222;
	strcpy(arrTienda[0].secciones[0].productos[2].nombreProducto,"Percil");
	strcpy(arrTienda[0].secciones[0].productos[2].unidad,"Litro");
	arrTienda[0].secciones[0].productos[2].precio=100;
	arrTienda[0].secciones[0].productos[3].clave=333;
	strcpy(arrTienda[0].secciones[0].productos[3].nombreProducto,"Suavitel");
	strcpy(arrTienda[0].secciones[0].productos[3].unidad,"Litros");
	arrTienda[0].secciones[0].productos[3].precio=70;
	arrTienda[0].secciones[0].productos[4].clave=444;
	strcpy(arrTienda[0].secciones[0].productos[4].nombreProducto,"Toallas");
	strcpy(arrTienda[0].secciones[0].productos[4].unidad,"Piezas");
	arrTienda[0].secciones[0].productos[4].precio=20;
	
	arrTienda[0].secciones[0].numE=2;
	arrTienda[0].secciones[0].numP=5;
	arrTienda[0].secciones[1].codigoSec=22222;
	strcpy(arrTienda[0].secciones[1].categoria,"Comida");
	strcpy(arrTienda[0].secciones[1].encargadoSec[0].nombreEmpleado,"Jose");
	strcpy(arrTienda[0].secciones[1].encargadoSec[0].apellidoEmpleado,"Jimenez");
	strcpy(arrTienda[0].secciones[1].encargadoSec[0].rango,"Intermedio");
	strcpy(arrTienda[0].secciones[1].encargadoSec[1].nombreEmpleado,"Julio");
	strcpy(arrTienda[0].secciones[1].encargadoSec[1].apellidoEmpleado,"Cruz");
	strcpy(arrTienda[0].secciones[1].encargadoSec[1].rango,"Alto");
	arrTienda[0].secciones[1].productos[0].clave=999;
	strcpy(arrTienda[0].secciones[1].productos[0].nombreProducto,"Cheetos");
	strcpy(arrTienda[0].secciones[1].productos[0].unidad,"Piezas");
	arrTienda[0].secciones[1].productos[0].precio=10;
	arrTienda[0].secciones[1].productos[1].clave=111;
	strcpy(arrTienda[0].secciones[1].productos[1].nombreProducto,"Refresco");
	strcpy(arrTienda[0].secciones[1].productos[1].unidad,"Litro");
	arrTienda[0].secciones[1].productos[1].precio=20;
	arrTienda[0].secciones[1].productos[2].clave=222;
	strcpy(arrTienda[0].secciones[1].productos[2].nombreProducto,"Manzanas");
	strcpy(arrTienda[0].secciones[1].productos[2].unidad,"Piezas");
	arrTienda[0].secciones[1].productos[2].precio=12;
	arrTienda[0].secciones[1].productos[3].clave=333;
	strcpy(arrTienda[0].secciones[1].productos[3].nombreProducto,"Uvas");
	strcpy(arrTienda[0].secciones[1].productos[3].unidad,"kilo");
	arrTienda[0].secciones[1].productos[3].precio=80;
	arrTienda[0].secciones[1].productos[4].clave=444;
	strcpy(arrTienda[0].secciones[1].productos[4].nombreProducto,"Huevo");
	strcpy(arrTienda[0].secciones[1].productos[4].unidad,"Kilo");
	arrTienda[0].secciones[1].productos[4].precio=40;
	
	arrTienda[0].secciones[0].numE=2;
	arrTienda[0].secciones[0].numP=5;
	arrTienda[0].secciones[2].codigoSec=33333;
	strcpy(arrTienda[0].secciones[2].categoria,"Ropa");
	strcpy(arrTienda[0].secciones[2].encargadoSec[0].nombreEmpleado,"Josefa");
	strcpy(arrTienda[0].secciones[2].encargadoSec[0].apellidoEmpleado,"Lugo");
	strcpy(arrTienda[0].secciones[2].encargadoSec[0].rango,"Alto");
	strcpy(arrTienda[0].secciones[2].encargadoSec[1].nombreEmpleado,"Aranza");
	strcpy(arrTienda[0].secciones[2].encargadoSec[1].apellidoEmpleado,"Castillo");
	strcpy(arrTienda[0].secciones[2].encargadoSec[1].rango,"Bajo");
	arrTienda[0].secciones[2].productos[0].clave=999;
	strcpy(arrTienda[0].secciones[2].productos[0].nombreProducto,"Sueter");
	strcpy(arrTienda[0].secciones[2].productos[0].unidad,"Piezas");
	arrTienda[0].secciones[2].productos[0].precio=150;
	arrTienda[0].secciones[2].productos[1].clave=111;
	strcpy(arrTienda[0].secciones[2].productos[1].nombreProducto,"Pantalon");
	strcpy(arrTienda[0].secciones[2].productos[1].unidad,"Piezas");
	arrTienda[0].secciones[2].productos[1].precio=300;
	arrTienda[0].secciones[2].productos[2].clave=222;
	strcpy(arrTienda[0].secciones[2].productos[2].nombreProducto,"Zapatos");
	strcpy(arrTienda[0].secciones[2].productos[2].unidad,"Pares");
	arrTienda[0].secciones[2].productos[2].precio=400;
	arrTienda[0].secciones[2].productos[3].clave=333;
	strcpy(arrTienda[0].secciones[2].productos[3].nombreProducto,"Blusas");
	strcpy(arrTienda[0].secciones[2].productos[3].unidad,"Piezas");
	arrTienda[0].secciones[2].productos[3].precio=100;
	arrTienda[0].secciones[2].productos[4].clave=444;
	strcpy(arrTienda[0].secciones[2].productos[4].nombreProducto,"Pijamas");
	strcpy(arrTienda[0].secciones[2].productos[4].unidad,"Piezas");
	arrTienda[0].secciones[2].productos[4].precio=350;
	
	int cont=1;
	
	while (1)
	{
		printf("\nElija la opcion de lo que desea realizar:\n");
		printf("1) Crear una tienda departamental\n");//Se pueden crear 4 más
		printf("2) Mostrar las tiendas departamentales registradas\n");
		printf("3) Mostrar las secciones registradas\n");
		printf("4) Mostrar los productos registrados\n");
		printf("5) Salir\n");
		scanf("%d", &opcion);
		switch (opcion)
		{
		case 1:
			printf("%cCu%cntas tiendas m%cs desea registar (l%cmite 4)?: ",168,160,160,161);
			scanf("%d", &t);
			for(i=0;i<t;i++){
				arrTienda[count] = crearTienda();
				agregarGerente(&arrTienda[count]);
				agregarSeccion(&arrTienda[count]); 
				count++;
			}
			break;
		case 2:
			if(count==1){ //Para cuando no se registren aún tiendas
				printf("\nTienda 1:\n--------------------------\n");
				imprimTienda(&arrTienda[0]);
			}
			for(i=0;i<t+count-1;i++){
				printf("\nTienda %d:\n--------------------------\n", i+1);
				imprimTienda(&arrTienda[i]);
			}
			break;
		case 3:
			if(count==1){
				printf("\nTienda 1:\n--------------------------\n");
				imprimSecc(&arrTienda[0]);
			}
			for(i=0;i<t+count-1;i++){
				printf("\nTienda %d:\n--------------------------\n", i+1);
				imprimSecc(&arrTienda[i]);
			}
			break;
		case 4:
			if(count==1){
				printf("\nTienda 1:\n--------------------------\n");
				imprimProduc(&arrTienda[0]);
			}
			for(i=0;i<t+count-1;i++){
				printf("\nTienda %d:\n--------------------------\n", i+1);
				imprimProduc(&arrTienda[i]);
			}
			break;
		case 5:
			return 0;
		default:
			printf("Opci%cn no v%clida",162,160);
		}
	}

	return 0;
}

Seccion crearSeccion()
{
	Seccion sec;

	printf("Ingrese el c%cdigo de la secci%cn: ", 162,162);
	scanf("%d", &sec.codigoSec);
	printf("Ingrese la categoria de la secci%cn: ",162);
	scanf("%s", &sec.categoria);
	return sec;
}
Producto registrarProducto()
{
	Producto product1;
	printf("Ingrese la clave del producto: ");
	scanf("%d", &product1.clave);
	printf("Ingrese el nombre del producto: ");
	scanf("%s", &product1.nombreProducto);
	printf("Especifique la unidad en la que esta el producto (kilos, piezas, libras,etc.): ");
	scanf("%s", &product1.unidad);
	printf("Ingrese el precio del producto: ");
	scanf("%f", &product1.precio);
	return product1;
}

Producto agregarProducto(Tienda *t, int j)
{
	int opcion = 0;
	int index = 0, p=0, i=0;
	printf("%cCu%cntos productos quieres agregar a la secci%cn (1-10)?",168,160,162);
	scanf("%d", &p);	
	while (i<p)
	{		
		printf("Producto numero %d:\n",i+1);
		Producto nuevoProducto = registrarProducto();
		t->secciones[j].productos[index] = nuevoProducto;
		index++;		
		i++;
	}
	t->secciones[j].numP=p;
}

Empleado crearEmpleado()
{
	Empleado empleadoEjem;
	printf("Ingrese el nombre del empleado: ");
	scanf("%s", &empleadoEjem.nombreEmpleado);
	printf("Ingrese el apellido del empleado: ");
	scanf("%s", &empleadoEjem.apellidoEmpleado);
	printf("Ingrese el rango del empleado: ");
	scanf("%s", &empleadoEjem.rango);
	return empleadoEjem;
}

void agregarEmpleado(Tienda *t, int seccioni)
{
	int opcion = 0, n=0,i=0;
	int index = 0;
	printf("%cCu%cntos empleados quieres agregar a la secci%cn (1-10)?", 168,160,162);
	scanf("%d", &n);
	while (i<n)
	{
		printf("Empleado numero %d:\n",i+1);
		Empleado nuevoEmpleado = crearEmpleado();
		t->secciones[seccioni].encargadoSec[index] = nuevoEmpleado;
		index++;
		i++; 
	}
	t->secciones[seccioni].numE=n;
}


Gerente registrarGerente()
{
	Gerente geren1;
	printf("Ingrese el nombre del gerente: ");
	scanf("%s", geren1.nombreGerente);
	printf("Ingrese el apellido del gerente: ");
	scanf("%s", geren1.apellidoGerente);
	printf("Ingrese el salario del gerente: ");
	scanf("%f", &geren1.salario);

	return geren1;
}

Tienda crearTienda()
{
	Tienda tiendaEjem;
	printf("Ingrese el nombre de la tienda: ");
	scanf("%s", &tiendaEjem.nombreTie);
	printf("Ingrese el codigo de la tienda: ");
	scanf("%d", &tiendaEjem.codigoTie);
	return tiendaEjem;
}

void agregarGerente(Tienda *tienda)
{
	Gerente nuevoGerente = registrarGerente();
	tienda->encargadoTie = nuevoGerente;
}

Seccion agregarSeccion(Tienda *tienda)
{
	int opcion=0,s=0,j=0;

	int index = 0;
	printf("%cCu%cntas secciones quiere agregar (1-5)?: ",168,160);
	scanf("%d",&s);
	while (j<s)
	{
		Seccion nuevaSeccion = crearSeccion();
		tienda->secciones[index] = nuevaSeccion;
		agregarProducto(tienda, index);
		agregarEmpleado(tienda, index);
		index++;
		j++;
	}
	tienda->numS=s;
}

void imprimTienda(Tienda *tienda)
{
	int j, k, n;
	
	printf("El nombre de la tienda es: %s\n", &tienda->nombreTie);
	printf("El c%cdigo de la tienda es: %d\n",162, tienda->codigoTie);
	printf("El gerente encargado de la tienda es: %s %s\n", tienda->encargadoTie.nombreGerente, tienda->encargadoTie.apellidoGerente);
	printf("El salario del gerente de la tienda es: $%.3f\n----------------------------\n", tienda->encargadoTie.salario);
	for (j = 0; j < tienda->numS; j++)
	{
		printf("Seccion %d:\n------------------------------\n", j + 1);
		printf("El c%cdigo de la secci%cn es: %d\n", 162,162,tienda->secciones[j].codigoSec);
		printf("La categoria de la secci%cn es: %s\n---------------------------\n", 162,tienda->secciones[j].categoria);
		for (n = 0; n < tienda->secciones->numE; n++)
		{
			printf("Empleado %d:\n-----------------------------------\n", n + 1);
			printf("El nombre del empleado de la secci%cn es: %s %s\n", 162, tienda->secciones[j].encargadoSec[n].nombreEmpleado, tienda->secciones[j].encargadoSec[n].apellidoEmpleado);
			printf("El rango del empleado de la secci%cn es: %s\n-------------------------------\n", 162, tienda->secciones[j].encargadoSec[n].rango);
		}
		for (k = 0; k < tienda->secciones->numP; k++)
		{
			printf("Producto %d:\n--------------------------------\n", k + 1);
			printf("El nombre del producto es: %s\n", tienda->secciones[j].productos[k].nombreProducto);
			printf("La clave del producto es: %d\n", tienda->secciones[j].productos[k].clave);
			printf("La unidad del producto es: %s\n", tienda->secciones[j].productos[k].unidad);
			printf("El precio del producto es: $%.3f\n-------------------------------\n", tienda->secciones[j].productos[k].precio);
		}
	}
}

void imprimSecc(Tienda *tienda){
	int j,k,n;
	
	for (j = 0; j < tienda->numS; j++)
	{
		printf("Secci%cn %d:\n------------------------------\n", 162, j + 1);
		printf("El c%cdigo de la secci%cn es: %d\n", 162, 162, tienda->secciones[j].codigoSec);
		printf("La categoria de la secci%cn es: %s\n---------------------------\n", 162, tienda->secciones[j].categoria);
		for (n = 0; n < tienda->secciones->numE; n++)
		{
			printf("Empleado %d:\n-----------------------------------\n", n + 1);
			printf("El nombre del empleado de la secci%cn es: %s %s\n", 162, tienda->secciones[j].encargadoSec[n].nombreEmpleado, tienda->secciones[j].encargadoSec[n].apellidoEmpleado);
			printf("El rango del empleado de la secci%cn es: %s\n-------------------------------\n", 162, tienda->secciones[j].encargadoSec[n].rango);
		}
		for (k = 0; k < tienda->secciones->numP; k++)
		{
			printf("Producto %d:\n--------------------------------\n", k + 1);
			printf("El nombre del producto es: %s\n", tienda->secciones[j].productos[k].nombreProducto);
			printf("La clave del producto es: %d\n", tienda->secciones[j].productos[k].clave);
			printf("La unidad del producto es: %s\n", tienda->secciones[j].productos[k].unidad);
			printf("El precio del producto es: $%.3f\n-------------------------------\n", tienda->secciones[j].productos[k].precio);
		}
	}
}

void imprimProduc(Tienda *tienda){
	int j,k,n;
	
	for (j=0; j<tienda->numS; j++)
	{
		printf("Secci%cn %d:\n------------------------------\n", 162, j + 1);
		for (k = 0; k < tienda->secciones->numP; k++)
		{
			printf("Producto %d:\n--------------------------------\n", k + 1);
			printf("El nombre del producto es: %s\n", tienda->secciones[j].productos[k].nombreProducto);
			printf("La clave del producto es: %d\n", tienda->secciones[j].productos[k].clave);
			printf("La unidad del producto es: %s\n", tienda->secciones[j].productos[k].unidad);
			printf("El precio del producto es: $%.3f\n-------------------------------\n", tienda->secciones[j].productos[k].precio);
		}
	}
}