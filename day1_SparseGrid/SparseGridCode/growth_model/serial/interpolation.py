#======================================================================
#
#     This routine interfaces with the TASMANIAN Sparse grid
#     The crucial part is 
#
#     aVals[iI]=solver.initial(aPoints[iI], n_agents)[0]  
#     => at every gridpoint, we solve an optimization problem
#
#     Simon Scheidegger, 11/16 ; 07/17
#======================================================================

import TasmanianSG
import numpy as np
from parameters import *
import nonlinear_solver_initial as solver
from mpi4py import MPI
from mpi4py.MPI import ANY_SOURCE

#======================================================================

def sparse_grid(n_agents, iDepth):
    
    grid  = TasmanianSG.TasmanianSparseGrid()

    k_range=np.array([k_bar, k_up])

    ranges=np.empty((n_agents, 2))


    for i in range(n_agents):
        ranges[i]=k_range

    iDim=n_agents

    grid.makeLocalPolynomialGrid(iDim, iOut, iDepth, which_basis, "localp")
    grid.setDomainTransform(ranges)

    aPoints=grid.getPoints()
    print(aPoints)
    iNumP1=aPoints.shape[0]
    aVals=np.empty([iNumP1, 1])
    

    ####################################
    # # MPI PROCESS
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    total_num_threads =  comm.Get_size()
    # Divide range 
    a0 = 0  ## range from (0,iNumP1)
    step = (iNumP1 - a0) / total_num_threads
    
    print('hello from rank', rank)
    local_a = a0 + (step * rank)
    local_b = local_a + step
    ####################################
    counts = comm.gather(step, root=0)
    local_vals =     

    C = None
    if rank == 0:
        C = numpy.zeros([iDim, iDepth], dtype=’float’)

    rowtype = MPI.INT.Create_contiguous(iDepth)
    rowtype.Commit()

    comm.Gatherv(sendbuf=[Cl, MPI.INT],
    recvbuf=[C, (counts, None), rowtype], root=0)

    for iI in range(local_a, local_b):
        aVals[iI]=solver.initial(aPoints[iI], n_agents)[0] 
        # v=aVals[iI]*np.ones((1,1))
        # to_print=np.hstack((aPoints[iI].reshape(1,n_agents), v))
        # np.savetxt(file, to_print, fmt='%2.16f')
    recv_VF = None
    comm.send(aVals[local_a:local_b], dest=0, tag=rank)
    if rank == 0:
        recv_VF = np.zeros_like(aVals)
        for iWorker in range(total_num_threads+1):
            pass
    # file=open("comparison0.txt", 'w')
    # file.close()
    # grid.loadNeededPoints()
    
    f=open("grid.txt", 'w')
    np.savetxt(f, aPoints, fmt='% 2.16f')
    f.close()
    
    return grid
#======================================================================

