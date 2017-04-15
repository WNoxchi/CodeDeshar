# Problem Set 3: Simulating the Spread of Disease and Virus Population Dynamics
# Wayne H Nixalo

import random
import pylab

'''
Begin helper code
'''

class NoChildException(Exception):
    """
    NoChildException is raised by the reproduce() method in the SimpleVirus
    and ResistantVirus classes to indicate that a virus particle does not
    reproduce. You can use NoChildException as is, you do not need to
    modify/add any code.
    """

'''
End helper code
'''

#
# PROBLEM 1 - 06-Dec-2016 16:58 - 17:39
#
class SimpleVirus(object):

    """
    Representation of a simple virus (does not model drug effects/resistance).
    """
    def __init__(self, maxBirthProb, clearProb):
        """
        Initialize a SimpleVirus instance, saves all parameters as attributes
        of the instance.
        maxBirthProb: Maximum reproduction probability (a float between 0-1)
        clearProb: Maximum clearance probability (a float between 0-1).
        """

        self.maxBirthProb = maxBirthProb
        self.clearProb = clearProb

    def getMaxBirthProb(self):
        """
        Returns the max birth probability.
        """
        return self.maxBirthProb

    def getClearProb(self):
        """
        Returns the clear probability.
        """
        return self.clearProb

    def doesClear(self):
        """ Stochastically determines whether this virus particle is cleared from the
        patient's body at a time step.
        returns: True with probability self.getClearProb and otherwise returns
        False.
        """

        if random.random() < self.clearProb:
            return True
        else:
            return False


    def reproduce(self, popDensity):
        """
        Stochastically determines whether this virus particle reproduces at a
        time step. Called by the update() method in the Patient and
        TreatedPatient classes. The virus particle reproduces with probability
        self.maxBirthProb * (1 - popDensity).

        If this virus particle reproduces, then reproduce() creates and returns
        the instance of the offspring SimpleVirus (which has the same
        maxBirthProb and clearProb values as its parent).

        popDensity: the population density (a float), defined as the current
        virus population divided by the maximum population.

        returns: a new instance of the SimpleVirus class representing the
        offspring of this virus particle. The child should have the same
        maxBirthProb and clearProb values as this virus. Raises a
        NoChildException if this virus particle does not reproduce.
        """

        if random.random() < ((self.maxBirthProb)*(1 - popDensity)):
            return SimpleVirus(self.maxBirthProb, self.clearProb)
        else:
            raise NoChildException



class Patient(object):
    """
    Representation of a simplified patient. The patient does not take any drugs
    and his/her virus populations have no drug resistance.
    """

    def __init__(self, viruses, maxPop):
        """
        Initialization function, saves the viruses and maxPop parameters as
        attributes.

        viruses: the list representing the virus population (a list of
        SimpleVirus instances)

        maxPop: the maximum virus population for this patient (an integer)
        """

        self.viruses = viruses
        self.maxPop = maxPop

    def getViruses(self):
        """
        Returns the viruses in this Patient.
        """
        return self.viruses


    def getMaxPop(self):
        """
        Returns the max population.
        """
        return self.maxPop


    def getTotalPop(self):
        """
        Gets the size of the current total virus population.
        returns: The total virus population (an integer)
        """

        return len(self.viruses)
        # virus = 0
        # for vir in self.viruses:
        #     virus += 1
        # return virus


    def update(self):
        """
        Update the state of the virus population in this patient for a single
        time step. update() should execute the following steps in this order:

        - Determine whether each virus particle survives and updates the list
        of virus particles accordingly.

        - The current population density is calculated. This population density
          value is used until the next call to update()

        - Based on this value of population density, determine whether each
          virus particle should reproduce and add offspring virus particles to
          the list of viruses in this patient.

        returns: The total virus population at the end of the update (an
        integer)
        """

        for virus in self.viruses:
            if virus.doesClear():
                self.viruses.remove(virus)

        popDensity = self.getTotalPop() / float(self.maxPop)

        for virus in self.viruses:
            try:
                self.viruses.append(virus.reproduce(popDensity))
            except NoChildException:
                pass

        return len(self.viruses)

        # virus = 0
        # for vir in self.getTotalPop():
        #     if random.random() > self.doesClear():
        #         virus += 1
        #     else:
        #         self.viruses.remove(vir)
        # self.popDensity = virus / self.getMaxPop()
        # self.viruses.add(self.reproduce(popDensity))

