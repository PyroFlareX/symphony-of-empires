#ifndef MAP_H
#define MAP_H

#include <stddef.h>
#include <GL/gl.h>
#include "world.hpp"

typedef enum {
	MAP_POLITICAL,
	MAP_PROVINCIAL,
	MAP_TOPOGRAPHIC,
}Map_Mode;

class Map {
public:
	Map(World * world, Map_Mode mode);
	~Map();
	
	void quad_create(size_t qx, size_t qy);
	void quad_update(size_t x, size_t y);

	World * world;
	size_t quad_size;
	size_t n_horz_quads;
	size_t n_vert_quads;
	GLuint * quads_gl_list_num;
	Map_Mode mode;
};

#endif
