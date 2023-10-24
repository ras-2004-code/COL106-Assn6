import random as rnd

min_len = 30
max_len = 200
num_books = 20
min_para = 3
max_para = 10
min_page = 200
max_page = 500
min_sen = 4
max_sen = 10
#extra search pattern
esp_min_len = 5
esp_max_len = 25
esp_num = 200

sentences = []
search_patterns = []

for i in range(num_books):
    num_pages = rnd.randint(min_page,max_page)
    for j  in range(num_pages):
        num_para = rnd.randint(min_para,max_para)
        for k in range(num_para):
            num_sen = rnd.randint(min_sen,max_sen)
            for l in range(num_sen):
                len = rnd.randint(min_len,max_len)
                s = ""
                for _ in range(len):
                    s += chr(rnd.randint(0,127))
                sentences.append((i,j,k,l,s))
                if(rnd.randint(0,99)>96):
                    s = rnd.randint(0,len-1)
                    e = rnd.randint(0,len-1)
                    if(s>e):
                        t = s
                        s = e
                        e = s
                    cs = s[s:e+1]
                    search_patterns.append(cs)



for i in range(esp_num):
    esp_len = rnd.randint(esp_min_len,esp_max_len)
    s = ""
    for _ in range(esp_len):
        s += chr(rnd.randint(0,127))
    search_patterns.append(s)

solutions = [[] for _ in range(len(search_patterns))]

for i in range(len(search_patterns)):
    p = search_patterns[i]
    l = len(p)
    for s in sentences:
        for j in range(len(s[4])-l+1):
            if(p == s[4][j:j+l]):
                solutions[i].append((s[0],s[1],s[2],s[3],j))





            






