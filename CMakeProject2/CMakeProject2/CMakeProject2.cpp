#include <iostream>
#include "Almacen.h"
#include "Casilla.h"
#include "CMakeProject2.h"


//Almacen alm = Almacen(10, 11);
//Almacen* pAlm = &alm;
/*
int main() {

	Robot robot1 = Robot(1, 6, 2);
	Robot* Probot1 = &robot1;

	Slot slot1 = Slot(1, 2, 2);
	Slot* Pslot1 = &slot1;

	Slot slot2 = Slot(2, 2, 3);
	Slot* Pslot2 = &slot2;
	Slot slot3 = Slot(3, 5, 2);
	Slot* Pslot3 = &slot3;
	Slot slot4 = Slot(1, 6, 3);
	Slot* Pslot4 = &slot4;
	Slot slot5 = Slot(1, 7, 3);
	Slot* Pslot5 = &slot5;
	Slot slot6 = Slot(1, 7, 1);
	Slot* Pslot6 = &slot6;
	Slot slot7 = Slot(1, 6, 1);
	Slot* Pslot7 = &slot7;
	Slot slot8 = Slot(1, 8, 1);
	Slot* Pslot8 = &slot8;
	Slot slot9 = Slot(1, 8, 3);
	Slot* Pslot9 = &slot9;

	alm.add_robot(Probot1);
	coor posxi = robot1.get_posicion_robot()[0];
	coor posxj = robot1.get_posicion_robot()[1];

	alm.add_slot(Pslot1);
	alm.add_slot(Pslot2);
	alm.add_slot(Pslot3);
	alm.add_slot(Pslot4);
	alm.add_slot(Pslot5);
	alm.add_slot(Pslot6);
	alm.add_slot(Pslot7);
	alm.add_slot(Pslot8);
	alm.add_slot(Pslot9);

	pAlm->get_pCasillas()[Pslot1->get_posicion_slot()[0]][Pslot1->get_posicion_slot()[1]]->set_gscore(0);
	setScore(pAlm, pAlm->get_pCasillas()[Pslot1->get_posicion_slot()[0]][Pslot1->get_posicion_slot()[1]]);

	mostrarAlmacen(pAlm);
	//imprimirScore(pAlm);
	imprimirMatriz(pathFinder(Probot1, Pslot1, pAlm));
	mostrarAlmacenPath(pAlm, pathFinder(Probot1, Pslot1, pAlm));

}*/
int main() {

	//creacion del objeto -- en progreso
	   //combalidaciones
	int numero_robots, filas, columnas, numero_slots;
	int x, y;
	//bienvenida al programa
	cout << "Bienvenido!" << endl;
	cout << "------------------------" << endl;
	cout << "Ingrese el numero de filas :";
	cin >> filas;
	cout << "Ingrese el numero de columnas: ";
	//-->creacion de la casilla
	cin >> columnas;
	Almacen alm = Almacen(filas, columnas);
	Almacen* pAlm = &alm;
	//numero de robots
	cout << "Ingrese el numero de robots: ";
	cin >> numero_robots;
	pAlm->get_robots().resize(numero_robots);
	//estableciendo la posicion de de cada uno de los robots

	vector<Robot> robots;
	//robots.resize(numero_robots);
	for (int i = 0; i < numero_robots; i++)
	{
		cout << "Ingrese el posicion x del robot: ";
		cin >> x;
		cout << "Ingrese la posicion y del robot: ";
		cin >> y;
		robots.push_back(Robot(i, x, y));
		pAlm->get_robots()[i] = &robots[i];
	}
	//numero de slots
	cout << "Ingrese el numero de slots: ";
	cin >> numero_slots;
	pAlm->get_slots().resize(numero_slots);
	//estableciendo la posicion de de cada uno de los robots

	vector<Slot> slots;
	//slots.resize(numero_slots);
	for (int i = 0; i < numero_slots; i++)
	{
		cout << "Ingrese el posicion x del slot: ";
		cin >> x;
		cout << "Ingrese la posicion y del slot: ";
		cin >> y;
		slots.push_back(Slot(i, x, y));
		pAlm->get_slots()[i] = &slots[i];
	}
	//Accion a realizar
	mostrarAlmacen(pAlm);
	//mostrarAlmacenPath(pAlm, pathFinder(pAlm->get_robots()[0], pAlm->get_slots()[0], pAlm));
}
