// prueba.h: archivo de inclusión para archivos de inclusión estándar del sistema,
// o archivos de inclusión específicos de un proyecto.
#ifndef funciones
#define funciones

#pragma once

#include <iostream>
#include "Almacen.h"


void mostrarAlmacen(Almacen* alm) { //Imprime el almacen en consola

	bool crobot = false;
	bool cslot = false;
	int cr = 0;
	int cs = 0;

	for (auto r : alm->get_pCasillas()) {
		for (auto c : r) {
			for (auto bot : alm->get_robots()) {
				if (c->get_pos() == bot->get_posicion_robot()) {
					crobot = true;
					cr++;
				}
				//Revisa si en la casilla hay un robot
			}
			for (auto slt : alm->get_slots()) {
				if (c->get_pos() == slt->get_posicion_slot()) {
					cslot = true;
					cs++;
				}
				//Revisa si en la casilla hay un slot
			}

			if (crobot == true) {
				std::cout << "(" << cr << ")";
				crobot = false;
				//Si en la casilla hay un robot, lo dibuja
			}

			else if (cslot == true) {
				std::cout << "[" << cs << "]";
				cslot = false;
				//Si en la casilla hay un slot, lo dibuja
			}

			else {
				std::cout << "...";
				//Dibuja un pixel vacio
			}
		}
		std::cout << std::endl;
	}
}

void imprimirScore(Almacen* alm) { // Ayuda a visualizar el score (costo de movimiento) de cada casilla
	for (int i = 0; i < alm->get_pCasillas().size(); i++) {
		for (int j = 0; j < alm->get_pCasillas()[i].size(); j++) {
			std::cout << alm->get_pCasillas()[i][j]->get_gscore() << " ";
		}
		std::cout << std::endl;
	}
}

bool buscarMatrix(std::vector<vector<coor>> matrix, vector<coor> busqueda) { //Busca si una coordenada esta en la matriz
	for (int i = 0; i < matrix.size(); i++) {
		if (matrix[i] == busqueda) {
			return true;
		}
	}
	return false;
}

void setScore(Almacen* alm, Casilla* cas) { // Establece el score de todas las casillas
	coor xInicial = cas->get_pos()[0];
	coor yInicial = cas->get_pos()[1];
	int score = alm->get_pCasillas()[xInicial][yInicial]->get_gscore();

	std::vector<vector<coor>> obstaculos;
	obstaculos.resize(alm->get_slots().size());
	for (int i = 0; i < alm->get_slots().size(); i++) { //Se asigna un obstaculo en las casillas con slots que no seran usados por el robot
		obstaculos[i] = alm->get_slots()[i]->get_posicion_slot();
	}

	//Asigna el score en todas las casillas adyacentes
	if (xInicial + 1 < alm->get_rows() && 
		alm->get_pCasillas()[xInicial + 1][yInicial]->get_gscore() >= score && 
		!(buscarMatrix(obstaculos, alm->get_pCasillas()[xInicial + 1][yInicial]->get_pos()))) 
	{
		alm->get_pCasillas()[xInicial + 1][yInicial]->set_gscore(score + 1);
		setScore(alm, alm->get_pCasillas()[xInicial + 1][yInicial]);
	}

	if (xInicial - 1 >= 0 && 
		alm->get_pCasillas()[xInicial - 1][yInicial]->get_gscore() >= score 
		&& !(buscarMatrix(obstaculos, alm->get_pCasillas()[xInicial - 1][yInicial]->get_pos()))) 
	{
		alm->get_pCasillas()[xInicial - 1][yInicial]->set_gscore(score + 1);
		setScore(alm, alm->get_pCasillas()[xInicial - 1][yInicial]);
	}

	if (yInicial + 1 < alm->get_cols() && 
		alm->get_pCasillas()[xInicial][yInicial + 1]->get_gscore() >= score && 
		!(buscarMatrix(obstaculos, alm->get_pCasillas()[xInicial][yInicial + 1]->get_pos()))) 
	{
		alm->get_pCasillas()[xInicial][yInicial + 1]->set_gscore(score + 1);
		setScore(alm, alm->get_pCasillas()[xInicial][yInicial + 1]);
	}

	if (yInicial - 1 >= 0 &&
		alm->get_pCasillas()[xInicial][yInicial - 1]->get_gscore() >= score && 
		!(buscarMatrix(obstaculos, alm->get_pCasillas()[xInicial][yInicial - 1]->get_pos()))) {
		alm->get_pCasillas()[xInicial][yInicial - 1]->set_gscore(score + 1);
		setScore(alm, alm->get_pCasillas()[xInicial][yInicial - 1]);
	}
}

