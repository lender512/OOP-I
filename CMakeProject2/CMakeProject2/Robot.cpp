#include "Robot.h"

Robot::Robot(numero_t _numero_robot, coor x, coor y) {// Producto* _contenido) {
	numero_robot = _numero_robot;
	posicion_robot = { x, y };
	//	contenido = _contenido;
}



//void Robot::depositar() {
//	estado_robot = false;
//	contenido = nullptr;
//}

//void Robot::cargar(Producto* producto) {
//	estado_robot = true;
//	contenido = producto;
//}

void Robot::set_Posicion_X(coor x) {
	posicion_robot[0] = x;
}

void Robot::set_Posicion_Y(coor y) {
	posicion_robot[1] = y;
}

void Robot::esperar() {
	posicion_robot[0] = posicion_robot[0];
	posicion_robot[1] = posicion_robot[1];
} // ya se que esto no hace nada pero como tengo imaginado la cosa se le otorga 1 movimiento a cada robot y luego se ejecutan todos y luego otro y asi, si la instruccion detecta una colision entonces le dice al robot que ejecute la funcion esperar. 

//Producto* Robot::get_producto() {
//	return contenido;
//}

numero_t Robot::get_numero_robot() {
	return numero_robot;
}

vector<coor> Robot::get_posicion_robot() {
	return posicion_robot;
}