import json
# json_str='{"name":"Mursalin" ,"isteacher":none}'
# py_obj=json.loads(json_str)
# print(type(py_obj),py_obj)
# pyt_obj={"name":"Mursalin" ,"isteacher":None}
# jsn_obj=json.dumps(pyt_obj)
# print(jsn_obj)

# with open("data.json","r") as f: 
#         print(json.load(f))
data1={
    "namme":"mursalin",
    "age":27,
    "isteacher":True
}
with open("data.json","w") as f:
        json.dump(data1,f,indent=4,sort_keys=True)