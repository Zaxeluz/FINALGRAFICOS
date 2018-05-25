// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"


#include <iostream>
#include <time.h>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "Nave.h"
#include "Tacoma.h"
#include "Basura.h"
#include "Cono.h"
#include "Letrero.h"
#include "Personaje.h"
#include "Bagon.h"
#include "Base.h"


using namespace std;

GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint modeloID;
GLuint vistaID;
GLuint proyeccionID;

GLuint coordenadaUVID;
GLuint samplerImagenID;
GLuint texturaUnoID;
GLuint texturaTacomaID;
GLuint texturaBagonID;
GLuint texturaBasuraID;
GLuint texturaConoID;
GLuint texturaLetreroID;
GLuint texturaPersonajeID;
GLuint texturaDiamanteID;

mat4 vista;
mat4 proyeccion;

Modelo *cuadrado;
Tacoma *tacoma;
Basura *basura;
Cono *cono;
Letrero *letrero;
Personaje *personaje;
Bagon *bagon;
Base *base;

Shader *shader;
//Declaración de ventana
GLFWwindow *window;

//Propiedades de la ventana
GLfloat ancho = 1024;
GLfloat alto = 768;

vec3 posicionCamara;

double tiempoAnterior;

void actualizarVista() {
	vista = lookAt(posicionCamara, //Posicion de la cámara
		vec3(0.0f, 0.0f, 0.0f),				//Posición del objetivo
		vec3(0.0f, 1.0f, 0.0f));			//Vector hacia arriba (rotación cámara)
}

void inicializarProyeccion() {
	proyeccion =
		perspective(45.0f, //Campo de visión (FoV)
			ancho / alto, //Relación de aspecto (Aspect ratio)
			0.1f, //Near clipping (Desde donde renderea)
			150.0f); //Far clipping (Hasta donde renderea)
}

float cuboX = 0.0f;
float cuboZ = 0.0f;

bool checarColisiones() {
	if (personaje->direccion == 0 || personaje->direccion == 1) {
		if (personaje->coordenadas.x + 1.9f >= cuboX - 1.0f &&
			personaje->coordenadas.x - 1.9f <= cuboX + 1.0f &&
			personaje->coordenadas.z + 0.7f >= cuboZ - 1.0f &&
			personaje->coordenadas.z - 0.7f <= cuboZ + 1.0f) {
			return true;
		}
	}
	
	if (personaje->direccion == 2 || personaje->direccion == 3) {
		if (personaje->coordenadas.x + 0.7f >= cuboX - 1.0f &&
			personaje->coordenadas.x - 0.7f <= cuboX + 1.0f &&
			personaje->coordenadas.z + 1.9f >= cuboZ - 1.0f &&
			personaje->coordenadas.z - 1.9f <= cuboZ + 1.0f) {
			return true;
		}
	}

	return false;
	
}

void actualizar() { 
	double tiempoActual = glfwGetTime();
	double tiempoDelta = tiempoActual - tiempoAnterior;

	

	/*int estadoDerecha = glfwGetKey(window,GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		posicionCamara.x += 0.01;
	}

	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		posicionCamara.x -= 0.01;
	}*/
	
	//Movimiento tacoma
	int estadoD = glfwGetKey(window, GLFW_KEY_D);
	if (estadoD == GLFW_PRESS) {
		personaje->direccion = 0;
	}
	
	int estadoA = glfwGetKey(window, GLFW_KEY_A);
	if (estadoA == GLFW_PRESS) {
		personaje->direccion = 1;
	}

	int estadoW = glfwGetKey(window, GLFW_KEY_W);
	if (estadoW == GLFW_PRESS) {
		personaje->direccion = 2;
	}

	int estadoS = glfwGetKey(window, GLFW_KEY_S);
	if (estadoS == GLFW_PRESS) {
		personaje->direccion = 3;
	}

	if (!checarColisiones()) {
		personaje->mover(tiempoDelta);
	}

	actualizarVista();
	tacoma->vista = vista;
	basura->vista = vista;
	cono->vista = vista;
	letrero->vista = vista;
	personaje->vista = vista;
	bagon->vista = vista;
	base->vista = vista;

	tiempoAnterior = tiempoActual;
}

void dibujar() {
	
	tacoma->dibujar(GL_TRIANGLES);
	basura->dibujar(GL_QUADS);
	cono->dibujar(GL_TRIANGLES);
	letrero->dibujar(GL_TRIANGLES);
	personaje->dibujar(GL_TRIANGLES);
	bagon->dibujar(GL_TRIANGLES);
	base->dibujar(GL_QUADS);

}


int main()
{
	
	

	//Inicialización de GLFW
	if (!glfwInit()) {
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se creó bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}



	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;


	red = green = blue = 0.75f;

	posicionCamara = vec3(0.0f, 40.0f, 70.0f);

	actualizarVista();
	inicializarProyeccion();

	tacoma = new Tacoma();
	tacoma->vista = vista;
	tacoma->proyeccion = proyeccion;

	basura = new Basura();
	basura->vista = vista;
	basura->proyeccion = proyeccion;

	cono = new Cono();
	cono->vista = vista;
	cono->proyeccion = proyeccion;
	
	letrero = new Letrero();
	letrero->vista = vista;
	letrero->proyeccion = proyeccion;

	personaje = new Personaje();
	personaje->vista = vista;
	personaje->proyeccion = proyeccion;

	bagon = new Bagon();
	bagon->vista = vista;
	bagon->proyeccion = proyeccion;



	base = new Base();
	base->vista = vista;
	base->proyeccion = proyeccion;

	//Crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";
	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID =
		glGetAttribLocation(shader->getID(), "posicion");
	colorID =
		glGetAttribLocation(shader->getID(), "color");
	modeloID =
		glGetUniformLocation(shader->getID(), "modelo");
	vistaID =
		glGetUniformLocation(shader->getID(), "vista");
	proyeccionID =
		glGetUniformLocation(shader->getID(), "proyeccion");

	samplerImagenID =
		glGetUniformLocation(shader->getID(), "samplerImagen");
	coordenadaUVID =
		glGetAttribLocation(shader->getID(), "coordenadaUV");

	texturaUnoID =
		Shader::cargarBMP("texturas\\carita.bmp");

	texturaTacomaID =
		Shader::cargarBMP("texturas\\tacoma.bmp");

	texturaBagonID =
		Shader::cargarBMP("texturas\\bagon.bmp");

	texturaBasuraID =
		Shader::cargarBMP("texturas\\bote.bmp");

	texturaConoID =
		Shader::cargarBMP("texturas\\cono.bmp");

	texturaDiamanteID =
		Shader::cargarBMP("texturas\\diamante.bmp");

	texturaPersonajeID =
		Shader::cargarBMP("texturas\\piel monito.bmp");

	texturaLetreroID =
		Shader::cargarBMP("texturas\\letrero.bmp");

	

	//Desenlazar shader
	shader->desenlazarShader();

	
	tacoma->shader = shader;
	tacoma->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaDiamanteID);

	basura->shader = shader;
	basura->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaBasuraID);

	cono->shader = shader;
	cono->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaConoID);

	letrero->shader = shader;
	letrero->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaLetreroID);

	personaje->shader = shader;
	personaje->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaPersonajeID);
	
	bagon->shader = shader;
	bagon->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaBagonID);

	base->shader = shader;
	base->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaTacomaID);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	

	tiempoAnterior = glfwGetTime();

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

