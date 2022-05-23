#include <iostream>

using namespace std;
const int MAX=50;
int main()
{
    int arr[MAX][MAX][MAX];
    int idx=0,d=0,r=0,c=0;
    int ch=0,d1=0,d2=0,d3=0;
    cout<<" Enter '1' for 1D array OR '3' for 3D array OR any number to exit!"<<endl;
    cin>>ch;
    cout<<" enter dimensions"<<endl;
    cin>>d1>>d2>>d3;
    while(ch)
    {
        if(ch==1)
        {
            cout<<"enter index to be converted to 1D"<<endl;
            cin>>d>>r>>c;
            idx=d*d2*d3+ r*d3+ c;
            cout<<idx<<endl;
        }
        else if(ch==3)
        {    cout<<"enter index to be converted to 3D"<<endl;
            cin>>idx;
            d=idx/(d2*d3);
            r=(idx-d*(d2*d3))/d3;
            c=(idx-d*(d2*d3))-r*d3;
            cout<<d<<" "<<r<<" "<<c<<endl;
        }
        else break;
        
    cout<< " Enter '1' for 1D array OR '3' for 3D array OR any number to exit!"<<endl;
        cin>>ch;
    }
    return 0;
}
