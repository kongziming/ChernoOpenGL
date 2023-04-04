#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>

#include "IndexBuffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "VertexArray.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		return 0;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	{
		float positions[] = {
		-0.5f, -0.5f, 0.0f, 0.0f,	// 0
		0.5f, -0.5f, 1.0f, 0.0f,	// 1
		0.5f, 0.5f, 1.0f, 1.0f,		// 2
		-0.5f, 0.5f, 0.0f, 1.0f		// 3
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.push<float>(2);
		layout.push<float>(2);
		va.addBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		//glm::mat4 proj = glm::ortho(-2.0, 2.0, -1.5, 1.5, -1.0, 1.0);
		glm::mat4 proj = glm::ortho(-4.0, 4.0, -3.0, 3.0, -1.0, 1.0);

		std::string filePath = SRC_PATH;
		Shader shader(filePath + "/basic.shader");
		shader.bind();
		shader.setUniform4f("u_Color", 1.0f, 0.3f, 0.4f, 1.f);
		shader.setUniformMat4f("u_MVP", proj);

		Texture texture(filePath + "/images/head.png");
		texture.bind();
		shader.setUniform1i("u_Texture", 0);
		glGetError();

		va.unBind();
		vb.unBind();
		ib.unBind();
		shader.unBind();

		Renderer renderer;

		float r = 0.f;
		float increment = 0.05f;
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			renderer.clear();

			shader.bind();
			shader.setUniform4f("u_Color", r, 0.3f, 0.8f, 1.f);

			renderer.draw(va, ib, shader);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

			if (r > 1.f)
			{
				increment = -0.05f;
			}
			else if (r < 0.f)
			{
				increment = 0.05f;
			}
			r += increment;

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}
