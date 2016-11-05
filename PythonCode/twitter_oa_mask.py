# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
import re

email_pattern = re.compile(r'^(E:\s?\S)\S*(\S@.+)$')

def mask_email(str):
    match = email_pattern.match(str)
    ret_str = ""
    if match:
        ret_str += match.group(1)
        ret_str += '*****'
        ret_str += match.group(2)
    return ret_str

def mask_phone(str):
    head = str[0:2]
    str = str[2:]
    str = re.sub(r'[\+\-\(\)\s]', '', str)
    print(str)
    length = len(str) - 10
    prefix = ''
    if length > 0:
        prefix += '+' + '*' * length + '-'
    suffix = str[-4:]
    return head + prefix + '***-***-' + suffix

for line in sys.stdin.readlines():
    if line == '\n':
        continue
    line = line.strip()
    if line[0] == 'E':
        print(mask_email(line))
    elif line[0] == 'P':
        print(mask_phone(line))