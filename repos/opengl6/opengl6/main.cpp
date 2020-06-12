//// objek 3d
//
////objek
//
//#include <iostream>
//// GLEW
//#include <GL/glew.h>
//// GLFW
//#include <GLFW/glfw3.h>
//#include <SOIL.h>
////GLM Libraries
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//// Other includes
//#include "myshader.h"
//
//using namespace glm;
////Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//
////window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//
//int main() {
//	glfwInit();
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "wafiq - 2210181042", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//	glfwSetKeyCallback(window, key_callback);
//	glewExperimental = GL_TRUE;
//	glewInit();
//	glViewport(0, 0, WIDTH, HEIGHT);
//	Shader ourShader("vs.vs", "fr.fr");
//	GLfloat vertices[] =
//	{
//		0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//		1.0f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//		1.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
//
//		0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,//kiri
//		1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f,
//		0.5f, 0.0f, 1.5f, 1.0f, 1.0f, 0.0f,
//
//		1.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,//kanan
//		1.0f, 0.5f, 1.0f, 0.0f, 1.0f, 0.0f,
//		1.5f, 0.0f, 1.5f, 0.0f, 1.0f, 0.0f,
//
//		0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,//belakang
//		1.0f, 0.5f, 1.5f, 1.0f, 0.0f, 0.0f,
//		1.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
//
//		//0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//		//-0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//		//0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//
//		//-0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//		//-0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//		//0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//		//0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f
//	};
//	GLuint indices[] = {
//		0, 1, 2,
//		3, 4, 5,
//		6, 7, 8,
//		9, 10, 11,
//		12, 13, 14,
//		14, 15, 12
//	};
//
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
//
//		ourShader.Use();
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		//glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
//		model = glm::rotate(model, 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
//		view = glm::translate(view, glm::vec3(0.0f, 0.2f, -3.0f));
//		//view = glm::lookAt(glm::vec3(4, 3, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
//		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//
//		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//
//		// Swap the screen buffers 
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

//// Camera View (1)
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
//		nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	// Vertex shader
//	Shader ourShader("vs1.vs", "fr1.fr");
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//	 -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
//	 0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
//	 0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//	 -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 -0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//	 -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
//	};
//	GLuint indices[] = {
//	 0, 1, 2,
//	 3, 4, 5,
//	 6, 7, 8,
//	 9, 10, 11,
//	 12, 13, 14,
//	 14, 15, 12
//	};
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
//		ourShader.Use();
		//glm::mat4 model;
		//glm::mat4 view;
		//glm::mat4 projection;
		//GLfloat radius = 3.0f;
		//GLfloat camX = float(-0.7)*radius;
		//GLfloat camY = float(0)*radius;
		//GLfloat camZ = float(0.7)*radius;
		//view =
		//	glm::lookAt(glm::vec3(camX, camY, camZ),
		//		glm::vec3(-0.5, 0.0, 0.0),
		//		glm::vec3(0.0, 1.0, 0.0));
		//projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f,
		//	100.0f);
//		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

// Camera View (2)

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
//		nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	// Vertex shader
//	Shader ourShader("vs1.vs", "fr1.fr");
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//	 -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
//	 0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
//	 0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//	 -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 -0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//	 -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
//	};
//	GLuint indices[] = {
//	 0, 1, 2,
//	 3, 4, 5,
//	 6, 7, 8,
//	 9, 10, 11,
//	 12, 13, 14,
//	 14, 15, 12
//	};
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
//		ourShader.Use();
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		GLfloat radius = 3.0f;
//		GLfloat camX = float(0.7)*radius;
//		GLfloat camY = float(0)*radius;
//		GLfloat camZ = float(0.7)*radius;
//		view = glm::lookAt(glm::vec3(camX, camY, camZ),
//			glm::vec3(0.0, 0.0, 0.0),
//			glm::vec3(0.0, 1.0, 0.0));
//		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

// Camera view(3)

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
//		nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	// Vertex shader
//	Shader ourShader("vs1.vs", "fr1.fr");
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//	 -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
//	 0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
//	 0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//	 -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 -0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//	 -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
//	};
//	GLuint indices[] = {
//	 0, 1, 2,
//	 3, 4, 5,
//	 6, 7, 8,
//	 9, 10, 11,
//	 12, 13, 14,
//	 14, 15, 12
//	};
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
//		ourShader.Use();
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		GLfloat radius = 3.0f;
//		GLfloat camX = float(0)*radius;
//		GLfloat camY = float(0.7)*radius;
//		GLfloat camZ = float(0.7)*radius;
//		view = glm::lookAt(glm::vec3(camX, camY, camZ),
//			glm::vec3(0.0, 0.0, 0.0),
//			glm::vec3(0.0, 1.0, 0.0));
//		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

