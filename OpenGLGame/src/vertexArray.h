#pragma once

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "vertexBufferLayout.h"

class VertexArray{
public:
	unsigned int ID;

	VertexArray();
	~VertexArray();

	void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void bind() const;
	void unBind() const;
private:

};

#endif