# 6.00.2x Intro to Computational Thinking & Data Science
# Wayne H. Noxchi
# 11-Mar-2016 11:29
# ------------------------------------------------------

# 1/2: code to load file data into var 'inFile' & parse data line by line:
def loadWords():
    inFile = open('julyTemps.txt')
    line = inFile.readline()
    fields = line.split()
    # fields = line.split(' ')
    # fields = line.split(" ")

# 3. Which set of conditions would capture all non-data lines in the file?:
>> if len(fields) != 3 or 'Boston' == fields[0] or 'Day' == fields[0]:
>> if len(fields) < 3 or not fields[0].isdigit():


# Full program:
def loadFile():
    inFile = open('julyTemps.txt')
    high = []
    low = []
    for line in inFile:
        fields = line.split()
        if len(fields) != 3 or 'Boston' == fields[0] or 'Day' == fields[0]:
            continue
        else:
            high.append(int(fields[1]))
            low.append(int(fields[2]))
    return (low, high)

def producePlot(lowTemps, highTemps):
    deffTemps = list(np.array(highTemps) - np.array(lowTemps))
    pylab.plot(range(1, 32), diffTemps)
    pylab.title('Day by Day Ranges in Temperature in Boston in July 2012')
    pylab.xlabel('Days')
    pylab.ylabel('Temperature Ranges')
    pylab.show()

(low, high) = loadFile()
producePlot(low, high)
