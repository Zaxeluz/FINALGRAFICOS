#pragma once
#include "Modelo.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

class Bagon : public Modelo {
public:
	vec3 coordenadas;
	float angulo;
	int direccion = 0;
	float velocidad = 2.0f;
	Bagon();
	void mover(double tiempoDelta);
};