#include "IndexBuffer.h"

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &ID);
}

IndexBuffer::IndexBuffer(unsigned int numCubes)
{
	generateData(numCubes);
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vecData.size() * sizeof(unsigned int), vecData.data(), GL_STATIC_DRAW);
}

void IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void IndexBuffer::unBind() const 
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

const unsigned int baseIndices[] = {
	0, 1, 2, 2, 3, 0, // Back face
	4, 5, 6, 6, 7, 4, // Front face
	4, 5, 1, 1, 0, 4, // Bottom face
	7, 6, 2, 2, 3, 7, // Top face
	4, 0, 3, 3, 7, 4, // Left face
	5, 1, 2, 2, 6, 5  // Right face
};

unsigned int* IndexBuffer::generateData(const unsigned int numCubes)
{
	vecData.clear();
	vecData.reserve(numCubes * 36);
	for (unsigned int i = 0; i < numCubes; i++) {
		for (unsigned int j = 0; j < 36; j++) {
			vecData.push_back(baseIndices[j] + (8 * i));
		}
	}
	return vecData.data();
}

