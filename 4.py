# #등분산, 이분산 체크 ->levene이용
# import pandas as pd
# from scipy import stats
#
# a1 = pd.read_excel("C:/Users/USER\Desktop\배터리,근로,성적,체중/배터리_지속시간_china.xlsx")
# a2 = pd.read_excel("C:/Users/USER\Desktop\배터리,근로,성적,체중/배터리_지속시간_korea.xlsx")
# result1 = stats.levene(a1.china, a2.korea, center='mean')
# print(result1)
# #p값이 0.05보다 한참 작으므로 H0기각. 즉 이분산으로 결정


# H0 : μ(china) = μ(korea) ->한국과 중국 지속시간이 같다
# H1 : μ(china) != μ(korea) -> 한국과 중국 지속시간이 다르다
import pandas as pd
from scipy import stats
from matplotlib import pyplot as plt
data = pd.read_excel("C:/Users/USER\Desktop\배터리,근로,성적,체중/배터리_지속시간.xlsx")
print(data.describe())

data.boxplot(column=['china', 'korea'], vert=False)
plt.show()
a1 = pd.read_excel("C:/Users/USER\Desktop\배터리,근로,성적,체중/배터리_지속시간_china.xlsx")
a2 = pd.read_excel("C:/Users/USER\Desktop\배터리,근로,성적,체중/배터리_지속시간_korea.xlsx")
result = stats.ttest_ind(a1.china, a2.korea, alternative='two-sided', equal_var=False)
print(result)
# p값이 0.05보다 현저하게 작으므로 H0기각. 즉, 두 공장 배터리 지속시간 차이가 있다.

