//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//using namespace std;
//using namespace glm;
//
//int main() {
//	vec4 vec(1.0f, 0.0f, 1.0f, 1.0f);
//	mat4 trans;
//	trans = translate(trans, vec3(2.0f, 2.0f, 1.0f));
//	vec = vec* trans;
//	cout << vec.x <<endl;
//	cout << vec.y << endl;
//	cout << vec.z << endl;
//	int v1 = 2,dx = 2,dy = 2, dz =1;
//	int v2 = 2;
//	int v3 = 1;
//	int v4 = 1;
//	cout << "v1 = " << v1 << "v2 = " << v2 << "v3 = " << v3 << "v4 = " << v4 << endl;
//	cout << "dx =" << dx << "dy =" << dy << "dz = " << dz << endl;
//	system("pause");
//	return 0;
//}

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <math.h>
//
//using namespace std;
//using namespace glm;
//
//int main() {
//	//vec4 vecy(0.0f, 2.0f, 0.0f, 0.1f);
//	//vec4 vecx(0.4f, 0.0f, 0.0f, 0.1f);
//	int x = 4, y = 2;
//	double V = 0;
//	V = std::sqrt(x * x + y * y);
//	cout << "V = " << V <<endl;
//	system("pause");
//	return 0;
//}

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include "math.h"
//
//using namespace std;
//using namespace glm;
//
//int main() {
//	glm::vec4 vec(5.0f, 2.0f, 0.0f, 1.0f);
//	glm::mat4 trans;
//	trans = scale(trans, vec3(0.0, 0.1, 0.0));
//	vec = trans * vec;
//	cout <<	(float)vec.x << endl;
//	cout << (float)vec.y << endl;
//	cout << (float)vec.z << endl;
//	cout << "x = " << 5 << " y = " << 2 << " z = " << 0 << endl;
//	cout << "s1 = " << 0 << " s2 = " << 0.1 << " s3 = " << 0 << endl;
//	return 0;
//}


//rotasi 1 bos



// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// //#include <GL/glut.h> 
// #include <iostream>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include "math.h"

// using namespace glm;
// using namespace std;
// int gambar_sebelum(float x, float y, float z);
// int gambar_sesudah(float x, float y, float z);
// int gambar_sebelum(float x, float y, float z) {
// 	if (!glfwInit()) {
// 		fprintf(stderr, "tidak berjalan");
// 		return -1;
// 	}
// 	GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is square", NULL, NULL);
// 	//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
// 	if (!myWindow) {
// 		fprintf(stderr, "tidak bisa launch window");
// 		glfwTerminate();
// 		return -1;
// 	}
// 	glfwMakeContextCurrent(myWindow);

// 	glewExperimental = GL_TRUE;
// 	glewInit();

// 	const GLubyte *renderer = glGetString(GL_RENDERER);
// 	const GLubyte *version = glGetString(GL_VERSION);

// 	printf("renderer = %s\n", renderer);
// 	printf("opengl version supported %s\n", version);

// 	glEnable(GL_DEPTH_TEST);
// 	glDepthFunc(GL_LESS);

// 	float titik[] = {
// 		0.5f  *x/y, 0.5f  *y/x, 0.0f*z,
// 		0.5f  *x/y, -0.5f *y/x, 0.0f*z,
// 		-0.5f *x/y, -0.5f *y/x, 0.0f*z,
// 		-0.5f *x/y, 0.5f  *y/x, 0.0f*z,
// 		0.5f  *x/y, 0.5f  *y/x, 0.0f*z,
// 		-0.5f *x/y, 0.5f  *y/x, 0.0f*z,
// 		0.5f  *x/y, -0.5f *y/x, 0.0f*z,
// 		-0.5f *x/y, -0.5f *y/x, 0.0f*z
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

// 	while (!glfwWindowShouldClose(myWindow)) {
// 		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 		glUseProgram(shader_program);
// 		glBindVertexArray(vao);
// 		glDrawArrays(GL_LINE_LOOP, 0, 4);
// 		glPointSize(30.0);
// 		glfwPollEvents();
// 		glfwSwapBuffers(myWindow);
// 	}
// 	glfwTerminate();
// 	system("pause");

// 	return 0;
// }
// int gambar_sesudah(float x, float y, float z) {
// 	if (!glfwInit()) {
// 		fprintf(stderr, "tidak berjalan");
// 		return -1;
// 	}
// 	GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is square", NULL, NULL);
// 	//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
// 	if (!myWindow) {
// 		fprintf(stderr, "tidak bisa launch window");
// 		glfwTerminate();
// 		return -1;
// 	}
// 	glfwMakeContextCurrent(myWindow);

// 	glewExperimental = GL_TRUE;
// 	glewInit();

