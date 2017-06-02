# 2017-Apr-17 10:57     -   WNx -   6.006 L9

str1 = "this is a big block of text of something nothingness blah blah hello lorem ipsum lala okay this should be long enough lets go."
str2 = "blah"

print(str1)
print(str2)
print any(str2 == str1[i:i+len(str2)] for i in range(len(str1) - len(str2)))
for i in range(len(str1) - len(str2)):
    print str1[i:i+len(str2)]
