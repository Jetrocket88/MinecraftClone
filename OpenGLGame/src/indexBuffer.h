#pragma once

#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include <glad/glad.h>

class IndexBuffer{
public:
	unsigned int ID;
	unsigned int count;
	unsigned int* data;

	IndexBuffer(unsigned int numCubes);
	~IndexBuffer();

	void bind() const;
	void unBind()const;
private:
	unsigned int* generateData(const unsigned int numCubes);
	std::vector<unsigned int> vecData;
};

#endif 
