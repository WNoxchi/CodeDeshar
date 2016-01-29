# 6.00.1x   -   PSet 2
# Wayne H. Noxchi | 27-Jan-2016 20:52
# --------------------------------------

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
