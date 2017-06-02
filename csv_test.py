file = open("test.txt","w")
file.write("yup")
file.write("mmhmm")
file.close()

file = open("submission.csv","w")
file.write("number label\n")

RESULT = [[1, 0.0],[2, 1.0], [3, 1.0], [4, 0.1]]
for line in RESULT:
    file.write("\n" + str(line[0]) + " " + str(line[1]))
