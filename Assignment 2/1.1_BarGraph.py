import matplotlib.pyplot as pyplot



index = (0,0,0,0,0,0,0,0,0,0)
sizes = [4.526722, 4.615962, 4.609034, 4.730886, 5.976195, 6.988001, 6.481840, 6.547767, 6.023763, 6.320204]

pyplot.bar(index, sizes, color="#6c3376")
pyplot.title("SCHED_OTHER")
pyplot.ylabel('Process Time')
pyplot.xlabel('Test Number')

pyplot.show()

index = (1, 2, 3, 4, 5, 6, 7,8,9,10)
sizes = [4.526722, 4.615962, 4.609034, 4.730886, 5.976195, 6.988001, 6.481840, 6.547767, 6.023763, 6.320204]

pyplot.bar(index, sizes, color="#6c3376")
pyplot.title("SCHED_RR")
pyplot.ylabel('Process Time')
pyplot.xlabel('Thread Priority')

pyplot.show()

index = (1, 2, 3, 4, 5, 6, 7,8,9,10)
sizes = []

pyplot.bar(index, sizes, color="#6c3376")
pyplot.title("SCHED_FIFO")
pyplot.ylabel('Process Time')
pyplot.xlabel('Thread Priority')

pyplot.show()
