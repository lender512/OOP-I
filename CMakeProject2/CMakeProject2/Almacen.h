#ifndef ALMACEN_H
#define ALMACEN_H

#include "tipos.h"
#include "casilla.h"
#include "robot.h"
#include "Slot.h"
#include <vector>


class Almacen {
private:
	cantidad rows;
	cantidad cols;
	vector<vector<Casilla>> casillas;
	vector<vector<Casilla*>> pCasillas;
	std::vector<Robot*> robots;
	std::vector<Slot*> slots;
public:
	Almacen(cantidad r, cantidad c);
	void add_robot(Robot* r);
	void add_slot(Slot* s);
	cantidad get_rows();
	std::vector<Robot*> get_robots();
	std::vector<Slot*> Almacen::get_slots();
	std::vector<vector<Casilla*>> get_pCasillas();
	cantidad get_cols();
};

#endif