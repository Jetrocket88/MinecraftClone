#pragma once

enum blockType {
	BLOCK_AIR,
	BLOCK_GRASS,
	BLOCK_DIRT
};

#ifndef BLOCK_H 
#define BLOCK_H 

class block {
	block();
public:
	blockType type;

private:
};


#endif 
