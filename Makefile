CC = g++
CFLAGS_local = -DTEXTOUTPUT -lm -O3 -fopenmp -ffast-math

PROP = src/prop.cpp
SRC = src/vec2.cpp
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

