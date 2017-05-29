#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

int ZtoR[256]={0,1,16,17,2,3,18,19,32,33,48,49,34,35,50,51,
               4,5,20,21,6,7,22,23,36,37,52,53,38,39,54,55,
               64,65,80,81,66,67,82,83,96,97,112,113,98,99,114,115,
                68,69,84,85,70,71,86,87,100,101,116,117,102,103,118,119,
                8,9,24,25,10,11,26,27,40,41,56,57,42,43,58,59,
                12,13,28,29,14,15,30,31,44,45,60,61,46,47,62,63,
                72,73,88,89,74,75,90,91,104,105,120,121,106,107,122,123,
                76,77,92,93,78,79,94,95,108,109,124,125,110,111,126,127,
                128,129,144,145,130,131,146,147,160,161,176,177,162,163,178,179,
                132,133,148,149,134,135,150,151,164,165,180,181,166,167,182,183,
                192,193,208,209,194,195,210,211,224,225,240,241,226,227,242,243,
                196,197,212,213,198,199,214,215,228,229,244,245,230,231,246,247,
                136,137,152,153,138,139,154,155,168,169,184,185,170,171,186,187,
                140,141,156,157,142,143,158,159,172,173,188,189,174,175,190,191,
                200,201,216,217,202,203,218,219,232,233,248,249,234,235,250,251,
                204,205,220,221,206,207,222,223,236,237,252,253,238,239,254,255};
int raster_print[256]={0};
int offset=0;
//=====================================================================
void fill_raster(const int&edge,int &offset){
    int len=edge/4;
    int depth=0;
    switch(len){
        case 16:depth=0;break;
        case 8:depth=1;break;
        case 4:depth=2;break;
        case 2:depth=3;break;
        case 1:depth=4;break;
    }
    for(int i=0;i<len;++i){
        for(int j=0;j<len;++j){
            if(i==0||j==0)raster_print[ZtoR[offset+i*len+j]]=depth;
            else raster_print[ZtoR[offset+i*len+j]]=depth;
            //fprintf(stderr,"%i  %i  %i \n",offset+i*len+j,ZtoR[offset+i*len+j],raster_print[ZtoR[offset+i*len+j]]);
        }
    }
    offset+=len*len;
}
void print_raster(FILE*fp){
    for(int i=0;i<256;++i){
        fprintf(fp,"%i ",raster_print[i]);
        if(15==i%16)fprintf(fp,"\n");
    }
}

//=====================================================================

int main(){
    time_t start=clock();
    srand(time(NULL));
//=====================================================================
    FILE*fp_in,*fp_out;
    fp_in=fopen("test_in.txt","rb+");
    int edge=0;
    while(fscanf(fp_in,"%i",&edge)!=EOF){
        fill_raster(edge,offset);
    }
    fclose(fp_in);
    fp_out=fopen("test_out.txt","wb+");
    print_raster(fp_out);
    fclose(fp_out);

//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}