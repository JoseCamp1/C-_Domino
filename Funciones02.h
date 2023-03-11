#include "Estructuras02.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <iostream>

using namespace std;

void pedirNombres(string& jugador1, string& jugador2, string& jugador3, string& jugador4)// esta funcion le piden los nombres a los jugadores
{
	cout << "\nDigite su nombre:\n";
	cin >> jugador1;
	cout << "\nDigite su nombre:\n";
	cin >> jugador2;
	cout << "\nDigite su nombre:\n";
	cin >> jugador3;
	cout << "\nDigite su nombre:\n";
	cin >> jugador4;
}

void creacionDomino(piesa& deDomino, vector<piesa>& domino)//esta funcion crea el domino
{
	cout << "\n*** EL DOMINO FUE CREADO ***\n";

	cout << "\n\n";
	for (int i = 0; i <= 6; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			deDomino.num1 = i;
			deDomino.num2 = j;
			domino.insert(domino.begin(), deDomino);
		}
	}
}

void mostrardomino(vector<piesa>& domino)//esta funcion imprime el domino y con esto me aseguro que todo este bien asignado
{
	for (int i = 0; i <= 27; i++)
	{
		if (i == 13)
		{
			cout << setw(4) << "[" << domino[i].num1 << "|" << domino[i].num2 << "]\n";
		}
		else
		{
			cout << setw(4) << "[" << domino[i].num1 << "|" << domino[i].num2 << "]";
		}

	}
	cout << "\n\n";
}



void revolverDomino(vector<piesa>& domino)//esta funcion revuelve el domnio de manera aleatoria siempre
{
	cout << "\n*** EL DOMINO FUE REVUELTO ***\n";
	cout << "\n\n";
	srand(time(NULL));
	random_shuffle(domino.begin(), domino.end());
}

void repartirDomino(vector<piesa>& domino, vector<piesa>& tablero, vector<piesa>& manoJugador1, vector<piesa>& manoJugador2, vector<piesa>& manoJugador3, vector<piesa>& manoJugador4)
{
	//esta funcion reparte 7 fichas a cada jugador
	cout << "size: " << domino.size();
	for (int i = 0; i <= 27; i++)
	{
		if (i<7)//cada 7 cambia de jugador
		{
			manoJugador1.push_back(domino[i]);			
		}
		else if (i>6 && i<14)
		{
			manoJugador2.push_back(domino[i]);
		}
		else if (i > 13 && i < 21)
		{
			manoJugador3.push_back(domino[i]);
		}
		else
		{
			manoJugador4.push_back(domino[i]);
		}

	}

}

void mostrarJuego(vector<piesa> tablero,vector<piesa> manoJugador1, vector<piesa> manoJugador2, vector<piesa> manoJugador3, vector<piesa> manoJugador4, string jugador1,string jugador2,string jugador3,string jugador4)
{
	//esta funcion muestra o imprime el tablero y las manos de los jugadores sirve para verificar y que se vea como se desarrolla el juego

	cout << "\n\t\t\t\t*** TABLERO ***\n"
		<<"\n";
	cout << "\t\t\t\tfichas totales:" << tablero.size() << "\n\t\t\t";
	for (int i = 0; i < tablero.size(); i++)
	{
		cout << setw(1) << "[" << tablero[i].num1 << "|" << tablero[i].num2 << "]";

	}
	cout<< "\n\n";
	cout << "\n*** TURNO 1 ***\n"
		<<"Nombre: " << jugador1 << "\n";
	cout << "fichas totales:" << manoJugador1.size() << endl;
	for (int i = 0; i < manoJugador1.size(); i++)
	{
		cout << setw(4) << "[" << manoJugador1[i].num1 << "|" << manoJugador1[i].num2 << "]";
	}
	cout << "\n\n";
	cout << "\n*** TURNO 2 ***\n"
		<< "Nombre: " << jugador2 << "\n";
	cout << "fichas totales:" << manoJugador2.size() << endl;
	for (int i = 0; i < manoJugador2.size(); i++)
	{
		cout << setw(4) << "[" << manoJugador2[i].num1 << "|" << manoJugador2[i].num2 << "]";
	}
	cout << "\n\n";
	cout << "\n*** TURNO 3 ***\n"
		<< "Nombre: " << jugador3 << "\n";
	cout << "fichas totales:" << manoJugador3.size() << endl;
	for (int i = 0; i < manoJugador3.size(); i++)
	{
		cout << setw(4) << "[" << manoJugador3[i].num1 << "|" << manoJugador3[i].num2 << "]";

	}
	cout << "\n\n";
	cout << "\n*** TURNO 4 ***\n"
		<< "Nombre: " << jugador4 << "\n";
	cout << "fichas totales:" << manoJugador4.size()<<endl;
	for (int i = 0; i < manoJugador4.size(); i++)
	{
		cout << setw(4) << "[" << manoJugador4[i].num1 << "|" << manoJugador4[i].num2 << "]";
	}
	cout << "\n\n";

}

