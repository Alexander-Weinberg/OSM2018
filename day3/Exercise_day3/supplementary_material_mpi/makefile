### CPP compiler wrapper
CXX=mpicxx

### Optimization flags
FFLAGS=-O3

#######################################################################	

all: broadcast.exec ar.exec 

#######################################################################	

## Brodcast.opp
broadcast.exec: broadcast.cpp
	$(CXX) $(FFLAGS) broadcast.cpp -o broadcast.exec

## allreduce.cpp
ar.exec: allreduce.cpp
	$(CXX) $(FFLAGS) allreduce.cpp -o ar.exec
## Example 1a
#1a.hello_world_mpi_cpp.exec: 1a.hello_world_mpi.cpp
#	$(CXX) $(FFLAGS) 1a.hello_world_mpi.cpp -o 1a.hello_world_mpi_cpp.exec
	
	
#######################################################################	

clean :
	rm -f *.exec

#######################################################################	
