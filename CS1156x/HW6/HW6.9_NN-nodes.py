# CS1156x - HW6 - Neural Networks, LinReg w/ Regularization
# Wayne H. Nixalo - 30-Dec-2016 20:52

def calculate_weights(layer_nodes):
    """Calculate the number of weights required for a neural network,
       where layer_nodes contains the number of nodes for each layer,
       excluding bias units."""
    n = len(layer_nodes)
    total = 0
    for i in range(n-1):
        prev = layer_nodes[i]+1     # add 1 to include bias unit
        curr = layer_nodes[i+1]
        total += prev*curr
        print("Layer {}: d+1={} -> {} = {}".format(i+1, prev, curr, prev*curr))
    return total

# code from: https://nathanielng.github.io/machine-learning/perceptron/regularization.html

# Terminal Output for 6.8, 6.9, 6.10:

# calculate_weights(layer_nodes = [9, 35, 1])
# Layer 1: d+1=10 -> 35 = 350
# Layer 2: d+1=36 -> 1 = 36
# Out[11]:
# 386
# calculate_weights(layer_nodes = [9, 17, 17, 1])
# Layer 1: d+1=10 -> 17 = 170
# Layer 2: d+1=18 -> 17 = 306
# Layer 3: d+1=18 -> 1 = 18
# Out[12]:
# 494
# calculate_weights(layer_nodes = [9, 18, 16, 1])
# Layer 1: d+1=10 -> 18 = 180
# Layer 2: d+1=19 -> 16 = 304
# Layer 3: d+1=17 -> 1 = 17
# Out[13]:
# 501
# calculate_weights(layer_nodes = [9, 19, 15, 1])
# Layer 1: d+1=10 -> 19 = 190
# Layer 2: d+1=20 -> 15 = 300
# Layer 3: d+1=16 -> 1 = 16
# Out[14]:
# 506
# calculate_weights(layer_nodes = [9, 20, 14, 1])
# Layer 1: d+1=10 -> 20 = 200
# Layer 2: d+1=21 -> 14 = 294
# Layer 3: d+1=15 -> 1 = 15
# Out[15]:
# 509
# calculate_weights(layer_nodes = [9, 21, 13, 1])
# Layer 1: d+1=10 -> 21 = 210
# Layer 2: d+1=22 -> 13 = 286
# Layer 3: d+1=14 -> 1 = 14
# Out[16]:
# 510
# calculate_weights(layer_nodes = [9, 22, 12, 1])
# Layer 1: d+1=10 -> 22 = 220
# Layer 2: d+1=23 -> 12 = 276
# Layer 3: d+1=13 -> 1 = 13
# Out[17]:
# 509
# calculate_weights(layer_nodes = [9, 11, 11, 11, 1])
# Layer 1: d+1=10 -> 11 = 110
# Layer 2: d+1=12 -> 11 = 132
# Layer 3: d+1=12 -> 11 = 132
# Layer 4: d+1=12 -> 1 = 12
# Out[18]:
# 386
# calculate_weights(layer_nodes = [9, 21, 13, 1])
# Layer 1: d+1=10 -> 21 = 210
# Layer 2: d+1=22 -> 13 = 286
# Layer 3: d+1=14 -> 1 = 14
# Out[19]:
# 510
# calculate_weights(layer_nodes = [9, 35, 1])
# Layer 1: d+1=10 -> 35 = 350
# Layer 2: d+1=36 -> 1 = 36
# Out[20]:
# 386
# calculate_weights(layer_nodes = [9, 17, 17, 1])
# Layer 1: d+1=10 -> 17 = 170
# Layer 2: d+1=18 -> 17 = 306
# Layer 3: d+1=18 -> 1 = 18
# Out[21]:
# 494
# calculate_weights(layer_nodes = [9, 11, 11, 11, 1])
# Layer 1: d+1=10 -> 11 = 110
# Layer 2: d+1=12 -> 11 = 132
# Layer 3: d+1=12 -> 11 = 132
# Layer 4: d+1=12 -> 1 = 12
# Out[22]:
# 386
# calculate_weights(layer_nodes = [9, 8, 8, 8, 8, 1])
# Layer 1: d+1=10 -> 8 = 80
# Layer 2: d+1=9 -> 8 = 72
# Layer 3: d+1=9 -> 8 = 72
# Layer 4: d+1=9 -> 8 = 72
# Layer 5: d+1=9 -> 1 = 9
# Out[23]:
# 305
# calculate_weights(layer_nodes = [9] + ([1]*18) + [1])
# Layer 1: d+1=10 -> 1 = 10
# Layer 2: d+1=2 -> 1 = 2
# Layer 3: d+1=2 -> 1 = 2
# Layer 4: d+1=2 -> 1 = 2
# Layer 5: d+1=2 -> 1 = 2
# Layer 6: d+1=2 -> 1 = 2
# Layer 7: d+1=2 -> 1 = 2
# Layer 8: d+1=2 -> 1 = 2
# Layer 9: d+1=2 -> 1 = 2
# Layer 10: d+1=2 -> 1 = 2
# Layer 11: d+1=2 -> 1 = 2
# Layer 12: d+1=2 -> 1 = 2
# Layer 13: d+1=2 -> 1 = 2
# Layer 14: d+1=2 -> 1 = 2
# Layer 15: d+1=2 -> 1 = 2
# Layer 16: d+1=2 -> 1 = 2
# Layer 17: d+1=2 -> 1 = 2
# Layer 18: d+1=2 -> 1 = 2
# Layer 19: d+1=2 -> 1 = 2
# Out[24]:
# 46