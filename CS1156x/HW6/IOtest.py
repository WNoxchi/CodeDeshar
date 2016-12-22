def loadData(filename):
    '''
    :param filename:
    :return returnArray, an array of arrays of floats:
    '''
    file = open(filename, 'r')
    filestring = file.readline()
    returnArray = []
    while filestring != '':
        line = []
        for s in filestring.split(' '):
            if s != '':
                line.append(float(s))
        returnArray.append(line)
        filestring = file.readline()
    file.close()
    return returnArray

thing = loadData('in.dta')
print(thing)
print(len(thing))