// 	const GLubyte *renderer = glGetString(GL_RENDERER);
// 	const GLubyte *version = glGetString(GL_VERSION);

// 	printf("renderer = %s\n", renderer);
// 	printf("opengl version supported %s\n", version);

// 	glEnable(GL_DEPTH_TEST);
// 	glDepthFunc(GL_LESS);

// 	float titik[] = {
// 		0.5f  *x/y, 0.5f  *y/x, 0.0f*z,
// 		0.5f  *x/y, -0.5f *y/x, 0.0f*z,
// 		-0.5f *x/y, -0.5f *y/x, 0.0f*z,
// 		-0.5f *x/y, 0.5f  *y/x, 0.0f*z,
// 		0.5f  *x/y, 0.5f  *y/x, 0.0f*z,
// 		-0.5f *x/y, 0.5f  *y/x, 0.0f*z,
// 		0.5f  *x/y, -0.5f *y/x, 0.0f*z,
// 		-0.5f *x/y, -0.5f *y/x, 0.0f*z
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

// 	while (!glfwWindowShouldClose(myWindow)) {
// 		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 		glUseProgram(shader_program);
// 		glBindVertexArray(vao);
// 		glDrawArrays(GL_LINE_LOOP, 0, 4);
// 		glPointSize(30.0);
// 		glfwPollEvents();
// 		glfwSwapBuffers(myWindow);
// 	}
// 	glfwTerminate();

// 	system("pause");
// 	return 0;
// }
// int main() {
	
// 	vec4 vec(5.0, 2.0f, 0.0f, 1.0f);
// 	mat4 trans;

// 	gambar_sebelum(5.0f, 2.0f, 0.0f);
	
// 	trans = rotate(trans, 90.0f, vec3(0.0, 0.0, 1.0));
// 	vec = trans * vec;

// 	gambar_sesudah(vec.x, vec.y, vec.z);

// 	cout <<	(float)vec.x << endl;
// 	cout << (float)vec.y << endl;
// 	cout << (float)vec.z << endl;
	
// 	return 0;
// }

