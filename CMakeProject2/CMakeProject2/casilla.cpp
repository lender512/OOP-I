#include "Casilla.h"

Casilla::Casilla(numero_t n, coor x, coor y, score gs) {
	posicion = { x, y };
	numero = n;
	gscore = gs;
}

std::vector<coor> Casilla::get_pos() {
	return posicion;
}

void Casilla::set_gscore(cantidad n) {
	gscore = n;
}

cantidad Casilla::get_gscore() {
	return gscore;
}

bool Casilla::get_estado() {
	return estado;
}

int Casilla::get_numero() {
	return numero;
}