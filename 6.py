import pandas as pd
from scipy import stats
from matplotlib import pyplot as plt

# H0 : μ(중간) = μ(기말) ->중간 기말 같다.
# H1 : μ(중간) < μ(기말) ->중간 기말이 좋아짐.

data = pd.read_excel("C:/Users/USER\Desktop\배터리,근로,성적,체중/확률및통계_성적.xlsx")
print(data[['midterm', 'final']].describe())

data.boxplot(column=['midterm', 'final'], vert=False)
plt.show()

result = stats.ttest_rel(data.midterm, data.final, alternative='less')
print(result)
# p값이 0.05보다 현저하게 작으므로 H0기각. 즉, 기말 성적이 좋아졌다.