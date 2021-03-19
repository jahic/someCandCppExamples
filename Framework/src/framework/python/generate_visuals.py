from  matplotlib import pyplot as plt
import numpy as np
import json




def autolabel(setting, rect):
    """Attach a text label above each bar in *rects*, displaying its height."""
    names = list(setting.keys()) 
    i = 1
    for name in names:
        col.annotate('{}'.format(setting[name]["settings"]),
                    xy=(rect[i - 1].get_x() + rect[i - 1].get_width() / 2, rect[i - 1].get_height()),
                    xytext=(0, 4),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')
        i = i + 1



with open('/home/arian/Framework/multiply_parallel.json') as json_file:
    data = json.load(json_file)




  # the label locations
width = 0.35  # the width of the bars

fig, ax = plt.subplots(nrows=len(data["tests"]["test_1"]["measurements"]), ncols=1)

i = 0

for col in ax:

    test_size = len(data["tests"])

    labels = []
    men_means = []

    for x in range(0, test_size):
        labels.append(list(data["tests"]["test_" + str(x + 1)]["measurements"].keys())[i])
        men_means.append(list(data["tests"]["test_" + str(x + 1)]["measurements"].values())[i])

    

    x = np.arange(len(labels))

    rects1 = col.bar(x - width/2, men_means, width, label='matrix_size')


    # Add some text for labels, title and custom x-axis tick labels, etc.
    col.set_ylabel('Time Format:' + str(data["time_unit"]))
    col.set_title('Matrix: ' + str(labels[0]))
    col.set_xticks(x)
    col.set_xticklabels(men_means)
    col.legend()
    i = i + 1
    autolabel(data["tests"], rects1)


fig.tight_layout()

plt.show()

