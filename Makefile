detected_OS := $(shell uname)

ifeq ($(detected_OS),Linux)
	CC = g++
endif
ifeq ($(detected_OS), Darwin)
	CC = g++-11
endif

CFLAGS_local = -lm -O3 -fopenmp -ffast-math 

PROP = src/prop.cpp
SRC = src/vec2.cpp src/test.cpp src/radiator.cpp src/detector.cpp src/utils.cpp src/target.cpp src/param.cpp src/interpolation.cpp
SRC_PROP = $(PROP) $(SRC)
INCLUDE = ./include/

all: Propagation

Propagation: $(SRC_PROP)
	mkdir -p results
	$(CC) $(SRC_PROP) -I$(INCLUDE) $(CFLAGS_local) -o PropagationHHG

run:
	./PropagationHHG

clean:
	rm -rf results/
	rm -rf PropagationHHG
	rm -rf output_*
	rm -rf slurm*

