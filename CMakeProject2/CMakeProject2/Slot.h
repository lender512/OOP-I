#ifndef SLOT
#define SLOT


#include <vector>
#include <string>
#include "tipos.h"


using namespace std;

class Slot {
private:
	numero_t numero_slot;
	vector<coor> posicion_slot;
public:
	Slot(numero_t numero_slot, coor x, coor y);
	//vector<Producto*> get_producto();
	cantidad get_capacidad();
	numero_t get_numero_slot();
	vector<coor> get_posicion_slot();
};

#endif