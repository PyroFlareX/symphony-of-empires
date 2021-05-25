#ifndef PROVINCE_H
#define PROVINCE_H

#include <stdint.h>
#include <string>
#include "pop.hpp"

#define PROVINCE_DISPUTED (size_t)-2
#define PROVINCE_NO_ONWER (size_t)-1

typedef uint16_t ProvinceId;

class World;
class Nation;
class Industry;
class Product;
class Province {
public:
	~Province();

	ProvinceId get_id(const World& world);
	void add_industry(World * world, Industry * industry);
	void remove_industry(World * world, Industry * industry);

	std::string name;
	std::string ref_name;
	uint32_t color;
	
	uint64_t population;
	float budget;

	size_t n_tiles = 0;
	size_t min_x = 65532;
	size_t min_y = 65532;
	size_t max_x = 0;
	size_t max_y = 0;
	
	size_t owner_id = PROVINCE_NO_ONWER;
	
	float supply_limit;
	float supply_rem;
	
	size_t worker_pool;

	std::vector<Nation *> owners;
	std::vector<Province *> neighbours;
	
	std::vector<size_t> stockpile;
	std::vector<Industry *> industries;
	std::vector<Product *> products;
    std::vector<Pop *> pops;
};

#endif
