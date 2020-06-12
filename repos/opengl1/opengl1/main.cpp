#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{

	if (!glfwInit()) {
		fprintf(stderr, "tidak berjalan");
		return 1;
	}
	GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is triangle", NULL, NULL);
	//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
	if (!myWindow) {
		fprintf(stderr, "tidak bisa launch window");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(myWindow);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *version = glGetString(GL_VERSION);

	printf("renderer = %s\n", renderer);
	printf("opengl version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float titik[] = {
		0.0f , 0.5f , 0.0f,
		0.5f , -0.5f , 0.0f,
		-0.5f , -0.5f , 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main(){"
		"	gl_Position = vec4(vp,1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_color;"
		"void main(){"
		"	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, fs);
	glAttachShader(shader_program, vs);
	glLinkProgram(shader_program);

	while (!glfwWindowShouldClose(myWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_program);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glPointSize(15.0);
		glfwPollEvents();
		glfwSwapBuffers(myWindow);
	}
	system("pause");
}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{

	if (!glfwInit()) {
		fprintf(stderr, "tidak berjalan");
		return -1;
	}
	GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is triangle", NULL, NULL);
	//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
	if (!myWindow) {
		fprintf(stderr, "tidak bisa launch window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(myWindow);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *version = glGetString(GL_VERSION);

	printf("renderer = %s\n", renderer);
	printf("opengl version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float titik[] = {
		0.0f , 0.5f , 0.0f,
		0.5f , -0.5f , 0.0f,
		-0.5f , -0.5f , 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main(){"
		"	gl_Position = vec4(vp,1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_color;"
		"void main(){"
		"	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, fs);
	glAttachShader(shader_program, vs);
	glLinkProgram(shader_program);

	while (!glfwWindowShouldClose(myWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_program);
		glBindVertexArray(vao);
		glDrawArrays(GL_POINTS, 0, 3);
		glPointSize(20.0);
		glfwPollEvents();
		glfwSwapBuffers(myWindow);
	}
	glfwTerminate();
	system("pause");
}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{

	if (!glfwInit()) {
		fprintf(stderr, "tidak berjalan");
		return -1;
	}
	GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is triangle", NULL, NULL);
	//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
	if (!myWindow) {
		fprintf(stderr, "tidak bisa launch window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(myWindow);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *version = glGetString(GL_VERSION);

	printf("renderer = %s\n", renderer);
	printf("opengl version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float titik[] = {
		0.5f , 0.5f , 0.0f,
		0.5f , -0.5f , 0.0f,
		-0.5f , -0.5f , 0.0f,
		-0.5f , 0.5f , 0.0f,
		0.5f , 0.5f , 0.0f,
		-0.5f , 0.5f , 0.0f,
		0.5f , -0.5f , 0.0f,
		-0.5f , -0.5f , 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main(){"
		"	gl_Position = vec4(vp,1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_color;"
		"void main(){"
		"	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, fs);
	glAttachShader(shader_program, vs);
	glLinkProgram(shader_program);

	while (!glfwWindowShouldClose(myWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_program);
		glBindVertexArray(vao);
		glDrawArrays(GL_LINES, 0, 8);
		glPointSize(30.0);
		glfwPollEvents();
		glfwSwapBuffers(myWindow);
	}
	glfwTerminate();
	system("pause");
}
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{

	if (!glfwInit()) {
		fprintf(stderr, "tidak berjalan");
		return -1;
	}
	GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is triangle", NULL, NULL);
	//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
	if (!myWindow) {
		fprintf(stderr, "tidak bisa launch window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(myWindow);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *version = glGetString(GL_VERSION);

	printf("renderer = %s\n", renderer);
	printf("opengl version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float titik[] = {
		0.5f , 0.5f , 0.0f,
		0.5f , -0.5f , 0.0f,
		-0.5f , -0.5f , 0.0f,
		-0.5f , 0.5f , 0.0f,
		0.5f , 0.5f , 0.0f,
		-0.5f , 0.5f , 0.0f,
		0.5f , -0.5f , 0.0f,
		-0.5f , -0.5f , 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main(){"
		"	gl_Position = vec4(vp,1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_color;"
		"void main(){"
		"	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, fs);
	glAttachShader(shader_program, vs);
	glLinkProgram(shader_program);

	while (!glfwWindowShouldClose(myWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_program);
		glBindVertexArray(vao);
		glDrawArrays(GL_LINE_LOOP, 0, 4);
		glPointSize(30.0);
		glfwPollEvents();
		glfwSwapBuffers(myWindow);
	}
	glfwTerminate();
	system("pause");
}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define s_w 640
#define s_h 480

using namespace std;
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE && action == GLFW_REPEAT) {
		cout << "spasi ditekan " << endl;
	}
	//cout << "kode asci = " << key << endl;
}

int main() {
	GLFWwindow *window;
	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(s_w,s_h,"key_interupt",NULL,NULL);

	int scw, sch;
	glfwGetFramebufferSize(window, &scw, &sch);

	if(!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS,1);

	glViewport(0.0f, 0.0f, scw, sch);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(0,s_w,0,s_h,0,1);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define s_w 640
#define s_h 480

using namespace std;
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == 'L' && action == GLFW_PRESS) {
		cout << "L Key Pressed " << endl;
	}
	cout << "kode asci = " << key << endl;
}

int main() {
	GLFWwindow *window;
	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(s_w, s_h, "key_interupt", NULL, NULL);

	int scw, sch;
	glfwGetFramebufferSize(window, &scw, &sch);

	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glViewport(0.0f, 0.0f, scw, sch);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(0, s_w, 0, s_h, 0, 1);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define s_w 640
#define s_h 480

using namespace std;
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE && action == GLFW_REPEAT) {
		cout << "spasi ditekan " << endl;
	}
	//cout << "kode asci = " << key << endl;
}

int main() {
	GLFWwindow *window;
	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(s_w, s_h, "key_interupt", NULL, NULL);

	int scw, sch;
	glfwGetFramebufferSize(window, &scw, &sch);

	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glViewport(0.0f, 0.0f, scw, sch);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(0, s_w, 0, s_h, 0, 1);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define s_w 640
#define s_h 480

using namespace std;

void character_callback(GLFWwindow *window, unsigned int codepoint);
void charmods_callback(GLFWwindow *window, unsigned int codepoint, int mods);
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

int main() {
	GLFWwindow *window;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(s_w, s_h, "hello", NULL, NULL);

	//glfwSetCharModsCallback(window, charmods_callback);
	glfwSetKeyCallback(window, keyCallback);
	int sw, sh;
	glfwGetFramebufferSize(window, &sw, &sh);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, sw, sh);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(0, s_w, 0, s_h, 0, 1);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwTerminate();

	return 0;
}

void character_callback(GLFWwindow *window, unsigned int codepoint) {
	cout << codepoint << endl;
}

void charmods_callback(GLFWwindow *window, unsigned int codepoint, int mods) {
	cout << codepoint << ":" << mods << endl;
	{
		cout << "shift key pressed aswell" << endl;
	}
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		cout << "spasi ditekan " << endl;
		//GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is triangle", NULL, NULL);
		//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
		glfwMakeContextCurrent(window);

		glewExperimental = GL_TRUE;
		glewInit();

		const GLubyte *renderer = glGetString(GL_RENDERER);
		const GLubyte *version = glGetString(GL_VERSION);

		printf("renderer = %s\n", renderer);
		printf("opengl version supported %s\n", version);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		float titik[] = {
			0.0f , 0.5f , 0.0f,
			0.5f , -0.5f , 0.0f,
			-0.5f , -0.5f , 0.0f
		};

		GLuint vbo;
		glGenBuffers(1, &vbo);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

		GLuint vao;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		const char* vertex_shader =
			"#version 400\n"
			"in vec3 vp;"
			"void main(){"
			"	gl_Position = vec4(vp,1.0);"
			"}";

		const char* fragment_shader =
			"#version 400\n"
			"out vec4 frag_color;"
			"void main(){"
			"	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
			"}";

		GLuint vs = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vs, 1, &vertex_shader, NULL);
		glCompileShader(vs);

		GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fs, 1, &fragment_shader, NULL);
		glCompileShader(fs);

		GLuint shader_program = glCreateProgram();
		glAttachShader(shader_program, fs);
		glAttachShader(shader_program, vs);
		glLinkProgram(shader_program);

		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram(shader_program);
			glBindVertexArray(vao);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glPointSize(15.0);
			glfwPollEvents();
			glfwSwapBuffers(window);
		}
		system("pause");
	}
}
