#pragma once

#ifndef _TREE_H_
#define _TREE_H_


#define GLFW_INCLUDE_GLEXT
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Node.h"
#include "Window.h"
#include "LSystem.h"
#include <utility>
#include <unordered_map>
#include <algorithm>

class Tree :
	public Node
{
private:
	std::vector<GLuint> indices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<glm::vec2> texels;
	glm::vec3 color;
	GLuint shader;

	glm::vec3 currentPos;
	glm::vec3 currentDir;

public:
	Tree(GLuint shader, LSystem * treeSystem, glm::vec3 startPos, GLint treeType);
	~Tree();

	void generateVertices(std::string);
	void randomize(int range);
	void update();
	void rotate(GLfloat angle, glm::vec3 axis);
	void rotateDir(GLfloat angle, glm::vec3 axis);
	void draw(GLuint shaderProgram, glm::mat4 C);
	void shiftAndResizeModel();
	void updateMinMaxCoordinates(float x, float y, float z);
	void updateBuffers();

	std::vector < std::pair < glm::vec3, glm::vec3 >> positionStack; // keeps track of prev position and direction

	glm::mat4 toWorld;

	LSystem * treeSystem;
	GLint recursions;
	GLuint VBO, VAO, EBO, colorBuffer, texBuffer;
	GLint treeType;
	std::string language;
	glm::vec3 startPos;
};

#endif