# -*- coding: utf-8 -*-
import ofoSort
from numpy import *
import matplotlib.pyplot as plt
import readCSV

def tdArrPlot():
	arr=ofoSort.read("tdArr.txt")

	# string to num
	td_arr=[]
	for s in arr:
		s=s.strip()
		td=int(s)
		td_arr.append(td)
	sum=0
	for i in range(len(td_arr)):
		sum+=td_arr[i]
		
	print "mean_time : ",sum/len(td_arr)
	
	# plot
	xpa = arange(len(td_arr))
	ypa = td_arr

	fig = plt.figure()
	ax = fig.add_subplot(111)
	plt.xlabel('Time_Mark')
	plt.ylabel('ResponseTime/micro_second')
	ax.plot(xpa,ypa) 

	plt.show()

tdArrPlot()




def cpu_ram_plot():
	a2arr= readCSV.washData('performance_ISMasterDemo.csv')
	begin=(int(a2arr[1][0][14:16]))*60+int(a2arr[1][0][17:19])
	RAM=1024*1024
	time_arr=[]
	cpu_arr=[]
	ram_arr=[]
	for arr in a2arr[1:]:
		time=(int(arr[0][14:16]))*60+int(arr[0][17:19])-begin
		print time,'\t',float(arr[3])/100,'\t',float(arr[4])/RAM
		time_arr.append(time)
		cpu_arr.append(float(arr[3])/100)
		ram_arr.append(float(arr[4])/RAM)
	
	# plot
	xpa = time_arr
	ypa1 = cpu_arr
	ypa2 = ram_arr

	fig = plt.figure()
	ax1 = fig.add_subplot(211)
	plt.xlabel('time/sec')
	plt.ylabel('cpu_used/(100%)')
	ax1.plot(xpa,ypa1) 

	ax2 = fig.add_subplot(212)
	plt.xlabel('time/sec')
	plt.ylabel('ram_used/(MB)')
	ax2.plot(xpa,ypa2) 
	
	plt.show()
	
	
	
#cpu_ram_plot()
	
	
	
	
	
	
	
	
	
	
	
