#pragma once

#ifndef VERTEX_BUFFER_H 
#define VERTEX_BUFFER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

class VertexBuffer{
public:
	unsigned int ID;

	VertexBuffer(unsigned int size, const void* data);
	~VertexBuffer();

	void bind() const;
	void unBind() const;
private:

};

#endif

