#include "Almacen.h"

Almacen::Almacen(cantidad r, cantidad c) {
	rows = r;
	cols = c;

	casillas.resize(rows);

	for (coor i = 0; i < rows; i++) {
		for (coor j = 0; j < cols; j++) {
			casillas[i].emplace_back(Casilla((i * rows) + j, i, j, 100));
		}
	}

	pCasillas.resize(rows);

	for (coor i = 0; i < pCasillas.size(); i++) {
		pCasillas[i].resize(cols);
		for (coor j = 0; j < pCasillas[i].size(); j++) {
			pCasillas[i][j] = &casillas[i][j];
		}
	}
}


void Almacen::add_robot(Robot* r) {
	robots.push_back(r);
}

void Almacen::add_slot(Slot* s) {
	slots.push_back(s);
}

int Almacen::get_cols() {
	return cols;
}

int Almacen::get_rows() {
	return rows;
}

std::vector<Robot*> Almacen::get_robots() {
	return robots;
}

std::vector<Slot*> Almacen::get_slots() {
	return slots;
}

std::vector<vector<Casilla*>> Almacen::get_pCasillas() {
	return pCasillas;
}