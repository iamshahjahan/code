text = open('cyclocomplexity.py')
token = ['for', 'while', 'if', 'switch']
count = 1

# for for while if

for l in text:
    l = l.split()
    for x in l:     # for
        if x is '#':
            break
        if x in token:
            count += 1
            print x
print "cyclomatic complexity: ", count
text.close()