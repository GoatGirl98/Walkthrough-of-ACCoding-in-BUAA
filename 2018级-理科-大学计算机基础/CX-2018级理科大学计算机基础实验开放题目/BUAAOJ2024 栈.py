def splitExp(s):
    expression = s.split()
    return expression

def expression_to_value(expression):
    stack_value = []
    for item in expression:
        if item in ['+', '-', '*', '/']:
            n2 = stack_value.pop()
            n1 = stack_value.pop()
            result = cal(n1, n2, item)
            stack_value.append(result)
        else:
            stack_value.append(int(item))
    return float(stack_value[0])


def cal(n1, n2, op):
    if op == '+':
        return n1 + n2
    if op == '-':
        return n1 - n2
    if op == '*':
        return n1 * n2
    if op == '/':
        return n1 / n2


expression = input()
value = float(expression_to_value(splitExp(expression)))
print("%.2f" % value)
