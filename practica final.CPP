#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <string>
////////////////////////////////// Variables globales
int *vector;
int n = -1;
char opM1[] = {'V','M','E','T'};
char opM2[] = {'C','M','I','E','B','G','L','V'};

////////////////////////////////// Metodos
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
	do{
		cout << "\n" << mensaje;
		cin >> Numero;
	}while (Numero<0);

	return (Numero);
}
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
							n = IngresarNumero("Ingrese el numero de datos del vector: ");
							vector = new int[n];
							LlenarVector(vector, n);
							break;
						case('M'):
							ImprimirVector(vector, n);
							getch();
							break;
						case('I'):
							d = IngresarNumero("Ingrese el dato que desea insertar: ");
							InsertarDatoVector(vector,d, n);
                    		 n++;
							break;
						case('E'):
							d = IngresarNumero("Ingrese el dato que desea eliminar: ");
							EliminarDatoVector(vector, d, n);
							break;
						case('B'):
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
							d = BuscarMayorVector(vector, n);
							cout << "\nEl dato mayor es: " << d <<".";
							break;
						case('L'):
							d = BuscarMenorVector(vector, n);
							cout << "\nEl dato menor es: " << d <<".";
							break;
					}
					
				}
				break;
			case('M'):
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

