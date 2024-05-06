# <p align='center'>Lab 3: Symmetric encryption & hashing<p>

##  Answer to Task 1 Solution: 
**Text file:**
```text
Hello this is Md Sadman Hafiz and I am learning computer network and security course It's interesting.
```

**Commands:** <br>
Encrypt using AES-128 in CBC mode:
```bash
openssl enc -aes-128-ecb -e -in test.txt -out hafiz_aes128cbc.bin -K 00112233445566778889aabbccddeeff
```

Encrypt using AES-128 in CFB mode:
```bash
openssl enc -aes-128-cbc -e -in test.txt -out hafiz_aes128cfb.bin -K 00112233445566778889aabbccddeeff -iv 0102030405060708
```

Encrypt using AES-128 in ECB mode:
```bash
openssl enc -aes-128-cfb -e -in test.txt -out hafiz_aes256.bin -K 00112233445566778889aabbccddeeff -iv 0102030405060708
```


**Output Encrypted files:** <br>
128cbc mode: <br>
<img src="./Task - 1/128cbc_bin.png" alt="output_ecb" width="500"/>
<br><br>
128 cfb mode: <br>
<img src="./Task - 1/128cfb_bin.png" alt="output_cbc" width="500"/>
<br><br>
128ecb mode: <br>
<img src="./Task - 1/128ecb_bin.png" alt="output_cfb" width="500"/>
256 cbc mode: <br>
<img src="./Task - 1/256cbc_bin.png" alt="output_cfb" width="500"/>

**Commands:** <br>
Decrypt using AES-128 in CBC mode:
```bash
openssl enc -aes-128-cbc -d -in hafiz_aes128cbc.bin -out hafiz_aes128cbcdecrypted.txt -K 00112233445566778889aabbccddeeff -iv 20304050607082143234324324233333

```

Encrypt using AES-128 in CBF mode:
```bash
openssl enc -aes-128-cfb -d -in hafiz_aes128cfb.bin -out hafiz_aes128cfbdycrypted.txt -K 00112233445566778889aabbccddeeff -iv 20304050607082143234324324233333

```

Encrypt using AES-128 in ECB mode:
```bash
openssl enc -aes-128-ecb -d -in hafiz_aes128ecb.bin -out hafiz_aes128ecbdecrypted.txt -K 00112233445566778889aabbccddeeff
```
Encrypt using AES-256 in CBC mode:
```bash
openssl enc -aes-256-cbc -d -in hafiz_aes256cbc.bin -out hafiz_aes256cbcdecrypted.txt -K 2222233333232323222223333323232322222333332323232222233333232323 -iv 5a04ec902686fb05a6b7a338b6e07760
```
All the decrypted file gave back the original task
<hr>

## ✔️ Task 2
### Solution
**Real image:** <br>
<img src="./Task - 2/original.bmp" alt="real_image" width="500"/>

**Commands:** <br>
Encryption using ECB mode:
```bash
openssl enc -aes-128-ecb -e -in sample.bmp -out hafiz_encryptedImage_ecb.bmp -K 00112233445566778889aabbccddeeff
```

Encryption using CBC mode:
```bash
openssl enc -aes-128-cbc -e -in sample.bmp -out encryptedImageCBC.bmp -K 00112233445566778889aabbccddeeff -iv 20304050607082143234324324233333
```
Now I cannot open any image files  either becasue. all the header file of both of the encrypted files also get encrypted. So we need to restore (Using GHEX)first 54 bits of the original imaage file.<br>
This time we are able to see the images.But as encrypted, We don't see any useful information of the images. <br>

**Output files:** <br>


ECB mode: <br>
<img src="./Task - 2/ecb.png" alt="encrypted_ecb" width="500"/>
<br><br>
CBC mode: <br>
<img src="./Task - 2/cbc.png" alt="encrypted_cbc" width="500"/>

