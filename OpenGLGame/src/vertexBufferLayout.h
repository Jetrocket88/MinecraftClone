#pragma once

#include <vector>
#include <glad/glad.h>

struct vertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalised;

	static unsigned int getSizeOfType(unsigned int type) {
		switch (type) {
		case GL_FLOAT:		   return 4;
		case GL_UNSIGNED_INT:  return 4;
		case GL_UNSIGNED_BYTE: return 1;
		}
	
		return 0;
	}
};

class VertexBufferLayout {
public:
	std::vector<vertexBufferElement> elements;
	unsigned int stride;


	VertexBufferLayout()
		:stride(0) { }


	template <typename T>
	void Push(unsigned int count) {
		static_assert(false, "Unsupported Type");
	}

	template<>
	void Push<float>(unsigned int count) {
		elements.push_back({ GL_FLOAT, count, GL_FALSE });
		stride += count * vertexBufferElement::getSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count) {
		elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		stride += count * vertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count) {
		elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE});
		stride += count * vertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
	}
	inline const std::vector<vertexBufferElement>& GetElements() const { return elements; };

};
