'''
author: Bodan Chen
Date: 2022-04-24 22:13:37
LastEditors: Bodan Chen
LastEditTime: 2022-04-24 22:13:37
Email: 18377475@buaa.edu.cn
'''
'''
author: Bodan Chen
Date: 2022-04-24 20:29:25
LastEditors: Bodan Chen
LastEditTime: 2022-04-24 22:12:22
Email: 18377475@buaa.edu.cn
'''

import requests
import matplotlib.pyplot as plt
import time

# 解决中文显示问题
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']  # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

cookie="connect.sid=s%3AI17RSiIC8fIpNzY9w9WvCMQFTOD4uJQJ.39GTaeac10BpiS12FrMCoQUl0lEFI5r1zu99xNEfyHc"
address="https://accoding.buaa.edu.cn:4000/api/contests/845/rank"

headers = {"Cookie":cookie}
response = requests.get(address,headers=headers)
res = str(response.json())
#print(res)
res=res.replace('true', 'True')
res=res.replace('false', 'False')
res=res.replace('null','None')
res=eval(res)

'''把数字转换成字母'''
def ToAlpha(number):
    shang,yu=divmod(number,26)
    s1=''
    s2=''
    if shang >0:
        s1=chr(shang+ord('B')-1)
    s2=chr(yu+ord('A'))
    #print(s1,s2)
    return s1+s2
#print(ord('A'))
'''存储题号和通过人数'''
dic={}
num=53
for i in range(1,num):
    #print(ToAlpha(i))
    dic[ToAlpha(i)]=0

for i in res:
    de=i
    try:
        for j in de['detail'].keys():
            try:
                if de['detail'][j]['result']=='AC':
                    dic[j]+=1
            except KeyError:
                pass
    except KeyError:
        pass
print(dic)
x_data=list(dic.keys())
y_data=list(dic.values())
#print(x_data)
current_time = time.strftime('%m-%d %H:%M:%S', time.localtime(time.time()))
print(current_time)
plt.figure(figsize=(20+(num-53),10),dpi=80)
for i in range(len(x_data)):
    plt.bar(x_data[i],y_data[i])
plt.title('投票数 '+str('('+current_time+')'))
plt.xlabel('')
plt.ylabel('')
plt.savefig('./top.jpg')
#plt.show()