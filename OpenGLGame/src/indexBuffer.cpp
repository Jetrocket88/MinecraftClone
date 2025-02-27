#include "IndexBuffer.h"


IndexBuffer::IndexBuffer(unsigned int c, const unsigned int* data)
	:count(c)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count, data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &ID);
}

void IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void IndexBuffer::unBind() const 
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

