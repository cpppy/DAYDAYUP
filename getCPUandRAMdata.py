import psutil
import sys
import time
import os
#import matplotlib.pylab as pl
import csv

if len(sys.argv)!=2:
	print "Parameter Error\nPlease run the tools with process's name as 1st permeter."
	sys.exit(-1)


myPName = sys.argv[1] #5904

myProcessList=[]
elaspeTime = 5
figure = 1

for process in psutil.process_iter():
	try:
		#print myPName,str(process.name())
		if (myPName in str(process.name())):
			myProcessList.append(process)
	except:
		pass

if len(myProcessList) == 0:
	print 'No Process named "%s".'%(myPName)
	print 'Process List \n'
	print 'Name%sID'%(' '*(26))
	print '='*40
	for prr in psutil.process_iter():
		#print prr
		try:
			print '%s%s%s' % (prr.name,"",prr.pid)
		except Exception,e:
			print "error"+str(e)
			sys.exit(-2)

loops = 1;

outPutFile = 'performance_%s.csv'%(myPName)
fp = open(outPutFile,'w')
fp.write('%s,%s,%s,%s,%s,%s,%s,%s\n'%('Time','PID','Name','CPU(%)','RSS(B)','VMS(B)','Threads','Handles'))

while(True):
	try:
		print 'Time\tPID\tName\tCPU(%)\tRss(B)\tVms(B)\tThreads\tHandles'
		for prc  in myProcessList:
			timestr =time.strftime('%Y-%m-%d %H:%M:%S',time.localtime())
			tpid = str(prc.pid)
			tpname = str(prc.name())
			tcpuPer = str(prc.cpu_percent())
			mmer = prc.memory_info()
			tRss = str(mmer.rss)
			tVms = str(mmer.vms)
			tThrds = str(len(prc.threads()))
			#tHans = str(prc.get_num_handles())
			tHans = '200';
			fp.write('%s,%s,%s,%s,%s,%s,%s,%s\n'%(timestr,tpid,tpname,tcpuPer,tRss,tVms,tThrds,tHans))
			printStr = '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s'%(timestr[-8:-3],tpid,tpname,tcpuPer,tRss,tVms,tThrds,tHans)
			
			print printStr
		loops =  loops + 1
		print
		time.sleep(elaspeTime)
	except IOError, ex:
		print 'Process not exist or other exception occuring during running "%s"' %ex
		print 'Process List \n'
		print 'Name%sID'%(' '*(26))
		print '='*40
		for prr in psutil.process_iter():
			try:
				print '%s%s%s'%(prr.name().strip(),' '*(30-len(prr.name().strip())),prr.pid)
			except:
				pass
		break

print 'The result file: %s'%(os.path.join(os.getcwd(),outPutFile))
fp.close()


'''
cpuList = []
memList = []
vmsList = []
dateList = []
handleList = []
if(figure):
	with open(os.path.join(os.getcwd(),outPutFile)) as csvfile:
		reader = csv.reader(csvfile)
		for row in reader:
			if(row[3] == "CPU(%)"):
				continue
			dateList.append(row[0])
			cpuList.append(row[3])
			memList.append(row[4])
			vmsList.append(row[5])
			handleList.append(row[7])
	pl.rcParams['font.sans-serif'] = ['SimHei'] #指定默认字体    
	pl.rcParams['axes.unicode_minus'] = False #解决保存图像是负号'-'显示为方块的问题 
	pl.figure(2)
	
	pl.title(u"%s稳定性图示"%myPName)
	ax1 = pl.subplot(221)
	ax2 = pl.subplot(222)
	ax3 = pl.subplot(223)
	ax4 = pl.subplot(224)

	pl.sca(ax1)
	pl.xlabel("Time stamp")
	pl.ylabel("CPU")
	pl.plot(range(len(cpuList)),cpuList,color='r')
	pl.xticks(range(len(cpuList)),dateList)
	pl.sca(ax2)
	pl.xlabel("Time stamp")
	pl.ylabel("Memory")
	pl.plot(range(len(memList)),memList,color='b')
	pl.xticks(range(len(cpuList)),dateList)
	pl.sca(ax4)
	pl.xlabel("Time stamp")
	pl.ylabel("VMS")
	pl.plot(range(len(vmsList)),vmsList,color='g')
	pl.xticks(range(len(cpuList)),dateList)
	pl.sca(ax3)
	pl.xlabel("Time stamp")
	pl.ylabel("Hanldes")
	pl.plot(range(len(handleList)),handleList,color='y')
	pl.xticks(range(len(cpuList)),dateList)
	
	pl.savefig("perf.png")
	'''