void buscarelDobleSeis(vector<piesa>& tablero,vector<piesa>& manoJugador1, vector<piesa>& manoJugador2, vector<piesa>& manoJugador3, vector<piesa>& manoJugador4, string &jugador1, string &jugador2, string &jugador3, string &jugador4)
{
	//esta funcion sirva para buscar entre los jugadores quien tiene la ficha 6|6
	//cuando la encuentra cambiara de posicion con el jugador que esta en el primer puesto 
	//y reordena los jugadores por el orden en el que ingresaron sus nombres.
	string nombreaux="";//esta variable sirve para guardar el nombre de un jugador para despues almanenarla en otra e ir haciendo los cambios
	vector<piesa> manoaux(0);//aqui guardo la mano del jugador momentaneamente hasta porder pasar el valor a la variable correcta
	for (int i = 0; i < manoJugador1.size(); i++)
	{
		if (manoJugador1[i].num1 == 6 && manoJugador1[i].num2 == 6)//condicion para encontrar el 6|6
		{
			//manoJugador1[i].num1 = 7;//esto es para comprovar si la condicion de ganar por menos puntos funciona.
			//manoJugador1[i].num2 = 7;
			tablero.push_back(manoJugador1[i]);
			manoJugador1.erase(manoJugador1.begin() + i);
			cout << "El jugador: " << jugador1 << " tiene la ficha [6|6] y comenzara a jugar primero.";
			

		}
	}
	for (int i = 0; i < manoJugador2.size(); i++)
	{
		if (manoJugador2[i].num1 == 6 && manoJugador2[i].num2 == 6)
		{
			//manoJugador2[i].num1 = 7;
			//manoJugador2[i].num2 = 7;
			tablero.push_back(manoJugador2[i]);
			manoJugador2.erase(manoJugador2.begin() + i);
			cout << "El jugador: " << jugador2 << " tiene la ficha [6|6] y comenzara a jugar primero.";
			nombreaux = jugador1;
			manoaux = manoJugador1;
			jugador1 = jugador2;
			manoJugador1 = manoJugador2;
			jugador2 = nombreaux;
			manoJugador2 = manoaux;			
		}
	}
	for (int i = 0; i < manoJugador3.size(); i++)
	{
		if (manoJugador3[i].num1 == 6 && manoJugador3[i].num2 == 6)
		{
			//manoJugador3[i].num1 = 7;
			//manoJugador3[i].num2 = 7;
			tablero.push_back(manoJugador3[i]);
			manoJugador3.erase(manoJugador3.begin() + i);
			cout << "El jugador: " << jugador3 << " tiene la ficha [6|6] y comenzara a jugar primero.";
			nombreaux = jugador1;
			manoaux = manoJugador1;
			jugador1 = jugador2;
			manoJugador1 = manoJugador2;
			jugador2 = nombreaux;
			manoJugador2 = manoaux;
			nombreaux = jugador1;
			manoaux = manoJugador1;
			jugador1 = jugador3;
			manoJugador1 = manoJugador3;
			jugador3 = nombreaux;
			manoJugador3 = manoaux;
			
		}
	}
	for (int i = 0; i < manoJugador1.size(); i++)
	{
		if (manoJugador4[i].num1 == 6 && manoJugador4[i].num2 == 6)
		{
			//manoJugador4[i].num1 = 7;
			//manoJugador4[i].num2 = 7;
			tablero.push_back(manoJugador4[i]);
			manoJugador4.erase(manoJugador4.begin() + i);
			cout << "El jugador: " << jugador4 << " tiene la ficha [6|6] y comenzara a jugar primero.";
			nombreaux = jugador1;
			manoaux = manoJugador1;
			jugador1 = jugador2;
			manoJugador1 = manoJugador2;
			jugador2 = nombreaux;
			manoJugador2 = manoaux;
			nombreaux = jugador1;
			manoaux = manoJugador1;
			jugador1 = jugador3;
			manoJugador1 = manoJugador3;
			jugador3 = nombreaux;
			manoJugador3 = manoaux;
			nombreaux = jugador1;
			manoaux = manoJugador1;
			jugador1 = jugador4;
			manoJugador1 = manoJugador4;
			jugador4 = nombreaux;
			manoJugador4 = manoaux;
			
		}
	}
	system("pause");
	//Esto es para comprovar si la condicion de ganar por menos puntos funciona.
	//Y si detecta cuando alguien no tiene fichas usables	
	/*for (int i = 0; i < manoJugador1.size(); i++)
	{
		manoJugador1[i].num1 = 7;
		manoJugador1[i].num2 = 7;
	}
	for (int i = 0; i < manoJugador2.size(); i++)
	{
		manoJugador2[i].num1 = 7;
		manoJugador2[i].num2 = 7;
	}
	for (int i = 0; i < manoJugador3.size(); i++)
	{
		manoJugador3[i].num1 = 7;
		manoJugador3[i].num2 = 7;
	}
	for (int i = 0; i < manoJugador4.size(); i++)
	{
		manoJugador4[i].num1 = 7;
		manoJugador4[i].num2 = 7;
	}*/
}