**Observations:** <br>
### Analysis & Comparison between ECB & CBC Mode

#### ECB Mode (Electronic Codebook):
- **Independent Encryption:** Each block of plaintext is encrypted independently using the same key.
- **No Diffusion:** Identical plaintext blocks lead to identical ciphertext blocks, lacking diffusion.
- **Vulnerabilities:** The mode's simplicity can lead to security issues, such as pattern preservation in encrypted images.

#### CBC Mode (Cipher Block Chaining):
- **XOR Chaining:** Each plaintext block is XORed with the previous ciphertext block before encryption.
- **Increased Diffusion:** Adds diffusion, enhancing security by disrupting patterns in the plaintext.
- **Initialization Vector:** Requires an Initialization Vector (IV) for the first block.

#### Comparison:
- **Speed and Simplicity:** ECB is simpler and faster but less secure, making it unsuitable for scenarios like image encryption.
- **Security and Efficiency:** CBC is more secure due to its chaining mechanism but is slightly slower and requires an IV.
- **Preferred Use:** For image encryption, CBC is generally preferred over ECB due to its better resistance to pattern preservation and higher security.


<hr>

## ✔️ Task 3
### Solution
**Text file:** <br>
<img src="./Images/Task 3/real.png" alt="real_image" width="500"/>

**Encryption Commands:** <br>
ECB mode:
```bash
openssl enc -aes-128-ecb -e -in test.txt -out hafiz_aes128ECBencrypted.bin -K 00112233445566778889aabbccddeeff
```
**After encryption:** <br>
<img src="./Task - 3/decryptionWithoutModify.png" alt="real_image" width="500"/>

**30th bit modification:** <br>
<img src="./Task - 3/30thBitModification.png" alt="real_image" width="500"/>

**3:** Trying to decrypt the modified file <br>

```bash
openssl enc -aes-128-ecb -d -in hafiz_aes128ECBencrypted.bin -out hafiz_aes128ECBdecrypted.txt -K 00112233445566778889aabbccddeeff
```
Now we can see the original text file is corrupted and some part of the text isn't readable anyway.

<img src="./Task - 3/corrupted text.png" alt="real_image" width="500"/>

Now I am trying  other modes.
CBC mode:
```bash
openssl enc -aes-128-cbc -e -in test.txt -out hafiz_aes128CBCencrypted.bin -K 00112233445566778889aabbccddeeff -iv 20304050607082143234324324233333 
```
<img src="./Task - 3/30thBitModificationCBC.png" alt="real_image" width="500"/>

Decrypted with corrupted text file :

<img src="./Task - 3/corrupted textCBC.png" alt="real_image" width="500"/>




CFB mode:
```bash
openssl enc -aes-128-cfb -e -in test.txt -out encrypted_test_cfb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

OFB mode:
```bash
openssl enc -aes-128-ofb -e -in test.txt -out encrypted_test_ofb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

CFB mode: <br>
<img src="./Images/Task 3/corrupted_cfb.png" alt="encrypted_test_cfb" width="500"/>

OFB mode: <br>
<img src="./Images/Task 3/corrupted_ofb.png" alt="encrypted_test_ofb" width="500"/>

**Decryption Commands:** <br>

CFB mode:
```bash
openssl enc -aes-128-cfb -d -in encrypted_test_cfb.txt -out decrypted_test_cfb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

OFB mode:
```bash
openssl enc -aes-128-ofb -d -in encrypted_test_ofb.txt -out decrypted_test_ofb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

**Decrypted files:** <br>
ECB mode: <br>
<img src="./Task - 3/corrupted text.png" alt="decrypted_test_ecb" width="500"/>

In the case of ECB mode,
- each block of plaintext is encrypted independently.
- since each block is encrypted separately, the corruption affects only one block.
- Explanation: In ECB mode, each block is encrypted independently. Therefore, the corruption only affects the specific block where it occurred. The rest of the plaintext remains intact.