//camera view 4

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
//		nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	// Vertex shader
//	Shader ourShader("vs1.vs", "fr1.fr");
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//	 -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
//	 0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
//	 0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//	 -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 -0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//	 -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
//	};
//	GLuint indices[] = {
//	 0, 1, 2,
//	 3, 4, 5,
//	 6, 7, 8,
//	 9, 10, 11,
//	 12, 13, 14,
//	 14, 15, 12
//	};
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
//		ourShader.Use();
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		GLfloat radius = 3.0f;
//		GLfloat camX = float(0)*radius;
//		GLfloat camY = float(-0.7)*radius;
//		GLfloat camZ = float(0.7)*radius;
//		view = glm::lookAt(glm::vec3(camX, camY, camZ),
//			glm::vec3(0.0, 0.0, 0.0),
//			glm::vec3(0.0, 1.0, 0.0));
//		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

// tugas 1
//nomor 2 a

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
//		nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	// Vertex shader
//	Shader ourShader("vs1.vs", "fr1.fr");
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//	 -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
//	 0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
//	 0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//	 -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 -0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//	 -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
//	};
//	GLuint indices[] = {
//	 0, 1, 2,
//	 3, 4, 5,
//	 6, 7, 8,
//	 9, 10, 11,
//	 12, 13, 14,
//	 14, 15, 12
//	};
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
//		ourShader.Use();
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		GLfloat radius = 3.0f;
//		GLfloat camX = float(0)*radius;
//		GLfloat camY = float(2.0)*radius;
//		GLfloat camZ = float(0.1)*radius;
//		view = glm::lookAt(glm::vec3(camX, camY, camZ),
//			glm::vec3(0.0, 0.0, 0.0),
//			glm::vec3(0.0, 1.0, 0.0));
//		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

// nomor 2b

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
//		nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	// Vertex shader
//	Shader ourShader("vs1.vs", "fr1.fr");
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//	 -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
//	 0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
//	 0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//	 -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 -0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//	 -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
//	};
//	GLuint indices[] = {
//	 0, 1, 2,
//	 3, 4, 5,
//	 6, 7, 8,
//	 9, 10, 11,
//	 12, 13, 14,
//	 14, 15, 12
//	};
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
		//ourShader.Use();
		//glm::mat4 model;
		//glm::mat4 view;
		//glm::mat4 projection;
		//GLfloat radius = 3.0f;
		//GLfloat camX = float(0)*radius;
		//GLfloat camY = float(0)*radius;
		//GLfloat camZ = float(0.7)*radius;
		//view = glm::lookAt(glm::vec3(camX, camY, camZ),
		//	glm::vec3(0.0, 0.0, 0.0),
		//	glm::vec3(0.0, 1.0, 0.0));
		//projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		//GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		//GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		//GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

//nomor 2 c

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
//		nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	// Vertex shader
//	Shader ourShader("vs1.vs", "fr1.fr");
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//	 -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
//	 0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
//	 0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//	 -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 -0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//	 -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
//	};
//	GLuint indices[] = {
//	 0, 1, 2,
//	 3, 4, 5,
//	 6, 7, 8,
//	 9, 10, 11,
//	 12, 13, 14,
//	 14, 15, 12
//	};
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
		//ourShader.Use();
		//glm::mat4 model;
		//glm::mat4 view;
		//glm::mat4 projection;
		//GLfloat radius = 3.0f;
		//GLfloat camX = float(0)*radius;
		//GLfloat camY = float(-2.0)*radius;
		//GLfloat camZ = float(0.1)*radius;
		//view = glm::lookAt(glm::vec3(camX, camY, camZ),
		//	glm::vec3(0.0, 0.0, 0.0),
		//	glm::vec3(0.0, 1.0, 0.0));
		//projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		//GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		//GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		//GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

