# debugging how to pull a specific digit from a float - 2017-Apr-14 11:35 - WNx

def pulldigit(num, order=1e1):
    x = ((num % order)/(order/10))
    # if round(x) - x < 0.0001:
    #     return round(x)
    # else: return int(x)
    return int(x%10)

t = [0.43157991963681974, 0.4139567031425334]
# t = [0.00019999999999999, 0.1]
d = 10
for j in range(len(t)):
    print(t[j])
    for i in range(d):
        print(pulldigit(t[j],10**(-d + i + 1)))
