#pragma once
#include "Modelo.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

class Letrero : public Modelo {
public:
	vec3 coordenadas;
	float angulo;
	int direccion = 0;
	float velocidad = 2.0f;
	Letrero();
	void mover(double tiempoDelta);
};