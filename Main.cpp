#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using
	// In this cse its OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// That means we have only modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Ctrate a GLFWwindow object
	GLFWwindow* window = glfwCreateWindow(800, 800, "Window", NULL, NULL);
	// Checks if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introoduce window into current contex
	glfwMakeContextCurrent(window);

	//Load GLAD to configure OpenGL
	gladLoadGL();

	glViewport(0, 0, 800, 800);

	glClearColor(0.0f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//Swap back and front buffer
	glfwSwapBuffers(window);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Terminate the window
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}