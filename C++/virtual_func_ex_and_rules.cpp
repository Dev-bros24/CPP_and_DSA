#include<iostream>
using namespace std;

class CWH{
    protected:
    string title;
    float rating;

    public:
    CWH(string s, float rt){
        title = s;
        rating = rt;
    }
    virtual void display() // if we don't write virtual here then in below line nos. 75 and 76 this will get called.
    {
        // cout<<"Faaltu"<<endl;
    }
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

/*

Rules for virtual functions:
1. They cannot be static.
2. They are accessed by object pointers.
3. Virtual functions can be a friend of another class.

4. A virtual function in a base class might not be used.  
Like in above example there is no definition inside it.

5. If a virtual function is defined in base class, then it's not neccessary 
that it should be defined in derived class.
 OR 
If the definition of the function is not present in derived class then 
it will use the definition from the base class.

*/