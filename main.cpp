#include <bits/stdc++.h>
#include <fstream>
#include <cstring>

using namespace std;

struct WAVE {
    char ChunkID[4];
    int ChunkSize;
    char Format[4];
    char Subchunk1ID[4];
    int Subchunk1Size;
    short AudioFormat;
    short NumChannels;
    int SampleRate;
    int ByteRate;
    short BlockAlign;
    short BitsPerSample;
    void display() {
    cout<<"  WAVE File Header\n";
    cout<<"Chunk ID: "<<string(ChunkID,4)<<endl;
    cout<<"Chunk Size: "<<ChunkSize<<" bytes"<<endl;
    cout<<"Format: "<<string(Format,4)<<endl;
    cout<<"Subchunk1 ID: "<<string(Subchunk1ID,4)<<endl;
    cout<<"Subchunk1 Size: "<<Subchunk1Size<<" bytes"<<endl;
    cout<<"Audio Format: "<<AudioFormat<<endl;
    cout<<"Number of Channels: "<<NumChannels<<endl;
    cout<<"Sample Rate: "<<SampleRate<<" Hz"<<endl;
    cout<<"Byte Rate: "<<ByteRate<<" bytes/sec"<<endl;
    cout<<"Block Align: "<<BlockAlign<<" bytes"<<endl;
    cout<<"Bits Per Sample: "<<BitsPerSample<<" bits"<<endl;
    }
};
struct OGG {
    char CapturePattern[4];
    int Version;
    char HeaderType[1];
    int GranulePosition;
    int BitstreamSerialNum;
    int PageSequenceNum;
    double CheckSum;
    void display() {
        cout<<"  OGG File Header\n";
        cout<<"Capture Pattern: "<<CapturePattern<<endl;
        cout<<"Version: "<<Version<<endl;
        cout<<"Header Type: "<<HeaderType<<endl;
        cout<<"Granule Position: "<<GranulePosition<<endl;
        cout<<"Bitstream Serial Number: "<<BitstreamSerialNum<<endl;
        cout<<"Page Sequence Number: "<<PageSequenceNum<<endl;
        cout<<"Check Sum: "<<CheckSum<<endl;
    }
};


int main() {
    string myFile;
    cout<<"Enter your file: ";
    getline(cin,myFile);
    ifstream file(myFile,ios::binary);
    if (!file)
        cout<<"Not a file\n";
    WAVE wave;
    OGG ogg;
    file.read(reinterpret_cast<char*>(&wave),sizeof(WAVE));
    if (strncmp(wave.ChunkID,"RIFF",4)==0 || strncmp(wave.Format,"WAVE",4)==0) {
        wave.display();
    } else {
     file.seekg(0,ios::beg);
     file.read(reinterpret_cast<char*>(&ogg),sizeof(OGG));
     if(ogg.CapturePattern[0]=='O' && ogg.CapturePattern[1]=='g' && ogg.CapturePattern[2]=='g' && ogg.CapturePattern[3]=='S')
        ogg.display();
     else cout<<"This audio file is unsupported";
    }

    return 0;
}