//nomor 2 d

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
//		nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	// Vertex shader
//	Shader ourShader("vs1.vs", "fr1.fr");
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//	 -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
//	 0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
//	 0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//	 -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 -0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//	 -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
//	};
//	GLuint indices[] = {
//	 0, 1, 2,
//	 3, 4, 5,
//	 6, 7, 8,
//	 9, 10, 11,
//	 12, 13, 14,
//	 14, 15, 12
//	};
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
//		ourShader.Use();
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		GLfloat radius = 3.0f;
//		GLfloat camX = float(0.0)*radius;
//		GLfloat camY = float(0.0)*radius;
//		GLfloat camZ = float(-1.4)*radius;
//		view = glm::lookAt(glm::vec3(camX, camY, camZ),
//			glm::vec3(0.0, 0.0, 0.0),
//			glm::vec3(0.0, 1.0, 0.0));
//		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

//nomor 2e

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
//		nullptr);
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//	// Build and compile our shader program
//	// Vertex shader
//	Shader ourShader("vs1.vs", "fr1.fr");
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
//	 -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
//	 0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
//	 0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//	 -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
//	 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
//	 -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//	 -0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
//	 -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
//	 0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
//	};
//	GLuint indices[] = {
//	 0, 1, 2,
//	 3, 4, 5,
//	 6, 7, 8,
//	 9, 10, 11,
//	 12, 13, 14,
//	 14, 15, 12
//	};
//	glEnable(GL_DEPTH_TEST);
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
//		sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	GLuint texture1;
//	GLuint texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
//		ourShader.Use();
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		GLfloat radius = 3.0f;
		//GLfloat camX = float(0.8)*radius;
		//GLfloat camY = float(-0.4)*radius;
		//GLfloat camZ = float(2.0)*radius;
		//view = glm::lookAt(glm::vec3(camX, camY, camZ),
		//	glm::vec3(0.0, 0.0, 0.0),
		//	glm::vec3(-1.0, 1.0, -1.0));
		//projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		//GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		//GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		//GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,
		nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	// Vertex shader
	Shader ourShader("vs1.vs", "fr1.fr");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
	
	//atas
	2.0 , 0.0 , 4.0 , 0.0 , 1.0, 1.0,
	0.0 , 0.0 , 2.0 , 0.0 , 1.0, 1.0,
	2.0 , 0.0 , 0.0 , 0.0 , 1.0, 1.0,

	2.0 , 0.0 , 0.0 , 0.0 , 1.0, 0.0,
	2.0 , 0.0 , 4.0 , 0.0 , 1.0, 0.0,
	4.0 , 0.0 , 0.0 , 0.0 , 1.0, 0.0,
	4.0 , 0.0 , 4.0 , 0.0 , 1.0, 0.0,
	
	4.0 , 0.0 , 4.0 , 0.0 , 1.0, 1.0,
	6.0 , 0.0 , 2.0 , 0.0 , 1.0, 1.0,
	4.0 , 0.0 , 0.0 , 0.0 , 1.0, 1.0,
	
	//sisi 1
	 2.0, 0.0, 0.0 , 0.2, 0.3, 0.4,
	 4.0, 0.0, 0.0 , 0.2, 0.3, 0.4,
	 2.0, -18.0, 0.0 , 0.2, 0.3, 0.4,
	 4.0, -18.0, 0.0 , 0.2, 0.3, 0.4,

	 //sisi2
	 4.0, 0.0, 0.0 , 0.2, 0.3, 1,
	 6.0, 0.0, 2.0 , 0.2, 0.3, 1,
	 4.0, -18.0, 0.0 , 0.2, 0.3, 1,
	 6.0, -18.0, 2.0 , 0.2, 0.3, 1,

	 //sisi3
	 4.0, 0.0, 4.0 , 1, 0.3, 0.4,
	 6.0, 0.0, 2.0 , 1, 0.3, 0.4,
	 4.0, -18.0, 4.0 , 1, 0.3, 0.4,
	 6.0, -18.0, 2.0 , 1, 0.3, 0.4,

	 //sisi4
	 4.0, 0.0, 4.0 , 1, 1, 0.4,
	 2.0, 0.0, 4.0 , 1, 1, 0.4,
	 4.0, -18.0, 4.0 , 1, 1, 0.4,
	 2.0, -18.0, 4.0 , 1, 1, 0.4,

	 //sisi5
	2.0, 0.0, 4.0 , 0.1, 0.3, 0.4,
	 0.0, 0.0, 2.0 , 0.1, 0.3, 0.4,
	 2.0, -18.0, 4.0 , 0.1, 0.3, 0.4,
	 0.0, -18.0, 2.0 , 0.1, 0.3, 0.4,
	

	// //sisi6
	 2.0, 0.0, 0.0 , 0.2, 0.3, 0.1,
	 0.0, 0.0, 2.0 , 0.2, 0.3, 0.1,
	 2.0, -18.0, 0.0 , 0.2, 0.3, 0.1,
	 0.0, -18.0, 2.0 , 0.2, 0.3, 0.1,

	 //bawah
	2.0 , -18.0 , 4.0 , 0.0 , 0.0, 1.0,
	0.0 , -18.0 , 2.0 , 0.0 , 0.0, 1.0,
	2.0 , -18.0 , 0.0 , 0.0 , 0.0, 1.0,

	2.0 , -18.0 , 0.0 , 0.2 , 1.0, 0.0,
	2.0 , -18.0 , 4.0 , 0.2 , 1.0, 0.0,
	4.0 , -18.0 , 0.0 , 0.2 , 1.0, 0.0,
	4.0 , -18.0 , 4.0 , 0.2 , 1.0, 0.0,

	4.0 , -18.0 , 4.0 , 0.0 , 0.5, 1.0,
	6.0 , -18.0 , 2.0 , 0.0 , 0.5, 1.0,
	4.0 , -18.0 , 0.0 , 0.0 , 0.5, 1.0,

	//diamond
	//bawah
	 2.0f, 6.0f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
	 3.0f, 6.0f, 0.0f, 1.0f, 0.0f, 0.0f,
	 2.5f, 2.0f, 2.0f, 1.0f, 0.0f, 0.0f,

	 3.0f, 6.0f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
	 3.0f, 6.0f, 4.0f, 1.0f, 1.0f, 0.0f,
	 2.5f, 2.0f, 2.0f, 1.0f, 1.0f, 0.0f,

	  2.0f, 6.0f, 0.0f, 1.0f, 1.0f, 0.0f,//kiri
	 2.0f, 6.0f, 4.0f, 1.0f, 1.0f, 0.0f,
	 2.5f, 2.0f, 2.0f, 1.0f, 1.0f, 0.0f,

	 2.0f, 6.0f, 4.0f, 1.0f, 0.0f, 0.0f,//belakang
	 3.0f, 6.0f, 4.0f, 1.0f, 0.0f, 0.0f,
	 2.5f, 2.0f, 2.0f, 1.0f, 0.0f, 0.0f,

	//atas
	 2.0f, 6.0f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
	 3.0f, 6.0f, 0.0f, 1.0f, 0.0f, 0.0f,
	 2.5f, 10.0f, 2.0f, 1.0f, 0.0f, 0.0f,

	 3.0f, 6.0f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
	 3.0f, 6.0f, 4.0f, 1.0f, 1.0f, 0.0f,
	 2.5f, 10.0f, 2.0f, 1.0f, 1.0f, 0.0f,

	  2.0f, 6.0f, 0.0f, 1.0f, 1.0f, 0.0f,//kiri
	 2.0f, 6.0f, 4.0f, 1.0f, 1.0f, 0.0f,
	 2.5f, 10.0f, 2.0f, 1.0f, 1.0f, 0.0f,

	 2.0f, 6.0f, 4.0f, 1.0f, 0.0f, 0.0f,//belakang
	 3.0f, 6.0f, 4.0f, 1.0f, 0.0f, 0.0f,
	 2.5f, 10.0f, 2.0f, 1.0f, 0.0f, 0.0f,

	//kotak bagian atas
		0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 4.0, 0.0, 1.0, 0.0,
		6.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		6.0, 0.0, 4.0, 0.0, 1.0, 0.0,

		-4.0, 2.0, 0.0, 0.0, 1.0, 0.0,
		-4.0, 2.0, 4.0, 0.0, 1.0, 0.0,
		10.0, 2.0, 0.0, 0.0, 1.0, 0.0,
		10.0, 2.0, 4.0, 0.0, 1.0, 0.0,

		0.0, 0.0, 4.0, 1.0, 1.0, 0.1,
		0.0, 0.0, 0.0, 1.0, 1.0, 0.1,
		-4.0, 2.0, 4.0, 1.0, 1.0, 0.1,
		-4.0, 2.0, 0.0, 1.0, 1.0, 0.1,

		 6.0, 0.0, 4.0, 1.0, 0.0, 0.1,
		 6.0, 0.0, 0.0, 1.0, 0.0, 0.1,
		 10.0, 2.0, 4.0, 1.0, 0.0, 0.1,
		 10.0, 2.0, 0.0, 1.0, 0.0, 0.1,

		 -4.0, 2.0, 4.0, 0.0, 0.5, 1.0,
		 10.0, 2.0, 4.0, 0.0, 0.5, 1.0,
		 6.0, 0.0, 4.0, 0.0, 0.5, 1.0,
		 0.0, 0.0, 4.0, 0.0, 0.5, 1.0,

		 -4.0, 2.0, 0.0, 1.0, 0.0, 0.0,
		 10.0, 2.0, 0.0, 1.0, 0.0, 0.0,
		 6.0, 0.0, 0.0, 1.0, 0.0, 0.0,
		 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,

		 //kotak bagian bawah
		 -4.0, -18.0, 0.0, 0.0, 1.0, 0.0,
		 -4.0, -18.0, 8.0, 0.0, 1.0, 0.0,
		 10.0, -18.0, 0.0, 0.0, 1.0, 0.0,
		 10.0, -18.0, 8.0, 0.0, 1.0, 0.0,

		 -6.0, -22.0, 0.0, 0.0, 1.0, 0.0,
		 -6.0, -22.0, 8.0, 0.0, 1.0, 0.0,
		 12.0, -22.0, 0.0, 0.0, 1.0, 0.0,
		 12.0, -22.0, 8.0, 0.0, 1.0, 0.0,

		 -4.0, -18.0, 8.0, 1.0, 1.0, 0.1,
		 -4.0, -18.0, 0.0, 1.0, 1.0, 0.1,
		 -6.0, -22.0, 8.0, 1.0, 1.0, 0.1,
		 -6.0, -22.0, 0.0, 1.0, 1.0, 0.1,

		 10.0, -18.0, 8.0, 1.0, 0.0, 0.1,
		 10.0, -18.0, 0.0, 1.0, 0.0, 0.1,
		 12.0, -22.0, 8.0, 1.0, 0.0, 0.1,
		 12.0, -22.0, 0.0, 1.0, 0.0, 0.1,

		-4.0, -18.0, 8.0, 1.0, 1.0, 1.0,
		-6.0, -22.0, 8.0, 1.0, 1.0, 1.0,
		 12.0, -22.0, 8.0, 1.0, 1.0, 1.0,
		 10.0, -18.0, 8.0, 1.0, 1.0, 1.0,
		
		-6.0, -22.0, 0.0, 1.0, 1.0, 1.0,
		 12.0, -22.0, 0.0, 1.0, 1.0, 1.0,
		 10.0, -18.0, 0.0, 1.0, 1.0, 1.0,
		-4.0, -18.0, 0.0, 1.0, 1.0, 1.0,

	};
	GLuint indices[] = {
	//bangun segi enam 
	0, 1, 2, 
	 
	 3, 4, 5, 
	 5, 6, 4,

	 7, 8, 9,
	 
	 10,11,12,
	 12,13,11,
	 
	 14,15,16,
	 16,17,15,
	
	 18,19,20,
	 20,21,19,

	 22,23,24,
	 24,25,23,

	 26,27,28,
	 28,29,27,

	30,31,32,
	32,33,31,

	34,35,36,

	37,38,39,
	39,40,38,

	41,42,43,

	//bangun diamond
	44,45,46,
	47,48,49,
	50,51,52,
	53,54,55,
	56,57,58,
	59,60,61,
	62,63,64,
	65,66,67,
	
	//bangun kotak bagian atas
	68,69,70,
	70,71,69,

	72,73,74,
	74,75,73,

	76,77,78,
	78,79,77,

	80,81,82,
	82,83,81,

	84,85,86,
	86,87,84,

	88,89,90,
	90,91,88,

	//bangun kotak bagian bawah
	92,93,94,
	94,95,93,

	96,97,98,
	98,99,97,

	100,101,102,
	102,103,101,

	104,105,106,
	106,107,105,

	108,109,110,
	110,111,108,

	112,113,114,
	114,115,112

	};
	glEnable(GL_DEPTH_TEST);
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
		sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	GLuint texture1;
	GLuint texture2;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
		ourShader.Use();
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		GLfloat radius = 3.0f,i = 0;
		GLfloat camX = float(-10.0)*radius;
		GLfloat camY = float(15.0)*radius;
		GLfloat camZ = float(10.0)*radius;
		view = glm::lookAt(glm::vec3(camX, camY, camZ),
			glm::vec3(0.0, 0.0, 0.0),
			glm::vec3(1.0, 1.0, 1.0));
		//view = glm::translate(view, glm::vec3(10.0f, -10.0f, -50.0f));
		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 288, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

//tugas 2
