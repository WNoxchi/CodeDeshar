# 6.00.1x   -   PSet 2
# Wayne H. Noxchi | 27-Jan-2016 20:52
# --------------------------------------

# --------------------------------------
# 2.3: Min Fixed Payment - Bisection Search
# Start: 28-Jan-2016 22:21 | Stop: 00:37 - 09:35 | Finish: 29-Jan-2016 10:53
# --------------------------------------

balance = 999999
annualInterestRate = 0.18

def MFP(annualInterestRate, balance):
    MIR = annualInterestRate / 12.0
    MPL = balance / 12.0
    MPU = (balance * ((1 + MIR) ** 12)) / 12.0
    newBal = balance
    guess = (MPL + MPU) / 2
    acc = 0.1
    
    while (MPL < (MPU - acc)):  # to avoid infinite loop: gap range set by accuracy
        guess = (MPL + MPU) / 2.0
        newBal = balance
        for i in range(12):
            # newBal = newBal - guess
            # newBal = newBal * (1 + MIR)
            MUB = newBal - guess
            newBal = MUB + MIR * MUB
        if newBal <= 0:     # if below zero, guess too big, set upperbound to guess
            MPU = guess
        else:               # otherwise (above zero) guess too small, lowerbound to guess
            MPL = guess
    print("Lowest Payment: %.2f" % guess)

MFP(annualInterestRate, balance)

# ---------------------------------
# OLD/GARBAGE:

# balance = 999999
# annualInterestRate = 0.18
# 
# MIR = annualInterestRate / 12.0
# MPL = balance / 12
# MPU = (balance * ((1 + MIR) ** 12)) / 12.0
# guess = (MPL + MPU) / 2
# eps = -0.3
# upBal = balance
# 
# def checkPay(guess):
#     upBal = balance
#     for i in range(12):
#         MUB = upBal - guess
#         upBal = MUB + MIR * MUB
#     return upBal
#     
# while (upBal > 0 or upBal < eps):
#     if upBal > 0:
#         MPL = guess
#         guess = (MPL + MPU) / 2
#     elif upBal < eps:
#         MPU = guess
#         guess = (MPL + MPU) / 2
# 
# print("Lowest Payment: %.2f" % guess)

# ---------------------------------

# def checkPay(guess, upBal):
#     upBal = balance
#     for i in range(12):
#         MUB = upBal - guess
#         upBal = MUB + MIR * MUB
#     return upBal
#     
# def adjustBound(guess, upBal):
#     if upBal > 0:
#         MPL = guess
#         guess = (MPL + MPU) / 2
#     elif upBal < eps:
#         MPU = guess
#         guess = (MPL + MPU) / 2
#     return guess
#     
# while (upBal > 0 or upBal < eps):
#     upBal = balance
#     upBal = checkPay(guess, upBal)
#     guess = adJustBound(guess, upBal)
#     
# print("Lowest Payment: %.2f" % guess)

# ---------------------------------

# balance = 999999
# annualInterestRate = 0.18
#
# MIR = annualInterestRate / 12.0
# MPL = balance / 12
# MPU = (balance * ((1 + MIR) ** 12)) / 12
# guess = (MPL + MPU) / 2
# eps = -0.3
# upBal = balance
#
# def checkPay(guess):
#     upBal = balance
#     for i in range(12):
#         MUB = upBal - guess
#         upBal = MUB + MIR * MUB
#     return upBal
#
# while (upBal != 0 or upBal < eps):
#     if checkPay(guess) > 0:
#         MPL = guess
#         guess = (MPL + MPU) / 2
#         upBal = balance
#     if checkPay(guess) < eps:
#         MPU = guess
#         guess = (MPL + MPU) /2
#         upBal = balance
# print("Lowest Payment: %.2f" % guess)
#
# # ----------------------
# while True
#     if checkPay(guess) > 0:
#         MPL = guess
#         guess = (MPL + MPU) / 2
#         print("MPL: %.2f" % guess)
#     if checkPay(guess) < eps:
#         MPU = guess
#         guess = (MPL + MPU) / 2
#         print("MPU: %.2f" % guess)
#     #elif checkPay(guess) == 0 and checkPay(guess) > eps:
#     #    print("Lowest Payment: %i" % guess)
#     #    break
#      #else: print("Lowest Payment: %i" % guess)
#     # else:
#     print("Lowest Payment: %.2f" % guess)
#     #     break

# --------------------------------------
# 2.2: Min Fixed Payment
# Start: 28-Jan-2016 18:58 | Stop: 1930 - 2200 | Finish: 28-Jan-2016 22:15
# --------------------------------------
# Prints 1 line: lowest payment

# balance = 3329
# annualInterestRate = 0.2

MIR = annualInterestRate / 12.0
MFMP = 10.0

def checkPayment(MFMP):
    upBal = balance
    for i in range(12):
        # print("ITER: %i" % i)
        MUB = upBal - MFMP
        upBal = MUB + MIR * MUB
        # print upBal
    return upBal
while checkPayment(MFMP) > 0:
    MFMP += 10
    checkPayment(MFMP)
print ("Lowest Payment: %i" % MFMP)

# ---------------------------------
# OLD/GARBAGE:

# def detPayment(MFMP, MIR, balance):
#     for i in range(12):
#         newBalance = balance
#         MUB = newBalance - MFMP
#         newBalance = MUB + MIR * MUB
#         return newBalance
# 
# while newBalance > 0.0:
#     detPayment(MFMP, MIR, balance)
#     MFMP += 10.0
# 
# print("Lowest Payment: %i" % MFMP)
# 
# 
# MIR = annualInterestRate / 12.0
# upBal = balance
# guess = 10
# 
# def checkPayment(guess, upBal):
#     for i in range(12):
#         MUB = upBal - guess
#         upBal = MUB + MIR * MUB
#     return upBal
# 
# while upBal > 0:
#     checkPayment(MFMP, balance)
#     MFMP += 10
# 
# print("Lowest Payment: %i" % MFMP)

# --------------------------------------
# 2.1: Paying the Minimum
# Start: 27-Jan-2016 20:53 | Finish: 27-Jan-2016 21:35
# --------------------------------------

# inputs: <balance> <annualInterestRate> <monthlyPaymentRate>

# Calc statements on monthly payment and remaining balance every month; print to
# screen. 2 digits. Print total paid that year & remaining balance at year end.

# balance = 4213
# monthlyPaymentRate = 0.04
# annualInterestRate = 0.2

# Monthly Interest Rate:
MIR = annualInterestRate / 12.0
newBalance = balance
totalPaid = 0.0
Month = 0

def displayInfo(Month, MMP, updatedBalance):
    print("Month: %i" % Month)
    print("Minimum monrthly payment: %.2f" % MMP)
    print("Remaining balance: %.2f" % newBalance)

# it's a fixed-length iteration so use a for-loop:
for i in range(12):
    Month += 1
    MMP = monthlyPaymentRate * newBalance
    MUB = newBalance - MMP
    newBalance = MUB + MIR * MUB
    totalPaid += MMP
    displayInfo(Month, MMP, newBalance)
print("Total paid: %.2f" % totalPaid)
print("Remaining balance: %.2f" % newBalance)
