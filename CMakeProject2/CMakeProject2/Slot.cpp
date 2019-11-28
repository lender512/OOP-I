#include "slot.h"
#include <iostream>

Slot::Slot(numero_t _numero_slot, coor x, coor y) {
	numero_slot = _numero_slot;
	posicion_slot = { x, y };
}

numero_t Slot::get_numero_slot() {
	return numero_slot;
}

vector<coor> Slot::get_posicion_slot() {
	return posicion_slot;
}