void menuManoJugador(int &contturnosPasados,vector<piesa>& tablero, vector<piesa>& manoJugador1, string jugador1)// esta funcion llevara el menu y condiciones para escojer la ficha en la mano del jugador
{
	piesa numaux ;
	bool salir = false;
	int opcion = 0, inicioFinal = 0, girarSi = 0, tamanioTablero = 0, contmanosinfichasUsables = 0;
	tamanioTablero = tablero.size();
	tamanioTablero = tamanioTablero - 1;// se pone -1 para que concuerde con el indice al que queremos escojer  
	for (int i = 0; i < manoJugador1.size(); i++)
	{
		if (manoJugador1[i].num1==tablero[0].num1)
		{
			contmanosinfichasUsables++;
		}
		else if (manoJugador1[i].num1 == tablero[tamanioTablero].num2)
		{
			contmanosinfichasUsables++;
		}
		else if (manoJugador1[i].num2 == tablero[0].num1)
		{
			contmanosinfichasUsables++;
		}
		else if (manoJugador1[i].num2 == tablero[tamanioTablero].num2)			
		{
			contmanosinfichasUsables++;
		}

	}
	cout << "\nFichas usables: " << contmanosinfichasUsables << endl;
	if (contmanosinfichasUsables == 0)//si no hay fichas usablees el jugador pasa de turno automaticamente 
	{
		cout << "\nEl jugador: " << jugador1 << ", no tiene fichas usables, pasa turno.\n";
		system("pause");
		contturnosPasados++;//se agrega +1 al cont de turnos que se han pasado
		salir = true;
	}
	while (salir == false)//condicion
	{
		cout << "\nTurno actual: " << jugador1 << endl;
		cout << "\nDe " << manoJugador1.size() << " ficha(s) en la mano\n"
			<< "Cual desea escoger? Digite el numero de la ficha\n"
			<< "Ej: 1,2,3,4,5,6,7\n";
		cin >> opcion;
		if (cin.fail())
		{
			cout << "error";

		}
		if (opcion <= manoJugador1.size())
		{
			opcion = opcion - 1;//esto es porque el usuario digitara numeros entre el 1 a 7 ,ignorando la posicion 0
			cout << "\nLa ficha es:\n";
			cout << setw(4) << "[" << manoJugador1[opcion].num1 << "|" << manoJugador1[opcion].num2 << "]\n";
			cout << "\nDesea girar la ficha de domino?\n"
				<< "\n1.Si  2.No\n";
			cin >> girarSi;
			if (girarSi == 1) //si quiere girar la ficha
			{
				numaux.num1 = manoJugador1[opcion].num1; //guardo el valor1 en un auxiliar para despues agregarlo al valor2, habiendo pasado el valor 2 al 1 primero 
				manoJugador1[opcion].num1 = manoJugador1[opcion].num2;
				manoJugador1[opcion].num2 = numaux.num1;
				cout << "\nFicha girada:\n";
				cout << setw(4) << "[" << manoJugador1[opcion].num1 << "|" << manoJugador1[opcion].num2 << "]\n";

			}
			cout << "\nDe que lado del tablero quiere agregar la ficha de domino:\n"
				<< "\n1. Inicio. 2. Final.\n";
			cin >> inicioFinal;

			if (inicioFinal == 1) //al principio del tablero
			{
				if (tablero[0].num1 == manoJugador1[opcion].num2)//si se cumple que son iguales se puede colocar la ficha
				{
					tablero.insert(tablero.begin(), manoJugador1[opcion]);//la agrego
					manoJugador1.erase(manoJugador1.begin() + opcion);//borro la ficha dela mano del jugador
					salir = true;
				}
				else
				{
					cout << "\nNo es posible agregar la ficha en esa posicion.\n";//sino es posible
				}
			}
			if (inicioFinal == 2)
			{
				if (tablero[tamanioTablero].num2 == manoJugador1[opcion].num1)//si se cumple que son iguales se puede colocar la ficha
				{

					tablero.push_back(manoJugador1[opcion]);//la agrego
					manoJugador1.erase(manoJugador1.begin() + opcion);//borro la ficha dela mano del jugador

					salir = true;
				}
				else
				{
					cout << "\nNo es posible agregar la ficha en esa posicion.\n";//sino es posible
				}
			}
			else
			{
				cout << "\nOpcion incorrrecta\n";
			}
		}
		else
		{
			cout << "\nOpcion incorrrecta\n";
		}
	}
}

