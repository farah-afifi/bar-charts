// individual task.cpp 
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{

	ofstream f("farah.svg");
	f << "<?xml version=\"1.0\" standalone=\"no\"?>";
	f << "\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n";
	f << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
	f << "<svg width=\"500\" height=\"500\"\n";
	f << "xmlns=\"http://www.w3.org/2000/svg\">\n";///the part of the code that makes the bar chart work

	int x = 80, y = 100 ,w=55,h[4],scale,maxIndex=0;

	cout<<"enter 4 integers between 0 and 400 that represents the height of the bars\n";
	for (int i = 0; i < 4; i++) {///the user inputs 4 integers that indicate the height of the bars
        cin >> h[i];
        if (h[i]<0||h[i]>400){
            cout<<"you have entered wrong inputs ,you should enter a number from zero to 400\n";
            system("pause");
        }
    }
    maxIndex=max_element(h,h+4)-h;///to know the index of the maximum integer
	scale=400/h[maxIndex];///the scale by which we will use to make the dimensions of the bar chart appropriate with the 400 pixel limit
	h[maxIndex]=400.0/scale;///we'll make the largest input the highest bar of them all

    x=120;
	for(int i = 0; i < 4; i++){
        y=100+(400-(h[i]*scale));
        f << "<rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<w<<"\" height=\""<<h[i]*scale<<"\"\n";
        f<<"style=\"fill:black;\"/>\n";
        x+=40+55;
	}


	f<<"<line x1=\"80\" y1=\"80\" x2=\"80\" y2=\"500\"\n";///the 2 lines that define the bar chart
    f<<"style=\"stroke:black;stroke-width:2\"/>\n";
    f<<"<line x1=\"80\" y1=\"500\" x2=\"500\" y2=\"500\"\n";
    f<<"style=\"stroke:black;stroke-width:2\"/>\n</svg>";

    cout<<"the svg file with the bar chart has been created\n";
    f.close();
	return 0;
}
