# #등분산, 이분산 체크 ->levene이용
# import pandas as pd
# from scipy import stats
#
# a1 = pd.read_excel("C:/Users/USER\Desktop\배터리,근로,성적,체중/주당_근로시간.xlsx")
# result1 = stats.levene(a1.daejeon, a1.gwangju, center='mean')
# print(result1)
# #p값이 0.05보다 한참 작으므로 H0기각. 즉 이분산으로 결정

import pandas as pd
from scipy import stats
from matplotlib import pyplot as plt

# H0 : μ(daejeon) = μ(gwangju) ->대전과 광주 근로시간 차이가 없다.
# H1 : μ(daejeon) != μ(gwangju) -> 대전과 광주 근로시간 차이가 있다.

data = pd.read_excel("C:/Users/USER\Desktop\배터리,근로,성적,체중/주당_근로시간.xlsx")
print(data.describe())

data.boxplot(column=['daejeon', 'gwangju'], vert=False)
plt.show()

result = stats.ttest_ind(data.daejeon, data.gwangju, alternative='two-sided', equal_var=False)
print(result)
# p값이 0.05보다 현저하게 작으므로 H0기각. 즉, 두 지역 주당 근로시간 차이가 있다.