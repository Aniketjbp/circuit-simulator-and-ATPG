#include<bits/stdc++.h>
using namespace std;
void dfs(map<int,vector<int>>l,bool visited[],map<int,string>m,int output,int value[])
{
    visited[output]=true;
    int n=l[output].size();
    if(n==1)
    {
        if(visited[l[output][0]]==true && m[output]=="NOT")
        {
            value[output]=!value[l[output][0]];
        }
        else
            return dfs(l,visited,m,l[output][0],value);
    }
    if(n==2)
    {
        if(visited[l[output][0]]==false && visited[l[output][1]]==false)
        {
            dfs(l,visited,m,l[output][0],value);
            dfs(l,visited,m,l[output][1],value);
        }
        if(visited[l[output][0]]==false && visited[l[output][1]]==true)
        {
            dfs(l,visited,m,l[output][0],value);
        }
        if(visited[l[output][0]]==true && visited[l[output][1]]==false)
        {
            dfs(l,visited,m,l[output][1],value);
        }
        if(m[output]=="AND")
            value[output]=value[l[output][0]] & value[l[output][1]];
        if(m[output]=="OR")
            value[output]=value[l[output][0]] | value[l[output][1]];
        if(m[output]=="XOR")
            value[output]=value[l[output][0]] ^ value[l[output][1]];
    }
    return ;
}

int main()
{
    map<int,vector<int>>l;
    map<int,string>m;
    int cnt=0;
    unordered_set<int>se;
    cout<<"Please assign node from integer 0 and give input in consecutive integers"<<endl;
    cout<<"Input any negative number to complete your Netlist"<<endl;
    while(true)
    {
        int i;
        string s;
        cin>>i>>s;
        if(i>=0)
        {   if(se.find(i)==se.end())se.insert(i);
            cnt++;
            if(s=="AND")
            {
                int c1,c2;
                cin>>c1>>c2;
                if(se.find(c1)==se.end()){cnt++; se.insert(c1);}
                if(se.find(c2)==se.end()){cnt++; se.insert(c2);}
                l[i].push_back(c1);
                l[i].push_back(c2);
                m[i]=s;
            }
            if(s=="OR")
            {
                int c1,c2;
                cin>>c1>>c2;
                if(se.find(c1)==se.end()){cnt++; se.insert(c1);}
                if(se.find(c2)==se.end()){cnt++; se.insert(c2);}
                l[i].push_back(c1);
                l[i].push_back(c2);
                m[i]=s;
            }
            if(s=="XOR")
            {
                int c1,c2;
                cin>>c1>>c2;
                if(se.find(c1)==se.end()){cnt++; se.insert(c1);}
                if(se.find(c2)==se.end()){cnt++; se.insert(c2);}
                l[i].push_back(c1);
                l[i].push_back(c2);
                m[i]=s;
            }
            if(s=="NOT")
            {
                int c1;
                cin>>c1;
                m[i]=s;
                if(se.find(c1)==se.end()){cnt++; se.insert(c1);}
                l[i].push_back(c1);
            }
        }
        else break;
    }
    int input=0;
    map<int,int>m1;
    for(int i=0; i<cnt; i++)
    {
        if(l.find(i)==l.end())
        {
            m1[input]=i;
            input++;
        }
    }
    bool visited[cnt];
    int value[cnt];
    cout<<"Number of Nodes "<<cnt<<endl;
    cout<<"Number of input "<<input<<endl;
    cout<<"Enter output Node"<<endl;
    int output_node;
    cin>>output_node;
    cout<<"Please enter boolean value of nodes ";
    for(int i=0; i<input-1; i++)cout<<m1[i]<<",";
    cout<<m1[input-1]<<" respectively"<<endl;
    bool stop=true;
    int inc=0;
    while(stop==true)
    {
        for(int i=0; i<cnt; i++)
        {
            visited[i]=false;
        }
        for(int i=0; i<input; i++)
        {
            int temp;
            cin>>temp;
            if(temp==0 || temp==1)
            {
                value[m1[i]]=temp;
                visited[m1[i]]=true;
            }
            else
            {
                stop=false;
                break;
            }
        }
        if(stop)
        {
            inc++;
            dfs(l,visited,m,output_node,value);
            cout<<"Input#"<<inc<<": "<<value[output_node]<<endl;
        }
    }
}
