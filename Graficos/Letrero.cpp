#include "stdafx.h"
#include "Letrero.h"

Letrero::Letrero() {
	//Inicializar transformaciones
	angulo = 0.0f;
	coordenadas = vec3(-6.0f, 7.5f, -15.0f);
	direccion = 1;

	vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//
	vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.5f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(15.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.5f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(15.5f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(15.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(16.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(15.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(15.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(15.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.5f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(6.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.5f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(6.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(16.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(16.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(16.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(15.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(15.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(15.5f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(15.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(15.5f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(15.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	
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

	modelo = mat4(1.0f); //Matriz identidad
	modelo = translate(modelo, coordenadas);

}

void Letrero::mover(double tiempoDelta) {
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