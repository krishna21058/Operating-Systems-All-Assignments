from matplotlib import pyplot

numList = [1, 2, 3]

labelList = ["SCHED_OTHER", "SCHED_RR", "SCHED_FIFO"]

colorList = [ "green","red", "blue"]

pyplot.bar(numList, data, tick_label = labelList, color = colorList)
pyplot.xlabel("Priorities")
pyplot.ylabel("Time Taken")
pyplot.title("Priorities VS Time")
pyplot.show()