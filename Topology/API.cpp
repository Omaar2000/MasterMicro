#include <iostream>
#include<bits/stdc++.h>
//#include <string.h>
//#include <exception>
// #include "json/json.h"
//  #include <libjson.h>
// #include<ptree.hpp>
// #include <json/value.h>
#include <fstream>
#include "json.hpp"
//#include <nlohmann/json.hpp>
// #include <boostpropertytreejsonparserdetailread.hpp>
// #include <boost/property_tree/ptree.hpp>

using namespace std;

using json = nlohmann::json;
// namespace pt = boost::property_tree;

class Component{
    protected:

    string ID ;
    string Type;
    map<string,string> Netlist;
    private:
    map<string,string> comp;

    public :
     Component()
    {

    }

    string getID()
    {
        return ID;
    }

    string getType()
    {
        return Type;
    }

    virtual map<string,string> &GetlastComp()
    {
        return comp;
    }
    map<string, string> &getNetlist()
    {
    return Netlist;
    }

    bool NetContainsKey(string NetlistNodeID)
    {
       auto itr = Netlist.find(NetlistNodeID);
       return itr != Netlist.end();
    }

};

class NMOS : public Component{
    private:

    map<string,string> M1;

    public :
     NMOS(string id, string type, map<string,string> netlist, map<string,string> m1 )
    {
    ID = id;
    Type= type;
    Netlist = netlist;
    M1 = m1;
    }

//    string getID()
//    {
//        return ID;
//    }
//
//    string getType()
//    {
//        return Type;
//    }
//
string writeNMOS()
    {
        string JsonNmos = "{\"type\": \"nmos\",\n \"id\": \""+getID()+ "\",\n\"" +getID() + "\": {\n \"default\": " + M1.find("default")->second +" ,\n\"min\": " + M1.find("min")->second +",\n\"max\": " + M1.find("max")->second +"},\n\"netlist\": {\n\"drain\": \"" + Netlist.find("drain")->second +"\",\n\"gate\":\"" + Netlist.find("gate")->second + "\",\n\"source\": \"" + Netlist.find("source")->second +"\"}\n}" ;
        cout <<JsonNmos<<endl;
      return JsonNmos;
    }

    map<string,string> &GetlastComp()
    {
        return M1;
    }
//    map<string, string> &getNetlist()
//    {
//    return Netlist;
//    }
//
//    bool NetContainsKey(string NetlistNodeID)
//    {
//       auto itr = Netlist.find(NetlistNodeID);
//       return itr != Netlist.end();
//    }
};

class resistance : public Component{
    private:

    map<string,string> Res;

    public :
     resistance(string id , string type, map<string,string> netlist, map<string,string> res)
    {
    ID = id;
    Type= type;
    Netlist = netlist;
    Res = res;
    }

//    string getID()
//    {
//        return ID;
//    }
//
//    string getType()
//    {
//        return Type;
//    }

//    void addNetlist( map<string,string> netlist)
//    Netlist = netlist;
//
//    void addRes( map<string,string> netlist)
//    Netlist = netlist;

    map<string,string> &GetlastComp()
    {
        return Res;
    }
//    map<string, string> &getNetlist()
//    {
//    return Netlist;
//    }
//
//    bool NetContainsKey(string NetlistNodeID)
//    {
//       auto itr = Netlist.find(NetlistNodeID);
//       return itr != Netlist.end();
//    }
    string writeRes()
    {
        string JsonRes = "{\"type\": \"resistor\",\n \"id\": \""+getID()+ "\",\n\"resistance\": {\n \"default\": " + Res.find("default")->second +" ,\n\"min\": " + Res.find("min")->second +",\n\"max\": " + Res.find("max")->second +"},\n\"netlist\": {\n\"t1\": \"" + Netlist.find("t1")->second +"\",\n\"t2\": \"" + Netlist.find("t2")->second +"\"} \n} ," ;
        cout <<JsonRes<<endl;

      return JsonRes;
    }
};
class Topology
{


private:

    string ID ;
    vector <resistance> Resistors;
    vector<NMOS> Nmos;
public :
     Topology(string id, vector <resistance> Resistors, vector<NMOS> Nmos )
    {
    ID = id;
    this->Resistors=Resistors;
    this->Nmos = Nmos;
    }

