 // #include <GL/glew.h>
 // #include <GLFW/glfw3.h>
 // #include <iostream>
 // #include <glm/glm.hpp>
 // #include <glm/gtc/matrix_transform.hpp>
 // #include <glm/gtc/type_ptr.hpp>
 // #include "math.h"
 // using namespace glm;
 // using namespace std;
 //  //Function prototypes
 // void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
 // // Window dimensions
 // const GLuint WIDTH = 800, HEIGHT = 600;
 // // Shaders
 // const GLchar* vertexShaderSource = "#version 330 core\n"
 // "layout (location = 0) in vec3 position;\n"
 // "layout (location = 1) in vec3 color;\n"
 // "out vec3 ourColor;\n"
 // "uniform mat4 transform;\n"
 // "void main()\n"
 // "{\n"
 // "gl_Position = transform * vec4(position, 1.0f);\n"
 // "ourColor = color;\n"
 // "}\0";
 // const GLchar* fragmentShaderSource = "#version 330 core\n"
 // "in vec3 ourColor;\n"
 // "out vec4 color;\n"
 // "void main()\n"
 // "{\n"
 // "color = vec4(ourColor, 1.0f);\n"
 // "}\n\0";
 //  //The MAIN function, from here we start the application and run the game loop
 // int main()
 // {
 // 	 //Init GLFW
 // 	glfwInit();
 // 	 //Set all the required options for GLFW
 // 	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
 // 	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
 // 	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 // 	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
 // 	 //Create a GLFWwindow object that we can use for GLFW's functions
 // 	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "TRIANGLE", nullptr, nullptr);
 // 	glfwMakeContextCurrent(window);
 // 	 //Set the required callback functions
 // 	glfwSetKeyCallback(window, key_callback);
 // 	 //Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
 // 	glewExperimental = GL_TRUE;
 // 	 //Initialize GLEW to setup the OpenGL Function pointers
 // 	glewInit();
 // 	 //Define the viewport dimensions
 // 	glViewport(0, 0, WIDTH, HEIGHT);
 // 	 //Build and compile our shader program
 // 	 //Vertex shader
 // 	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
 // 	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
 // 	glCompileShader(vertexShader);
 // 	 //Check for compile time errors
 // 	GLint success;
 // 	GLchar infoLog[512];
 // 	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
 // 	if (!success)
 // 	{
 // 		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
 // 		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
 // 	}
 // 	 Fragment shader
 // 	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
 // 	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
 // 	glCompileShader(fragmentShader);
 // 	 Check for compile time errors
 // 	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
 // 	if (!success)
 // 	{
 // 		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
 // 		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
 // 	}
 // 	 Link shaders
 // 	GLuint shaderProgram = glCreateProgram();
 // 	glAttachShader(shaderProgram, vertexShader);
 // 	glAttachShader(shaderProgram, fragmentShader);
 // 	glLinkProgram(shaderProgram);
 // 	 Check for linking errors
 // 	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
 // 	if (!success) {
 // 		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
 // 		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
 // 	}
 // 	glDeleteShader(vertexShader);
 // 	glDeleteShader(fragmentShader);
 // 	 Set up vertex data (and buffer(s)) and attribute pointers
 // 	GLfloat vertices[] = {
 // 		 Positions // Colors
 // 		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Right
 // 		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // Bottom Left
 // 		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // Top
 // 	};
 // 	glm::mat4 trans;
 // 	trans = glm::rotate(trans, 90.0f, glm::vec3(0.0, 0.0, 1.0));
 // 	GLuint VBO, VAO;
 // 	glGenVertexArrays(1, &VAO);
 // 	glGenBuffers(1, &VBO);
 // 	 Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
 // 	glBindVertexArray(VAO);
 // 	glBindBuffer(GL_ARRAY_BUFFER, VBO);
 // 	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
 // 	 Position attribute
 // 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
 // 	glEnableVertexAttribArray(0);
 // 	 Color attribute
 // 	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
 // 	glEnableVertexAttribArray(1);
 // 	glBindVertexArray(0); // Unbind VAO
 // 	 Game loop
 // 	while (!glfwWindowShouldClose(window))
 // 	{
 // 		 Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
 // 		glfwPollEvents();
 // 		 Render
 // 		 Clear the colorbuffer
 // 		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
 // 		glClear(GL_COLOR_BUFFER_BIT);
 // 		 Draw the triangle
 // 		glUseProgram(shaderProgram);
 // 		glm::mat4 transform;
 // 		transform=glm::translate(transform, glm::vec3(0.5f,-0.5f,0.0f));
 // 		transform = glm::rotate(transform, 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
 // 		GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
 // 		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
 // 		glBindVertexArray(VAO);
 // 		glDrawArrays(GL_TRIANGLES, 0, 3);
 // 		glBindVertexArray(0);
 // 		 Swap the screen buffers
 // 		glfwSwapBuffers(window);
 // 	}
 // 	 Properly de-allocate all resources once they've outlived their purpose
 // 	glDeleteVertexArrays(1, &VAO);
 // 	glDeleteBuffers(1, &VBO);
 // 	 Terminate GLFW, clearing any resources allocated by GLFW.
 // 	glfwTerminate();
 // 	return 0;
 // }
 //  Is called whenever a key is pressed/released via GLFW
 // void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
 // {
 // 	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
 // 		glfwSetWindowShouldClose(window, GL_TRUE);
 // }