void sinPiesas(string& ganador, vector<piesa> manoJugador1, string jugador1)//esta funcion verifica si el jugador ya no tiene fichas en la mano y si es asi ese jugador gano
{
	int piesas = 0;
	piesas = manoJugador1.size();
	if (piesas == 0)
	{
		ganador = jugador1;
		cout << "\nEl jugador: " << jugador1 << " Gano la partida!!!!\n";
		system("pause");
	}
}
void nopuedenponerPiesa(int &contturnosPasados,string& ganador, vector<piesa> tablero, vector<piesa> manoJugador1, vector<piesa> manoJugador2, vector<piesa> manoJugador3, vector<piesa> manoJugador4, string jugador1, string jugador2, string jugador3, string jugador4)
{
	//esta funcion se activara depues que el contador de turnos pasados llegue a 4,esto significa que ningun jugador tiene  fichas para colocar
	//el juego no puede continuar ,entonces realiza una suma de los puntos en cada mano de cada jugador e evaula quien tiene menos puntos y lo declara 
	//ganador del juego
		int puntosjugador1 = 0, puntosjugador2 = 0, puntosjugador3 = 0, puntosjugador4 = 0;
	
	if (contturnosPasados == 4)
	{
		cout << "\nNingun jugador tiene fichas usables.\n" 
			<<"\nEl ganador se determinara por quien tiene menos puntos.\n";
		for (int i = 0; i < manoJugador1.size(); i++)
		{
			puntosjugador1 = puntosjugador1 + manoJugador1[i].num1;//sumo los puntos y los almaceno en variables
			puntosjugador1 = puntosjugador1 + manoJugador1[i].num2;
		}
		for (int i = 0; i < manoJugador2.size(); i++)
		{
			puntosjugador2 = puntosjugador2 + manoJugador2[i].num1;
			puntosjugador2 = puntosjugador2 + manoJugador2[i].num2;
		}
		for (int i = 0; i < manoJugador3.size(); i++)
		{
			puntosjugador3 = puntosjugador3 + manoJugador3[i].num1;
			puntosjugador3 = puntosjugador3 + manoJugador3[i].num2;
		}
		for (int i = 0; i < manoJugador4.size(); i++)
		{
			puntosjugador4 = puntosjugador4 + manoJugador4[i].num1;
			puntosjugador4 = puntosjugador4 + manoJugador4[i].num2;
		}
		if (puntosjugador1 < puntosjugador2 && puntosjugador1 < puntosjugador3 && puntosjugador1 < puntosjugador4)//hago la comparacion para sacar al ganador
		{
			cout << "\nEl ganador de la partida es: " << jugador1 << endl;
			ganador = jugador1;
			system("pause");
		}
		else if (puntosjugador2 < puntosjugador1 && puntosjugador2 < puntosjugador3 && puntosjugador2 < puntosjugador4)
		{
			cout << "\nEl ganador de la partida es: " << jugador2 << endl;
			ganador = jugador2;
			system("pause");
		}
		else if (puntosjugador3 < puntosjugador1 && puntosjugador3 < puntosjugador2 && puntosjugador3 < puntosjugador4)
		{
			cout << "\nEl ganador de la partida es: " << jugador3 << endl;
			ganador = jugador3;
			system("pause");
		}
		else if (puntosjugador4 < puntosjugador1 && puntosjugador4 < puntosjugador2 && puntosjugador4 < puntosjugador3)
		{
			cout << "\nEl ganador de la partida es: " << jugador4 << endl;
			ganador = jugador4;
			system("pause");
		}
	}
}