#
# PROBLEM 2 - 06-Dec-2016 18:22
#
def simulationWithoutDrug(numViruses, maxPop, maxBirthProb, clearProb,
                          numTrials):
    """
    Run the simulation and plot the graph for problem 3 (no drugs are used,
    viruses do not have any drug resistance).
    For each of numTrials trial, instantiates a patient, runs a simulation
    for 300 timesteps, and plots the average virus population size as a
    function of time.

    numViruses: number of SimpleVirus to create for patient (an integer)
    maxPop: maximum virus population for patient (an integer)
    maxBirthProb: Maximum reproduction probability (a float between 0-1)
    clearProb: Maximum clearance probability (a float between 0-1)
    numTrials: number of simulation runs to execute (an integer)
    """

    results, timeSteps = [], 300
    for trial in range(numTrials):
        # instantiate patient
        virus = SimpleVirus(maxBirthProb, clearProb)
        viruses = [virus for vir in range(numViruses)]
        patient = Patient(viruses, maxPop)
        # simulation
        totalViruses = []
        for tStep in range(timeSteps):
            totalViruses.append(patient.update())
        # results
        results.append(totalViruses)

    # average results
    average = []
    for tStep in range(timeSteps):
        totalInStep = []
        for result in results:
            totalInStep.append(result[tStep])
        average.append(sum(totalInStep)/float(numTrials))

    # plot
    pylab.plot(average, label='Virus Population Simulation')
    pylab.title('Simple Virus Simulation')
    pylab.xlabel('Time Steps')
    pylab.ylabel('Average Virus Population')
    pylab.legend(loc='best')
    pylab.show()

    # AvgTotal, time = [], []
    # for trial in range(numTrials):
    #     viruses = []
    #     for vir in range(numViruses):
    #         viruses.append(SimpleVirus(maxBirthProb, clearProb))
    #     patient = Patient(viruses, maxPop)
    #     totalViruses = []
    #     for tStep in range(300):
    #         totalViruses.append(patient.update())
    #         time.append(tStep)
    #     AvgTotal.append(totalViruses)
    # result = []
    # for i in range(numTrials):
    #     average = 0
    #     for k in range(300):
    #         average += AvgTotal[i][k]
    #     result.append(average/float(300))
    #
    #
    # pylab.plot(time, AvgTotal)
    # pylab.xlabel("Time Step")
    # pylab.ylabel("Average Virus Population")
    # pylab.legend("AvgViruses/Time")
    # pylab.title("SimpleVirus Simulation")
    # pylab.show()