//#include <iostream>
//// GLEW
//#include <GL/glew.h>
//// GLFW
//#include <GLFW/glfw3.h>
//// Other Libs
//#include <SOIL.h>
//// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//// Other includes
//#include "myshader.h"
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void create_texture(const char get_file[14], GLuint& texture);
//void triangle(GLuint& VAO, GLuint& VBO); //GLuint& EBO
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Triangle", nullptr, nullptr);
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
//	Shader ourShader("vertex.vs", "fragment.frag");
//	// Set GL Array and handle with Shader Class
//	GLuint VAO, VBO;
//	triangle(VAO, VBO);
//	while (!glfwWindowShouldClose(window))
//	{
//		// Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
//		glfwPollEvents();
//		// Render
//		// Clear the color buffer
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		// Activate shader
//		ourShader.Use();
//		//Transformation
//		glm::mat4 model;
//		glm::mat4 view;
//		glm::mat4 projection;
//		model = glm::rotate(model, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
//		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
//		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		// Get their uniform location
//		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
//		// Pass them to the shaders
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		// Draw container
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//		// Swap the screen buffers
//		glfwSwapBuffers(window);
//	}
//	// Properly de-allocate all resources once they've outlived their purpose
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	// Terminate GLFW, clearing any resources allocated by GLFW.
//	glfwTerminate();
//	return 0;
//}
//void triangle(GLuint& VAO, GLuint& VBO) //GLuint &EBO
//{
//	GLfloat vertices[] = {
//		// Positions //Colors
//		0.5f,-0.5f, 0.0f, 1.0f, 0.0f, 0.0f, //Left
//		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, //Right
//		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f //Top
//	};
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	// glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// Position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	//Color Attrib
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0); // Unbind VAO
//}
//// Function that can create texture
//void create_texture(const char get_file[14], GLuint &texture) {
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
//		// Set our texture parameters
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	// Set texture filtering
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	// Load, create texture and generate mipmaps
//	int width, height;
//	unsigned char* image = SOIL_load_image(get_file, &width, &height, 0, SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	SOIL_free_image_data(image);
//	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
//}
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}

//BELUM SELESAI

#include <iostream>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// Other Libs
#include <SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// Other includes
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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
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
	Shader ourShader("vertex.vs", "fragment.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions // Colors // Texture Coords
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // Top Left
	};
	GLuint indices[] = { // Note that we start from 0!
	0, 1, 3, // First Triangle
	1, 2, 3 // Second Triangle
	};
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0); // Unbind VAO
	// Load and create a texture
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
		// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT(usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load image, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("lemari.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Bind Texture
		glBindTexture(GL_TEXTURE_2D, texture);
		// Activate shader
		ourShader.Use();

		// Draw container
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

#include <iostream>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// Other Libs
#include <SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// Other includes
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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr,
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
	Shader ourShader("myver.waf", "fragment.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions // Colors // Texture Coords
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // Top Left
	};
	GLuint indices[] = { // Note that we start from 0!
	0, 1, 3, // First Triangle
	1, 2, 3 // Second Triangle
	};
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 *
		sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 *
		sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0); // Unbind VAO
	// Load and create a texture
	GLuint texture1;
	GLuint texture2;
	// ====================
	// Texture 1
	// ====================
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
		// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("lemari.png", &width, &height, 0,
		SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,
		image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
		// ===================
		// Texture 2
		// ===================
		glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	image = SOIL_load_image("smile.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Activate shader
		ourShader.Use();
		// Bind Textures using texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture2"), 1);


		// Draw container
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}