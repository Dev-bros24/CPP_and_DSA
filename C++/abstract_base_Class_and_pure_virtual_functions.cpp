#include<iostream>
using namespace std;

/*
Abstract base class means a class which will be surely just used for making derived
classes and there should be a pure virtual function inside it for it to be an
abstract base class. No object can be created of an abstract class.
*/

class CWH{
    protected:
    string title;
    float rating;

    public:
    CWH(string s, float rt){
        title = s;
        rating = rt;
    }
    virtual void display()=0;  // do-nothing function --> Pure virtual function
    
};

class CWHVideo : public CWH{
    protected:
    float videoLength;

    public:
    CWHVideo(string s, float rt, float vl) : CWH(s, rt){
        videoLength = vl;
    }

    void display()
    {
        cout<<"Title of this video is: "<<title<<endl;
        cout<<"Rating: "<<rating<<" is the rating of this video"<<endl;
        cout<<"Length of this video is: "<<videoLength<<endl;
    }
};

class CWHText : public CWH{
    protected:
    int words;
    public:
    CWHText(string s, float rt, int wc) : CWH(s, rt){
        words = wc;
    }

    void display()
    {
        cout<<"Title of this Article is: "<<title<<endl;
        cout<<"Rating: "<<rating<<" is the rating of this Article "<<endl;
        cout<<"Number of words in this tutorial are: "<<words<<endl;
    }
};

int main(){
    string title;
    float rating, vlen;
    int words;

    // For CWH video
    title = "C++ Tutorial";
    rating = 4.82;
    vlen = 4.23;
    CWHVideo cppvideo(title, rating, vlen);
    // cppvideo.display();

    // For CWH text
    title = "C++ Tutorial text";
    rating = 4.34;
    words = 435;
    CWHText cpptext(title, rating, words);
    // cpptext.display();

    CWH *ptr[2];
    ptr[0] = &cppvideo;
    ptr[1] = &cpptext;

    ptr[0] -> display();
    ptr[1] -> display();

    return 0;
}

