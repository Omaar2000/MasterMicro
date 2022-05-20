#include <iostream>
#include<bits/stdc++.h>
//#include <string.h>
//#include <exception>
// #include "json/json.hpp"
//  #include <libjson.h>
// #include<ptree.hpp>
// #include <json/value.h>
#include <fstream>
#include "json.hpp"
#include <boostpropertytreejsonparserdetailread.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace std;

using json = nlohmann::json;
namespace pt = boost::property_tree;

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
     NMOS(string id, string type, map<string,string> netlist, map<string,string> res )
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
};
class Topology
{


private:

    string ID ;
    vector <resistance> Resistors;
    vector<NMOS> Nmos;
public :
     Topology(string id)
    {
    ID = id;
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

    vector <resistance> getResistors()
    {
        return Resistors;
    }

    vector <NMOS> getNmos()
    {
        return Nmos;
    }
    void queryDevices()
    {
    // TODO print devices in this topology
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

    }
};


class Api{
private:

    vector<NMOS> nmos;
    vector<resistance> res;
    vector<Topology> Topologies;
public :



    void readJSON()
    {
        pt::ptree root;
        pt::read_json("topology.json", root);  // Load the json file in this ptree
        string  topId = root.get<string>("id");
        string type;
        string id;
        map<string,string> lastComp;
        map<string,string> netlist;

        for (pt::ptree::value_type & v : root.get_child("component"))
  {
//    if(v.first.get<string>("type") == "resistor")
    type = v.get<string>("type");




  }
    }
    void writeJSON()
    {
    }
    vector<Topology> &getTopologies()
    {
        return Topologies;
    }
    void deleteTopology(string TopID)
    {

    }
    void queryDevices(string TopID)
    {

    }
    void queryDevicesWithNetlistNode(string TopID, string NetID)
    {

    }



};

int main()
{
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
