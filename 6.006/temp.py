# import string
#
# thing = " "*len(string.punctuation)+string.lowercase
# length = len(thing)
# print("[{}]: {}".format(thing, length))
#
# trans_table = string.maketrans(string.punctuation + string.uppercase,
#                                 " "*len(string.punctuation) + string.lowercase)
#
# print("Translation Table:\n{}".format(trans_table))
#
#
# translation_table = string.maketrans(string.punctuation+string.uppercase,
#                    " "*len(string.punctuation)+string.lowercase)
#
# print("Translation Table:\n{}".format(translation_table))

# A = [0,1,2,3,4,5,6,7,8,9]
# # B = [11,22,33,44]
# X = []
#
# i = 0
# if i < len(A):
#     X.extend(A[i:])
#
# print("A:{}\nX:{}".format(A,X))

def merge(L,R):
    i = 0
    j = 0
    answer = []
    while i < len(L) and j < len(R):
        if L[i] < R[j]:
            answer.append(L[i])
            i += 1
        else:
            answer.append(R[j])
            j += 1
    if i < len(L):
        print("i < len(L): extending answer by: {}".format(L[i:]))
        answer.extend(L[i:])
    if j < len(R):
        answer.extend(R[j:])
        print("j < len(R): extending answer by: {}".format(R[j:]))
    return answer

L = [1,2,3,4]
R = [6,7,8,9]

print(merge(L,R))
