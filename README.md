# dicominfo
get DICOM meta information

complie
```
g++ -o dicominfo3 dicominfo3.cpp -ldcmdata -lofstd -loflog -lz
```
execute
```
./dicominfo3 [DICOM file]
```

show Japanese information.
```
./dicominfo3 [DICOM file] | nkf -sw
```
