### CPP compiler wrapper
CXX=mpicxx

### Optimization flags
FFLAGS=-O3

#######################################################################	

all: broadcast.exec

#######################################################################	

## Brodcast.opp
broadcast.exec: broadcast.cpp
	$(CXX) $(FFLAGS) broadcast.cpp -o broadcast.exec

## Example 1a
#1a.hello_world_mpi_cpp.exec: 1a.hello_world_mpi.cpp
#	$(CXX) $(FFLAGS) 1a.hello_world_mpi.cpp -o 1a.hello_world_mpi_cpp.exec
	
	
#######################################################################	

clean :
	rm -f *.exec

#######################################################################	
