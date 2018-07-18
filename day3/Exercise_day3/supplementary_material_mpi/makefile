### CPP compiler wrapper
CXX=mpicxx

### Optimization flags
FFLAGS=-O3

#######################################################################	

all: broadcast.exec ar.exec scatter.exec

#######################################################################	

## Brodcast.opp
broadcast.exec: broadcast.cpp
	$(CXX) $(FFLAGS) broadcast.cpp -o broadcast.exec

## allreduce.cpp
ar.exec: allreduce.cpp
	$(CXX) $(FFLAGS) allreduce.cpp -o ar.exec
	
## scatter.cpp
scatter.exec: scatter.cpp
	$(CXX) $(FFLAGS) scatter.cpp -o scatter.exec
	
#######################################################################	

clean :
	rm -f *.exec

#######################################################################	
