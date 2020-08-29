#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
 
int main (int argc, char *argv[]){
	
        int n_giorni=0,i=0;
        double giorni,morti,positivi,contagiati;
        fstream l,s;
        //l.open("codv-19_morti.txt",ios::in);
        //l.open("positivi.txt",ios::in);
        l.open("contagiati.txt",ios::in);
	while(!l.eof()){
             n_giorni++;
             l.ignore(100,'\n');
	}
        n_giorni--;
        cout << "n. giorni = " << n_giorni<<endl;
        double g[n_giorni],m[n_giorni],p[n_giorni],c[n_giorni];
        double p_giornalieri[n_giorni],m_giornalieri[n_giorni],c_giornalieri[n_giorni];
	l.close();
        //l.open("codv-19_morti.txt", ios::in);
        //l.open("positivi.txt",ios::in);
        l.open("contagiati.txt",ios::in);
        //s.open("morti_giornalieri.txt",ios::out);
        //s.open("positivi_giornalieri.txt",ios::out);
        s.open("contagi_giornalieri.txt",ios::out);
	while(!l.eof()){
             l>>giorni>>contagiati;
       	     g[i]=giorni;
             c[i]=contagiati;
             if (l.eof())
	        break;
	        i++;   
                //cout << "giorno " << giorni <<"\t"<<"n. morti= " <<morti<<endl;
        }
        cout << "contatore= " <<i<<endl;
        //m_giornalieri[0]=7; //n.morti al giorno 0
        //p_giornalieri[0]=221; //n.positivi al giorno 0
        c_giornalieri[0]=229; //n.contagiati al giorno 0
        for (int j=1; j<=n_giorni; j++)
	{
	    c_giornalieri[j]=c[j]-c[j-1];
            //m_giornalieri[j]=m[j]-m[j-1];
	    //p_giornalieri[j]=p[j]-p[j-1];
	    cout<<"c_giornalieri["<<j<<"]= "<<c_giornalieri[j-1]<<endl;
            s<<j<<"\t"<<c_giornalieri[j-1]<<endl;
	}       	
        l.close();
        l.clear();
        s.close();
        s.clear();
return 0;
}
