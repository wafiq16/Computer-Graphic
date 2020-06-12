
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "math.h"

using namespace glm;
using namespace std;

void Circlin(float radius, int a);
void create_red_vao(GLuint &vao);
void create_red_vao(GLuint &vao);

float i;

void setup_viewport(GLFWwindow *window) {
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0,0,width,height);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-22,22,-17,17,-1.0f,1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main() {
	if (!glfwInit()) {
		fprintf(stderr, "eror gan\n");
	}

	GLFWwindow *window = glfwCreateWindow(640, 480, "Circle", NULL, NULL);
	if (!window) {
		fprintf(stderr, "tidak bisa buka opengl\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte *renderer = glGetString(GL_VERSION);
	const GLubyte *version = glGetString(GL_VERSION);

	printf("renderer = %s\n", renderer);
	printf("opengl version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(window)) {
		setup_viewport(window);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3ub(255, 255, 0);
		Circlin(3, 360);
		glPushMatrix();

		glfwPollEvents();

		glfwSwapBuffers(window);
	}
}

void Circlin(float radius, int a) {
	glBegin(GL_POLYGON);
	int dots = 360;
	int x_mid = 0;
	int y_mid = 0;
	int angle, i;

	glVertex2f(x_mid, y_mid);
	for (i = 0; i <= a;i++ ) {
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x,y);
	}
	glVertex2f(x_mid, y_mid);
	glEnd();
}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "math.h"

using namespace glm;
using namespace std;

void create_redvao(GLint &vao);
void create_dots_vao(GLint &vao);
void Circlin(float radius, int a);
void counters();

float i = 0;
int counter = 0;

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
	GLFWwindow* window = glfwCreateWindow(640, 480, "Circle", NULL, NULL);
	if (!window) {
		fprintf(stderr, "tidak bisa membuka window\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("opengl version supported : %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(window)) {
		setup_viewport(window);
		counters();
		vec4 vec(11.0, 0.0, 0.0, 0.0);
		mat4 rot;
		rot = rotate(rot, i, vec3(0.0, 0.0, 1.0));
		vec = vec * rot;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3ub(255, 255, 0);
		Circlin(3, 360);
		glPushMatrix();
		glColor3ub(20, 0, 240);
		glTranslatef(vec.x, vec.y, vec.z);
		Circlin(1, 360);
		glPopMatrix();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	return 0;
}

void Circlin(float radius, int a) {
	glBegin(GL_POLYGON);
	int dots = 360;
	int x_mid = 0;
	int y_mid = 0;
	int angle, i;

	glVertex2f(x_mid, y_mid);

	for (i = 0; i <= a; i++) {
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x, y);
	}
	glVertex2f(x_mid, y_mid);
	glEnd();
}

void counters() {
	if (counter > 500) {
		if (i > 360.0f)
			i = 0.0f;
		else
			i = i + 1.0f;
		counter = 0;
	}
	counter++;
}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "math.h"

using namespace glm;
using namespace std;

void draw_sinus(int amp, int derajat);
void counters();

float i = 0;
int counter = 0;

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
	GLFWwindow* window = glfwCreateWindow(640, 480, "Sinusoidal", NULL, NULL);
	if (!window) {
		fprintf(stderr, "tidak bisa membuka window\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("opengl version supported : %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(window)) {
		setup_viewport(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3ub(255, 255, 0);
		draw_sinus(5, 360);
		glPushMatrix();
		//glColor3ub(20, 0, 240);
		//glTranslatef(vec.x, vec.y, vec.z);
		//Circlin(1, 360);
		glPopMatrix();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	return 0;
}

void draw_sinus(int amp, int derajat) {
	glBegin(GL_POINTS);
	//int dots = 360;
	int x_mid = 0;
	int y_mid = 0;
	int i, j = 0;
	int lasty = 0;

	for (i = 0; i <= derajat; i++) {
		float angle = (float)i;
		float x = angle / 18;
		float y = amp * sin(angle * 3.14 / 180);
		lasty = y;
		glVertex2f(x, y);
	}
	glEnd();
}