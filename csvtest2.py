result = [[0,1.0],[1,1.0],[2,0.0],[3,0.0]]
myfile = open("submission.txt","w")
myfile.write("id,label");
for item in result:
    myfile.write("\n" + str(item[0]+1) + "," + str(item[1]))
myfile.close()
