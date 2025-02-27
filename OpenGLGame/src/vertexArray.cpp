#include "vertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &ID);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	bind();
	vb.bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalised, layout.stride, (const void*)offset);
		offset += element.count * vertexBufferElement::getSizeOfType(element.type);
	}
}

void VertexArray::bind() const
{
	glBindVertexArray(ID);
}

void VertexArray::unBind() const
{
	glBindVertexArray(0);
}
