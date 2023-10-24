#ifndef RESOURCES_H
#define RESOURCES_H

#include "windows.h"
#include <string>

struct EmbeddedResource {
	void* p_resource; // Windows api manages memory itself.
	DWORD size_in_memory;
};

EmbeddedResource load_embedded_resource(const std::string& resource_name);

#endif // RESOURCES_H