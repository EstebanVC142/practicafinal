#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <string>
////////////////////////////////// Variables globales
int *vector; // Vector para el menu de vectores
int n = -1; // Cantidad de elementos del vector
char opM1[] = {'V','M','E','T'}; // Posibles entradas del menu principal o menu 1 
char opM2[] = {'C','M','I','E','B','G','L','V'}; // Posibles entradas del submenu vectores o matrices o menu 2
bool vc = false; // Bandera para comprobar paso por c del menu vector
bool mc = false; // Bandera para comprobar paso por c del menu matriz
int **matriz;
int m2 = -1; // 
int n2 = -1;

////////////////////////////////// Funciones 
char IngresarCaracterOpcionesMensaje(char letras[],int k)
{
	char c;
	while(true)
	{
		cout << "Ingrese la opcion deseada: ";
		cin >> c;
		c = toupper(c);
		for (int i = 0; i < k; i++)
		{
			if (c == letras[i])
			{
				return (c);
			}
		}
      cout << "\nOpcion invalida.\n";
	}
	return 0;
}

int IngresarNumero(char* mensaje)
{
	int Numero;
	
	cout << "\n" << mensaje;
	cin >> Numero;
	return (Numero);
}

int IngresarNumeroPositivo(char* mensaje)
{
	int Numero;
	do{
		cout << "\n" << mensaje;
		cin >> Numero;
	}while (Numero<0);

	return (Numero);
}

//-----------> Funciones del vector

void LlenarVector(int* &_vector,int _n)	
{

	for (int i = 0; i < _n; ++i)
	{
		cout << "\nIngrese el elemento de la posicion "<<i<< ": ";
		cin >> _vector[i];
	}
}

void ImprimirVector(int* &_vector,int _n)
{

	for (int i = 0; i < _n; ++i)
	{
		cout << "| "<<_vector[i]<< " |";
	}
}


int BuscarDatoVector(int* &_vector, int d, int _n)
{

	for (int i = 0; i < _n; ++i)
	{
		if (_vector[i] == d)
		{
			return (i);
		}
	}
	return (-1);
}

void InsertarDatoVector(int* &_vector,int d, int _n)
{
	int* __vector = new int[_n+1];

	for (int i = 0; i < _n; i++)
	{
		__vector[i] =_vector[i];
	}
	__vector[_n] = d;
	_vector = __vector;
}

int BuscarMayorVector(int* &_vector, int _n)
{
	int max = _vector[0];

	for (int i = 1; i < _n; i++)
	{
		if (_vector[i] > max)
		{
			max = _vector[i];
		}
	}
	return max;
}

int BuscarMenorVector(int* &_vector, int _n)
{
	int min = _vector[0];

	for (int i = 1; i < _n; i++)
	{
		if (_vector[i] < min)
		{
			min = _vector[i];
		}
	}
	return min;
}

void EliminarDatoVector(int* &_vector,int d, int &_n)
{
	int contar = 0;
	for (int i = 0; i < _n; i++)
	{
		if (_vector[i] == d)
		{
			contar++;
		}
	}
	int* __vector = new int[_n - contar];
	int k = 0;
	for (int i = 0; i < _n; i++)
	{
		if (_vector[i] != d)
		{
			__vector[k] = _vector[i];
			k++;
		}
	}
	_vector = __vector;
	_n -= contar;
}
//----------> Funciones para matriz
void LlenarMatriz(int* &_matriz,int _m2, _n2)	
{

	for (int i = 0; i < _m2; ++i)
	{
		for (int j = 0; j <  _n2; j++)
		{
			cout << "\nIngrese el elemento de la posicion ["<<i<< ", "<<j<<"]: ";
			cin >> _matriz[i][j];
		}	
	}
}