// rotasi 2

 //#include <GL/glew.h>
 //#include <GLFW/glfw3.h>
 //#include <iostream>
 //#include <glm/glm.hpp>
 //#include <glm/gtc/matrix_transform.hpp>
 //#include <glm/gtc/type_ptr.hpp>
 //#include "math.h"

 //using namespace glm;
 //using namespace std;

 //int gambar_sebelum(float x, float y, float z);
 //int gambar_sesudah(float x, float y, float z);
 //int gambar_sebelum(float x, float y, float z) {
	// if (!glfwInit()) {
	//	 fprintf(stderr, "tidak berjalan");
	//	 return -1;
	// }
	// GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is square", NULL, NULL);
	// //myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
	// if (!myWindow) {
	//	 fprintf(stderr, "tidak bisa launch window");
	//	 glfwTerminate();
	//	 return -1;
	// }
	// glfwMakeContextCurrent(myWindow);

	// glewExperimental = GL_TRUE;
	// glewInit();

	// const GLubyte *renderer = glGetString(GL_RENDERER);
	// const GLubyte *version = glGetString(GL_VERSION);

	// printf("renderer = %s\n", renderer);
	// printf("opengl version supported %s\n", version);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LESS);

	// float titik[] = {
	//	 0.5f  *x / y, 0.5f  *y / x, 0.0f*z,
	//	 0.5f  *x / y, -0.5f *y / x, 0.0f*z,
	//	 -0.5f *x / y, -0.5f *y / x, 0.0f*z,
	//	 -0.5f *x / y, 0.5f  *y / x, 0.0f*z,
	//	 0.5f  *x / y, 0.5f  *y / x, 0.0f*z,
	//	 -0.5f *x / y, 0.5f  *y / x, 0.0f*z,
	//	 0.5f  *x / y, -0.5f *y / x, 0.0f*z,
	//	 -0.5f *x / y, -0.5f *y / x, 0.0f*z
	// };

	// GLuint vbo;
	// glGenBuffers(1, &vbo);

	// glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

	// GLuint vao;
	// glGenVertexArrays(1, &vao);
	// glBindVertexArray(vao);
	// glEnableVertexAttribArray(0);
	// glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	// const char* vertex_shader =
	//	 "#version 400\n"
	//	 "in vec3 vp;"
	//	 "void main(){"
	//	 "	gl_Position = vec4(vp,1.0);"
	//	 "}";

	// const char* fragment_shader =
	//	 "#version 400\n"
	//	 "out vec4 frag_color;"
	//	 "void main(){"
	//	 "	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
	//	 "}";

	// GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	// glShaderSource(vs, 1, &vertex_shader, NULL);
	// glCompileShader(vs);

	// GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	// glShaderSource(fs, 1, &fragment_shader, NULL);
	// glCompileShader(fs);

	// GLuint shader_program = glCreateProgram();
	// glAttachShader(shader_program, fs);
	// glAttachShader(shader_program, vs);
	// glLinkProgram(shader_program);

	// while (!glfwWindowShouldClose(myWindow)) {
	//	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	 glUseProgram(shader_program);
	//	 glBindVertexArray(vao);
	//	 glDrawArrays(GL_LINE_LOOP, 0, 4);
	//	 glPointSize(30.0);
	//	 glfwPollEvents();
	//	 glfwSwapBuffers(myWindow);
	// }
	// glfwTerminate();
	// system("pause");

	// return 0;
 //}
 //int gambar_sesudah(float x, float y, float z) {
	// if (!glfwInit()) {
	//	 fprintf(stderr, "tidak berjalan");
	//	 return -1;
	// }
	// GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is square", NULL, NULL);
	// //myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
	// if (!myWindow) {
	//	 fprintf(stderr, "tidak bisa launch window");
	//	 glfwTerminate();
	//	 return -1;
	// }
	// glfwMakeContextCurrent(myWindow);

	// glewExperimental = GL_TRUE;
	// glewInit();

	// const GLubyte *renderer = glGetString(GL_RENDERER);
	// const GLubyte *version = glGetString(GL_VERSION);

	// printf("renderer = %s\n", renderer);
	// printf("opengl version supported %s\n", version);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LESS);

	// float titik[] = {
	//	 0.5f  *x / y, 0.5f  *y / x, 0.0f*z,
	//	 0.5f  *x / y, -0.5f *y / x, 0.0f*z,
	//	 -0.5f *x / y, -0.5f *y / x, 0.0f*z,
	//	 -0.5f *x / y, 0.5f  *y / x, 0.0f*z,
	//	 0.5f  *x / y, 0.5f  *y / x, 0.0f*z,
	//	 -0.5f *x / y, 0.5f  *y / x, 0.0f*z,
	//	 0.5f  *x / y, -0.5f *y / x, 0.0f*z,
	//	 -0.5f *x / y, -0.5f *y / x, 0.0f*z
	// };

	// GLuint vbo;
	// glGenBuffers(1, &vbo);

	// glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

	// GLuint vao;
	// glGenVertexArrays(1, &vao);
	// glBindVertexArray(vao);
	// glEnableVertexAttribArray(0);
	// glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	// const char* vertex_shader =
	//	 "#version 400\n"
	//	 "in vec3 vp;"
	//	 "void main(){"
	//	 "	gl_Position = vec4(vp,1.0);"
	//	 "}";

	// const char* fragment_shader =
	//	 "#version 400\n"
	//	 "out vec4 frag_color;"
	//	 "void main(){"
	//	 "	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
	//	 "}";

	// GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	// glShaderSource(vs, 1, &vertex_shader, NULL);
	// glCompileShader(vs);

	// GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	// glShaderSource(fs, 1, &fragment_shader, NULL);
	// glCompileShader(fs);

	// GLuint shader_program = glCreateProgram();
	// glAttachShader(shader_program, fs);
	// glAttachShader(shader_program, vs);
	// glLinkProgram(shader_program);

	// while (!glfwWindowShouldClose(myWindow)) {
	//	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	 glUseProgram(shader_program);
	//	 glBindVertexArray(vao);
	//	 glDrawArrays(GL_LINE_LOOP, 0, 4);
	//	 glPointSize(30.0);
	//	 glfwPollEvents();
	//	 glfwSwapBuffers(myWindow);
	// }
	// glfwTerminate();

	// system("pause");
	// return 0;
 //}
 //int main() {
	//gambar_sebelum(5.0f, 2.0f, 0.0f);
 //	vec4 vec(5.0, 2.0f, 0.0f, 1.0f);
 //	mat4 trans;
 //	trans = rotate(trans, 45.0f, vec3(0.0, 1.0, 0.0));
 //	vec = trans * vec;

	//gambar_sesudah(vec.x, vec.y, vec.z);

 //	cout << (float)vec.x << endl;
 //	cout << (float)vec.y << endl;
 //	cout << (float)vec.z << endl;

 //	return 0;
 //}

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include "math.h"
//
//using namespace glm;
//using namespace std;
//
//#define s_w 640
//#define s_h 480
//
//void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
//
//void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
//	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
//		vec4 vec(100.0f, 100.0f, 0.0f, 1.0f);
//		mat4 trans;
//		trans = translate(trans, vec3(25.0f, 50.0f, 0.0f));
//		vec = vec * trans;
//		//cout << vec.x << " "<< vec.y << " "<< vec.z << endl;
//		cout << "spasi ditekan " << endl;
//		//GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is triangle", NULL, NULL);
//		//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
//		glfwMakeContextCurrent(window);
//
//		glewExperimental = GL_TRUE;
//		glewInit();
//
//		const GLubyte *renderer = glGetString(GL_RENDERER);
//		const GLubyte *version = glGetString(GL_VERSION);
//
//		printf("renderer = %s\n", renderer);
//		printf("opengl version supported %s\n", version);
//
//		glEnable(GL_DEPTH_TEST);
//		glDepthFunc(GL_LESS);
//
//		float titik[] = {
//			-0.25f - 0.75f , 1.25f - 0.5f , 0.0f,
//			0.0f - 0.75f   , 0.75f - 0.5f , 0.0f,
//			-0.5f - 0.75f  , 0.75f - 0.5f  , 0.0f
//		};
//
//		GLuint vbo;
//		glGenBuffers(1, &vbo);
//
//		glBindBuffer(GL_ARRAY_BUFFER, vbo);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);
//
//		GLuint vao;
//		glGenVertexArrays(1, &vao);
//		glBindVertexArray(vao);
//		glEnableVertexAttribArray(0);
//		glBindBuffer(GL_ARRAY_BUFFER, vbo);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
//
//		const char* vertex_shader =
//			"#version 400\n"
//			"in vec3 vp;"
//			"void main(){"
//			"	gl_Position = vec4(vp,1.0);"
//			"}";
//
//		const char* fragment_shader =
//			"#version 400\n"
//			"out vec4 frag_color;"
//			"void main(){"
//			"	frag_color = vec4(0.3, 0.7 , 1 , 1.0);"
//			"}";
//
//		GLuint vs = glCreateShader(GL_VERTEX_SHADER);
//		glShaderSource(vs, 1, &vertex_shader, NULL);
//		glCompileShader(vs);
//
//		GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
//		glShaderSource(fs, 1, &fragment_shader, NULL);
//		glCompileShader(fs);
//
//		GLuint shader_program = glCreateProgram();
//		glAttachShader(shader_program, fs);
//		glAttachShader(shader_program, vs);
//		glLinkProgram(shader_program);
//
//		while (!glfwWindowShouldClose(window)) {
//			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//			glUseProgram(shader_program);
//			glBindVertexArray(vao);
//			glDrawArrays(GL_TRIANGLES, 0, 3);
//			glPointSize(15.0);
//			glfwPollEvents();
//			glfwSwapBuffers(window);
//		}
//		system("pause");
//	}
//}
//
//int main(void){
//	//100, 100, 0
//	//50, 25, 0
//	if (!glfwInit()) {
//			fprintf(stderr, "tidak berjalan");
//			return 1;
//		}
//	GLFWwindow *myWindow = glfwCreateWindow(640, 480, "this is triangle", NULL, NULL);
//	//myWindow = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
//	if (!myWindow) {
//			fprintf(stderr, "tidak bisa launch window");
//			glfwTerminate();
//			return 1;
//		}
//	glfwMakeContextCurrent(myWindow);
//
//	glfwSetKeyCallback(myWindow, keyCallback);
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	const GLubyte *renderer = glGetString(GL_RENDERER);
//	const GLubyte *version = glGetString(GL_VERSION);
//
//	printf("renderer = %s\n", renderer);
//	printf("opengl version supported %s\n", version);
//
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS);
//
//	float titik[] = {
//			-0.25f , 1.25f , 0.0f,
//			0.0f , 0.75f , 0.0f,
//			-0.5f , 0.75f , 0.0f 
//	};
//
//	GLuint vbo;
//	glGenBuffers(1, &vbo);
//
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);
//
//	GLuint vao;
//	glGenVertexArrays(1, &vao);
//	glBindVertexArray(vao);
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
//
//	const char* vertex_shader =
//		"#version 400\n"
//		"in vec3 vp;"
//		"void main(){"
//		"	gl_Position = vec4(vp,1.0);"
//		"}";
//
//	const char* fragment_shader =
//		"#version 400\n"
//		"out vec4 frag_color;"
//		"void main(){"
//		"	frag_color = vec4(0.6, 0.5 , 1 , 1.0);"
//		"}";
//
//	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vs, 1, &vertex_shader, NULL);
//	glCompileShader(vs);
//
//	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fs, 1, &fragment_shader, NULL);
//	glCompileShader(fs);
//
//	GLuint shader_program = glCreateProgram();
//	glAttachShader(shader_program, fs);
//	glAttachShader(shader_program, vs);
//	glLinkProgram(shader_program);
//
//	while (!glfwWindowShouldClose(myWindow)) {
//			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//			glUseProgram(shader_program);
//			glBindVertexArray(vao);
//			glDrawArrays(GL_TRIANGLES, 0, 3);
//			glPointSize(15.0);
//			glfwPollEvents();
//			glfwSwapBuffers(myWindow);
//		}
//	system("pause");
//}