    string getID()
    {
        return ID;
    }

    void addResistor(resistance resistor)
    {
        Resistors.push_back(resistor);
    }

    void addNMOS(NMOS nmos)
    {
        Nmos.push_back(nmos);
    }

    vector <resistance>& getResistors()
    {
        return Resistors;
    }

    vector <NMOS> &getNmos()
    {
        return Nmos;
    }

    string writeDevicesInJson()
    {   string j;
        for(int i = 0; i < Resistors.size(); i++)
            j += Resistors[i].writeRes();
        for(int i = 0; i < Nmos.size(); i++)
        j += Nmos[i].writeNMOS();
    return j;
    }

    void queryDevicesWithNetlistNode(string NetID)
    {
        vector<resistance> foundRes;
        vector<NMOS> foundNMOS;
    for(int i = 0; i<Resistors.size() ; i++)
    {
     if(Resistors[i].NetContainsKey(NetID))
        foundRes.push_back(Resistors[i]);
    }
    for(int i = 0; i<Nmos.size() ; i++)
    {
     if(Nmos[i].NetContainsKey(NetID))
        foundNMOS.push_back(Nmos[i]);
    }

    printDevices(foundRes, foundNMOS);
    }

    void printDevices(string topID)
    {   if(!Nmos.empty() || !Resistors.empty())
       {
         cout<< "Topology "+ topID +" contains:"<<endl;
        for(int i = 0; i < Resistors.size(); i++)
        {
            cout<< Resistors[i].getID()<<endl;
        }
        for(int i = 0; i < Nmos.size(); i++)
        {
            cout<< Nmos[i].getID()<<endl;
        }
       }
       else cout<<"No devices in this Topology"<<endl;
    }
    void printDevices(vector<resistance> &FoundRes, vector<NMOS> &FoundNmos)
    {   if(!FoundNmos.empty() || !FoundRes.empty())
       {
         cout<< "devices  connected to the given netlist node contains:"<<endl;
        for(int i = 0; i < Resistors.size(); i++)
        {
            cout<< Resistors[i].getID()<<endl;
        }
        for(int i = 0; i < Nmos.size(); i++)
        {
            cout<< Nmos[i].getID()<<endl;
        }
       }
       else cout<< "Not found! "<<endl;
    }
};


//============================================= API CLASS ===========================

class Api{
private:

    vector<NMOS> nmos;
    vector<resistance> res;
    vector<Topology> Topologies;
public :



    void readJSON()
    {
        // pt::ptree root;
        // pt::read_json("topology.json", root);  // Load the json file in this ptree
        std::ifstream ifs("topology.json");
        json jf = json::parse(ifs);
        string  topId ;
        topId = jf["id"];
//        cout<<topId<<endl;
        string  type;
//        auto j = jf["components"][0];
        string id ;
//        cout <<j["id"]<<endl;
//        cout<<jf["components"].size()<<endl;
//
//        cout <<j["id"]<<endl;
//        cout <<jf["components"][0]["id"]<<endl;
        map<string,string> lastComp;
        map<string,string> netlist;
        int itr = 0;
        // auto i = jf["components"][];
        for(auto i : jf["components"]){
            type = i["type"];
            id = i["id"];
           
            netlist.clear();
            lastComp.clear();
            if(type == "resistor")
            {
                

            lastComp.insert(make_pair("default",to_string(i["resistance"]["default"])));
            lastComp.insert({"min",to_string(i["resistance"]["min"])});
            lastComp.insert({"max",to_string(i["resistance"]["max"])});
    


            netlist.insert({"t1",(string)i["netlist"]["t1"]});
            netlist.insert({"t2",(string)i["netlist"]["t2"]});
            

           resistance res1(id, type,netlist,lastComp);
           res.push_back(res1);
                       

            }
            else if(type == "nmos")
            {
            lastComp.insert(make_pair("default",to_string(i["m1"]["default"])));
            lastComp.insert({"min",to_string(i["m1"]["min"])});
            lastComp.insert({"max",to_string(i["m1"]["max"])});

            netlist.insert({"drain",i["netlist"]["drain"]});
            netlist.insert({"gate",i["netlist"]["gate"]});
            netlist.insert({"source",i["netlist"]["source"]});
           NMOS m1(id, type, netlist, lastComp);
           nmos.push_back(m1);
            }
            Topology top(topId, res, nmos);
            Topologies.push_back(top);

        }
  }
    void addTop(Topology top)
    {
        Topologies.push_back(top);
    }