////////////////////////////////// Programa principal
void main ()
{
	char c = ' ';
	char c2 = ' ';
	while(c != 'T')
	{
   	clrscr();
		cout << "(V) Vectores.\n";
		cout << "(M) Matrices.\n";
		cout << "(E) Estudiantes.\n";
		cout << "(T) Terminar.\n";

		c = IngresarCaracterOpcionesMensaje(opM1,4);
		switch(c)
		{
			case('V'):
         		c2 = ' ';
				while(c2 != 'V')
				{
			   		clrscr();
					cout << "(C) llenar vector.\n";
					cout << "(M) Imprimir vector.\n";
					cout << "(I) Insertar dato en el vector.\n";
					cout << "(E) Eliminar en el vector.\n";
					cout << "(B) Buscar dato en el vector.\n";
					cout << "(G) Imprimir dato mayor del vector.\n";
					cout << "(L) Imprimir dato menor del vector.\n";
					cout << "(V) Volver al menu principal.\n";
					c2 = IngresarCaracterOpcionesMensaje(opM2,8);
					int d = 0;
					int b = 0;
					switch(c2)
					{
						case('C'):
							n = IngresarNumeroPositivo("Ingrese el numero de datos del vector: ");
							vector = new int[n];
							LlenarVector(vector, n);
							vc = true;
							break;
						case('M'):
							if (!vc)
							{
								cout << "Debe ingresar el vector antes de usar esta opcion.";
								getch();
								break;
							}
							if (n <= 0)
							{
								cout << "\nEl vector esta vacio.";
								getch();
								break;
							}
							ImprimirVector(vector, n);
							getch();
							break;
						case('I'):
							if(!vc)
							{
								cout << "Debe ingresar el vector antes de usar esta opcion.";
								getch();
								break;
							}
							d = IngresarNumero("Ingrese el dato que desea insertar: ");
							InsertarDatoVector(vector,d, n);
                    		 n++;
							break;
						case('E'):
							if(!vc)
							{
								cout << "Debe ingresar el vector antes de usar esta opcion.";
								getch();
								break;
							}
							if (n <= 0)
							{
								cout << "\nNo hay datos en el vector para realizar esta operacion.";
								getch();
								break;
							}
							d = IngresarNumero("Ingrese el dato que desea eliminar: ");
							EliminarDatoVector(vector, d, n);
							break;
						case('B'):
							if(!vc)
							{
								cout << "Debe ingresar el vector antes de usar esta opcion.";
								getch();
								break;
							}
							if (n <= 0)
							{
								cout << "\nNo hay datos en el vector para realizar esta operacion.";
								getch();
								break;
							}
							d = IngresarNumero("Ingrese el dato que desea buscar: ");
							b = BuscarDatoVector(vector, d, n);
							if (b == -1)	
							{
								cout<< "\nEl dato no se encontro.";
							}
							else
							{
								cout << "\nLa posicion del dato |"<< d <<"| es: "<< b << ".";
							}

							getch();
							break;
						case('G'):
							if (!vc)
							{
								cout << "Debe ingresar el vector antes de usar esta opcion.";
								getch();
								break;
							}
							if (n <= 0)
							{
								cout << "\nNo hay datos en el vector para realizar esta operacion.";
								getch();
								break;
							}
							d = BuscarMayorVector(vector, n);
							cout << "\nEl dato mayor es: " << d <<".";
							getch();
							break;
						case('L'):
							if(!vc)
							{
								cout << "Debe ingresar el vector antes de usar esta opcion.";
								getch();
								break;
							}
							if (n <= 0)
							{
								cout << "\nNo hay datos en el vector para realizar esta operacion.";
								getch();
								break;
							}
							d = BuscarMenorVector(vector, n);
							cout << "\nEl dato menor es: " << d <<".";
							getch();
							break;
					}
					
				}
				break;
			case('M'):
				c2 = ' ';
				while(c2 != 'V')
				{
			   		clrscr();
					cout << "(C) llenar matriz.\n";
					cout << "(M) Imprimir matriz.\n";
					cout << "(I) Matriz identidad.\n";
					cout << "(E) Matriz simetrica.\n";
					cout << "(B) Matriz transpuesta.\n";
					cout << "(G) Imprimir elementos de la diagonal principal.\n";
					cout << "(L) Imprimir elementos de la diagonal secundaria.\n";
					cout << "(V) Volver al menu principal.\n";
					c2 = IngresarCaracterOpcionesMensaje(opM2,8);
					int d = 0;
					int b = 0;
					switch(c2)
					{
						case('C'):
							m2 = IngresarNumeroPositivo("Ingrese el numero de datos de filas de la matriz: ");
							n2 = IngresarNumeroPositivo("Ingrese el numero de datos de columnas de la matriz: ");
							matriz = new int[m2][n2];
							LlenarMatriz(matriz, m2, n2);
							mc = true;
							break;
					}
				}	
				break;
			case('E'):
				break;
			case('T'):
				break;
			default:
				break;
		}
	}
}

