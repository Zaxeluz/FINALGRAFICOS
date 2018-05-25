#include "stdafx.h"
#include "Base.h"

Base::Base() {
	//Inicializar transformaciones
	angulo = 0.0f;
	coordenadas = vec3(12.0f, 0.0f, 0.0f);
	direccion = 1;

	// TRAPECIO-1
	vertices.push_back({ vec4(-20.0f, 0.0f, -300.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-20.0f, 0.0f, 40.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(20.0f, 0.0f, 40.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(20.0f, 0.0f, -300.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	

	//Aqui sigue el mapa UV

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 0.0f));
	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(0.0f, 1.0f));

}

void Base::mover(double tiempoDelta) {
	switch (direccion) {
	case 0: //derecha
		coordenadas.x += velocidad * tiempoDelta;
		angulo = 90.0f * 3.14159f / 180.0f;
		break;
	case 1: //izquierda
		coordenadas.x -= velocidad * tiempoDelta;
		angulo = 270.0f * 3.14159f / 180.0f;
		break;
	case 2: //arriba
		coordenadas.z -= velocidad * tiempoDelta;
		angulo = 180.0f * 3.14159f / 180.0f;
		break;
	case 3: //abajo
		coordenadas.z += velocidad * tiempoDelta;
		angulo = 0.0f;
		break;
	default:
		break;
	}


	modelo = mat4(1.0f); //Matriz identidad
	modelo = translate(modelo, coordenadas);
	modelo = rotate(modelo, angulo, vec3(0.0f, 1.0f, 0.0f));

}