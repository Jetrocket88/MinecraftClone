#pragma once

#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

class IndexBuffer{
public:
	unsigned int ID;
	unsigned int count;

	IndexBuffer(unsigned int count, const unsigned int* data);
	~IndexBuffer();

	void bind() const;
	void unBind()const;
private:

};

#endif 
