# 🎵 Audio File Header Reader

A simple C++ program I built during my **2nd year of college (2023–2024)** to practice binary file handling.  
It detects and displays basic header information for **WAVE (WAV)** and **OGG** audio files.

## 🚀 Features
- Reads binary headers of audio files.
- Supports:
  - **WAVE (.wav)** format:
    - Chunk ID
    - Format
    - Number of Channels
    - Sample Rate
    - Bits per Sample
    - and more…
  - **OGG (.ogg)** format:
    - Capture Pattern
    - Version
    - Granule Position
    - Bitstream Serial Number
    - Page Sequence Number
    - Checksum
- Displays parsed header information in a clean format.

## 📂 Example Usage
```bash
Enter your file: test.wav

  WAVE File Header
Chunk ID: RIFF
Chunk Size: 123456 bytes
Format: WAVE
Subchunk1 ID: fmt 
Subchunk1 Size: 16 bytes
Audio Format: 1
Number of Channels: 2
Sample Rate: 44100 Hz
Byte Rate: 176400 bytes/sec
Block Align: 4 bytes
Bits Per Sample: 16 bits
```
-----------------
```bash
Enter your file: test.ogg

  OGG File Header
Capture Pattern: OggS
Version: 0
Header Type: 1
Granule Position: 12345
Bitstream Serial Number: 67890
Page Sequence Number: 2
Check Sum: 123456.0
```

## 🛠️ How to Compile & Run
```bash
g++ main.cpp -o AudioFileReader
./AudioFileReader
```


## 📖 Notes

- This project was created in my 2nd year of college (2023–2024) as part of my learning journey in C++ and binary file I/O.

- It’s a simple program for learning purposes, not a complete audio parser.

