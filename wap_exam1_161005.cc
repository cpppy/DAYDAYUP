#include <iostream>
#include <vector>

using namespace std;
int P=3;
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

void printnums(vector<vector<vector<int> > >& nums)
{
    cout<<"nums : "<<endl;
    cout<<"------------------------------------"<<endl;
    int len=nums.size();
    for(int i=0;i<len;++i)
   {
       for(int j=0;j<len;++j)
       {
           for(int k=0;k<len;++k)
           {
               cout<<nums[i][j][k]<<'\t';
           }
           cout<<endl;
       }
       cout<<endl;
   }
   cout<<"---------------------------------------"<<endl;
}

int main()
{
    int M,N;
    //cin>>M>>N>>P;
    M=2;
    N=2;
    P=3;

    vector<vector<vector<int> > > nums(M,vector<vector<int> >(M,vector<int>(M,0)));
    nums[0][1][1]=1;
    nums[0][0][0]=1;
    /*
    for(int i=0;i<M;++i)
    {
        for(int j=0;j<M;++j)
        {
            for(int k=0;k<M;++k)
            {
                int num;
                //cin>>num;
                nums[i][j][k]=num;
            }
        }
    }
    */
    vector<vector<int> >cubes;
    vector<int> clen;
    clen.push_back(2);
    cubes.push_back(clen);
    cubes.push_back(clen);
    clen[0]=1;
    clen.push_back(1);
    /*
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
    */


    vector<vector<int> > pos(N,vector<int>(3,0));
    int s=N-1;
    vector<vector<vector<int> > > nnums=nums;
    int count = 0;
    for(int si=0;si<N;++si)
    {
        nnums=sumCube(nnums,cubes[si],pos[si],clen[si]);
    }
    count++;
    while(!finish(nnums))
    {

        cout<<count<<endl;
        nnums=nums;
        cout<<M<<"        "<<clen[s]<<endl;
        if(pos[s][0]+pos[s][1]+pos[s][2] == 3*(M-clen[s]))
        {
            cout<<"cube_"<<s<<"  rived [n][n][n]"<<endl;
            while((pos[s][0]+pos[s][1]+pos[s][2]) == 3*(M-clen[s]))
            {
                s -=1;
                if(s<0 || s>N-1)
                {
                    cout<<"did not have cube[-1] !"<<endl;
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
            cout<<"cube_"<<s<<"  come to "<<pos[s][0]<<','<<pos[s][1]<<','<<pos[s][2]<<endl;
            for(int si=0;si<N;++si)
            {
                nnums=sumCube(nnums,cubes[si],pos[si],clen[si]);
            }
            s=N-1;
        }
        printnums(nums);
    }

    for(int si=0;si<N;++si)
    {
        cout<<pos[si][0]<<" "<<pos[si][1]<<" "<<pos[si][2]<<endl;
    }



    cout << "Hello world!" << endl;
    return 0;
}
