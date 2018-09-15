temp_input = [int(x) for x in input().split()]
size = temp_input[0]
case = temp_input[1]

path_list = list()
result = set([])
flag_new = True
success = True
for i in range(0, case):
    temp_input = [int(x) for x in input().split()]
    a = temp_input[0]
    b = temp_input[1]
    for item in path_list:
        if a in item:
            item.add(b)
            flag_new = False
        elif b in item:
            item.add(a)
            flag_new = False

    if flag_new:
        c = set([a,b])
        path_list.append(c)
    flag_new = True

'''print(path_list)'''

i = 1
wholeSet = list()

while i <= size:
    temp_set = set([])
    for itemm in path_list:
        if i in itemm:
            temp_set = temp_set|itemm


    if temp_set not in wholeSet:
        wholeSet.append(temp_set)
    i += 1

#print(wholeSet)

i = 1
while i<=int(size/2):
    for itemmm in wholeSet:
        if i in itemmm and size-i+1 in itemmm:
            result.add(i)
            '''print(str(i) + ' and ' + str(size-i+1) + ' are in')'''
            continue
    i+=1

#print(result)


if len(result)==int(size/2):
    print('Yes')
else:
    print('No')
