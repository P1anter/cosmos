import pandas as pd
from scipy import stats
from matplotlib import pyplot as plt

# H0 : μ(가입전) = μ(가입후) ->가입 전후 같다.
# H1 : μ(가입전) > μ(가입후) ->가입 후 줄었음.

data = pd.read_excel("C:/Users/USER\Desktop\배터리,근로,성적,체중/체중비교.xlsx")
print(data[['before', 'after']].describe())

data.boxplot(column=['before', 'after'], vert=False)
plt.show()

result = stats.ttest_rel(data.before, data.after, alternative='greater')
print(result)
# p값이 0.05보다 현저하게 작으므로 H0기각. 즉, 가입 후 체중이 줄어들었음.