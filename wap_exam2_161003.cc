#include <iostream>
#include <vector>

using namespace std;

void getPoints(vector<int> rooms,vector<int>& points,vector<vector<int> >& con,int i,int rt,int score);
int maxscore=0;

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> rooms(N+1,0);
    vector<int> points(N+1,0);
    for(int i=1;i<=N;++i)
    {
        int num;
        cin>>num;
        points[i]=num;
    }
    vector<vector<int> > con(N+1,vector<int>(N+1,0));
    for(int i=0;i<N-1;++i)
    {
        int x,y;
        cin>>x>>y;
        con[x][y]=1;
        con[y][x]=1;
    }

    getPoints(rooms,points,con,1,M,0);
    cout<<maxscore<<endl;

    return 0;
}


void getPoints(vector<int> rooms,vector<int>& points,vector<vector<int> >& con,int i,int rt,int score)
{
    if(rt==0 || i==rooms.size())
    {
        maxscore = max(score,maxscore);
    }
    else if(rt==rooms.size()-i)
    {
        for(int ni=i;ni<rooms.size();++ni)
        {
            //choose ni
            if(rooms[ni]==0)
            {
                rooms[ni]=1;
                score+=points[ni];
            }
            for(int j=1;j<rooms.size();++j)
            {
                if(con[ni][j]==1 && rooms[j]==0)
                {
                    rooms[j]=1;
                    score += points[j];
                }
            }
        }
        maxscore = max(score,maxscore);
    }
    else
    {
        //not choose i
        getPoints(rooms,points,con,i+1,rt,score);

        //choose i
        if(rooms[i]==0)
        {
            rooms[i]=1;
            score+=points[i];
        }
        for(int j=1;j<rooms.size();++j)
        {
            if(con[i][j]==1 && rooms[j]==0)
            {
                rooms[j]=1;
                score += points[j];
            }
        }
        getPoints(rooms,points,con,i+1,rt-1,score);

    }
}