vector<vector<coor>> pathFinder(Robot* inicio, Slot* fin, Almacen* alm) { // Encuentra el camino mas corto y devuelve un vector con la sucesion de coordenadas
	coor xMeta = fin->get_posicion_slot()[0];							//para llegar al slot
	coor yMeta = fin->get_posicion_slot()[1];
	setScore(alm, alm->get_pCasillas()[xMeta][yMeta]);

	vector<vector<coor>> pasos;
	coor xRobot = inicio->get_posicion_robot()[0];
	coor yRobot = inicio->get_posicion_robot()[1];
	int minimo = 1000;

	while (minimo != 1) { // Se detiene cuando esta en una casilla adyacente al slot
		coor newXRobot = 0;
		coor newYRobot = 0;
		//Busca la casilla adyacente con menor score
		if (xRobot + 1 < alm->get_rows() && minimo > alm->get_pCasillas()[xRobot + 1][yRobot]->get_gscore()) {
			newXRobot = alm->get_pCasillas()[xRobot + 1][yRobot]->get_pos()[0];
			newYRobot = alm->get_pCasillas()[xRobot + 1][yRobot]->get_pos()[1];
			minimo = alm->get_pCasillas()[xRobot + 1][yRobot]->get_gscore();
		}
		if (xRobot - 1 >= 0 && minimo > alm->get_pCasillas()[xRobot - 1][yRobot]->get_gscore() ) {
			newXRobot = alm->get_pCasillas()[xRobot - 1][yRobot]->get_pos()[0];
			newYRobot = alm->get_pCasillas()[xRobot - 1][yRobot]->get_pos()[1];
			minimo = alm->get_pCasillas()[xRobot - 1][yRobot]->get_gscore();
		}
		if (yRobot - 1 < alm->get_cols() && minimo > alm->get_pCasillas()[xRobot][yRobot + 1]->get_gscore()) {
			newXRobot = alm->get_pCasillas()[xRobot][yRobot + 1]->get_pos()[0];
			newYRobot = alm->get_pCasillas()[xRobot][yRobot + 1]->get_pos()[1];
			minimo = alm->get_pCasillas()[xRobot][yRobot + 1]->get_gscore();
		}
		if (yRobot - 1 >= 0 && minimo > alm->get_pCasillas()[xRobot][yRobot - 1]->get_gscore()){
			newXRobot = alm->get_pCasillas()[xRobot][yRobot - 1]->get_pos()[0];
			newYRobot = alm->get_pCasillas()[xRobot][yRobot - 1]->get_pos()[1];
			minimo = alm->get_pCasillas()[xRobot][yRobot - 1]->get_gscore();
		}
		xRobot = newXRobot;
		yRobot = newYRobot;
		pasos.push_back({xRobot, yRobot});
	}
	return pasos;
}

void imprimirMatriz(std::vector<vector<coor>> matrix) { //Imprime el path
	std::cout << "Path: {";
	for (int i = 0; i < matrix.size(); i++) {
		std::cout << "(" << matrix[i][0] << ", " << matrix[i][1] << " ), ";
	}
	std::cout << "}" << std::endl;
}

void mostrarAlmacenPath(Almacen* alm, vector<vector<coor>> path) { //Imprime el almacen con el path


	bool crobot = false;
	bool cslot = false;
	bool cpath = false;
	int cr = 0;
	int cs = 0;

	for (auto r : alm->get_pCasillas()) {
		for (auto c : r) {
			for (auto bot : alm->get_robots()) {
				if (c->get_pos() == bot->get_posicion_robot()) {
					crobot = true;
					cr++;
				}
			}
			for (auto slt : alm->get_slots()) {
				if (c->get_pos() == slt->get_posicion_slot()) {
					cslot = true;
					cs++;
				}
			}

			for (auto pth : path) {
				if (c->get_pos() == pth) {
					cpath = true;
				}
			}

			if (crobot == true) {
				std::cout << "(" << cr << ")";
				crobot = false;
			}

			else if (cslot == true) {
				std::cout << "[" << cs << "]";
				cslot = false;
			}

			else if (cpath == true) {
				std::cout << "   ";
				cpath = false;
			}

			else {
				std::cout << "...";
			}
		}
		std::cout << std::endl;
	}
}

#endif