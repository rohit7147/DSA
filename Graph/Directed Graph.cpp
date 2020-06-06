
/**/
/*int getComponent(struct Graph *G,int k,int a[])
{
    int i,count=0;
    stack<int> s;
    list<int>::iterator it;
    map<int,int> m;
    vector<bool> vis(G->V,false);
    for(i=0;i<G->V;i++)
    {
        if(!vis[i])
        {
            s.push(i);
            m[a[i]]++;
            while(!s.empty())
            {
                int src=s.top();
                if(!vis[src]) count++;
                vis[src]=true;
                for(it=G->adj[src].begin();it!=G->adj[src].end();it++)
                {
                    if(!vis[*it])
                    {
                        s.push(*it);
                        m[a[*it]]++;
                        if(m.size()<=k)
                            count++;
                        break;
                    }
                }
                if(it==G->adj[src].end())
                {
                    m[a[src]]--;
                    if(m[a[src]]==0)
                    {
                        //cout<<"value erased : "<<src+1<<endl;
                        m.erase(a[src]);
                    }
                    s.pop();
                }
            }
        }
        m.erase(m.begin(),m.end());
    }
    return count;
}*/
