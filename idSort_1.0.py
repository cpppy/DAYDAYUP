# -*- coding: utf-8 -*-





def read(filename):

    arr = []

    of=open(filename)

    linesarr=of.readlines()

    for line in linesarr:

    	line=line.strip()

    	if(len(line)!=0):

        	arr.append(line)

    of.close()

    return arr





if __name__ == '__main__':

	#read txt file

	arr=read("ofo查询.txt")



	# deal with array of readlines, get bike_id , sort it, 

	# found a dic to connect id and its key in original_arr

	id = {}

	idarr=[]

	for i in range(len(arr)):

		pos = arr[i].find(' ')

		#print pos

		pos2 = pos

		while (arr[i][pos2]==' '):

			pos2 += 1

		arr[i]=arr[i][0:pos]+'   '+arr[i][pos2:]

		sub = int(arr[i][0:pos])

		#print i,"   ",int(sub)

		id[sub]=i

		idarr.append(sub)



	# first : erase the same   ;  second : sort it

	idarr=list(set(idarr))

	idarr=sorted(idarr,cmp=None,key=None,reverse=False)



	#write the sorted result to res[]

	res = []

	for idnum in  idarr:

		res.append(arr[id[idnum]])

	

	# write res[] into txt_file

	fo = open("ofoSort.txt","w")



	for resi in res:

		print resi

		fo.write(resi+'\n')

		

	fo.close()  

		
		
