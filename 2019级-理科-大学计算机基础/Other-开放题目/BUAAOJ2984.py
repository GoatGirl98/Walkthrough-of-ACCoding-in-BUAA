import re
import math
for _ in range(int(input())):
    code = input()
    code = code.replace('\t', '    ')
    code = re.sub('#(?! )', '# ', code, 1)
    code = re.sub('(?P<s>^ +)', lambda x: '    '*math.ceil(x.group('s').count(' ')/4), code)
    print(code)

