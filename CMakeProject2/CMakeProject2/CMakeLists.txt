# CMakeList.txt: proyecto de CMake para CMakeProject2, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

# Agregue un origen al ejecutable de este proyecto.
add_executable (CMakeProject2 "CMakeProject2.cpp" "CMakeProject2.h" "casilla.cpp" "Almacen.cpp" "tipos.h" "Robot.cpp" "Slot.cpp")

# TODO: Agregue pruebas y destinos de instalación si es necesario.
