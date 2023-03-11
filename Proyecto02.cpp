// Fecha de Creacion:2/12/22
// Nombre: Jose Campos Chaves
// Fecha de ultima modificacion:9/12/22
// Descripcion:
// Ejercicio 2: 
// Crear una aplicación para el juego del dominó.El objetivo de un jugador es ganar
// la partida conforme criterios básicos de juego.
// 
// Implementación:
//
// Realice una aplicación de consola utilizando el lenguaje de programación C++, 
// que permita a 4 personas jugar una partida de dominó, no se utilizarán las reglas 
// oficiales.Se propone una versión simplificada del juego.Se realizará una partida 
// sencilla en donde las reglas básicas que regulan el juego del dominó se describen a continuación :
// El juego se desarrolla con cuatro jugadores, a los cuales hay que solicitarles el nombre.
// Las 28 fichas de dominó serán repartidas al azar(7 fichas a cada jugador).
// El jugador / a que inicia la partida será quien tenga la ficha 6 / 6 (doble seis),
// continuando el turno por el siguiente jugador según el orden de ingreso.En su turno,
// cada jugador colocará una de sus piezas con la restricción de que dos piezas solo 
// pueden colocarse juntas cuando los cuadrados adyacentes son del mismo valor.
// Si un jugador no puede colocar ninguna ficha en su turno, tendrá que pasar el turno al siguiente jugador.
// El final de la partida puede venir determinado por dos situaciones : (1) un jugador colocó
// la última de sus fichas y, por tanto, ganó la partida; o(2) todos los jugadores tienen aún fichas,
// pero ninguno puede colocar ninguna de ellas.En este último caso, ganará la partida el jugador cuyas
// fichas sumen menos puntos.
//



#include"Funciones02.h"
#include <vector>




using namespace std;

int main()
{
	string ganador = "";//esta es la condicion para que los menu se detengan cuando se encuentre un ganador
	int turnos = 1, contturnosPasados = 0;//turnos sirve para llevar los turnos de cada jugador y contturnos pasados por los jugadores .
	//
	piesa deDomino;
	vector<piesa> domino(0);//aqui creo el domino y lo guardo
	vector<piesa> tablero(0);//aqui sera dnd se desarrolle el juego
	vector<piesa> manoJugador1(0);//mano de cada jugador *
	vector<piesa> manoJugador2(0);
	vector<piesa> manoJugador3(0);
	vector<piesa> manoJugador4(0);
	string jugador1 = "", jugador2 = "", jugador3 = "", jugador4 = "";//nombres de los jugadores




	int opcion = 0;
	do
	{
		cout << "\n\t\t\t===================================================\n";
		cout << "\t\t\t= Desea iniciar el programa (1)Iniciar , (2)Salir =";
		cout << "\n\t\t\t===================================================\n";
		cin >> opcion;
		system("pause");
		system("cls");
		if (opcion == 1)
		{
			cout << "\n\t\t\t\t\t\t\t=======================\n";
			cout << "\t\t\t\t\t\t\t= Bienvenido al juego =";
			cout << "\n\t\t\t\t\t\t\t=======================\n";
			system("pause");
			system("cls");


			cout << "\n\t\t\t\t\t\t\t\t\t ==========\n";
			cout << "\t\t\t\t\t\t\t\t\t = Domino =";
			cout << "\n\t\t\t\t\t\t\t\t\t ==========\n";
			system("pause");
			cout << "\n\t\t\t==============================================================================================================\n";
			cout << "\n\t\t\t= El juego se desarrolla con cuatro jugadores.                                                              =\n";
			cout << "\n\t\t\t= Las 28 fichas de domino seran repartidas al azar(7 fichas a cada jugador).                                =\n";
			cout << "\n\t\t\t= El jugador / a que inicia la partida sera quien tenga la ficha 6 / 6 (doble seis),                        =\n";
			cout << "\n\t\t\t= continuando el turno por el siguiente jugador segun el orden de ingreso.En su turno,                      =\n";
			cout << "\n\t\t\t= cada jugador colocara una de sus piezas con la restriccion de que dos piezas solo                         =\n";
			cout << "\n\t\t\t= pueden colocarse juntas cuando los cuadrados adyacentes son del mismo valor.                              =\n";
			cout << "\n\t\t\t= Si un jugador no puede colocar ninguna ficha en su turno, tendra que pasar el turno al siguiente jugador. =\n";
			cout << "\n\t\t\t= El final de la partida puede venir determinado por dos situaciones : (1) un jugador coloco                =\n";
			cout << "\n\t\t\t= la ultima de sus fichas y, por tanto, gano la partida; o(2) todos los jugadores tienen aun fichas,        =\n";
			cout << "\n\t\t\t= pero ninguno puede colocar ninguna de ellas.En este ultimo caso, ganara la partida el jugador cuyas       =\n";
			cout << "\n\t\t\t= fichas sumen menos puntos.                                                                                =\n";
			cout << "\n\t\t\t==============================================================================================================\n";
			cout << "\n\t\t\t \n";
			cout << "\n\t\t\t \n";
			system("pause");
			system("cls");
			pedirNombres(jugador1, jugador2, jugador3, jugador4);
			creacionDomino(deDomino, domino);
			mostrardomino(domino);
			revolverDomino(domino);
			//mostrardomino(domino);	
			repartirDomino(domino, tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4);
			mostrarJuego(tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4, jugador1, jugador2, jugador3, jugador4);
			buscarelDobleSeis(tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4, jugador1, jugador2, jugador3, jugador4);
			mostrarJuego(tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4, jugador1, jugador2, jugador3, jugador4);
			menuTurnos(contturnosPasados, ganador, turnos, tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4, jugador1, jugador2, jugador3, jugador4);
			nopuedenponerPiesa(contturnosPasados, ganador, tablero, manoJugador1, manoJugador2, manoJugador3, manoJugador4, jugador1, jugador2, jugador3, jugador4);

			cout << "=================================================\n";
			cout << "= A continuacion se le dirigira al menu inicial =\n"
				<< "= y podra volver a jugar o salir del juego.     =\n";
			cout << "=================================================\n";
			system("pause");//para reiniciar todo
			domino.clear();
			tablero.clear();
			manoJugador1.clear();
			manoJugador2.clear();
			manoJugador3.clear();
			manoJugador4.clear();
			jugador1 = "";
			jugador2 = "";
			jugador3 = "";
			jugador4 = "";
			turnos = 1;
			contturnosPasados = 0;
			string ganador = "";			

		}
		else if (opcion == 2)
		{
			cout << "\n\t\t\t==========================================\n";
			cout << "\t\t\t= Gracias por su tiempo, tenga buen dia. =";
			cout << "\n\t\t\t==========================================\n";
			cout << "\n\t\t\t=================================================================\n";
			cout << "\t\t\t= Hecho por Jose Campos Chaves para Curso Programacion INA 2022 =";
			cout << "\n\t\t\t=================================================================\n";
		}
		else
		{
			cout << "\n\t\t\t========================================\n";
			cout << "\t\t\t= Opcion incorrecta intentelo de nuevo =";
			cout << "\n\t\t\t========================================\n";
		}

	} while (opcion != 2);
	
	return 0;
}


