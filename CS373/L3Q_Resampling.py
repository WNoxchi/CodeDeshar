# CS 373 - AI for Robotics - Ls3 Particle Filters - Resampling
# WNx   -   2017-Apr-14 14:52

# Algorithm: Particle Filter Resampling
# index = U[1..N]
# β = 0
# for i = 1..N
#     β <- β + U{0..2*w_max}
#     if w_index < β
#         β <- β - w_index
#         index <- index + 1
#     else
#         pick P_index

# Pseudocode:
# while w[index] < B:
#     B = B - w[index]
#     index = index + 1
# select p[index]


tot = sum(w)
Wmax = max(w)
index = 0
B = 0
for i in range(N):
    B = (B + 2*Wmax) % tot
    while w[index] < B:
        B -= w[index]
        index = (index + 1) % N
    p3.append(p[index])

# NOTE: aha, so B is a random distribution between 0 and 2*Wmax
# Staff answer:
p3 = []
index = int(random.random() * N)
beat = 0.0
mw = max(W)
for i in range(N):
    beta += random.random() * 2.0 * mw
    while beta > w[index]:
        beta -= w[index]
        index = (index + 1) % N
    p3.append(p[index])
p = p3
