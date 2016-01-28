# 6.00.1x   -   PSet 2
# Wayne H. Noxchi | 27-Jan-2016 20:52
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
