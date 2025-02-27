#include "vertexBuffer.h"

VertexBuffer::VertexBuffer(unsigned int size, const void* data)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &ID);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBuffer::unBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
