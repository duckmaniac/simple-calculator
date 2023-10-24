#include "Resources.h"

EmbeddedResource load_embedded_resource(const std::string& resource_name) {
	HRSRC hRes;
	HGLOBAL hMem;
	hRes = FindResource(NULL, resource_name.c_str(), RT_RCDATA);
	hMem = LoadResource(NULL, hRes);

	return EmbeddedResource{ LockResource(hMem), SizeofResource(NULL, hRes) };
}