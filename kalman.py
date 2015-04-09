from numpy import matrix as mat
from numpy import set_printoptions

set_printoptions(formatter={'float': lambda x:  str(x)})

def filter(x, P):
    for n in range(len(measurements)):
        
        # prediction
        x = (F * x) + u
        P = F * P * F.transpose()
        
        # measurement update
        Z = mat([measurements[n]])
        y = Z.T - (H * x)
        S = H * P * H.T + R
        K = P * H.T * S.I
        x = x + (K * y)
        P = (I - (K * H)) * P
    
    print 'x= ' + str(x)
    print "\n"
    print 'P= ' + str(P)


measurements = [[5., 10.], [6., 8.], [7., 6.], [8., 4.], [9., 2.], [10., 0.]]
initial_xy = [4., 12.]

# measurements = [[1., 4.], [6., 0.], [11., -4.], [16., -8.]]
# initial_xy = [-4., 8.]

# measurements = [[1., 17.], [1., 15.], [1., 13.], [1., 11.]]
# initial_xy = [1., 19.]

dt = 0.1

x = mat([[initial_xy[0]], [initial_xy[1]], [0.], [0.]]) # initial state (location and velocity)
u = mat([[0.], [0.], [0.], [0.]]) # external motion


P =  mat([[0., 0., 0., 0.], [0., 0., 0., 0.], [0., 0., 1000., 0.], [0., 0., 0., 1000.]])# initial uncertainty
F =  mat([[1., 0., dt, 0.], [0., 1., 0., dt], [0., 0., 1., 0.], [0., 0., 0., 1.]])# next state function
H =  mat([[1., 0, 0., 0.], [0., 1., 0., 0.]])# measurement function
R =  mat([[.1, 0.], [0., .1]])# measurement uncertainty
I = mat([[1., 0., 0., 0.], [0., 1., 0., 0.], [0., 0., 1., 0.], [0., 0., 0., 1.]]) # identity matrix


filter(x, P)