void menuTurnos(int &contturnosPasados,string &ganador,int &turnos,vector<piesa> &tablero, vector<piesa> &manoJugador1, vector<piesa> &manoJugador2, vector<piesa> &manoJugador3, vector<piesa> &manoJugador4, string &jugador1, string &jugador2, string &jugador3, string &jugador4)
{
	// esta funcion es un menu para los turnos de los jugadores los turnos pasan de manera automatica


	while (ganador == "")
	{
		cout << "\nFase de Turnos.\n"
			<< "\nTurno 1: " << jugador1 << endl
		<< "\nTurno 2: " << jugador2 << endl
		<< "\nTurno 3: " << jugador3 << endl
		<< "\nTurno 4: " << jugador4 << endl;
		switch (turnos)
		{
		case 0:
			system("cls");//se llaman a las funciones en cada turno
			turnos++;
			mostrarJuego(tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4, jugador1, jugador2, jugador3, jugador4);
			menuManoJugador(contturnosPasados,tablero, manoJugador1, jugador1);
			sinPiesas(ganador, manoJugador1, jugador1);
			break;
		case 1:
			system("cls");
			turnos++;
			mostrarJuego(tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4, jugador1, jugador2, jugador3, jugador4);
			menuManoJugador(contturnosPasados,tablero, manoJugador2, jugador2);
			sinPiesas(ganador, manoJugador2, jugador2);
			break;
		case 2:
			system("cls");
			turnos++;
			mostrarJuego(tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4, jugador1, jugador2, jugador3, jugador4);
			menuManoJugador(contturnosPasados,tablero, manoJugador3, jugador3);
			sinPiesas(ganador, manoJugador3, jugador3);
			break;
		case 3:
			system("cls");
			turnos=0;
			mostrarJuego(tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4, jugador1, jugador2, jugador3, jugador4);
			menuManoJugador(contturnosPasados,tablero, manoJugador4, jugador4);
			sinPiesas(ganador, manoJugador4, jugador4);
			if (contturnosPasados == 4)//se evalua si los 4 pasaron en los ultimos 4 turnos seguidos 
			{
				ganador = "Ninguno";//si es asi se le da valor a ganador para que se salga del ciclo
			}
			else
			{
				contturnosPasados = 0;//sino se pone el cont en 0 para seguir evaluando
			}			
			break;

		default:
			system("cls");
			cout << "\nerror\n";
			break;	


			
		}
	} 
}

