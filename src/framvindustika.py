p,w=map(int,input().split())
a=p*w//100
print(f"[{'#'*a}{'-'*(w-a)}] | {p:3}%")