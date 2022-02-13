#pragma once

#include <stdint.h>

struct Requete {
	char clef[20];
	uint32_t borneId;
	char action[50];
} __attribute((packed));