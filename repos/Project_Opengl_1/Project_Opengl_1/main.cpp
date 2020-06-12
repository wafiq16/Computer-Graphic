#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "math.h"
#include <stdlib.h>

using namespace glm;
using namespace std;

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void draw_sinus(int amp, int derajat);
void draw_circle(int radius, int derajat);
void draw_cliff(int panjang,int lebar);
void draw_sky(int panjang, int lebar);
void draw();
void counters();

float i = 0;
int button = 0;
int lastbutton = 0;
int flag = 0;
int counter = 0;
int my_count = 0;
int my_flag = 0;
int sudut_edar = 270;
int radius_orbit = 25;
float x_orbit = 0;
float y_orbit = 0;
void setup_viewport(GLFWwindow* window) {
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / float(height);
	glViewport(0, 0, width, height);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-22, 22, -17, 17, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main() {
	if (!glfwInit()) {
		fprintf(stderr, "eror gan\n");
		return 1;
	}
	GLFWwindow* window = glfwCreateWindow(640, 480, "Projek 1 2210181042 wafiq", NULL, NULL);
	if (!window) {
		fprintf(stderr, "tidak bisa membuka window\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keyCallback);
	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("opengl version supported : %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(window)) {
		//my_count++;
		setup_viewport(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		draw();
		glPopMatrix();
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	return 0;
}

void draw_sinus(int amp, int derajat) {
	glBegin(GL_POLYGON);
	int x_mid = 0;
	int y_mid = 0;
	int i, j = 0;

	for (i = 0; i <= derajat; i++) {
		float angle = (float)i;
		float x = angle / 18;
		float y = amp * sin(angle * 3.14 / 180);
		if (y < 0) {
			y = -100;
		}
		glVertex2f(x, y);
	}

	glEnd();
}

void counters() {
	if (sudut_edar >= 120)
		sudut_edar = 0;
	x_orbit = (float)radius_orbit * sin((float)sudut_edar /57.3);
	y_orbit = (float)radius_orbit * cos((float)sudut_edar /57.3);
	fprintf(stderr, "xb = %d yb = %d sudut = %d\n", x_orbit, y_orbit,sudut_edar);
	sudut_edar += 1;
}
void draw_circle(int radius,int derajat) {
	glBegin(GL_POLYGON);
	int dots = 360;
	int x_mid = 0;
	int y_mid = 0;
	int angle, i;

	glVertex2f(x_mid, y_mid);
	for (i = 0; i <= derajat; i++) {
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x, y);
	}
	glVertex2f(x_mid, y_mid);
	glEnd();
}

void draw_cliff(int panjang, int lebar) {
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(panjang, 0);
	glVertex2f(panjang, lebar);
	glVertex2f(0,lebar);
	glEnd();
}

void draw_sky(int panjang, int lebar) {
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(panjang, 0);
	glVertex2f(panjang, lebar);
	glVertex2f(0, lebar);
	glEnd();
}
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		//draw();
		//button = 1;
		flag = 1;
	}
	/*else {
		button = 0;
	}*/
	if (flag) {
		my_count++;
		counters();
	}
	
	fprintf(stderr, "b=%d lb=%d\n", button, lastbutton);
}
void draw() {
	vec4 vec_bola(5.0, 13.0, 0.0, 1.0);
	vec4 vec_ombak(5.0, 7.0, 0.0, 1.0);
	vec4 vec_karang(-22.0, -17.0, 0.0, 1.0);

	mat4 rot_bola;
	mat4 rot_ombak;
	mat4 trans_bola;
	mat4 trans_ombak;
	mat4 trans_karang;

	trans_bola = rotate(rot_bola, i, vec3(0, 0, 0.0));
	trans_ombak = translate(trans_ombak, vec3(-1, 0.0, 0.0));
	trans_karang = translate(trans_karang, vec3(1.0, 0.0, 0.0));

	vec_bola = vec_bola * rot_bola;
	vec_ombak = vec_ombak * trans_ombak;
	vec_karang = vec_karang * trans_karang;

	glTranslatef(vec_karang.x, vec_karang.y, vec_karang.z);
	glColor3ub(55, 0, 0);
	draw_cliff(10, 20);

	glTranslatef(-my_count / 1, vec_ombak.y, vec_ombak.z);
	glColor3ub(0, 0, 255);
	draw_sinus(7, 18000);

	glTranslatef((my_count / 1), vec_ombak.y, vec_ombak.z);
	if (sudut_edar <= 30 || sudut_edar >= 90) {
		glColor3ub(255, 100, 10);
		draw_sky(100,200);
		draw_sky(100,-200);
		//fprintf(stderr, "gambar langit bos");
	}
	glTranslatef(x_orbit+15, y_orbit, vec_bola.z);
	glColor3ub(255, 255, 0);
	draw_circle(2, 360);
}