//cpp
#include<iostream>
#include <cmath>
using namespace std;


double calculateDistance(double lat1, double long1, double lat2, double long2) {
    double pi =3.14;
    double dist;
    dist = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2);
    dist = acos(dist);
    dist = (6371 * pi * dist) / 180;
    return dist;
}
int main(){
    int a, b; //a is the no. of friends invited, b is the total no. of friends
    
    cin>>a>>b;
    char name[b];

    double my_lat, my_longt;
    cin>> my_lat, my_longt;

    double distance[b];

    double frn[b][2];

    for(int i=0; i<b; i++){
        cin>>name[i];
        cin>>frn[i][0]>>frn[i][1];
        distance[i]=calculateDistance(frn[i][0], frn[i][1], my_lat,my_longt);

    }
    int temp;
    char tempc;

    for(int i=0;i<b;i++)
	{		
		for(int j=i+1;j<b;j++)
		{
			if(distance[i]>distance[j])
			{
				temp  =distance[i];
				distance[i]=distance[j];
				distance[j]=temp;
                tempc=name[i];
                name[i]=name[j];
                name[j]=tempc;
			}
		}
	}
    int tot_dis=0;

    for(int i=0;i<a;i++){
        cout<<name[i]<<" "<<distance[i];
        tot_dis=tot_dis+distance[i];
    }
    cout<<" INR"<<tot_dis*1;
    

    return 0;
}
