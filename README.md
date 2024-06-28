# paradigms-pa-4
## Command used to compile project

```PS C:\Users\kvita\CLionProjects\par-4> g++ -o fileCode.exe main.cpp TextProcessor.cpp TextEditor.cpp Caes
arCipher.cpp -LC:\Users\kvita\CLionProjects\paradigms-pa-3 -lcryptography -static-libgcc -static-libstdc++
```

## Test plan
### Normal flow
```
PS C:\Users\kvita\CLionProjects\par-4> C:\Users\kvita\CLionProjects\par-4\fileCode.exe

Choose action  1 - encrypt, 2 - decrypt, 3 -exit
1
Enter input file: C:\Users\kvita\CLionProjects\par-4\input.txt.txt
Enter output file: C:\Users\kvita\CLionProjects\par-4\decoded.txt.txt
Enter key: 3

Choose action  1 - encrypt, 2 - decrypt, 3 -exit
2
Enter input file: C:\Users\kvita\CLionProjects\par-4\decoded.txt.txt
Enter output file: C:\Users\kvita\CLionProjects\par-4\encoded.txt.txt
Enter key: 3

Choose action  1 - encrypt, 2 - decrypt, 3 -exit
3
PS C:\Users\kvita\CLionProjects\par-4>
```
#### Results
![image](https://github.com/kvitoslava-yarish/paradigms-pa-4/assets/150699851/e0ddf981-816f-465a-9a8f-cdb8d716a28a)

### Validation

#### Menu choice validation
![image](https://github.com/kvitoslava-yarish/paradigms-pa-4/assets/150699851/6aef5c0f-ac72-4e53-8bc5-544bfaa0e6a4)

#### Wrong path validation
![image](https://github.com/kvitoslava-yarish/paradigms-pa-4/assets/150699851/3f934e6b-5697-4e99-b5d9-984351ae7648)

#### Key validation
![image](https://github.com/kvitoslava-yarish/paradigms-pa-4/assets/150699851/33957725-7aec-4963-9db0-0c6c3441f5dd)
#### Input file is empty (no problmes)
![image](https://github.com/kvitoslava-yarish/paradigms-pa-4/assets/150699851/dbfcac10-8f61-49ac-8708-96f58ae450d2)
#### Input file is large (5 mb)
25 sec - to decode file
