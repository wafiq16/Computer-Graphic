// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <iostream>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include "math.h"

// using namespace glm;
// using namespace std;

// #define s_w 640
// #define s_h 480

// void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

// void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
// 	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
// 		vec4 vec(100.0f, 100.0f, 0.0f, 1.0f);
// 		mat4 trans;
// 		trans = translate(trans, vec3(25.0f, 50.0f, 0.0f));
// 		vec = vec * trans;
// 		cout << "spasi ditekan " << endl;
// 		//GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is triangle", NULL, NULL);
// 		//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
// 		glfwMakeContextCurrent(window);

// 		glewExperimental = GL_TRUE;
// 		glewInit();

// 		const GLubyte *renderer = glGetString(GL_RENDERER);
// 		const GLubyte *version = glGetString(GL_VERSION);

// 		printf("renderer = %s\n", renderer);
// 		printf("opengl version supported %s\n", version);

// 		glEnable(GL_DEPTH_TEST);
// 		glDepthFunc(GL_LESS);

// 		float titik[] = {
// 			vec.x , vec.x , 0.0f,
// 			vec.y , vec.y , 0.0f,
// 			vec.z , vec.z , 0.0f
// 		};

// 		GLuint vbo;
// 		glGenBuffers(1, &vbo);

// 		glBindBuffer(GL_ARRAY_BUFFER, vbo);
// 		glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

// 		GLuint vao;
// 		glGenVertexArrays(1, &vao);
// 		glBindVertexArray(vao);
// 		glEnableVertexAttribArray(0);
// 		glBindBuffer(GL_ARRAY_BUFFER, vbo);
// 		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

// 		const char* vertex_shader =
// 			"#version 400\n"
// 			"in vec3 vp;"
// 			"void main(){"
// 			"	gl_Position = vec4(vp,1.0);"
// 			"}";

// 		const char* fragment_shader =
// 			"#version 400\n"
// 			"out vec4 frag_color;"
// 			"void main(){"
// 			"	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
// 			"}";

// 		GLuint vs = glCreateShader(GL_VERTEX_SHADER);
// 		glShaderSource(vs, 1, &vertex_shader, NULL);
// 		glCompileShader(vs);

// 		GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
// 		glShaderSource(fs, 1, &fragment_shader, NULL);
// 		glCompileShader(fs);

// 		GLuint shader_program = glCreateProgram();
// 		glAttachShader(shader_program, fs);
// 		glAttachShader(shader_program, vs);
// 		glLinkProgram(shader_program);

// 		while (!glfwWindowShouldClose(window)) {
// 			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 			glUseProgram(shader_program);
// 			glBindVertexArray(vao);
// 			glDrawArrays(GL_TRIANGLES, 0, 3);
// 			glPointSize(15.0);
// 			glfwPollEvents();
// 			glfwSwapBuffers(window);
// 		}
// 		system("pause");
// 	}
// }


// int main() {
// 	GLFWwindow *window = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);

// 	//GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is triangle", NULL, NULL);
// 	//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
// 	glfwMakeContextCurrent(window);

// 	glewExperimental = GL_TRUE;
// 	glewInit();

// 	const GLubyte *renderer = glGetString(GL_RENDERER);
// 	const GLubyte *version = glGetString(GL_VERSION);

// 	printf("renderer = %s\n", renderer);
// 	printf("opengl version supported %s\n", version);

// 	glEnable(GL_DEPTH_TEST);
// 	glDepthFunc(GL_LESS);

// 	float titik[] = {
// 		100.0f , 100.0 , 0.0f,
// 		0.5f , -0.5f , 0.0f,
// 		-0.5f , -0.5f , 0.0f
// 	};

// 	GLuint vbo;
// 	glGenBuffers(1, &vbo);
// 	glBindBuffer(GL_ARRAY_BUFFER, vbo);
// 	glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

// 	GLuint vao;
// 	glGenVertexArrays(1, &vao);
// 	glBindVertexArray(vao);
// 	glEnableVertexAttribArray(0);
// 	glBindBuffer(GL_ARRAY_BUFFER, vbo);
// 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

// 	const char* vertex_shader =
// 		"#version 400\n"
// 		"in vec3 vp;"
// 		"void main(){"
// 		"	gl_Position = vec4(vp,1.0);"
// 		"}";

// 	const char* fragment_shader =
// 		"#version 400\n"
// 		"out vec4 frag_color;"
// 		"void main(){"
// 		"	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
// 		"}";

// 	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
// 	glShaderSource(vs, 1, &vertex_shader, NULL);
// 	glCompileShader(vs);

// 	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
// 	glShaderSource(fs, 1, &fragment_shader, NULL);
// 	glCompileShader(fs);

// 	GLuint shader_program = glCreateProgram();
// 	glAttachShader(shader_program, fs);
// 	glAttachShader(shader_program, vs);
// 	glLinkProgram(shader_program);

// 	while (!glfwWindowShouldClose(window)) {
// 		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 		glUseProgram(shader_program);
// 		glBindVertexArray(vao);
// 		glDrawArrays(GL_TRIANGLES, 0, 3);
// 		glPointSize(15.0);
// 		glfwPollEvents();
// 		glfwSwapBuffers(window);
// 	}
// 	system("pause");
// 	return 0;
// }