CBC mode: <br>
<img src="./Task - 3/corrupted textCBC.png" alt="decrypted_test_cbc" width="500"/>

In the case of CBC mode,
- each block of plaintext is XORed with the previous ciphertext block before encryption.
- if a single bit of the ciphertext is corrupted, it affects the decryption of the current and subsequent blocks due to error propagation.
- While CBC mode encrypts blocks in a chained manner, the corruption in one block affects the decryption of subsequent blocks. However, the first block can still be recovered as it only depends on the IV and the first block of ciphertext.

CFB mode: <br>
<img src="./Task - 3/corrupted textCFB.png" alt="decrypted_test_cfb" width="500"/>

In the case of CFB mode,
- the ciphertext of the previous block is encrypted and XORed with the current plaintext block to generate the current ciphertext block.
- if a single bit of the ciphertext is corrupted, it affects the decryption of the current block.
- Explanation: In CFB mode, the corruption in one ciphertext block affects the decryption of subsequent blocks. However, due to the feedback mechanism, only a part of the subsequent blocks is corrupted. As a result, more information can be recovered compared to CBC mode.

OFB mode: <br>
<img src="./Task - 3/corrupted textOFB.png" alt="decrypted_test_ofb" width="500"/>

In the case of OFB mode,
- the key stream is generated independently of the plaintext.
- Explanation: Similar to CFB mode, the corruption in one ciphertext block affects the decryption of subsequent blocks. However, in OFB mode, the feedback mechanism is independent of the plaintext, resulting in a similar recovery as in CFB mode..

<hr>

## ✔️ Task 4
### Solution
Here I have  tested the a test text file with all the four modes , with these commands and here is the result.

**Commands:** <br>
ECB mode:
```bash
openssl enc -aes-128-ecb -e -in test4.txt -out test4ECBEncrypt.txt -K 00112233445566778889aabbccddeeff

```

CBC mode:
```bash
openssl enc -aes-128-cbc -e -in test4.txt -out test4Encrypt.txt -K 00112233445566778889aabbccddeeff -iv 0102030405060708

```

CFB mode:
```bash
openssl enc -aria-128-cfb -e -in test4.txt -out test4CFBEncrypt.txt -K 00112233445566778889aabbccddeeff -iv 0102030405060708

```

OFB mode:
```bash
openssl enc -aria-128-ofb -e -in test4.txt -out test4OFBEncrypt.txt -K 00112233445566778889aabbccddeeff -iv 0102030405060708

```

**Observations and Explanations:** <br>
- ECB mode necessitates padding due to its block-by-block encryption approach. Padding becomes necessary when the plaintext's size isn't a multiple of the block size to fill the last block adequately.
- Similarly, CBC mode mandates padding to address the same issue as ECB. Furthermore, CBC mode utilizes an IV (Initialization Vector) for XOR operation with the first block. However, padding remains essential for the final block.
- Unlike ECB and CBC, CFB mode operates on a byte level, eliminating the need for padding since it doesn't function on a block level. Consequently, the ciphertext length remains identical to the plaintext length.
- Likewise, OFB mode operates independently of the plaintext, generating a key stream, thereby obviating the necessity for padding. Consequently, the length of the ciphertext aligns with that of the plaintext.
<hr>

## ✔️ Task 5
### Solution
**Text file:** <br>
```text
Sylhet is a beautiful city
```

**Commands:** <br>
```bash
# MD5
openssl dgst -sha1 text.txt

# SHA-256
openssl dgst -md5 text.txt

# SHA-512
openssl dgst -sha256 text.txt
```

**Output:** <br>
MD5: <br>
<img src="./Task - 5/md5.png" alt="md5" width="700"/>

SHA-1: <br>
<img src="./Task - 5/sha1.png" alt="sha256" width="700"/>

SHA-256: <br>
<img src="./Task - 5/sha256.png" alt="sha512" width="700"/>

