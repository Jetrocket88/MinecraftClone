#pragma once

#include "block.h"

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#ifndef CHUNK_H 
#define CHUNK_H 

class chunk{
public:
	static const int CHUNK_SIZE = 16;
	static const int CHUNK_HEIGHT = 256;
	
	block blocks[CHUNK_SIZE][CHUNK_HEIGHT][CHUNK_SIZE];

	void generateMesh(std::vector<glm::vec3>& vertices, std::vector<unsigned int>& indices) {
		for (int i = 0; i < CHUNK_SIZE; i++) {
			for (int j = 0; j < CHUNK_SIZE; j++) {
				for (int k = 0; k < CHUNK_SIZE; k++) {
			
				}
			}	
		}
	}
private:
	void addBlockToMesh(int x, int y, int z, std::vector<glm::vec3>& vertices, std::vector<unsigned int>& indices) {

	}
};


#endif 
