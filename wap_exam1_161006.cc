#include <iostream>
#include <vector>

using namespace std;
int P;
vector<vector<vector<int> > > sumCube(vector<vector<vector<int> > >& nums,vector<int>& cube,vector<int>& posi,int len)
{
   vector<vector<vector<int> > > tmp(len,vector<vector<int> >(len,vector<int>(len,0)));
   int s=0;
   for(int i=0;i<len;++i)
   {
       for(int j=0;j<len;++j)
       {
           for(int k=0;k<len;++k)
           {
               tmp[i][j][k]=cube[s];
               s++;
               nums[posi[0]+i][posi[1]+j][posi[2]+k] += tmp[i][j][k];
           }
       }
   }
   return nums;
}

vector<vector<vector<int> > > delCube(vector<vector<vector<int> > >& nums,vector<int>& cube,vector<int>& posi,int len)
{
   vector<vector<vector<int> > > tmp(len,vector<vector<int> >(len,vector<int>(len,0)));
   int s=0;
   for(int i=0;i<len;++i)
   {
       for(int j=0;j<len;++j)
       {
           for(int k=0;k<len;++k)
           {
               tmp[i][j][k]=cube[s];
               s++;
               nums[posi[0]+i][posi[1]+j][posi[2]+k] -= tmp[i][j][k];
           }
       }
   }
   return nums;
}

bool finish(vector<vector<vector<int> > >& nums)
{
    for(int i=0;i<nums.size();++i)
    {
        for(int j=0;j<nums.size();++j)
        {
            for(int k=0;k<nums.size();++k)
            {
                int n=nums[i][j][k]%P;
                if(n!=0) return false;
            }
        }
    }
    return true;
}

int main()
{
    int M,N;
    cin>>M>>N>>P;

    vector<vector<vector<int> > > nums(M,vector<vector<int> >(M,vector<int>(M,0)));

    for(int i=0;i<M;++i)
    {
        for(int j=0;j<M;++j)
        {
            for(int k=0;k<M;++k)
            {
                int num;
                cin>>num;
                nums[i][j][k]=num;
            }
        }
    }

    vector<vector<int> >cubes;
    vector<int> clen;

    for(int i=0;i<N;++i)
    {
        int len;
        cin>>len;
        clen.push_back(len);
        vector<int> tmp;
        for(int i=0;i<len;++i)
        {
            int num;
            cin>>num;
            tmp.push_back(num);
        }
        cubes.push_back(tmp);
        tmp.clear();
    }


    vector<vector<int> > pos(N,vector<int>(3,0));
    vector<vector<vector<int> > > nnums=nums;
    for(int si=0;si<N;++si)
    {
        nnums=sumCube(nnums,cubes[si],pos[si],clen[si]);
    }
    int s=N-1;
    while(!finish(nnums))
    {
        nnums=delCube(nnums,cubes[s],pos[s],clen[s]);
        if(pos[s][0]+pos[s][1]+pos[s][2] == 3*(M-clen[s]))
        {
            while((pos[s][0]+pos[s][1]+pos[s][2]) == 3*(M-clen[s]))
            {
                s -=1;
                if(s<0 || s>N-1)
                {
                    break;
                }
            }
            if(pos[s][2]<M-clen[s]) pos[s][2]++;
            else if(pos[s][1]<M-clen[s]) pos[s][1]++;
            else  pos[s][0]++;
            for(int si=s;si<N;++si)
            {
                pos[si][0]=0;
                pos[si][1]=0;
                pos[si][2]=0;
            }
            nnums=nums;
            for(int si=0;si<N;++si)
            {
                nnums=sumCube(nnums,cubes[si],pos[si],clen[si]);
            }

            s=N-1;
        }
        else
        {
            if(pos[s][2]<M-clen[s]) pos[s][2]++;
            else if(pos[s][1]<M-clen[s]) pos[s][1]++;
            else pos[s][0]++;
            nnums=sumCube(nnums,cubes[s],pos[s],clen[s]);
            s=N-1;
        }
    }

    for(int si=0;si<N;++si)
    {
        cout<<pos[si][0]<<" "<<pos[si][1]<<" "<<pos[si][2]<<endl;
    }

    return 0;
}
