# Configuración
TARGET       := main
MODULE_DIR   := modules
BUILD_DIR    := build
OUTPUT_DIR   := output
INO_SOURCES  := $(wildcard *.ino)
CPP_SOURCES  := $(OUTPUT_DIR)/$(notdir $(INO_SOURCES:.ino=.cpp)) $(wildcard $(MODULE_DIR)/*.cpp)
OBJECTS      := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(CPP_SOURCES)))
INCLUDES     := -I. -I$(MODULE_DIR) -I$(OUTPUT_DIR)
CXXFLAGS     := -Wall -Wextra $(INCLUDES)
CXX          := g++

# Cabecera y pie automáticos
define ARDUINO_HEADER
// Implementaciones de librerias de precompilacion para el fichero a traves de macros
#ifndef ARDUINO
#include "stdArduino.h"
#endif
// Implementacion de codigo .ino
endef
define ARDUINO_FOOTER
// Funcion main con tracking y deteccion de patrones
#ifndef ARDUINO
int main(){
	setup();
	int i=0 ;
	while(true) {
		std::cout << "Tick : "<< i++ << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(/*1000*/ 50));
		if (i > 5){
			std::cout<<"Activando Deteccion de patron"<<std::endl;
			detectPatron();
		}
		loop();
		}
	}

#endif

endef
export ARDUINO_HEADER
export ARDUINO_FOOTER

# Verbosidad
ifeq ($(V),1)
    Q :=
    VE = @true
    VR = @true
else
    Q := @
    VE = @echo
    VR = @echo "  $1"
endif

.PHONY: all clean rebuild help convert

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(call VR,LINK)
	$(Q)$(CXX) $^ -o $@

# Regla para convertir .ino a output/*.cpp
$(OUTPUT_DIR)/%.cpp: %.ino | $(OUTPUT_DIR)
	$(call VR,CONVERT $<)
	$(Q)echo "$$ARDUINO_HEADER" > $@
	$(Q)cat $< >> $@
	$(Q)echo "$$ARDUINO_FOOTER" >> $@

# Regla para compilar output/*.cpp
$(BUILD_DIR)/%.o: $(OUTPUT_DIR)/%.cpp | $(BUILD_DIR)
	$(call VR,CXX $<)
	$(Q)$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar módulos
$(BUILD_DIR)/%.o: $(MODULE_DIR)/%.cpp | $(BUILD_DIR)
	$(call VR,CXX $<)
	$(Q)$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	$(call VR,MKDIR $@)
	$(Q)mkdir -p $@

$(OUTPUT_DIR):
	$(call VR,MKDIR $@)
	$(Q)mkdir -p $@

clean:
	$(VE) "Limpiando proyecto..."
	$(Q)rm -rf $(BUILD_DIR) $(TARGET) $(OUTPUT_DIR)

rebuild: clean all

convert: $(INO_SOURCES:%.ino=$(OUTPUT_DIR)/%.cpp)

help:
	@echo "Opciones de compilación:"
	@echo "  make           - Compila el proyecto (convierte .ino automáticamente)"
	@echo "  make convert   - Solo convierte .ino a .cpp en $(OUTPUT_DIR)/"
	@echo "  make V=1       - Compila mostrando comandos completos"
	@echo "  make clean     - Elimina todos los archivos generados"
	@echo "  make rebuild   - Recompila completamente"
	@echo "  make help      - Muestra esta ayuda"