    void writeJSON(string topID)
    {
         string topology;
         for(auto i = Topologies.begin(); i != Topologies.end(); i++)
            if(i->getID() == topID){
         topology = (string)"{\n\"id\": \""+ (string)topID +"\",\n\"components\": [ \n" + (string)i->writeDevicesInJson() + "\n  ]\n}";
        std::ofstream o("newJSon.json");
        json j = json::parse(topology);
        o << std::setw(4) << j << std::endl;
    }
    }

    void getTopologies()
    {   if(!Topologies.empty())
        {
            cout<<"topologies currently in the memory"<<endl;
        for(int i = 0; i <Topologies.size(); i++)
        {
            cout<<Topologies[i].getID()<<endl;
        }
    }
    }
    void deleteTopology(string TopID)
    {
        int s = Topologies.size();
        for(auto i = Topologies.begin(); i != Topologies.end(); i++)
            if(i->getID() == TopID)
            Topologies.erase(i);

        if(s == Topologies.size())
        cout <<"Topology not found! "<<endl;
    }
    void queryDevices(string TopID)
    {
        for(auto i = Topologies.begin(); i != Topologies.end(); i++)
           {if(i->getID() == TopID)
            {
                i->printDevices(TopID);
                break;
            }
            if (i == Topologies.end())
            cout <<"element not found! "<<endl;
            }
    }
    void queryDevicesWithNetlistNode(string TopID, string NetID)
    {
        for(auto i = Topologies.begin(); i != Topologies.end(); i++)
           {
               if(i->getID() == TopID )
            {
                i->queryDevicesWithNetlistNode(NetID);
                break;
            }
            if (i == Topologies.end())
            cout <<"element not found! "<<endl;
            }
    }




 };
int main()
{
    Api app;
    app.readJSON();
    map<string,string> lastComp;
    map<string,string> netlist;
    vector<resistance> resistors;
    vector<NMOS> m1;
    lastComp.insert({"default", "1"});
    lastComp.insert({"min","0.5"});
    lastComp.insert({"max","1.5"});

    netlist.insert({"t1", "vdd"});
    netlist.insert({"t2","n1"});

    resistance res2("res2", "resistor", netlist, lastComp);
    resistors.push_back(res2);

    lastComp.clear();
    netlist.clear();

    lastComp.insert({"default", "1"});
    lastComp.insert({"min","0.5"});
    lastComp.insert({"max","1.5"});

    netlist.insert({"drain", "n1"});
    netlist.insert({"gate","vout"});
    netlist.insert({"source","vss"});

    NMOS nmos1("m2", "nmos", netlist, lastComp);
    m1.push_back(nmos1);
    Topology top("top2", resistors, m1);
    // cout << top.getID()<<endl;
    app.addTop(top);
    //app.writeJSON("top2");
    app.queryDevices("top1");
    app.getTopologies();
//    vector<NMOS> nmos;
//    vector<resistance> resistor;
//    vector<Topology> Topologies;
//    map<string,string> netlist;
//    map<string,string> nmosM1;
//    map<string,string> res1;
//    nmosM1.insert({"default","1.5"});
//    nmosM1.insert({"min","1"});
//    nmosM1.insert({"max","2"});
//    netlist.insert({"drain","n1"});
//    netlist.insert({"gate","vin"});
//    netlist.insert({"source","vss"});
//    NMOS m1("m1","nmos",netlist,nmosM1 );
//    cout << m1.NetContainsKey("gate");
//
//    cout<<m1.getType()<<endl;
//    cout<<m1.getID()<<endl;


//    for(auto itr = m1.getNetlist().begin(); itr != m1.getNetlist().end(); itr ++)
//    {
//        cout << '\t' << itr->first << '\t' << itr->second
//             << '\n';
//    }
//    for(auto itr = m1.GetlastComp().begin(); itr != m1.GetlastComp().end(); itr ++)
//    {
//        cout << '\t' << itr->first << '\t' << itr->second
//             << '\n';
//    }
////    nmos.push_back()
    return 0;
}