**Observations and Explanations:** <br>
- Hash Length:
    - MD5 produces a 128-bit (16-byte) hash value.
    - SHA-256 produces a 256-bit (32-byte) hash value.
    - SHA-1 produces a 160-bit (20-byte) hash value.
-Security Grades:
    -MD5 is acknowledged as insecure and susceptible to collision attacks.
    -For applications requiring robust security, SHA-256 and SHA-512 provide superior security features and are advised.
-Performance:
    -MD5 operates at a higher speed compared to SHA-256 and SHA-512.
    -In contrast, SHA-512 exhibits slower processing speeds compared to SHA-256.

<hr>

## ✔️ Task 6
### Solution
**Text file:** <br>
```text
Sylhet is a beautiful city
```

**Commands:** <br>
Short key length:
```bash
# HMAC-MD5
openssl dgst -sha1 -hmac "hafi's key" test.txt

# HMAC-SHA256
openssl dgst -md5 -hmac "Hafiz's key" test.txt

# HMAC-SHA1
openssl dgst -sha256 -hmac "Hafiz's Key" test.txt
```

Long key length:
```bash
# HMAC-MD5
openssl dgst -sha1 -hmac "this is using a very long key" test.txt

# HMAC-SHA256
openssl dgst -md5 -hmac "this is using a very long key" test.txt

# HMAC-SHA1
openssl dgst -sha256 -hmac "this is using a very long key" test.txt
```

**Observations:** <br>
HMAC-MD5:
- Small Key: A limited key length heightens susceptibility to brute-force attacks.
-Large Key: Increasing the key length strengthens security, reducing the risk of brute-force attacks.
- <img src="./Task - 6/md5.png" alt="md5" width="500"/>
<br>

HMAC-SHA256:
- Short key: Reduced key size raised susceptibility to brute-force attacks.
- Long key: Expanded key size significantly boosted security.
- <img src="./Task - 6/sha256.png" alt="sha256" width="500"/>
<br>

HMAC-SHA1:
- Short key: Smaller keys are more vulnerable to brute-force attacks despite SHA1's inherent strength.
- Long key: Larger keys enhance security significantly, making brute-force attacks impractical.
- <img src="./Task - 6/sh1.png" alt="sha1" width="500"/>

<hr>

## ✔️ Task 7
### Solution
**Text file:** <br>
```text
Assignment done
```

**Commands:** <br>
```bash
openssl dgst -md5 text.txt

```
Output put of non modified hash value:

<img src="./Task - 7/output_md5.png" alt="H1" width="500"/>


Now flipped the 30th bit

<img src="./Task - 7/flipped the 30th bit.png" alt="H1" width="500"/>

```bash
openssl dgst -md5 text.txt

```
got different Hash value.
<img src="./Task - 7/output_modified.png" alt="H1" width="500"/>

Now hashed again





**Code to calculate same bits:**
```python
h1 = "bb1ae33a0a9d01394c152ad4d3c6c40d"
h2 = "000a0de64d5b6278c18d064b8125ecac"

i = 0
cnt = 0
for ch in h1:
    if ch==h2[i]:
        cnt = cnt + 1
    i = i + 1

print(cnt)
```


```bash
Output: Character Matched : 1
```

Similar things done for sha256 too.

```python
h1 = "d9345ab3fed7a7e20f6b1f54a5bd72288de5e6c39ab238e568c9bdad1f87e621"
h2 = "66d3891ca7f911e290a82996f5d3ac4d8dfd6f618170953c5dcbd2780765a1e9"

i = 0
cnt = 0
for ch in h1:
    if ch==h2[i]:
        cnt = cnt + 1
    i = i + 1

print(cnt)
```
```bash
Output: Character Matched : 6
```


**Observations:** <br>
- The hash values of H1 and H2 are different.
- There is 1 character match in this two hashed value
-After Flipping the hash value doesnt match .

<hr>