#
# PROBLEM 3
#
class ResistantVirus(SimpleVirus):
    """
    Representation of a virus which can have drug resistance.
    """

    def __init__(self, maxBirthProb, clearProb, resistances, mutProb):
        """
        Initialize a ResistantVirus instance, saves all parameters as attributes
        of the instance.

        maxBirthProb: Maximum reproduction probability (a float between 0-1)

        clearProb: Maximum clearance probability (a float between 0-1).

        resistances: A dictionary of drug names (strings) mapping to the state
        of this virus particle's resistance (either True or False) to each drug.
        e.g. {'guttagonol':False, 'srinol':False}, means that this virus
        particle is resistant to neither guttagonol nor srinol.

        mutProb: Mutation probability for this virus particle (a float). This is
        the probability of the offspring acquiring or losing resistance to a drug.
        """

        SimpleVirus.__init__(self, maxBirthProb, clearProb)
        self.resistances = resistances
        self.mutProb = mutProb
    #
    #
    # def getResistances(self):
    #     """
    #     Returns the resistances for this virus.
    #     """
    #     return self.resistances
    #
    # def getMutProb(self):
    #     """
    #     Returns the mutation probability for this virus.
    #     """
    #     return self.mutProb
    #
    # def isResistantTo(self, drug):
    #     """
    #     Get the state of this virus particle's resistance to a drug. This method
    #     is called by getResistPop() in TreatedPatient to determine how many virus
    #     particles have resistance to a drug.
    #
    #     drug: The drug (a string)
    #
    #     returns: True if this virus instance is resistant to the drug, False
    #     otherwise.
    #     """
    #
    #     return self.resistances.get(drug, False)
    #
    #
    # def reproduce(self, popDensity, activeDrugs):
    #     """
    #     Stochastically determines whether this virus particle reproduces at a
    #     time step. Called by the update() method in the TreatedPatient class.
    #
    #     A virus particle will only reproduce if it is resistant to ALL the drugs
    #     in the activeDrugs list. For example, if there are 2 drugs in the
    #     activeDrugs list, and the virus particle is resistant to 1 or no drugs,
    #     then it will NOT reproduce.
    #
    #     Hence, if the virus is resistant to all drugs
    #     in activeDrugs, then the virus reproduces with probability:
    #
    #     self.maxBirthProb * (1 - popDensity).
    #
    #     If this virus particle reproduces, then reproduce() creates and returns
    #     the instance of the offspring ResistantVirus (which has the same
    #     maxBirthProb and clearProb values as its parent). The offspring virus
    #     will have the same maxBirthProb, clearProb, and mutProb as the parent.
    #
    #     For each drug resistance trait of the virus (i.e. each key of
    #     self.resistances), the offspring has probability 1-mutProb of
    #     inheriting that resistance trait from the parent, and probability
    #     mutProb of switching that resistance trait in the offspring.
    #
    #     For example, if a virus particle is resistant to guttagonol but not
    #     srinol, and self.mutProb is 0.1, then there is a 10% chance that
    #     that the offspring will lose resistance to guttagonol and a 90%
    #     chance that the offspring will be resistant to guttagonol.
    #     There is also a 10% chance that the offspring will gain resistance to
    #     srinol and a 90% chance that the offspring will not be resistant to
    #     srinol.
    #
    #     popDensity: the population density (a float), defined as the current
    #     virus population divided by the maximum population
    #
    #     activeDrugs: a list of the drug names acting on this virus particle
    #     (a list of strings).
    #
    #     returns: a new instance of the ResistantVirus class representing the
    #     offspring of this virus particle. The child should have the same
    #     maxBirthProb and clearProb values as this virus. Raises a
    #     NoChildException if this virus particle does not reproduce.
    #     """
    #
    #     resistant = True
    #     # check resistances
    #     for drug in activeDrugs:
    #         if not self.isResistantTo(drug):
    #             resistant = False
    #             break
    #     if resistant:
    #         reproduces = random.random() <= self.maxBirthProb * (1 - popDensity)
    #         if reproduces:
    #             # mutate resistances
    #             resistances = {k:v if random.random() > self.mutProb else not v for k, v in self.resistances.items()}
    #             # return new ones
    #             return ResistantVirus(self.getMaxBirthProb(), self.getClearProp(), resistances, self.mutProb)
    #     raise NoChildException



class TreatedPatient(Patient):
    """
    Representation of a patient. The patient is able to take drugs and his/her
    virus population can acquire resistance to the drugs he/she takes.
    """

    def __init__(self, viruses, maxPop):
        """
        Initialization function, saves the viruses and maxPop parameters as
        attributes. Also initializes the list of drugs being administered
        (which should initially include no drugs).
        viruses: The list representing the virus population (a list of
        virus instances)
        maxPop: The  maximum virus population for this patient (an integer)
        """
        Patient.__init__(self, viruses, maxPop)
        self.prescriptions = []

    def addPrescription(self, newDrug):
        """
        Administer a drug to this patient. After a prescription is added, the
        drug acts on the virus population for all subsequent time steps. If the
        newDrug is already prescribed to this patient, the method has no effect.
        newDrug: The name of the drug to administer to the patient (a string).
        postcondition: The list of drugs being administered to a patient is updated
        """
        if newDrug not in self.prescriptions:
            self.prescriptions.append(newDrug)

    # def getPrescriptions(self):
    #     """
    #     Returns the drugs that are being administered to this patient.
    #     returns: The list of drug names (strings) being administered to this
    #     patient.
    #     """
    #     return self.prescriptions
    #
    # def getResistPop(self, drugResist):
    #     """
    #     Get the population of virus particles resistant to the drugs listed in
    #     drugResist.
    #     drugResist: Which drug resistances to include in the population (a list
    #     of strings - e.g. ['guttagonol'] or ['guttagonol', 'srinol'])
    #     returns: The population of viruses (an integer) with resistances to all
    #     drugs in the drugResist list.
    #     """
    #     return len([v for v in self.viruses if all(v.isResistantTo(d) for d in drugResist)])
    #
    # def update(self):
    #     """
    #     Update the state of the virus population in this patient for a single
    #     time step. update() should execute these actions in order:
    #     - Determine whether each virus particle survives and update the list of
    #       virus particles accordingly
    #     - The current population density is calculated. This population density
    #       value is used until the next call to update().
    #     - Based on this value of population density, determine whether each
    #       virus particle should reproduce and add offspring virus particles to
    #       the list of viruses in this patient.
    #       The list of drugs being administered should be accounted for in the
    #       determination of whether each virus particle reproduces.
    #     - Reproduction probability:
    #       self.maxBirthProb * (1 - popDensity)
    #     returns: The total virus population at the end of the update (an
    #     integer)
    #     """
    #     # from Patient class:
    #     self.viruses = [vir for vir in self.getViruses() if not vir.doesClear()]
    #     popDensity = len(self.viruses) / float(self.maxPop)
    #
    #     for vir in self.viruses[:]:
    #         try:
    #             self.viruses.append(vir.reproduce(popDensity, self.getPrescriptions()))
    #         except NoChildException:
    #             pass
    #     return self.getTotalPop()



