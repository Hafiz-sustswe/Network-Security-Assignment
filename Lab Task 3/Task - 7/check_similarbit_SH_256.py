h3 = "d9345ab3fed7a7e20f6b1f54a5bd72288de5e6c39ab238e568c9bdad1f87e621"
h4 = "66d3891ca7f911e290a82996f5d3ac4d8dfd6f618170953c5dcbd2780765a1e9"

i = 0
cnt = 0
for ch in h3:
    if ch==h4[i]:
        cnt = cnt + 1
    i = i + 1

print(cnt)

#output Number of similar bit between original hash value and modified text hash value = 6.
