#ifndef ROBOT
#define ROBOT

#include <vector>
#include <string>
#include "tipos.h"
//#include "producto.h"

using namespace std;

class Robot {
private:
	numero_t numero_robot;
	vector<coor> posicion_robot;
	//Producto* contenido;
public:
	Robot(numero_t numero_robot, coor x, coor y); //Producto* contenido);
	void set_Posicion_X(coor x);
	void set_Posicion_Y(coor y);

	void depositar();
	//void cargar(Producto* producto);
	void esperar();
	//Producto* get_producto();
	numero_t get_numero_robot();
	vector<coor> get_posicion_robot();
};

#endif