#
# PROBLEM 4
#
def simulationWithDrug(numViruses, maxPop, maxBirthProb, clearProb, resistances,
                       mutProb, numTrials):
    """
    Runs simulations and plots graphs for problem 5.

    For each of numTrials trials, instantiates a patient, runs a simulation for
    150 timesteps, adds guttagonol, and runs the simulation for an additional
    150 timesteps.  At the end plots the average virus population size
    (for both the total virus population and the guttagonol-resistant virus
    population) as a function of time.

    numViruses: number of ResistantVirus to create for patient (an integer)
    maxPop: maximum virus population for patient (an integer)
    maxBirthProb: Maximum reproduction probability (a float between 0-1)
    clearProb: maximum clearance probability (a float between 0-1)
    resistances: a dictionary of drugs that each ResistantVirus is resistant to
                 (e.g., {'guttagonol': False})
    mutProb: mutation probability for each ResistantVirus particle
             (a float between 0-1).
    numTrials: number of simulation runs to execute (an integer)

    """

    #
    # PROBLEM 4
    #
    def simulationWithDrug(numViruses, maxPop, maxBirthProb, clearProb, resistances,
                           mutProb, numTrials):
        """
        Runs simulations and plots graphs for problem 5.

        For each of numTrials trials, instantiates a patient, runs a simulation for
        150 timesteps, adds guttagonol, and runs the simulation for an additional
        150 timesteps.  At the end plots the average virus population size
        (for both the total virus population and the guttagonol-resistant virus
        population) as a function of time.

        numViruses: number of ResistantVirus to create for patient (an integer)
        maxPop: maximum virus population for patient (an integer)
        maxBirthProb: Maximum reproduction probability (a float between 0-1)
        clearProb: maximum clearance probability (a float between 0-1)
        resistances: a dictionary of drugs that each ResistantVirus is resistant to
                     (e.g., {'guttagonol': False})
        mutProb: mutation probability for each ResistantVirus particle
                 (a float between 0-1).
        numTrials: number of simulation runs to execute (an integer)

        """
        # timesteps, virusesAtStep, resistantViruses, VirusAvg, ResistAvg = [], [], [], [], []
        # # init total & avg lists to zeros
        # for step in range(timesteps):
        #     virusesAtStep.append(0)
        #     resistantViruses.append(0)
        # for trial in range(numTrials):
        #     viruses = []
        #     # create resistant viruses
        #     for n in range(numViruses):
        #         viruses.append(ResistantVirus(maxBirthProb, clearProb, resistances, mutProb))
        #     # create patient
        #     patient = TreatedPatient(viruses, maxPop)
        #     # run sim
        #     for step in range(timesteps):
        #         if step == 150:
        #             patient.addPrescription("guttagonol")
        #         virusesAtStep[step] += patient.update()
        #         resistantViruses[step] += patient.getResistPop(['guttagonal'])
        #
        # # get avg for each tstep
        # for step in range(timesteps):
        #     Averages.append(virusesAtStep[step]/float(numTrials))
        #     ResistAvg.append(resistantViruses[step]/float(numTrials))
        #
        # # plot the results
        # pylab.plot(range(timesteps), virusesAtTime, '-b', label='Total Population')
        # pylab.plot(range(timesteps), guttagonolResistantViruses, '-r',
        #     label='Guttagonol Resistant')
        # pylab.xlabel('Time Step')
        # pylab.ylabel('Average Virus Population')
        # pylab.title('Simulated Average Virus Population Vs. Time')
        # pylab.legend(loc='upper left')
        # pylab.show()


# Reference / Checking: https://github.com/tsh/EDX-MITx--6.00.2x/blob/master/ProblemSet3/ps3b.py
