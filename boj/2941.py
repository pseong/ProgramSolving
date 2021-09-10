a = ["c=","c-","dz=", "d-","lj","nj","s=","z="]
st = input()
for ch in a:
    st = st.replace(ch,"1")
print(len(st))