# 2.008x Fundamentals of Manufacturing Processes - PSet 10: Cost
# Wayne H Nixalo  -   12-Jan-2017 22:21
# https://courses.edx.org/courses/course-v1:MITx+2.008x+3T2016/courseware/Cost/10-4_Problem_Set/?child=first
##################################################################
# 10-1.1 Material Cost
# Estimate the material cost per case, which is made of a PC-ABS
# plastic. Assume that 20% of the material is wasted (without
# recycling), the case is 45 grams, and the current pricing of
# this PC-ABS blend for all production volumes is 3.23 USD/kg
from math import ceil

def CostTool(Ctool, N, nT):
    """ C1
        Ctool:  cost of 1 set of tooling
        N:      total forecasted production volume
        nT:     number units each toolset can make before wearout
    """
    return (Ctool/float(N))*ceil(N/float(nT))             # C1
def CostEquip(ndot, Cmach, L, t_wo):
    """ C2
        ndot:  production rate, single machine
        Cmach: purchase cost, 1 machine
        L:     load factor; fraction productive time
        t_wo:  writeoff time (equipmnt lifetime)
    """
    return (1/float(ndot))*(Cmach/float(L*t_wo))    # C2
def CostMater(m, Cmat, f):
    """ C3
        m:      part mass
        Cmat:   material cost per unit mass
        f:      scrap fraction
    """
    return (m*Cmat)/(1 - float(f))              # C3
def CostOverh(Coh, ndot):
    """ C4
        Coh:    total cost of overhead
        ndot:   production rate
    """
    return Coh/float(ndot)               # C4

# PC-ABS plastic
waste_fraction = 0.2
part_mass = 45e-3
price_kg_PC = 3.23

C3 = CostMater(part_mass, price_kg_PC, waste_fraction)
print("10-1.1:");
print("C3 = ${}".format(round(C3, 2)))

##################################################################
# 10-1.2 Tooling Cost

alumMold_cost = 4000.
mold_lifetime = 10000

prod_vol_1 = 5000
prod_vol_2 = 15000

C15k = CostTool(alumMold_cost, prod_vol_1, mold_lifetime)
C115k = CostTool(alumMold_cost, prod_vol_2, mold_lifetime)

print("10-1.2:");
print("C_1,5k = ${}/part\nC_1,15k = ${}/part".format(\
                                round(C15k, 2), round(C115k, 2)))

##################################################################
# 10-1.3 Mold Selection

prod_vol = 50000
alum_life = 10000
steel_life = 100000

C_150kA = CostTool(alumMold_cost, prod_vol, alum_life)
C_stal = (prod_vol * C_150kA)/ceil(prod_vol/float(steel_life))

print("10-1.3:");
print("C_150k,Aluminum = ${}/part\n C_150k,Steel = ${} (max)".format(\
        round(C_150kA, 2), round(C_stal, 2)))

##################################################################
# 10-1.4 Machine Selection

inject_press = 50e6 # 50 MPA
footprint = 217e-2  # 217 cm^2
case_mass = 45e-3   # 45 grams
scrap_frac = 0.2

if case_mass + case_mass * scrap_frac > 50e-3:
    mach = 'Machine 3'
else:
    mach = 'Machine 2'

print("10-1.4:");
print(mach)

##################################################################
# 10-1.5 Machine Cost

prod_rate = 100000  # per month, 1.2M per year
inject_cycle_time = 1 # minutes
mach_uptime = 0.8
mach_price = 30000
writeoff = 10   # years

mach_monthly_cap = (inject_cycle_time * 60 * 24 * 30)

machines = prod_rate / (mach_monthly_cap * mach_uptime)
machines = int(ceil(machines))

# for a year. uptime factored into # machines --> set to 1
C2 = CostEquip(prod_rate * 12, mach_price * machines, 1, writeoff)

print("10-1.5:");
print("Number of machines: {}. C2 = ${}/part.".format(\
        machines, round(C2, 4)))

##################################################################
# 10-1.6 Overhead Cost

prod_rate = int(1.2e6)
labor_hourly_cost = 60
# labor_util = 0.75
labor_util = 1.0
cost_mach = 6
machines = 3
labor_daily_hours = 24

labor_yearly_cost = labor_hourly_cost * labor_daily_hours * 365
cost_mach_year = cost_mach * 24 * 365

# I thought we're factoring labor utilization (3/4 machines -> 0.75) but guess not. set to 1.
tot_overhead = (labor_yearly_cost / labor_util) + (machines * cost_mach_year)
C4 = CostOverh(tot_overhead, prod_rate)

print("10-1.6:")
print("C4 = ${}/part.".format(round(C4, 2)))
